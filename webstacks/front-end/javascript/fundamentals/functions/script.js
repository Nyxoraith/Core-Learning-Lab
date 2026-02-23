function soma1(num1, num2) {
    return num1 + num2;
}

const soma2 = function(num1, num2) {
    return num1 + num2; 
}

const soma3 = (num1, num2) => {
    return num1 + num2; 
}

const soma4 = (num1, num2) => num1 + num2;

const dobro = num => num * 2;

// Funcoes podem ser passadas como argumento

function aplicar(f, num) {
    const result = f(num);
    console.log("RESULTADO = " + result);
}

aplicar(dobro, 20);