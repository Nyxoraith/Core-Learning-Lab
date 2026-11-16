function State(){
    this.listSection = null;
    this.saveList = null
    this.editTaskName = null;
}

const state = new State();

export function init(){
    state.listSection = document.querySelector("#list-task");
    state.saveList = [];
    loadTasks();
}

export function addTask(newTask){
    const task = createTask(newTask);
    state.listSection.appendChild(task);
}

function createTask(task, liston=0, list){
    const p = document.createElement("p");
    const span = document.createElement("span");
    const div = document.createElement("div");
    const btnEdit = document.createElement("button");
    const btnRemove = document.createElement("button");
    const btnSave = document.createElement("button");

    div.classList.add("li-buttons")

    btnEdit.classList.add("buttons");
    btnEdit.classList.add("edit");

    btnRemove.classList.add("buttons");
    btnRemove.classList.add("remove");
    
    btnSave.classList.add("buttons");
    btnSave.classList.add("save");

    span.innerHTML = "📌 ";
    p.innerHTML = `${task}`;
    btnEdit.innerText = "Editar";
    btnRemove.innerText = "Apagar";
    btnSave.innerText = "Salvar";
    
    span.appendChild(p);
    div.appendChild(btnEdit);
    div.appendChild(btnRemove);
    div.appendChild(btnSave);

    if(liston === 0){
        const li = document.createElement("li");
        li.appendChild(span);
        li.appendChild(div);

        return li;
    }

    if(liston === 1){
        list.appendChild(span);
        list.appendChild(div);
    }
}

export function saveTask(clickedItem){
    const taskItem = clickedItem.closest("li");
    if(taskItem){
        const taskElement = taskItem.querySelector("p");
        const taskName = taskElement.textContent;
        state.saveList.push(taskName);

        if(state.saveList){
            localStorage.tasks = JSON.stringify(state.saveList);
        }
    }
}

export function removeTask(clickedItem, task){
    const taskItem = clickedItem.closest("li");

    if(taskItem){
        const taskElement = taskItem.querySelector("p");
        const taskName = taskElement.textContent;
        const index = state.saveList.indexOf(taskName);

        task.taskName = task.taskName.filter((element) => element !== taskName);
        state.saveList.splice(index, 1);
        taskItem.remove();

        localStorage.tasks = JSON.stringify(state.saveList);
    }
}

export function editTask(clickedItem){
    const taskItem = clickedItem.closest("li");
    const buttons = taskItem.querySelectorAll("button");
    const pElement = taskItem.querySelector("p");
    const spanElement = taskItem.querySelector("span")
    const divElement = taskItem.querySelector("div")
    
    state.editTaskName = pElement.textContent;

    spanElement.remove();
    for(let i = 0; i < buttons.length; i++){
        buttons[i].remove();
    }

    const btnSaveEdit = document.createElement("button");
    const btnCancelEdit = document.createElement("button");
    const inputName = document.createElement("input");

    inputName.classList.add("input-Edit");
    inputName.setAttribute("name", "edit-task");
    inputName.setAttribute("id", "edit-task");


    btnSaveEdit.classList.add("buttons");
    btnSaveEdit.classList.add("saveEdit");

    btnCancelEdit.classList.add("buttons");
    btnCancelEdit.classList.add("cancelEdit");

    btnSaveEdit.innerText = "Salvar";
    btnCancelEdit.innerText = "Cancelar";
    
    inputName.value = state.editTaskName;

    divElement.appendChild(btnSaveEdit);
    divElement.appendChild(btnCancelEdit);

    taskItem.appendChild(inputName)
    taskItem.appendChild(divElement);
}

export function saveEditTask(clickedItem, task){
    const taskItem = clickedItem.closest("li");
    const inputName = taskItem.querySelector("input");
    const newTaskName = inputName.value;

    const indexTaskList = task.taskName.indexOf(state.editTaskName);
    if(indexTaskList !== -1){
        task.taskName[indexTaskList] = newTaskName;
    }
    
    const indexsaveList = state.saveList.indexOf(state.editTaskName);
    if(indexsaveList !== -1){
        state.saveList[indexsaveList] = newTaskName;
        localStorage.tasks = JSON.stringify(state.saveList);
    }
    cancelEditTask(taskItem, task, indexTaskList);
}

export function cancelEditTask(clickedItem, task, index=-1){
    const taskItem = clickedItem.closest("li");
    const inputName = taskItem.querySelector("input");
    const divElement = taskItem.querySelector("div")
    inputName.remove();
    divElement.remove();

    if(index === -1){
        const indexEditTaskName = task.taskName.indexOf(state.editTaskName);
        reCreateTask(taskItem, indexEditTaskName, task);
    }else{
        reCreateTask(taskItem, index, task);
    }

}

function reCreateTask(taskItem, index, task){
    createTask(task.taskName[index], 1, taskItem);
}

function loadTasks(){
    if(localStorage.tasks){
        state.saveList = JSON.parse(localStorage.getItem("tasks"));
        state.saveList.forEach( task => addTask(task));
    }
}