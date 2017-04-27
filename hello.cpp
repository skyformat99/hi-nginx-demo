#include "view.hpp"


namespace hi {

    class hello : public view {
    public:

        void handler(request& req, response& res) {
            res.headers.find("Content-Type")->second = "text/plain;charset=UTF-8";
            res.content = "hello,world";
            res.status = 200;
        }

    };
}

extern "C" hi::view* create() {
    return new hi::hello();
}

extern "C" void destroy(hi::view* p) {
    delete p;
}
