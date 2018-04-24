package hi;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.regex.Pattern;

public class jdemo implements hi.servlet {

    public jdemo() {

    }

    public void handler(hi.request req, hi.response res) {
        if (req.method.equals(new String("GET"))) {
            if (Pattern.matches("^/hello/?$", req.uri)) {
                this.do_hello(req, res);
            } else if (Pattern.matches("^/empty/?$", req.uri)) {
                this.do_empty(req, res);
            } else if (Pattern.matches("^/error/?$", req.uri)) {
                this.do_error(req, res);
            } else if (Pattern.matches("^/redirect/?$", req.uri)) {
                this.do_redirect(req, res);
            } else if (Pattern.matches("^/form/?$", req.uri)) {
                this.do_form(req, res);
            } else if (Pattern.matches("^/math/?$", req.uri)) {
                this.do_math(req, res);
            } else if (Pattern.matches("^/session/?$", req.uri)) {
                this.do_session(req, res);
            } else if (Pattern.matches("^/md5/?$", req.uri)) {
                this.do_md5(req, res);
            } else {
                this.do_error(req, res);
            }

        }
    }

    private void do_hello(hi.request req, hi.response res) {
        res.headers.get("Content-Type").set(0, new String("text/plain;charset=UTF-8"));
        res.status = 200;
        res.content = "hello,world";
    }

    private void do_error(hi.request req, hi.response res) {
        res.status = 404;
        res.content = "404 Not found";
    }

    private void do_redirect(hi.request req, hi.response res) {
        res.status = 302;
        ArrayList<String> h = new ArrayList<String>();
        h.add(new String("/hello"));
        res.headers.put(new String("Location"), h);
    }

    private void do_empty(hi.request req, hi.response res) {

    }

    private void do_form(hi.request req, hi.response res) {
        res.headers.get("Content-Type").set(0, new String("text/plain;charset=UTF-8"));
        res.status = 200;
        res.content = "head data\n";
        res.content = res.content.concat(this.foreach_headers(req.headers));
        res.content = res.content.concat("cookie data\n");
        res.content = res.content.concat(this.foreach_headers(req.cookies));
        res.content = res.content.concat("form data\n");
        res.content = res.content.concat(this.foreach_headers(req.form));
        res.content = res.content.concat(String.format("%s\n%s\n%s\n%s\n%s\n", req.client, req.method, req.user_agent, req.uri, req.param));
    }

    private void do_math(hi.request req, hi.response res) {
        if (req.form.containsKey("a") && req.form.containsKey("b") && req.form.containsKey("m")) {
            res.headers.get(new String("Content-Type")).set(0, new String("text/plain;charset=UTF-8"));
            res.status = 200;
            String m = req.form.get("m");
            double a = Double.parseDouble(req.form.get("a")), b = Double.parseDouble(req.form.get("b"));
            if (m.equals("add")) {
                res.content = String.valueOf(a + b);
            } else if (m.equals("sub")) {
                res.content = String.valueOf(a - b);
            } else if (m.equals("multi")) {
                res.content = String.valueOf(a * b);
            } else if (m.equals("div")) {
                res.content = String.valueOf(a / b);
            } else {
                res.content = m.concat(" method is not support.");
            }

        }
    }

    private void do_session(hi.request req, hi.response res) {
        res.headers.get(new String("Content-Type")).set(0, new String("text/plain;charset=UTF-8"));
        res.status = 200;
        String key = "test";
        int value = 0;
        if (req.session.containsKey(key)) {
            value = Integer.parseInt(req.session.get(key));
            res.session.put(key, String.valueOf(value + 1));
        } else {
            res.session.put(key, String.valueOf(value));
        }
        res.content = String.format("hello,%d", value);
        res.status = 200;
    }

    private void do_md5(hi.request req, hi.response res) {
        String plaintext = "hello,md5!";
        res.status = 200;
        res.content = String.format("%s md5= %s", plaintext, this.md5(plaintext));
    }

    private String foreach_headers(HashMap<String, String> headers) {
        String result = new String();
        Iterator it = headers.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry en = (Map.Entry) it.next();
            result = result.concat(String.format("%s\t=\t%s\n", en.getKey(), en.getValue()));
        }
        return result;
    }

    private String md5(String str) {
        try {
            java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
            byte[] array = md.digest(str.getBytes());
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < array.length; ++i) {
                sb.append(Integer.toHexString((array[i] & 0xFF) | 0x100).substring(1, 3));
            }
            return sb.toString();
        } catch (java.security.NoSuchAlgorithmException e) {
        }
        return null;
    }
}
