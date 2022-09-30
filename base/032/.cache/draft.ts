import {evaluate, puts} from "./shell";


function get_men(vet: number[]): number[] { //todo
}

function get_calm_women(vet: number[]): number[] { //todo
}

function sort(vet: number[]): number[] { //todo
}

function sort_stress(vet: number[]): number[] { //todo
}

function reverse(vet: number[]): number[] { //todo
}

function reverse_inplace(vet: number[]): number[] { //todo
}

function unique(vet: number[]): number[] { //todo
}

function repeated(vet: number[]): number[] { //todo
}




// -------------------------- MAIN --------------------------

function main() {
    let chain = new Map();
    let ui: string[] = [];

    chain.set("get_men",         () => puts(fmt(        get_men(to_vet(ui[1])))));
    chain.set("get_calm_women",  () => puts(fmt( get_calm_women(to_vet(ui[1])))));
    chain.set("sort",            () => puts(fmt(           sort(to_vet(ui[1])))));
    chain.set("sort_stress",     () => puts(fmt(    sort_stress(to_vet(ui[1])))));
    chain.set("reverse",         () => puts(fmt(        reverse(to_vet(ui[1])))));
    chain.set("reverse_inplace", () => puts(fmt(reverse_inplace(to_vet(ui[1])))));
    chain.set("unique",          () => puts(fmt(         unique(to_vet(ui[1])))));
    chain.set("repeated",        () => puts(fmt(       repeated(to_vet(ui[1])))));
    
    evaluate(chain, ui);
}

// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token: string): number[] {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
}

//Converte de vetor para string sem inserir os espaços
//[1, 2, 3, 4] => "[1,2,3,4]"
function fmt(vet: number[]): string {
    return "[" + vet.join(", ") + "]";
}

main()

