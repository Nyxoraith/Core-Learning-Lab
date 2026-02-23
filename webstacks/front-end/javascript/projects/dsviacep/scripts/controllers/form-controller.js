import Address from "../models/address.js";
import * as addressService from "../services/address-service.js";
import * as listController from "./list-controller.js";

function State(){
    this.address = new Address();

    this.btnSave = null;
    this.btnClear = null;

    this.inputCep = null;
    this.inputStreet = null;
    this.inputNumber = null;
    this.inputCity = null;

    this.errorCep = null;
    this.errorNumber = null;
}

const state = new State();

export function init(){
    state.inputCep = document.forms.novoEndereco.cep;
    state.inputStreet = document.forms.novoEndereco.rua;
    state.inputNumber = document.forms.novoEndereco.numero;
    state.inputCity = document.forms.novoEndereco.cidade;

    state.btnSave = document.forms.novoEndereco.btnSave;
    state.btnClear = document.forms.novoEndereco.btnClear;

    state.errorCep = document.querySelector('[data-error="cep"]');
    state.errorNumber = document.querySelector('[data-error="number"]');

    state.inputCep.addEventListener('change', handleInputCepChange);
    state.inputNumber.addEventListener('change', handleInputNumberChange);
    state.inputNumber.addEventListener('keyup', handleInputNumberKeyup);

    state.btnClear.addEventListener('click', handleBtnClearClick);
    state.btnSave.addEventListener('click', handleBtnSaveClick);
}

async function handleInputCepChange(event) {
    const cep = event.target.value;
    
    try{
        const address = await addressService.findByCep(cep);
        
        state.inputStreet.value = address.street;
        state.inputCity.value = address.city;
        state.address = address;

        setFormError("cep", "");
        state.inputNumber.focus();
    }catch(e){
        setFormError("cep", "Informe um CEP válido");
        state.inputStreet.value = "";
        state.inputCity.value = "";
    }
}

function handleInputNumberChange(event){
    if(event.target.value == ""){
        setFormError("number", "Campo requerido");
    }else {
        setFormError("number", "");
    }
}

function handleInputNumberKeyup(event){
    state.address.number = event.target.value;
}

function handleBtnSaveClick(event){
    event.preventDefault();

    const errors = addressService.getErros(state.address);

    const keys = Object.keys(errors);

    if (keys.length > 0){
        for(let i = 0; i < keys.length; i++){
            setFormError(keys[i], errors[keys[i]])
        }
    }else{
        listController.addCard(state.address);
        clearForm();
    }
}

function handleBtnClearClick(){
    clearForm();
}

function setFormError(key, value){
    const element = document.querySelector(`[data-error="${key}"]`);
    element.innerHTML = value;
}

function clearForm(){
    state.inputCep.value = "";
    state.inputStreet.value = "";
    state.inputNumber.value = "";
    state.inputCity.value = "";

    state.address = new Address();

    state.inputCep.focus();
}