let add = document.getElementById("add");
add.addEventListener("click", adicionar);

let end = document.getElementById("end");
end.addEventListener("click", finalizar);

let num = document.getElementById("num");
let list = document.getElementById("list");
let resposta = document.getElementById("res");
let array = [];


function adicionar(){
    if(num.value.length == 0){
        window.alert("Digite um valor");
    }else{
        number = Number(num.value)
        if((number >= 1 && number <= 100) && array.indexOf(number) == -1){
            let option = document.createElement("option");
            array.push(number);
            option.textContent = `Valor ${number} adicionado.`;      
            list.appendChild(option);
            resposta.innerHTML = "";
        }else{
            window.alert("Valor inválido ou já encontrado na lista");
        }
        num.value = "";
        num.focus();
    }
}

function finalizar(){
    if(array.length != 0){
        let total = array.length;

        let maior = array[0];
        let menor = array[0];
        let soma = 0;
        let media = 0;

        for(let n in array){
            if(maior < array[n]){
                maior = array[n];
            }

            if(menor > array[n]){
                menor = array[n];
            }

            soma += array[n];
        }

        media = soma / array.length;

        resposta.innerHTML = `<p>Ao todo, temos ${total} números cadastrados.</p>`;
        resposta.innerHTML += `<p>O maior valor informado foi ${maior}</p>`;
        resposta.innerHTML += `<p>O menor valor informado foi ${menor}</p>`;
        resposta.innerHTML += `<p>Somando todos os valores, temos ${soma}</p>`;
        resposta.innerHTML += `<p>A média dos valores digitados é ${media}.</p>`;
    }else{
        window.alert("Adicione valores antes de finalizar!");
    }

}