var data = new Date();
var horas = data.getHours();
var divHoras = window.document.getElementById("horas");
var img = window.document.getElementById("img");

divHoras.innerHTML = `Agora são ${horas} horas.`;
if(horas <= 12){
    img.src = "assets/manha.jpg";
    img.alt = "Manhã"
    document.body.style.background = "#8eb2c2";
}else if(horas >= 13 && horas <= 18){
    img.src = "assets/tarde.jpg";
    img.alt = "Tarde"
    document.body.style.background = "#b5832a";
}else{
    img.src = "assets/noite.jpg";
    img.alt = "Noite"
    document.body.style.background = "#0f1f39";
}