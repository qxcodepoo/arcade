class Car{
    pass; // Passageiros
    passMax; // limite de Passageiros
    gas; // tanque
    gasMax; // limite do tanque
    km; // quantidade de quilometragem

    constructor() { //todo
    }

    toString() { //todo
    }

    enter() { //todo
    }

    leave() { //todo
    }
    
    fuel(gas) { //todo
    }

    drive (km) { //todo
    }    
};


function main() {
    let chain = new Map();
    let ui = [];
    let car = new Car();

    chain.set("enter",      () => car.enter());
    chain.set("leave",      () => car.leave());
    chain.set("show",       () => print(car.toString()));
    chain.set("drive",      () => car.drive(+ui[1]));
    chain.set("fuel",       () => car.fuel(+ui[1]));
    chain.set("help",       () => print("show, enter, leave, drive, fuel, help, end"));

    execute(chain, ui);
}

// ------------ Funções de Leitura --------------------

// Caso não interativo via moodle
let __lines = require("fs").readFileSync(0).toString().split("\n");
let input = () => __lines.shift();

// Caso interativo via readline
// let readline = require("readline-sync")
// let input = () => readline.question();

// ------------ Funções de Escrita --------------------

let write = text => process.stdout.write("" + text);
let print = text => console.log(text);

// ------------ Funções de Formatação --------------------

// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token) {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
}

//Converte de vetor para string sem inserir os espaços
//[1, 2, 3, 4] => "[1,2,3,4]"
function fmt(vet) {
    return "[" + vet.join(", ") + "]";
}

// ------------ Funções do Shell --------------------


let execute = (chain, ui) => __shell(chain, ui, true);
let shell   = (chain, ui) => __shell(chain, ui, false);

function __shell(chain, ui, on_moodle) {
    while (true) {
        if (!on_moodle)
            write("$")
        let line = input();
        if (on_moodle)
            print("$" + line);
            
        ui.splice(0); //apagar tudo
        line.split(" ").forEach(x => ui.push(x));
        
        let cmd = ui[0];
        if (cmd == "end") {
            return;
        } else if (chain.has(cmd)) {
            chain.get(cmd)();
        } else {
            print("fail: command not found");
        }
    }
}

main()