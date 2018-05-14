<?php

namespace hi\blog;

require_once 'hi/servlet.php';


class home implements \hi\servlet{
    public function handler(\hi\request $req, \hi\response $res) {
        $res->content= 'Home page.';
        $res->status =200;
    }
}

