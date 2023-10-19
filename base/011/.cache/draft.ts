//++

class Slot {
    nome: string;
    qtd: number;
    preco: number;

    constructor(nome: string = "empty", qtd: number = 0, preco: number = 0.0) {
        this.nome = nome;
        this.qtd = qtd;
        this.preco = preco;
    }

    toString(): string {
        return `[${this.nome.padStart(8)} :${this.qtd.toString().padStart(2)} U : ${this.preco.toFixed(2)} RS]`;
    }
}

class Machine {
    espirais: Slot[];
    saldo: number;
    lucro: number;

    constructor(qtd: number = 0) {
        this.espirais = new Array(qtd).fill(new Slot());
        this.saldo = 0;
        this.lucro = 0;
    }

    get(indice: number): Slot {
        if (indice < 0 || indice >= this.espirais.length) {
            console.log("fail: indice nao existe");
            return new Slot();
        }
        return this.espirais[indice];
    }

    set(indice: number, name: string, qtd: number, price: number): void {
        if (indice < 0 || indice >= this.espirais.length) {
            console.log("fail: indice nao existe");
            return;
        }
        const espiral = new Slot(name, qtd, price);
        if (espiral.qtd < 0) {
            console.log("fail: quantidade invalida");
            return;
        }
        this.espirais[indice] = espiral;
    }

    limpar(indice: number): void {
        this.espirais[indice] = new Slot();
    }

    inserirDinheiro(value: number): void {
        if (value <= 0) {
            console.log("fail: valor invalido");
            return;
        }
        this.saldo += value;
    }

    pedirTroco(): number {
        const troco = this.saldo;
        this.saldo = 0;
        return troco;
    }

    comprar(ind: number): void {
        if (ind < 0 || ind >= this.espirais.length) {
            console.log("fail: indice nao existe");
            return;
        }
        if (this.saldo < this.espirais[ind].preco) {
            console.log("fail: saldo insuficiente");
            return;
        }
        if (this.espirais[ind].qtd === 0) {
            console.log("fail: espiral sem produtos");
            return;
        }
        this.saldo -= this.espirais[ind].preco;
        this.espirais[ind].qtd -= 1;
        console.log(`voce comprou um ${this.espirais[ind].nome}`);
    }

    getSaldo(): number {
        return this.saldo;
    }

    toString(): string {
        const espiralStr = this.espirais
            .map((slot, index) => `${index} ${slot.toString()}`)
            .join('\n');
        return `saldo: ${this.saldo.toFixed(2)}\n${espiralStr}`;
    }
}


let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);



function main() {
    let machine = new Machine(0);

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if (args[0] === "end") {
            break;
        } else if (args[0] === "show") {
            console.log(machine.toString());
        } else if (args[0] === "init") {
            machine = new Machine(+args[1]);
        } else if (args[0] === "limpar") {
            machine.limpar(+(args[1]));
        } else if (args[0] === "dinheiro") {
            machine.inserirDinheiro(+args[1]);
        } else if (args[0] === "comprar") {
            machine.comprar(+args[1]);
        } else if (args[0] === "set") {
            machine.set(+args[1], args[2], +(args[3]), +args[4]);
        } else if (args[0] === "troco") {
            console.log(`voce recebeu ${machine.pedirTroco().toFixed(2)} RS`);
        } else {
            console.log("comando invalido");
        }
    }
}

main();
