import Task from "../models/tasks.js";
import * as ListController from "./list-controller.js";

function State(){
    this.task = new Task();

    this.inputTask = null;
    this.inputAdd = null;
    this.inputError = null

    this.taskListContainer = null;
}   

const state = new State();

export function init() {
    state.inputTask = document.forms.newTask.task;
    state.inputAdd = document.forms.newTask.add;
    state.inputError = document.querySelector("[data-error='task-name']");
    state.taskListContainer = document.querySelector("#list-task");

    state.inputAdd.addEventListener("click", handleInputAddClick);
    
    state.taskListContainer.addEventListener("click", handleTaskListClick);

}

function handleInputAddClick(event){
    event.preventDefault();
    const errors = getErrors(state.inputTask.value);
    if(errors){
        setFormError("Campo Requerido!");
    }else{
        state.task.taskName.push(state.inputTask.value);
        const lastIndex = state.task.taskName.length - 1;
        ListController.addTask(state.task.taskName[lastIndex]);
        clearForm();
    }
}

function handleTaskListClick(event){  
    if(event.target.classList.contains("edit")){
        event.preventDefault();
        handleInputEditClick(event.target);
    }


    if(event.target.classList.contains("remove")){
        event.preventDefault();
        handleInputRemoveClick(event.target);
    }

    if(event.target.classList.contains("save")){
        event.preventDefault();
        handleInputSaveClick(event.target);
    }

    if(event.target.classList.contains("saveEdit")){
        event.preventDefault();
        handleInputSaveEditClick(event.target);
    }

    if(event.target.classList.contains("cancelEdit")){
        event.preventDefault();
        handleInputCancelEditClick(event.target);
    }

}

function handleInputEditClick(clickedElement){
    ListController.editTask(clickedElement);
}

function handleInputRemoveClick(clickedElement){
    ListController.removeTask(clickedElement, state.task);
}

function handleInputSaveClick(clickedElement){
    ListController.saveTask(clickedElement);
}

function handleInputSaveEditClick(clickedElement){
    ListController.saveEditTask(clickedElement, state.task);
}

function handleInputCancelEditClick(clickedElement){
    ListController.cancelEditTask(clickedElement, state.task);
}

function getErrors(task){
    if(!task || task == ""){
        return 1;
    }
}

function setFormError(error){
    state.inputError.innerHTML = error;
}

function clearForm(){
    state.inputError.innerHTML = "";
    state.inputTask.value = "";
}