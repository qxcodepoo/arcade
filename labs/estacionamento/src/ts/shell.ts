const input = () => ""; // MODO_TESTE
export {};

// @DROP
abstract class Veiculo {
    private id: string;
    protected tipo: string;
    protected entrada: number;

    constructor(id: string) {
        this.id = id;
        this.tipo = "";
        this.entrada = 0;
    }
    setEntrada(entrada: number): void {
        this.entrada = entrada;
    }
    getEntrada(): number {
        return this.entrada;
    }
    getTipo(): string {
        return this.tipo;
    }
    getId(): string {
        return this.id;
    }
    toString(): string {
        return (
            this.tipo.padStart(10, "_") +
            " : " +
            this.id.padStart(10, "_") +
            " : " +
            this.entrada
        );
    }
    abstract calcularValor(saida: number): number;
}

class Bike extends Veiculo {
    constructor(id: string) {
        super(id);
        this.tipo = "Bike";
    }
    calcularValor(saida: number): number {
        return 3;
    }
}

class Moto extends Veiculo {
    constructor(id: string) {
        super(id);
        this.tipo = "Moto";
    }
    calcularValor(saida: number): number {
        let tempo = saida - this.entrada;
        return tempo / 20;
    }
}

class Carro extends Veiculo {
    constructor(id: string) {
        super(id);
        this.tipo = "Carro";
    }
    calcularValor(saida: number): number {
        let tempo = saida - this.entrada;
        return Math.max(tempo / 10, 5);
    }
}

class Estacionamento {
    veiculos: Veiculo[];
    tempo: number;

    constructor() {
        this.veiculos = [];
        this.tempo = 0;
    }
    private procurarVeiculo(id: string): number {
        for (let i = 0; i < this.veiculos.length; i++) {
            if (this.veiculos[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

    estacionar(veiculo: Veiculo): void {
        veiculo.setEntrada(this.tempo);
        this.veiculos.push(veiculo);
    }

    pagar(id: string): void {
        let pos = this.procurarVeiculo(id);
        if (pos == -1) {
            console.log("fail: veiculo nao encontrado");
        }
        let veiculo = this.veiculos[pos];
        console.log(
            veiculo.getTipo() +
                " chegou " +
                veiculo.getEntrada() +
                " saiu " +
                this.tempo +
                ". Pagar R$ " +
                veiculo.calcularValor(this.tempo).toFixed(2),
        );
    }

    sair(id: string): void {
        let pos = this.procurarVeiculo(id);
        if (pos == -1) {
            console.log("fail: veiculo nao encontrado");
        }
        this.veiculos.splice(pos, 1);
    }

    passarTempo(tempo: number): void {
        this.tempo += tempo;
    }

    toString(): string {
        return (
            this.veiculos.map((v) => v.toString()).join("\n") +
            (this.veiculos.length == 0 ? "" : "\n") +
            "Hora atual: " +
            this.tempo
        );
    }
}
// @KEEP
function main() {
    // @DROP
    const estacionamento = new Estacionamento();
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const args = line.split(" ");
        const cmd = args[0];

        if (cmd === "end") {
            break;
        } else if (cmd === "show") {
            // @DROP
            console.log(estacionamento.toString());
        } else if (cmd === "estacionar") {
            // @COM
            const tipo = args[1];
            const id = args[2];
            // @DROP
            if (tipo === "bike") {
                estacionamento.estacionar(new Bike(id));
            } else if (tipo === "moto") {
                estacionamento.estacionar(new Moto(id));
            } else if (tipo === "carro") {
                estacionamento.estacionar(new Carro(id));
            }
        } else if (cmd === "tempo") {
            const tempo = +args[1];
            // @DROP
            estacionamento.passarTempo(tempo);
        } else if (cmd === "pagar") {
            // CHAME OS METODOS PAGAR E SAIR
            // @COM
            const id = args[1];
            // @DROP
            estacionamento.pagar(id);
            estacionamento.sair(id);
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
