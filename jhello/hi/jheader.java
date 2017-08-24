package hi;

public class jheader implements hi.servlet {

    public jheader() {

    }

    public void handler(hi.request req, hi.response res) {
        String key = "Connection";
        if (req.headers.containsKey(key)) {
            res.content = String.format("%s=%s", key, req.headers.get(key));
        } else {
            res.content = String.format("not found %s header", key);
        }
        res.status = 200;
    }
}
