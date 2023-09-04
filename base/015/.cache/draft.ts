
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

class Agenda {
    private contatos: Contact[];
    constructor() {
    }
    private findContact(name: string): number {
    }
    addContact(name: string, fones: Fone[]): void {
    }
    rmContact(name: string): void {
    }
    getContact(name: string): Contact | null {
    }
    getContacts(): Contact[] {
    }
    getFavorited(): Contact[] {
    }
    search(pattern: string): Contact[] {
    }
    toString(): string {
    }
}

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
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