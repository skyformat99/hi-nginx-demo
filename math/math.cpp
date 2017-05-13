#include "servlet.hpp"
#include <boost/lexical_cast.hpp>

namespace hi {

    class math : public servlet {

        void handler(request& req, response& res) {
            if (req.method == "GET") {
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
        }

    };
}

extern "C" hi::servlet* create() {
    return new hi::math();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}