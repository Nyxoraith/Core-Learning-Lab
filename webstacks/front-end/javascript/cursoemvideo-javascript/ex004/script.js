var btnTabuada = document.getElementById("tabuada");
btnTabuada.addEventListener("click", calcular);

function calcular(){
    var num = document.getElementById("num");

    if(num.value.length == 0){
        window.alert("Por favor, digite um número!");
    }else{
        var tabuada = document.getElementById("tabs");
        num = Number(num.value);
        tabuada.innerHTML = "";

        for(var i = 1; i <= 10; i++){
            var option = document.createElement("option")
            option.value = `${num * i}`;
            option.textContent = `${num} * ${i} = ${num * i}`;
            tabuada.appendChild(option);
        }
    }


}