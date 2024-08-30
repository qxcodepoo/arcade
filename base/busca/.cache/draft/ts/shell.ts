import { inside, index_of, find_if, min_element, find_min_if } from "./student";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);
export {};

function main() {
    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if (args[0] === "end")   { 
            break;
        }
        else if (args[0] === "in"){
            let result = inside(to_vet(args[1]), +args[2]);
            write(result ? "true" : "false");
        }
        else if (args[0] === "index_of"){
            let result = index_of(to_vet(args[1]), +args[2]);
            write(result);
        }
        else if (args[0] === "find_if"){
            let result = find_if(to_vet(args[1]));
            write(result);
        }
        else if (args[0] === "min_element"){
            let result = min_element(to_vet(args[1]));
            write(result);
        }
        else if (args[0] === "find_min_if"){
            let result = find_min_if(to_vet(args[1]));
            write(result);
        }
        else {
            write("fail: Comando inválido");
        }
    }
}

main();



// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token: string): number[] {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
}
