
class Slot {
    nome: string;
    qtd: number;
    preco: number;

    constructor(nome: string = "empty", qtd: number = 0, preco: number = 0.0) {
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
    }

    get(indice: number): Slot {
    }

    set(indice: number, name: string, qtd: number, price: number): void {
    }

    limpar(indice: number): void {
    }

    inserirDinheiro(value: number): void {
    }

    pedirTroco(): number {
    }

    comprar(ind: number): void {
    }

    getSaldo(): number {
    }

    toString(): string {
        const espiralStr = this.espirais
            .map((slot, index) => `${index} ${slot.toString()}`)
            .join('\n');
        return `saldo: ${this.saldo.toFixed(2)}\n${espiralStr}`;
    }
}


function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }


function main() {
    let machine = new Machine(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
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
 */