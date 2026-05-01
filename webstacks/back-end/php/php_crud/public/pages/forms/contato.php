<?php

require "../../../bootstrap.php";


if (isEmpty()){
    flash("message", "Preencha todos os campos");

    return redirect("contato");
}

$sanitized = validate([
    "name" => "s",
    "email" => "e",
    "subject" => "s",
    "message" => "s"
]);

$data = [
    "quem" => $sanitized->email,
    "para" => "@contato.com.br",
    "mensagem" => $sanitized->message,
    "assunto" => $sanitized->subject
];

if(send($data)){
    flash("message", "Email enviado com sucesso", "success");
    return redirect("contato");
}