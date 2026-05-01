<?= getFlash("message"); ?>

<?php 
    $user = find("users", "id", $_GET["id"]);
?>
<form action="/pages/forms/update_user.php" method="post">

    <input type="hidden" name="id" value="<?= $user->id ?>">

    <div class="form-group">
        <label for="">Nome</label>
        <input type="text" class="form-control" name="name" placeholder="Digite seu nome" value="<?= $user->name ?>">
    </div>

    <div class="form-group">
        <label for="">Sobrenome</label>
        <input type="text" class="form-control" name="sobrenome" placeholder="Digite seu sobrenome" value="<?= $user->sobrenome ?>">
    </div>

    <div class="form-group">
        <label for="">Email</label>
        <input type="Email" class="form-control" name="email" placeholder="Digite seu Email" value="<?= $user->email ?>">
    </div>

    <button type="submit" class="btn btn-primary">Atualizar</button>

</form>