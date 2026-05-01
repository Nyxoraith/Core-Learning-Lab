<?php

function connect(){
    $pdo = new \PDO("mysql:host=localhost;dbname=;charset=utf8mb4", "", "");

    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $pdo->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_OBJ);

    return $pdo;
}

function create($table, $fields){
    $pdo = connect();

    if(!is_array($fields)){
        $fields = (array) $fields;
    }

    $sql = "INSERT INTO {$table}";
    $sql .= "(".implode(",", array_keys($fields)) . ")";

    $sql .= " VALUES (:".implode(",:", array_keys($fields)) . ")";

    $insert = $pdo->prepare($sql);

    return $insert->execute($fields);
}

function all($table){
    $pdo = connect();

    $sql = "SELECT * FROM {$table}";

    $list = $pdo->query($sql);
    $list->execute();

    return $list->fetchAll();
}

function update($table, $fields, $where){
    $pdo = connect();

    if(!is_array($fields)){
        $fields = (array) $fields;
    }

    $data = array_map(function($field){
        return "{$field} = :{$field}";
    }, array_keys($fields));

    $sql = "UPDATE {$table} SET ";
    $sql .= implode(", ", $data);

    $sql .= " WHERE {$where[0]} = :{$where[0]}";
    
    $data = array_merge($fields, [$where[0] => $where[1]]);

    $sqlUpdate = $pdo->prepare($sql);
    $sqlUpdate->execute($data);

    return $sqlUpdate->rowCount();
}

function find($table, $field, $value){
    $pdo = connect();

    $value = filter_var($value, FILTER_SANITIZE_NUMBER_INT);

    $sql = "SELECT * FROM {$table} WHERE {$field} = :{$field}";

    $sqlFind = $pdo->prepare($sql);
    $sqlFind->bindValue($field, $value);
    $sqlFind->execute();

    return $sqlFind->fetch();
}

function delete($table, $field, $value){
    $pdo = connect();

    $sql = "DELETE FROM {$table} WHERE {$field} = :{$field}";

    $sqlDelete = $pdo->prepare($sql);
    $sqlDelete->bindValue($field, $value);
    
    return $sqlDelete->execute();
}
