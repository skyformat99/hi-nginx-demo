#ifndef DEMO_HPP
#define DEMO_HPP

#include "view.hpp"
#include <Poco/Format.h>
#include <Poco/Path.h>
#include <Poco/DeflatingStream.h>
#include <sstream>
#include <opencv2/opencv.hpp>

namespace nginx {

    class hello : public view {
    public:

        hello() {
        }

        ~hello() {
        }

        void handler(const request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            std::string key("test");
            if (res.nginx_cache->has(key)) {
                res.content = res.nginx_cache->get(key)->value();
            } else {
                res.content = "hello,world";
                res.nginx_cache->add(key, nginx::cache_string(res.content, 60 * 1000));
            }
            res.status = 200;


        }

    };

    class ses : public view {
    public:

        ses() {
        }

        ~ses() {
        }

        void handler(const request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content.clear();

            if (res.nginx_session->find("test") == res.nginx_session->end()) {
                res.nginx_session->insert(std::make_pair("test", 1));
            } else {
                int tmp;
                res.nginx_session->at("test").convert<int>(tmp);
                res.nginx_session->at("test") = ++tmp;
            }
            res.cookies["test"] = res.nginx_session->at("test").toString();

            for (auto & item : *res.nginx_session) {
                res.content.append(Poco::format("session:\r\n%[0]s = %[1]s\r\n", item.first, item.second.toString()));
            }
            for (auto & item : req.cookies) {
                res.content.append(Poco::format("cookies:\r\n%[0]s = %[1]s\r\n", item.first, item.second));
            }
            res.status = 200;
        }

    };

    class empty : public view {
    public:

        empty() {
        }

        ~empty() {
        }

        void handler(const request& req, response& res) {

        }

    };

    class form : public view {
    public:

        form() {
        }

        ~form() {
        }

        void handler(const request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";

            res.status = 200;
            res.content.append("head data\r\n");
            for (auto &item : req.headers) {
                res.content.append(Poco::format("%[0]s\t=\t%[1]s\r\n", item.first, item.second));
            }
            res.content.append("form data\r\n");
            for (auto & item : req.form) {
                res.content.append(Poco::format("%[0]s\t=\t%[1]s\r\n", item.first, item.second));
            }
            res.content.append("route data\r\n");
            for (auto & item : req.route) {
                res.content.append(Poco::format("%[0]s\r\n", item));
            }
        }

    };

    class thum : public view {
    public:

        thum() {
        }

        ~thum() {
        }

        void handler(const request& req, response& res) {
            if (req.form.find("upload") != req.form.end()) {
                const std::string& upload_dir = req.headers.at("cpp_upload_dir");
                Poco::Path src_web_path(req.form.at("upload")),
                        src_real_path(upload_dir + src_web_path.toString());
                Poco::Path des_web_path(src_web_path.parent().toString() + src_web_path.getBaseName() + "-thum." + src_web_path.getExtension())
                        , des_real_path(upload_dir + des_web_path.toString());

                cv::Mat src = cv::imread(src_real_path.toString());
                cv::resize(src, src, cv::Size(src.cols / 3, src.rows / 3), 0, 0, CV_INTER_LINEAR);
                if (cv::imwrite(des_real_path.toString(), src)) {
                    res.content = Poco::format("<img src='%[0]s' />", "/upload" + des_web_path.toString());
                } else {
                    res.content = Poco::format("<p>%[0]s</p>", des_real_path.toString());
                }
            } else {
                res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
                res.content = "Not found upload field.";
            }
        }

    };
    
    class gzip :public view{
        void handler(const request& req, response& res){
            res.headers.insert(std::make_pair("Content-Encoding","gzip"));
            std::ostringstream os;
            Poco::DeflatingOutputStream gzipper(os,Poco::DeflatingStreamBuf::STREAM_GZIP);
            gzipper << "hello,world";
            gzipper.close();
            res.content = os.str();
            
        }

    };


}


#endif /* DEMO_HPP */
