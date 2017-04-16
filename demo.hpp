#ifndef DEMO_HPP
#define DEMO_HPP

#include "view.hpp"
#include "form.hpp"
#include <sstream>
#include <Poco/Format.h>
#include <Poco/Path.h>
#include <Poco/DeflatingStream.h>


namespace hi {

    class hello : public view {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content = "hello,world";
            res.status = 200;
        }

    };

    class empty : public view {
    public:

        void handler(request& req, response& res) {

        }

    };

    class form : public view {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content.clear();
            res.status = 200;
            const std::string& method = req.headers["method"];
            if (method == "GET") {
                hi::set_get_form(req.headers, req.form);
            }
            if (method == "POST" || method == "PUT") {
                std::string content_type = req.headers.find("Content-Type")->second;
                if (content_type.find("multipart/form-data") != std::string::npos) {
                    std::string allow_field = "upload"
                            , allow_type = "image/jpeg|image/png"
                            , upload_dir = Poco::Path::current() + "html/upload";
                    double upload_size = 1048567;
                    hi::upload_handler upload_handler(allow_field, allow_type, upload_dir, upload_size);
                    hi::set_post_or_put_form(req.form["temp_body_file_path"], req.headers, &upload_handler, req.form);
                } else if (content_type.find("application/x-www-form-urlencoded") != std::string::npos) {
                    hi::set_post_or_put_form(req.form["temp_body_file_path"], req.headers, 0, req.form);
                }
            }
            res.content.append("head data\r\n");
            for (auto &item : req.headers) {
                res.content.append(Poco::format("%[0]s\t=\t%[1]s\r\n", item.first, item.second));
            }
            res.content.append("form data\r\n");
            for (auto & item : req.form) {
                res.content.append(Poco::format("%[0]s\t=\t%[1]s\r\n", item.first, item.second));
            }
        }

    };

    class gzip : public view {

        void handler(request& req, response& res) {
            res.headers.insert(std::make_pair("Content-Encoding", "gzip"));
            std::ostringstream os;
            Poco::DeflatingOutputStream gzipper(os, Poco::DeflatingStreamBuf::STREAM_GZIP);
            gzipper << "hello,world";
            gzipper.close();
            res.content = os.str();

        }

    };

    class redirect : public view {

        void handler(request& req, response& res) {
            res.status = 302;
            res.headers.insert(std::make_pair("Location", "/hello"));
        }

    };

    class error : public view {

        void handler(request& req, response& res) {
            res.status = 404;
            res.content = "404 Not found";
        }

    };


}


#endif /* DEMO_HPP */
