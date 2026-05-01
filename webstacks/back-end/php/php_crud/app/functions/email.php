<?php

function send(array $data){
    $email = new PHPMailer\PHPMailer\PHPMailer;
    $email->CharSet = "UTF-8";
    $email->SMTPSecure = "plain";
    $email->isSMTP();
    $email->Host = "";
    $email->Port = 465;
    $email->SMTPAuth = true;
    $email->Username = "";
    $email->Password = "";
    $email->isHTML(true);
    $email->setFrom("");
    $email->FromName = $data["quem"];
    $email->addAddress($data["para"]);
    $email->Body = $data["mensagem"];
    $email->Subject = $data["assunto"];
    $email->AltBody = "Para ver esse email tnha certeza de estar vendo em um programa que aceitar ver HTML";
    $email->msgHTML($data["mensagem"]);

    return $email->send();
}