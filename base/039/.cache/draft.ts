//retorna um vetor de pares
function occurr(vet: number[]): number[][] {
}

//retorna um vetor de pares
function teams(vet: number[]): number[][] {

}

function mnext(vet: number[]): number[] {
}

function alone(vet: number[]): number[] {
}

function couple(vet: number[]): number {
}

function has_subseq(vet: number[], seq: number[], pos: number): boolean {
}

function subseq(vet: number[], seq: number[]) {
}

function erase(vet: number[], pos_list: number[]): number[] {
}

function clear(vet: number[], value: number) {
}


// -------------------------- MAIN --------------------------

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   {
            break; 
        }
        else if (args[0] === "occurr") {
            write(fmtpair(occurr(to_vet(args[1]))));
        }
        else if (args[0] === "teams") {
            write(fmtpair(teams(to_vet(args[1]))));
        }
        else if (args[0] === "mnext") {
            write(fmt(mnext(to_vet(args[1]))));
        }
        else if (args[0] === "alone") {
            write(fmt(alone(to_vet(args[1]))));
        }
        else if (args[0] === "couple") {
            write(couple(to_vet(args[1])));
        }
        else if (args[0] === "subseq") {
            write(subseq(to_vet(args[1]), to_vet(args[2])));
        }
        else if (args[0] === "erase") {
            write(fmt(erase(to_vet(args[1]), to_vet(args[2]))));
        }
        else if (args[0] === "clear") {
            write(fmt(clear(to_vet(args[1]), +args[2])));
        }
        else {
            write("Comando invalido");
        }
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
function fmt(vet: any[]): string {
    return "[" + vet.join(", ") + "]";
}

function fmtpair(vet: number[][]): string {
    return fmt(vet.map((x: number[]) => {
        let [key, value] = x;
        return "(" + key + ", " + value + ")";
    }));
}


main()

