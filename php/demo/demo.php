
<?php

require_once 'hi/servlet.php';
require_once 'hi/route.php';

class demo implements \hi\servlet {

    public function handler(\hi\request $req, \hi\response $res) {
        $app = \hi\route::get_instance();
        $app->add('{^/hello$}', array('GET'), function ($rq, $rs, &$param) {
            $rs->content = 'hello,world';
            $rs->status = 200;
        });

        $app->add('{^/who/(?P<name>\w+)/?$}', array('GET'), function ($rq, $rs, &$param) {
            $rs->content = 'hello,'.$param['name'];
            $rs->status = 200;
        });
        $app->run($req, $res);
    }

}



