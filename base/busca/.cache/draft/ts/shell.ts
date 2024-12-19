const input = () => "";
export {};

function inside(vet: number[], value: number): boolean {
    return false;
}

function index_of(vet: number[], value: number): number {
    return 0;
}

function find_if(vet: number[]): number {
    return 0;
}

function min_element(vet: number[]): number {
    return 0;
}

function find_min_if(vet: number[]): number {
    return 0;
}


function main() {
    while (true) {
        let line = input();
        console.log("$" + line);
        
        let args = line.split(" ");

        if (args[0] === "end")   { 
            break;
        }
        else if (args[0] === "in"){
            let result = inside(to_vet(args[1]), +args[2]);
            console.log(result ? "true" : "false");
        }
        else if (args[0] === "index_of"){
            let result = index_of(to_vet(args[1]), +args[2]);
            console.log(result);
        }
        else if (args[0] === "find_if"){
            let result = find_if(to_vet(args[1]));
            console.log(result);
        }
        else if (args[0] === "min_element"){
            let result = min_element(to_vet(args[1]));
            console.log(result);
        }
        else if (args[0] === "find_min_if"){
            let result = find_min_if(to_vet(args[1]));
            console.log(result);
        }
        else {
            console.log("fail: Comando inválido");
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
