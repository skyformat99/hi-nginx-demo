#include "servlet.hpp"
#include "cookie.hpp"


namespace hi {

    class empty : public servlet {
    public:

        void handler(request& req, response& res) {
            std::map<std::string, std::string> cookies;
            hi::get_input_cookies(req.headers, cookies);
            if (cookies.find("SESSION") == cookies.end()) {
                cookies["SESSION"] = "123456";
                hi::set_output_cookies(cookies, res.headers);
            }

        }

    };

}

extern "C" hi::servlet* create() {
    return new hi::empty();
}

extern "C" void destroy(hi::servlet* p) {
    delete p;
}

