const input = () => ""; // MODO_TESTE
export {};

// @DROP

class Client {
    private id: string;
    private fone: number;

    constructor(id: string, fone: number) {
        this.id = id;
        this.fone = fone;
    }

    toString(): string {
        return `${this.id}:${this.fone}`;
    }

    getId(): string {
        return this.id;
    }

    setId(id: string): void {
        this.id = id;
    }

    getFone(): number {
        return this.fone;
    }

    setFone(fone: number): void {
        this.fone = fone;
    }
}

class Theater {
    private seats: (Client | null)[];

    constructor(capacity: number) {
        //this.cadeiras = new Array(capacidade).fill(null);
        // O método fill(null) é utilizado para preencher todos os elementos do array recém-criado com o valor null.

        this.seats = [];
        for (let i = 0; i < capacity; i++) {            
            this.seats.push(null);
        } 
    }

    search(name: string): number {
        for(let i = 0; i < this.seats.length; i++) {
            if (this.seats[i] !== null && this.seats[i]!.getId() === name) {                
                return i;
            }        
        }
        return -1;
    }

    verificarIndice(index: number): boolean {
        if(index >= 0 && index < this.seats.length) {
            return true;
        }
        return false;
    }

    getSeats(): (Client | null)[] {
       return this.seats;
    }

    reserve(id: string, phone: number, ind: number): boolean {
        if(this.verificarIndice(ind) == false) {
            console.log("fail: cadeira nao existe");
            return false;
        }
        if (this.seats[ind] !== null) {
            console.log ("fail: cadeira ja esta ocupada");            
            return false;
        }
        if(this.search(id) != -1) {            
            console.log ("fail: cliente ja esta no cinema");
            return false;        
        }
        
        let cliente = new Client(id, phone);
        this.seats[ind] = cliente;
        return true;
    }

    cancel(id: string): void {
        if (this.search(id) === -1) {
            console.log ("fail: cliente nao esta no cinema");        
        }
        this.seats[this.search(id)!] = null;   
    }

    toString(): string {
        let cadeirasOcupadas = ""
        for(let i = 0; i < this.seats.length; i++) {
            if(this.seats[i] !== null) {
                cadeirasOcupadas += this.seats[i]!.toString() + " ";
            }
            else {
                cadeirasOcupadas += "- "
            }
        }
        return `[${cadeirasOcupadas.slice(0, -1)}]`;


        //let cadeiras = this.cadeiras.map (x => x === null ? "-" : x.toString()).join(" ");        
        //return `[${cadeiras}]`;
    }
}

// @KEEP


function main() {
    // @DROP
    let adp = new Theater(0);
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd === "end") {
            break;
        } else if (cmd === "show") { 
            // @DROP
            console.log(adp.toString());
        } else if (cmd === "init") {
            // @COM
            const seats = parseInt(par[1], 10);
            // @DROP
            adp = new Theater(seats);
        } else if (cmd === "reserve") {
            // @COM
            const id = par[1];
            const phone = parseInt(par[2]);
            const index = parseInt(par[3], 10);
            // @DROP
            adp.reserve(id, phone, index);
        } else if (cmd === "cancel") {
            // @COM
            const id = par[1];
            // @DROP
            adp.cancel(id);
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();