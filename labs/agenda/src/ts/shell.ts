const input = () => ""; // MODO_TESTE
export {};

// @DROP

class Fone {
    private id: string;
    private number: string;
    
    constructor(id: string = "", number: string = "") {
        this.id = id;
        this.number = number;
    }
    
    getId(): string {
        return this.id;
    }
    
    getNumber(): string {
        return this.number;
    }
    
    isValid(): boolean {
        const valid = "0123456789()-.";
        for (const c of this.number) {
            if (!valid.includes(c)) {
                return false;
            }
        }
        return true;
    }
    
    toString(): string {
        return `${this.id}:${this.number}`;
    }
}

class Contact {
    private name: string;
    private favorited: boolean;
    private fones: Fone[];
    
    constructor(name: string = "") {
        this.name = name;
        this.favorited = false;
        this.fones = [];
    }
    
    getName(): string {
        return this.name;
    }
    
    getFones(): Fone[] {
        return this.fones;
    }
    
    addFone(id: string, number: string): void {
        const fone = new Fone(id, number);
        if (fone.isValid()) {
            this.fones.push(new Fone(id, number));
        } else {
            console.log("fail: invalid number");
        }
    }
    
    rmFone(index: number): void {
        if (index < 0 || index >= this.fones.length) {
            return;
        }
        this.fones.splice(index, 1);
    }
    
    toogleFavorited(): void {
        this.favorited = !this.favorited;
    }
    
    isFavorited(): boolean {
        return this.favorited;
    }
    
    toString(): string {
        return `${this.favorited ? "@" : "-"} ${this.name} [${this.fones.join(", ")}]`;
    }
}

class Agenda {
    private contatos: Contact[];
    constructor() {
        this.contatos = [];
    }
    private findContact(name: string): number {
        for (let i = 0; i < this.contatos.length; i++) {
            if (this.contatos[i].getName() === name) {
                return i;
            }
        }
        return -1;
    }
    addContact(name: string, fones: Fone[]): void {
        let ind = this.findContact(name);
        if (ind === -1) {
            this.contatos.push(new Contact(name));
            this.contatos.sort((a, b) => a.getName().localeCompare(b.getName()));
            ind = this.findContact(name);
        }
        for (const fone of fones) {
            this.contatos[ind].addFone(fone.getId(), fone.getNumber());
        }
    }
    rmContact(name: string): void {
        const ind = this.findContact(name);
        if (ind !== -1) {
            this.contatos.splice(ind, 1);
        }
    }
    getContact(name: string): Contact | null {
        const ind = this.findContact(name);
        if (ind !== -1) {
            return this.contatos[ind];
        }
        return null;
    }
    getContacts(): Contact[] {
        return this.contatos;
    }
    getFavorited(): Contact[] {
        return this.contatos.filter((contact) => contact.isFavorited());
    }
    search(pattern: string): Contact[] {
        const resp: Contact[] = [];
        for (const elem of this.contatos) {
            if (elem.toString().includes(pattern)) {
                resp.push(elem);
            }
        }
        return resp;
    }
    toString(): string {
        return this.contatos.map((contact) => contact.toString()).join("\n");
    }
}

// @KEEP

function main(): void {
    const agenda = new Agenda(); // @DROP
    while (true) {
        let line = input();
        console.log("$" + line);
        
        let args = line.split(" ");
        
        if (args[0] === "end") {
            break;
        } else if (args[0] === "add") {//name id:fone id:fone ...
            // @COM
            const name = args[1];
            const fones: Fone[] = [];
            for (let i = 2; i < args.length; i++) {
                const [label, number] = args[i].split(':');
                fones.push(new Fone(label, number));
            }
            // @DROP
            agenda.addContact(name, fones);
        } else if (args[0] === "show") {
            // @DROP
            console.log(agenda.toString());
        } else if (args[0] === "rmFone") {//id index
            // @COM
            const id = args[1];
            const index = parseInt(args[2]);
            // @DROP
            const contato: Contact | null = agenda.getContact(id);
            if (contato !== null) {
                contato.rmFone(index);
            }
        } else if (args[0] === "rm") {
            const name = args[1];
            // @DROP
            agenda.rmContact(name);
        } else if (args[0] === "tfav") {
            // @COM
            const id = args[1];
            // @DROP
            const contato: Contact | null = agenda.getContact(id);
            if (contato !== null) {
                contato.toogleFavorited();
            }
        } else if (args[0] === "search") {//pattern
            // @COM
            const pattern = args[1];
            // @DROP
            console.log(agenda.search(pattern).join("\n"));
        } else if (args[0] === "favs") {
            // @DROP
            console.log(agenda.getFavorited().join("\n"));
        } else {
            console.log("fail: comando invalido");
        }
    }
}


main();
