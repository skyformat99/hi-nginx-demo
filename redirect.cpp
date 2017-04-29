#include "servlet.hpp"

namespace hi{
    class redirect : public servlet {

        void handler(request& req, response& res) {
            res.status = 302;
            res.headers.insert(std::make_pair("Location", "/hello"));
        }

    };
}

extern "C" hi::servlet* create() {
    return new hi::redirect();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}
