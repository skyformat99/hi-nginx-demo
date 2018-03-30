<?php

require_once 'hi/servlet.php';

class form implements servlet {

    public function __construct() {
        
    }

    public function __destruct() {
        
    }

    public function handler(\hi\request $req, \hi\response $res) {
        $content = "form :<br />";
        foreach ($req->form as $key => $value) {
            $content .= $key . "=" . $value . "<br />";
        }
        $content .= "headers :<br />";
        foreach ($req->headers as $key => $value) {
            $content .= $key . "=" . $value . "<br />";
        }
        $content .= "cookies :<br />";
        foreach ($req->cookies as $key => $value) {
            $content .= $key . "=" . $value . "<br />";
        }
        $content .= "session :<br />";
        foreach ($req->session as $key => $value) {
            $content .= $key . "=" . $value . "<br />";
        }
        $res->content = $content;
        $res->status = 200;
    }

}
