
<?php

require_once 'hi/servlet.php';
require_once 'hi/route.php';

require_once 'vendor/autoload.php';

class demo implements \hi\servlet {

    public function handler(\hi\request $req, \hi\response $res) {
        $app = \hi\route::get_instance();
        $app->add('{^/$}', array('GET'), function ($rq, $rs, &$param) {
            $rs->content = 'hello,world';
            $rs->status = 200;
        });

        $app->add('{^/who/(?P<name>\w+)/?$}', array('GET'), function ($rq, $rs, &$param) {
            $rs->content = 'hello,' . $param['name'];
            $rs->status = 200;
        });

        $app->add('{^/phpinfo/?$}', array('GET'), function($rq, $rs, &$param) {
            ob_start();
            phpinfo();
            $rs->content = ob_get_contents();
            $rs->status = 200;
            ob_end_clean();
        });

        $app->add('{^/cache/?$}', array('GET'), function($rq, $rs, &$param) {
            $key = 'cache_test';
            $value = 0;
            if (array_key_exists($key, $rq->cache)) {
                $value = intval($rq->cache[$key]) + 1;
            }
            $rs->cache[$key] = $value;
            $rs->content = "$key : " . $value;
            $rs->status = 200;
        });

        $app->add('{^/crypt/(?P<string>\w+)/?}', array('GET'), function($rq, $rs, &$param) {
            $bcrypt = new Zend\Crypt\Password\Bcrypt();
            $rs->content = $bcrypt->create($param['string']);
            $rs->status = 20;
        });
        
        $app->add('{/(?P<param_1>\w+)/(?P<param_2>\w+)/?}',array('GET'),function($rq,$rs,&$param){
            $classname="hi\\". $param["param_1"]."\\". $param["param_2"];
            $app= new $classname();
            $app->handler($rq,$rs);

        });

        $app->run($req, $res);
    }

}
