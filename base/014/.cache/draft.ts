
let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);


class Fone { //todo
    private id: string;
    private number: string;
    
    constructor(id: string = "", number: string = "") { //todo
    }
    
    getId(): string { //todo
    }
    
    getNumber(): string { //todo
    }
    
    isValid(): boolean { //todo
    }
    
    toString(): string { //todo
    }
}

class Contact { //todo
    private name: string;
    private favorited: boolean;
    private fones: Fone[];
    
    constructor(name: string = "") { //todo
    }
    
    getName(): string { //todo
    }
    
    getFones(): Fone[] { //todo
    }
    
    addFone(id: string, number: string): void { //todo
    }
    
    rmFone(index: number): void { //todo
    }
    
    toogleFavorited(): void { //todo
    }
    
    isFavorited(): boolean { //todo
    }
    
    toString(): string { //todo
    }
}


function main() {
    let contato = new Contact();
    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");
        
        if (args[0] === "end") {
            break;
        } else if (args[0] === "init") {
            contato = new Contact(args[1]);
        } else if (args[0] === "add") {
            contato.addFone(args[1], args[2]);
        } else if (args[0] === "rm") {
            contato.rmFone(+args[1]);
        } else if (args[0] === "tfav") {
            contato.toogleFavorited();
        } else if (args[0] === "show") {
            write(contato);
        } else {
            write("fail: comando invalido");
        }
    }
}

main();