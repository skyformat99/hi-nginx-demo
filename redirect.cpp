#include "view.hpp"

namespace hi{
    class redirect : public view {

        void handler(request& req, response& res) {
            res.status = 302;
            res.headers.insert(std::make_pair("Location", "/hello"));
        }

    };
}

extern "C" hi::view* create() {
    return new hi::redirect();
}

extern "C" void destroy(hi::view* p) {
    delete p;
}
