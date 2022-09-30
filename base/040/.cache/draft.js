
function count(vet, value) { //todo
}

function sum(vet) { //todo
}

function average(vet) { //todo
}

function more_men(vet) { //todo
}

function half_compare(vet) { //todo
}

function sex_battle(vet) { //todo


}


// -------------------------- MAIN --------------------------

function main() {
    let chain = new Map();
    let ui = [];

    chain.set("count",        () => puts(       count(to_vet(ui[1]), +ui[2])   ));
    chain.set("sum",          () => puts(         sum(to_vet(ui[1]))           ));
    chain.set("average",      () => puts(     average(to_vet(ui[1])).toFixed(2)));
    chain.set("more_men",     () => puts(    more_men(to_vet(ui[1]))           ));
    chain.set("half_compare", () => puts(half_compare(to_vet(ui[1]))           ));
    chain.set("sex_battle",   () => puts(  sex_battle(to_vet(ui[1]))           ));

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
let puts = text => console.log(text);

// ------------ Funções de Formatação --------------------

// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token) {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
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
            puts("$" + line);
            
        ui.splice(0); //apagar tudo
        line.split(" ").forEach(x => ui.push(x));
        
        let cmd = ui[0];
        if (cmd == "end") {
            return;
        } else if (chain.has(cmd)) {
            chain.get(cmd)();
        } else {
            puts("fail: command not found");
        }
    }
}

main()


