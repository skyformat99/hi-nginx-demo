package hi;

public class jsession implements hi.servlet {

    public jsession() {

    }

    public void handler(hi.request req, hi.response res) {
        String key = "test";
        int value = 0;
        if (req.session.containsKey(key)) {
            value =Integer.parseInt(req.session.get(key));
            res.content = String.format("%s=%d", key, value);
            res.session.put(key, String.valueOf(value+1));
        } else {
            res.session.put(key, String.valueOf(value));
            res.content = String.format("%s=%d", key, value);
        }
        res.status = 200;
    }
}
