<?php
    $dsn = "mysql:dbname=testt;host:127.0.0.1";
    $user = "root";
    $pass = "";

    try{
        $conn = new PDO($dsn, $user, $pass);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }catch (PDOException $e){
        echo "Connection failed: " . $e->getMessage();
    }
?>