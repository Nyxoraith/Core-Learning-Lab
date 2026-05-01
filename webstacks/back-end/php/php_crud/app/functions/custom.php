<?php

function dd($dump){
    var_dump($dump);
    die();
}

function request(){

    $requestType = $_SERVER["REQUEST_METHOD"];

    if($requestType == "POST"){
        return $_POST;
    }

    return $_GET;
}

function redirect($target){
    header("location:/?page=$target");
}

function redirectToHome(){
    header("location:/");
}