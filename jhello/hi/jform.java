package hi;

public class jform implements hi.servlet {

    public jform() {
    }

    public void handler(hi.request req, hi.response res) {
        String key = "a";
        if (req.form.containsKey(key)) {
            res.content = String.format("%s=%s", key, req.form.get(key));
        } else {
            res.content = String.format("not found %s", key);
        }
        res.status = 200;
    }
}
