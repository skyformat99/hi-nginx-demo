package hi;

import java.io.File;
import java.io.StringWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Locale;


import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;

public class jfreemarker implements hi.servlet {

    public jfreemarker() {
    }

    public void handler(hi.request req, hi.response res) {
        try {
            
        } catch (Exception e) {
        }
        try {
            Configuration cfg = new Configuration();
            cfg.setEncoding(Locale.CHINA, "utf-8");
            cfg.setDefaultEncoding("utf-8");
            cfg.setDirectoryForTemplateLoading(new File("java/tpl"));
            Template template = cfg.getTemplate("jfreemarker.ftl");

            Map<String, Object> data = new HashMap<String, Object>();
            data.put("message", "Hello World!");

            List<String> countries = new ArrayList<String>();
            countries.add("张三");
            countries.add("李四");
            countries.add("王五");
            countries.add("赵六");

            data.put("countries", countries);

            StringWriter out = new StringWriter();
            template.process(data, out);
            out.flush();
            res.content = out.toString();
            res.status = 200;
        } catch (TemplateException e) {
            res.status =500;
            res.content = "tpl error";
        } catch (Exception e){
            res.status=500;
            res.content = "io error";
        }
    }
}
