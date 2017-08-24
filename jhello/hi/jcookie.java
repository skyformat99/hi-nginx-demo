package hi;

public class jcookie implements hi.servlet {

    public jcookie() {
    }

    public void handler(hi.request req, hi.response res) {
        String key = "SESSIONID";
        if (req.cookies.containsKey(key)) {
            res.content = String.format("%s=%s", key, req.cookies.get(key));
        } else {
            res.content = String.format("not found %s", key);
        }
        res.status = 200;
    }

}
