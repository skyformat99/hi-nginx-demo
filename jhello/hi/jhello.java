package hi;

public class jhello implements hi.servlet {

    public jhello() {

    }

    public void handler(hi.request req, hi.response res) {
        res.status = 200;
        res.content = String.format("%s,%s,%s,%s,%s",req.client,req.method,req.user_agent,req.uri,req.param);

    }
}
