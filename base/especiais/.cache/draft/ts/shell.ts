//retorna um vetor de pares
function occurr(vet: number[]): number[][] {
    return [];
}

//retorna um vetor de pares
function teams(vet: number[]): number[][] {
    return [];
}

function mnext(vet: number[]): number[] {
    return [];
}

function alone(vet: number[]): number[] {
    return [];
}

function couple(vet: number[]): number {
    return 0;
}

function has_subseq(vet: number[], seq: number[], pos: number): boolean {
    return true;
}

function subseq(vet: number[], seq: number[]) {
    return 0;
}

function erase(vet: number[], pos_list: number[]): number[] {
    return [];
}

function clear(vet: number[], value: number): number[] {
    return [];
}

//DEL!------------------------ MAIN --------------------------

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
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
    return "[" + vet?.join(", ") + "]";
}

function fmtpair(vet: number[][]): string {
    return fmt(vet?.map((x: number[]) => {
        let [key, value] = x;
        return "(" + key + ", " + value + ")";
    }));
}


main()
