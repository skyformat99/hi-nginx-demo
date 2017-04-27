#include "view.hpp"

namespace hi{
    class error : public view {

        void handler(request& req, response& res) {
            res.status = 404;
            res.content = "404 Not found";
        }

    };
}

extern "C" hi::view* create() {
    return new hi::error();
}

extern "C" void destroy(hi::view* p) {
    delete p;
}
