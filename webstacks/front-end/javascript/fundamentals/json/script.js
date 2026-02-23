const obj = {
    id: 53,
    date: "2021-10-20",
    items: [
        {
            description: "Celular",
            price: 1499.99,
            quantity: 1
        },
        {
            description: "Mouse",
            price: 100.0,
            quantity: 2
        }
    ],
    client: {
        name: "Maria Red",
        email: "maria@gmail.com",
        active: true
    }
};

//Txt Parse para JSON
const txt = `{"nome": "Computador", "price": 50.9, "due-date": "2025-04-15"}`;
const json = JSON.parse(txt);

//JSON Parse para Txt
const jsonString = JSON.stringify(obj);