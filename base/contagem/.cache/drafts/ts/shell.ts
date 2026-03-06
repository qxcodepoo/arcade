function input() { return ""; }
export {};

function count(vet: number[], value: number): number {
    return 0;
}

function sum(vet: number[]): number {
    return 0;
}

function average(vet: number[]): number {
    return 0;
}

function more_men(vet: number[]): string {
    return "";
}

function half_compare(vet: number[]): string {
    return "";
}

function sex_battle(vet: number[]): string {
    return "";
}

function main() {
    while (true) {
        let line = input();
        console.log("$" + line);

        let args = line.split(" ");
        let cmd = args[0];

        if      (cmd === "end")          { break;                                             }
        else if (cmd === "count")        { console.log(count(to_vet(args[1]), +args[2]));     }
        else if (cmd === "sum")          { console.log(sum(to_vet(args[1])));                 }
        else if (cmd === "average")      { console.log(average(to_vet(args[1]))?.toFixed(2)); }
        else if (cmd === "more_men")     { console.log(more_men(to_vet(args[1])));            }
        else if (cmd === "half_compare") { console.log(half_compare(to_vet(args[1])));        }
        else if (cmd === "sex_battle")   { console.log(sex_battle(to_vet(args[1])));          }
        else                             { console.log("fail: comando invalido");             }
    }
}

// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token: string): number[] {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
}


main()
