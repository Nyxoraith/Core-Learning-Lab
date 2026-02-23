var btnVerificar = document.getElementById("count");
btnVerificar.addEventListener("click", contar);

function contar(){
    var starTxt = document.getElementById("start");
    var resultado = document.getElementById("res");
    
    if(starTxt.value.length <= 0){
        resultado.innerHTML = `<p>Impossivel contar!</p>`;
    }else{
        var start = Number(starTxt.value);
        var end = Number(document.getElementById("end").value);
        var step = Number(document.getElementById("step").value);

        if(step <= 0){
            window.alert("Passo Inválido! Considerando PASSO 1");
            step = 1;
        }
        
        resultado.innerHTML = `<p>Contando:</p>`
        if(start < end){
            for(var i = start; i <= end; i += step){
                resultado.innerHTML += `${i} &#x1F449;`;
            }
        }else{
            for(var i = start; i >= end; i -= step){
                resultado.innerHTML += `${i} &#x1F449`;
            }
        }
        resultado.innerHTML += ` &#x1F38C;`;
    }
}