
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

class Agenda { //todo
    private contatos: Contact[];
    constructor() { //todo
    }
    private findContact(name: string): number { //todo
    }
    addContact(name: string, fones: Fone[]): void { //todo
    }
    rmContact(name: string): void { //todo
    }
    getContact(name: string): Contact | null { //todo
    }
    getContacts(): Contact[] { //todo
    }
    getFavorited(): Contact[] { //todo
    }
    search(pattern: string): Contact[] { //todo
    }
    toString(): string { //todo
    }
}

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main(): void {
    const agenda = new Agenda();
    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");
        
        if (args[0] === "end") {
            break;
        } else if (args[0] === "add") {//name id:fone id:fone ...
            const fones: Fone[] = [];
            for (let i = 2; i < args.length; i++) {
                const parts: string[] = args[i].split(':');
                fones.push(new Fone(parts[0], parts[1]));
            }
            agenda.addContact(args[1], fones);
        } else if (args[0] === "show") {
            write(agenda.toString());
        } else if (args[0] === "rmFone") {//id index
            const contato: Contact | null = agenda.getContact(args[1]);
            if (contato !== null) {
                contato.rmFone(Number(args[2]));
            }
        } else if (args[0] === "rm") {//id
            agenda.rmContact(args[1]);
        } else if (args[0] === "tfav") {
            const contato: Contact | null = agenda.getContact(args[1]);
            if (contato !== null) {
                contato.toogleFavorited();
            }
        } else if (args[0] === "search") {//pattern
            write(agenda.search(args[1]).join("\n"));
        } else if (args[0] === "favs") {//pattern
            write(agenda.getFavorited(args[1]).join("\n"));
        } else {
            write("fail: comando invalido");
        }
    }
}


main();