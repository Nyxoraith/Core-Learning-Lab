<?php
    require_once "db.php";

    if(isset($_GET['query']) && !empty($_GET['query'])){

    $search = $_GET['query'];

    $sql = "SELECT * FROM comments WHERE comment like '$search'";
    foreach ($result = $conn->query($sql) as $row){
        echo "<p style='text-align: center;'>O comentário: <b>" . $row['comment'] . "</b>" . " foi encontrado!</p>";
    }

    
    echo "DEBUG - Query enviada: " . $sql;
    }
?>