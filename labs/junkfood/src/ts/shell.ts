const input = () => ""; // MODO_TESTE
export { };

// @DROP
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

    setSlot(indice: number, name: string, qtd: number, price: number): void {
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

// @KEEP

function main() {
    // @DROP
    let machine = new Machine(0);
    // @KEEP
    while (true) {
        let line = input();
        console.log("$" + line);

        let args = line.split(" ");
        let cmd = args[0];

        if (cmd == "show") {
            // @DROP
            console.log(machine.toString());
        } else if (cmd == "init") {
            // @COM
            let qtd_espirais = parseInt(args[1]);
            // @DROP
            machine = new Machine(qtd_espirais);
        } else if (cmd == "limpar") {
            // @COM
            let indice = parseInt(args[1]);
            // @DROP
            machine.limpar(indice);
        } else if (cmd == "dinheiro") {
            // @COM
            let value = parseFloat(args[1]);
            // @DROP
            machine.inserirDinheiro(value);
        } else if (cmd == "comprar") {
            // @COM
            let ind = parseInt(args[1]);
            // @DROP
            machine.comprar(ind);
        } else if (cmd == "set") {
            // @COM
            let indice = parseInt(args[1]);
            let nome = args[2];
            let qtd = parseInt(args[3]);
            let preco = parseFloat(args[4]);
            // @DROP
            machine.setSlot(indice, nome, qtd, preco);
        } else if (cmd == "troco") {
            // @DROP
            let troco = machine.pedirTroco();
            console.log(`voce recebeu ${troco.toFixed(2)} RS`);
        } else if (cmd == "end") {
            break;
        } else {
            console.log("comando invalido");
        }
    }
}

main();