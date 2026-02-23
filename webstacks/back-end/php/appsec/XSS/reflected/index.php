<?php
    if(isset($_GET['pesquisa']) and !empty($_GET['pesquisa'])){
       echo '<p>Você pesquisou por: ', $_GET['pesquisa'], '</p>';
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>XSS Reflected</title>
</head>
<body>
    <form action="index.php" method="get">
        <label for="pesquisa">
            Pesquisa:
        </label>
        <input type="text" name="pesquisa">
        <input type="submit" value="Pesquisar">
    </form>
</body>
</html>