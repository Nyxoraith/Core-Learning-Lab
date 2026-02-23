function State(){
    this.listSection = null;
}

const state = new State();

export function init(){
    state.listSection = document.querySelector("#lista-enderecos");
}

export function addCard(address){
    const card = createCard(address);
    state.listSection.appendChild(card);
}

function createCard(address){
    const li = document.createElement("li");
    const city = document.createElement("h3");
    const line = document.createElement("p");
    const cep = document.createElement("span");


    city.innerHTML = address.city;
    line.innerHTML = `${address.street}, ${address.number}`;
    cep.innerHTML = address.cep;

    li.appendChild(city);
    li.appendChild(line);
    li.appendChild(cep);

    return li;
}