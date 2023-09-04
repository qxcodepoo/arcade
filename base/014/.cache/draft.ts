
let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);


class Fone {
    private id: string;
    private number: string;
    
    constructor(id: string = "", number: string = "") {
    }
    
    getId(): string {
    }
    
    getNumber(): string {
    }
    
    isValid(): boolean {
    }
    
    toString(): string {
    }
}

class Contact {
    private name: string;
    private favorited: boolean;
    private fones: Fone[];
    
    constructor(name: string = "") {
    }
    
    getName(): string {
    }
    
    getFones(): Fone[] {
    }
    
    addFone(id: string, number: string): void {
    }
    
    rmFone(index: number): void {
    }
    
    toogleFavorited(): void {
    }
    
    isFavorited(): boolean {
    }
    
    toString(): string {
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