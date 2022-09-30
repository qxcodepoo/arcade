import {evaluate, puts} from "./shell";

//retorna um vetor de pares
function occurr(vet: number[]): number[][] { //todo
}

//retorna um vetor de pares
function teams(vet: number[]): number[][] { //todo

}

function mnext(vet: number[]): number[] { //todo
}

function alone(vet: number[]): number[] { //todo
}

function couple(vet: number[]): number { //todo
}

function has_subseq(vet: number[], seq: number[], pos: number): boolean { //todo
}

function subseq(vet: number[], seq: number[]) { //todo
}

function erase(vet: number[], pos_list: number[]): number[] { //todo
}

function clear(vet: number[], value: number) { //todo
}


// -------------------------- MAIN --------------------------

function main() {
    let chain = new Map();
    let ui: string[] = [];

    chain.set("occurr",      () => puts(fmtpair( occurr(to_vet(ui[1])))));
    chain.set("teams",       () => puts(fmtpair(  teams(to_vet(ui[1])))));
    chain.set("mnext",       () => puts(fmt(      mnext(to_vet(ui[1])))));
    chain.set("alone",       () => puts(fmt(      alone(to_vet(ui[1])))));
    chain.set("couple",      () => puts(          couple(to_vet(ui[1]))));
    chain.set("subseq",      () => puts(          subseq(to_vet(ui[1]), to_vet(ui[2]))));
    chain.set("erase",       () => puts(fmt(       erase(to_vet(ui[1]), to_vet(ui[2])))));
    chain.set("clear",       () => puts(fmt(       clear(to_vet(ui[1]), +ui[2]))));


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
function fmt(vet: any[]): string {
    return "[" + vet.join(", ") + "]";
}

function fmtpair(vet: number[][]): string {
    return fmt(vet.map((x: number[]) => {
        let [key, value] = x;
        return "" + key + ":" + value;
    }));
}


main()

