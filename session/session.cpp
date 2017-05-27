
#include "servlet.hpp"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

namespace hi {

    class session : public servlet {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            std::string key("test_key");
            long i = 0, j = 0;
            if (req.session.find(key) == req.session.end()) {
                res.session[key] = "0";
            } else {
                i = boost::lexical_cast<long>(req.session[key]) + 1;
                res.session[key] = boost::lexical_cast<std::string>(i);
            }
#ifdef USE_HIREDIS
            std::string lkey = "test-list";
            if (this->REDIS) {
                if (!this->REDIS->exists(lkey)) {
                    this->REDIS->lpush(lkey,{"0"});
                    this->REDIS->expire(lkey, 300);
                } else {
                    j = boost::lexical_cast<long>(this->REDIS->lpop(lkey)) + 1;
                    this->REDIS->lpush(lkey,{boost::lexical_cast<std::string>(j)});
                }
            }
#endif

            res.content = (boost::format("hello,%1%,%2%") % i % j).str();
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

