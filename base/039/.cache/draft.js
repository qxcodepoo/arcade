
//retorna um vetor de pares
function occurr(vet) { //todo
}

//retorna um vetor de pares
function teams(vet) { //todo

}

function mnext(vet) { //todo
}

function alone(vet) { //todo
}

function couple(vet) { //todo
}

function has_subseq(vet, seq, pos) { //todo
}

function subseq(vet, seq) { //todo
}

function erase(vet, pos_list) { //todo
}

function clear(vet, value) { //todo
}


// -------------------------- MAIN --------------------------

function main() {
    let chain = new Map();
    let ui = [];

    chain.set("occurr",      () => puts(fmtpair( occurr(to_vet(ui[1])))));
    chain.set("teams",       () => puts(fmtpair(  teams(to_vet(ui[1])))));
    chain.set("mnext",       () => puts(fmt(      mnext(to_vet(ui[1])))));
    chain.set("alone",       () => puts(fmt(      alone(to_vet(ui[1])))));
    chain.set("couple",      () => puts(          couple(to_vet(ui[1]))));
    chain.set("subseq",      () => puts(          subseq(to_vet(ui[1]), to_vet(ui[2]), +ui[3])));
    chain.set("erase",       () => puts(fmt(       erase(to_vet(ui[1]), to_vet(ui[2])))));
    chain.set("clear",       () => puts(fmt(       clear(to_vet(ui[1]), +ui[2]))));


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

//Converte de vetor para string sem inserir os espaços
//[1, 2, 3, 4] => "[1,2,3,4]"
function fmt(vet) {
    return "[" + vet.join(", ") + "]";
}

function fmtpair(vet) {
    return fmt(vet.map((x) => {
        let [key, value] = x;
        return "" + key + ":" + value;
    }));
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

