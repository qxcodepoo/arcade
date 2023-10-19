
class Slot {
    nome: string;
    qtd: number;
    preco: number;

    constructor(nome: string = "empty", qtd: number = 0, preco: number = 0.0) {
    }

    toString(): string {
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
