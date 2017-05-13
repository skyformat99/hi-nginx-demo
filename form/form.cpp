#include "servlet.hpp"



namespace hi {

    class form : public servlet {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content.clear();
            res.status = 200;

            res.content.append("head data\r\n");
            for (auto &item : req.headers) {
                res.content.append(item.first + "\t=\t" + item.second).append("\n");
            }
            res.content.append("form data\r\n");
            for (auto & item : req.form) {
                res.content.append(item.first + "\t=\t" + item.second).append("\n");
            }
            res.content.append("cookies data\r\n");
            for (auto & item : req.cookies) {
                res.content.append(item.first + "\t=\t" + item.second).append("\n");
            }
            res.content.append(req.client).append("\n")
                    .append(req.user_agent).append("\n")
                    .append(req.method).append("\n")
                    .append(req.uri).append("\n")
                    .append(req.param).append("\n");

        }

    };

}

extern "C" hi::servlet* create() {
    return new hi::form();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}