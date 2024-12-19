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


const input = () => ""; 
export {};

function main() {
    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   {
            break; 
        }
        else if (args[0] === "occurr") {
            console.log(fmtpair(occurr(to_vet(args[1]))));
        }
        else if (args[0] === "teams") {
            console.log(fmtpair(teams(to_vet(args[1]))));
        }
        else if (args[0] === "mnext") {
            console.log(fmt(mnext(to_vet(args[1]))));
        }
        else if (args[0] === "alone") {
            console.log(fmt(alone(to_vet(args[1]))));
        }
        else if (args[0] === "couple") {
            console.log(couple(to_vet(args[1])));
        }
        else if (args[0] === "subseq") {
            console.log(subseq(to_vet(args[1]), to_vet(args[2])));
        }
        else if (args[0] === "erase") {
            console.log(fmt(erase(to_vet(args[1]), to_vet(args[2]))));
        }
        else if (args[0] === "clear") {
            console.log(fmt(clear(to_vet(args[1]), +args[2])));
        }
        else {
            console.log("Comando invalido");
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
