#include "servlet.hpp"


namespace hi {

    class empty : public servlet {
    public:

        void handler(request& req, response& res) {

        }

    };

}

extern "C" hi::servlet* create() {
    return new hi::empty();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}

