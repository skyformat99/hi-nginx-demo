#include "view.hpp"
#include "form.hpp"
#include <sstream>


namespace hi {

    class form : public view {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content.clear();
            res.status = 200;
            std::map<std::string, std::string> form;

            if (req.method == "GET") {
                hi::set_get_form(req, form);
            }
            if (req.method == "POST" || req.method == "PUT") {
                std::string content_type = req.headers.find("Content-Type")->second;
                if (content_type.find("multipart/form-data") != std::string::npos) {
                    std::string allow_field = "upload"
                            , allow_type = "image/jpeg|image/png"
                            , upload_dir = Poco::Path::current() + "html/upload";
                    double upload_size = 1048567;
                    hi::upload_handler upload_handler(allow_field, allow_type, upload_dir, upload_size);
                    hi::set_post_or_put_form(req, &upload_handler, form);
                } else if (content_type.find("application/x-www-form-urlencoded") != std::string::npos) {
                    hi::set_post_or_put_form(req, 0, form);
                }
            }
            res.content.append("head data\r\n");
            for (auto &item : req.headers) {
                res.content.append(Poco::format("%[0]s\t=\t%[1]s\r\n", item.first, item.second));
            }
            res.content.append("form data\r\n");
            for (auto & item : form) {
                res.content.append(Poco::format("%[0]s\t=\t%[1]s\r\n", item.first, item.second));
            }
            res.content.append(Poco::format("%[0]s-%[1]s-%[2]s", req.client, req.method, req.uri));
        }

    };

}

extern "C" hi::view* create() {
    return new hi::form();
}

extern "C" void destroy(hi::view* p) {
    delete p;
}