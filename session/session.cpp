
#include "servlet.hpp"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

namespace hi {

    class session : public servlet {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            std::string key("test");
            long i = 0;
            if (req.session.find(key) == req.session.end()) {
                res.session[key] = "0";
            } else {
                i = boost::lexical_cast<long>(req.session[key]) + 1;
                res.session[key] = boost::lexical_cast<std::string>(i);
            }

            res.content = (boost::format("hello,%1%") % i ).str();
            res.status = 200;

        }

    };
}

extern "C" hi::servlet* create() {
    return new hi::session();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}

