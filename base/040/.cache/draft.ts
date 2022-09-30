import {evaluate, puts} from "./shell";


function count(vet: number[], value: number): number { //todo
}

function sum(vet: number[]): number { //todo
}

function average(vet: number[]): number { //todo
}

function more_men(vet: number[]): string { //todo
}

function half_compare(vet: number[]): string { //todo
}

function sex_battle(vet: number[]): string { //todo


}


// -------------------------- MAIN --------------------------

function main() {
    let chain = new Map();
    let ui: string[] = [];

    chain.set("count",        () => puts(       count(to_vet(ui[1]), +ui[2])   ));
    chain.set("sum",          () => puts(         sum(to_vet(ui[1]))           ));
    chain.set("average",      () => puts(     average(to_vet(ui[1])).toFixed(2)));
    chain.set("more_men",     () => puts(    more_men(to_vet(ui[1]))           ));
    chain.set("half_compare", () => puts(half_compare(to_vet(ui[1]))           ));
    chain.set("sex_battle",   () => puts(  sex_battle(to_vet(ui[1]))           ));

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

