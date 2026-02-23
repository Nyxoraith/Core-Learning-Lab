<?php
$servername = "localhost";
$username = "root";
$password = "";

// Create connection
$conn = mysqli_connect($servername, $username, $password);

// Check connection
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}

if (!mysqli_select_db($conn, "testt")) {
    echo "Erro ao selecionar o banco de dados: " . mysqli_error($conn);
    exit();
}

if ($result = mysqli_query($conn, "SELECT * FROM comments")){
    $all_comments = mysqli_fetch_all($result, MYSQLI_ASSOC);
    foreach ($all_comments as $row) {
        echo "Indice: " . $row['indice'] . " | Comentário: " . $row['comment'] . "<br>";
    }
}

if(isset($_GET["comment"]) and !empty($_GET["comment"])){
    mysqli_query($conn, "INSERT INTO `comments` (`indice`, `comment`) VALUES (NULL, '$_GET[comment]')"); 
};

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>XSS Stored</title>
</head>
<body>
    <form action="index2.php" method="get">
        <label for="comment">
            Escrever um comentario.
        </label>
        <input type="text" name="comment">
        <input type="submit" value="Comentar">
    </form>
</body>
</html>