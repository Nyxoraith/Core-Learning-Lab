<?php

function validate(array $fields){

    $request = request();

    $sanitized = [];

    foreach($fields as $field => $type){

        if(!isset($request[$field])) continue;

        switch($type){
            case 's':
                $sanitized[$field] = filter_var($request[$field], FILTER_SANITIZE_STRING);
                break;

            case 'i':
                $sanitized[$field] = filter_var($request[$field], FILTER_SANITIZE_NUMBER_INT);
                break;
                
            case 'e':
                $sanitized[$field] = filter_var($request[$field], FILTER_SANITIZE_EMAIL);
                break;
        }
    }

    return (object) $sanitized;
}

function isEmpty(){
    
    $request = request();
    $empty = false;

    foreach ($request as $key => $value){
        if(empty($request[$key])){
            $empty = true;
        }
    }

    return $empty;
}