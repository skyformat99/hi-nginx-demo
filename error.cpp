#include "servlet.hpp"

namespace hi{
    class error : public servlet {

        void handler(request& req, response& res) {
            res.status = 404;
            res.content = "404 Not found";
        }

    };
}

extern "C" hi::servlet* create() {
    return new hi::error();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}
