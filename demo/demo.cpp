
#include "servlet.hpp"

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>


namespace hi {

    class demo : public servlet {
    public:

        void handler(request& req, response& res) {
            if (req.method == "GET") {
                if (req.uri == "/demo/hello") {
                    this->do_hello(req, res);
                } else if (req.uri == "/demo/empty") {
                    this->do_empty(req, res);
                } else if (req.uri == "/demo/error") {
                    this->do_error(req, res);
                } else if (req.uri == "/demo/redirect") {
                    this->do_redirect(req, res);
                } else if (req.uri == "/demo/form") {
                    this->do_form(req, res);
                } else if (req.uri == "/demo/math") {
                    this->do_math(req, res);
                } else if (req.uri == "/demo/session") {
                    this->do_session(req, res);
                } else {
                    this->do_error(req, res);
                }
            }else if (req.method=="POST" && req.uri=="/demo/form"){
                this->do_form(req, res);
            }
        }
    private:

        void do_hello(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content = "hello,world";
            res.status = 200;
        }

        void do_empty(request& req, response& res) {

        }

        void do_error(request& req, response& res) {
            res.status = 404;
            res.content = "404 Not found";
        }

        void do_form(request& req, response& res) {
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

        void do_math(request& req, response& res) {
            if (req.form.find("a") != req.form.end()
                    && req.form.find("b") != req.form.end()
                    && req.form.find("m") != req.form.end()) {
                res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
                res.content.clear();
                res.status = 200;
                double a = boost::lexical_cast<double>(req.form["a"])
                        , b = boost::lexical_cast<double>(req.form["b"]);
                const std::string& m = req.form["m"];

                if (m == "add") {
                    res.content = boost::lexical_cast<std::string>(a + b);
                } else if (m == "sub") {
                    res.content = boost::lexical_cast<std::string>(a - b);
                } else if (m == "multi") {
                    res.content = boost::lexical_cast<std::string>(a * b);
                } else if (m == "div") {
                    res.content = boost::lexical_cast<std::string>(a / b);
                } else {
                    res.content = m + " method is not support.";
                }

            }
        }

        void do_redirect(request& req, response& res) {
            res.status = 302;
            res.headers.insert(std::make_pair("Location", "/demo/hello"));
        }

        void do_session(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            std::string key("test");
            long i = 0;
            if (req.session.find(key) == req.session.end()) {
                res.session[key] = "0";
            } else {
                i = boost::lexical_cast<long>(req.session[key]) + 1;
                res.session[key] = boost::lexical_cast<std::string>(i);
            }

            res.content = (boost::format("hello,%1%") % i).str();
            res.status = 200;
        }

    };
}

extern "C" hi::servlet* create() {
    return new hi::demo();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}

