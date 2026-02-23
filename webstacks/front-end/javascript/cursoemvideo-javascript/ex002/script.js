var btnVerficar = document.getElementById("btnVerificar");
btnVerficar.addEventListener("click", verificar);

function verificar(){
    var anoNasc = document.getElementById("nasc");
    var data = new Date();
    var anoAtual = data.getFullYear();
    var resultado = document.getElementById("res");

    if(anoNasc.value.length == 0 || Number(anoNasc.value) > anoAtual || Number(anoNasc.value) < 1900){
        window.alert("[ERRO] Verifique os dados e tente novamente!");
    }else{
        var idade = anoAtual - Number(anoNasc.value);
        var sex = document.getElementsByName("radsex");
        var genero;
        var img = document.createElement("img");


        if(sex[0].checked){
            genero = "Homem";
                
            if(idade >= 0 && idade <= 6){ 
                img.setAttribute("src", "assets/bebe.png");
            }else if(idade < 25){
                img.setAttribute("src", "assets/jovem-m.png");
            }else if (idade < 60){
                img.setAttribute("src", "assets/adulto-m.png");
            }else{
                img.setAttribute("src", "assets/idoso-m.png");
            }
        }else{
            genero = "Mulher";
        
            if(idade >= 0 && idade <= 6){ 
                img.setAttribute("src", "assets/bebe.png");
            }else if(idade < 25){
                img.setAttribute("src", "assets/jovem-f.png");
            }else if (idade < 60){
                img.setAttribute("src", "assets/adulto-f.png");
            }else{
                img.setAttribute("src", "assets/idoso-f.png");
            }
        }
        resultado.innerHTML = `Detectamos ${genero} com ${idade} anos.`;
        resultado.appendChild(img);
    }

}