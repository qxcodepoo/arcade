abstract class Veiculo {
    private id: string;
    protected tipo: string;
    protected entrada: number;
    
    constructor(id: string) {
    }
    setEntrada(entrada: number): void {
    }
    getEntrada(): number {
    }
    getTipo(): string {
    }
    getId(): string {
    }
    toString(): string {
    }
    abstract calcularValor(saida: number): number;
}

class Bike extends Veiculo {
    constructor(id: string) {
    }
    calcularValor(saida: number): number {
    }
}

class Moto extends Veiculo {
    constructor(id: string) {
    }
    calcularValor(saida: number): number {
    }
}

class Carro extends Veiculo {
    constructor(id: string) {
    }
    calcularValor(saida: number): number {
    }
}

class Estacionamento {
    veiculos: Veiculo[];
    tempo: number;

    constructor() {
    }
    private procurarVeiculo(id: string): number {
    }
    
    estacionar(veiculo: Veiculo): void {
    }

    pagar(id: string): void {
    }

    sair(id: string): void {
    }

    passarTempo(tempo: number): void {
    }

    toString(): string {

    }
}

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let est = new Estacionamento();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end") { 
            break;                                                       
        }
        else if (args[0] === "show") { 
            console.log(est.toString());                                 
        }
        else if (args[0] === "bike") {
            est.estacionar(new Bike(args[1]));
        }
        else if (args[0] === "moto") {
            est.estacionar(new Moto(args[1]));
        }
        else if (args[0] === "carro") {
            est.estacionar(new Carro(args[1]));
        }
        else if (args[0] === "tempo") {
            est.passarTempo(+args[1]);
        }
        else if (args[0] === "pagar") {
            est.pagar(args[1]);
            est.sair(args[1]);
        }
        else {
            console.log("fail: omando invalido");
        }
    }
}

main();
