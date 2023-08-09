
function get_men(vet: number[]): number[] {
}

function get_calm_women(vet: number[]): number[] {
}

function sort(vet: number[]): number[] {
}

function sort_stress(vet: number[]): number[] {
}

function reverse(vet: number[]): number[] {
}

function unique(vet: number[]): number[] {
}

function repeated(vet: number[]): number[] {
}




// -------------------------- MAIN --------------------------

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let vet = new Array<string>();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")             { break;                                                       }
        else if (args[0] === "get_men")         { write(fmt(get_men(       to_vet(args[1])))); }
        else if (args[0] === "get_calm_women")  { write(fmt(get_calm_women(to_vet(args[1])))); }
        else if (args[0] === "sort")            { write(fmt(sort(          to_vet(args[1])))); }
        else if (args[0] === "sort_stress")     { write(fmt(sort_stress(   to_vet(args[1])))); }
        else if (args[0] === "reverse")         { write(fmt(reverse(       to_vet(args[1])))); }
        else if (args[0] === "unique")          { write(fmt(unique(        to_vet(args[1])))); }
        else if (args[0] === "repeated")        { write(fmt(repeated(      to_vet(args[1])))); }
        else                                    { write("fail: comando invalido");                             }
    }
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

