#include "servlet.hpp"
#include "form.hpp"
#include <Poco/NumericString.h>
#include <Poco/NumberFormatter.h>

namespace hi {

    class math : public servlet {

        void handler(request& req, response& res) {
            if (req.method == "GET") {
                std::map<std::string, std::string> form;
                hi::set_get_form(req, form);
                if (form.find("a") != form.end()
                        && form.find("b") != form.end()
                        && form.find("m") != form.end()) {
                    res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
                    res.content.clear();
                    res.status = 200;
                    double a = Poco::strToDouble(form["a"].c_str())
                            , b = Poco::strToDouble(form["b"].c_str());
                    const std::string& m = form["m"];

                    if (m == "add") {
                        res.content = Poco::NumberFormatter::format(a + b);
                    } else if (m == "sub") {
                        res.content = Poco::NumberFormatter::format(a - b);
                    } else if (m == "multi") {
                        res.content = Poco::NumberFormatter::format(a * b);
                    } else if (m == "div") {
                        res.content = Poco::NumberFormatter::format(a / b);
                    } else {
                        res.content = form["m"] + " method is not support.";
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