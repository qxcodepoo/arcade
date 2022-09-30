import {evaluate, puts} from "./shell";

function inside(vet: number[], value: number): boolean { //todo
    for (let elem of vet)
    return false;
}

function index_of(vet: number[], value: number): number { //todo
    for (let i = 0; i < vet.length; i++)
    return -1;
}

function find_if(vet: number[]): number { //todo
    for (let i = 0; i < vet.length; i++)
    return -1;
}

function min_element(vet: number[]): number { //todo
    let pos = -1;
    for (let i = 0; i < vet.length; i++)
    return pos;
}

function find_min_if(vet: number[]): number { //todo
    let pos = -1;
    for (let i = 0; i < vet.length; i++)
    return pos;
}



// -------------------------- MAIN --------------------------

function main() {
    let chain = new Map();
    let ui: string[] = [];

    chain.set("in",           () => puts(     inside(to_vet(ui[1]), +ui[2])));
    chain.set("index_of",     () => puts(   index_of(to_vet(ui[1]), +ui[2])));
    chain.set("find_if",      () => puts(    find_if(to_vet(ui[1]))        ));
    chain.set("min_element",  () => puts(min_element(to_vet(ui[1]))        ));
    chain.set("find_min_if",  () => puts(find_min_if(to_vet(ui[1]))        ));

    evaluate(chain, ui);
}

// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token: string): number[] {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
}

main()

