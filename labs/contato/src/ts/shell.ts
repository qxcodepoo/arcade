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

// @KEEP

function main() {
    let contato = new Contact(); // @DROP
    while (true) {
        let line = input();
        console.log("$" + line);
        const args = line.split(" ");
        const cmd = args[0];
        
        if (cmd === "end") {
            break;
        } else if (cmd === "init") {
            const name = args[1];
            // @DROP
            contato = new Contact(name);
        } else if (cmd === "add") {
            const id = args[1];
            const number = args[2];
            // @DROP
            contato.addFone(id, number);
        } else if (cmd === "rm") {
            const index = +args[1];
            // @DROP
            contato.rmFone(index);
        } else if (cmd === "tfav") {
            // @DROP
            contato.toogleFavorited();
        } else if (cmd === "show") {
            // @DROP
            console.log(contato.toString());
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
