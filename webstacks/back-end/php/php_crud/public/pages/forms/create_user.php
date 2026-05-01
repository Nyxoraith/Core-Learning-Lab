<?php

require "../../../bootstrap.php";


if (isEmpty()){
    flash("message", "Preencha todos os campos");

    return redirect("create_user");
}

$sanitized = validate([
    "name" => "s",
    "sobrenome" => "s",
    "email" => "e",
    "password" => "s"
]);

$cadastrado = create("users", $sanitized);

if($cadastrado){
    flash("message", "Cadastrado com sucesso", "success");

    return redirect("create_user");
}

flash("message", "Erro ao cadastrar");
redirect("create_user");
