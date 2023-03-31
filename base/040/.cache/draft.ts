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

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")          { break;                                                       }
        else if (args[0] === "count")        { write(count(to_vet(args[1]), +args[2]));                     }
        else if (args[0] === "sum")          { write(sum(to_vet(args[1])));                                 }
        else if (args[0] === "average")      { write(average(to_vet(args[1])).toFixed(2));                  }
        else if (args[0] === "more_men")     { write(more_men(to_vet(args[1])));                            }
        else if (args[0] === "half_compare") { write(half_compare(to_vet(args[1])));                    }
        else if (args[0] === "sex_battle")   { write(sex_battle(to_vet(args[1])));                          }
        else                                 { write("fail: comando invalido");                             }
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

