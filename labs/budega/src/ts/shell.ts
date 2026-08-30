const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Person {
    private name: string;
    constructor(name: string) {
        this.name = name;
    }
    public getName(): string {
        return this.name;
    }
    public setName(name: string): void {
        this.name = name;
    }
}

class Market {
    caixas: Array<Person | null>;
    espera: Array<Person>;

    constructor(nCaixas: number) {
        this.caixas = [];
        for (let i = 0; i < nCaixas; i++) {
            this.caixas.push(null);
        }
        this.espera = [];
    }
    chegar(pessoa: Person): void {
        this.espera.push(pessoa);
    }
    chamar(index: number) {
        if (this.espera.length == 0) {
            console.log("fail: sem clientes");
            return;
        }
        if (this.caixas[index] != null) {
            console.log("fail: caixa ocupado");
            return;
        }
        this.caixas[index] = this.espera.shift()!;
    }
    finalizar(index: number): void {
        if (index >= this.caixas.length) {
            console.log("fail: caixa inexistente");
            return;
        }
        if (this.caixas[index] == null) {
            console.log("fail: caixa vazio");
            return;
        }
        this.caixas[index] = null;
    }

    toString(): string {
        let caixas = this.caixas
                    .map(x => x == null ? "-----" : x.getName())
                    .join(", ")
        let espera = this.espera
                    .map(x => x.getName())
                    .join(", ");
        return "Caixas: [" + caixas + "]\nEspera: [" + espera + "]";
    }
}

// @KEEP
function main() {
    // @DROP
    let market = new Market(3);
    // @KEEP
    while (true) {
        const line = input();
        console.log("$" + line);

        var par = line.split(" ");
        var cmd = par[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "show") { 
            // @DROP
            console.log(market.toString());
        } else if (cmd == "init") { 
            // @COM
            const nCaixas = parseInt(par[1]);
            // @DROP
            market = new Market(nCaixas);
        } else if (cmd == "arrive") { 
            // @COM
            const nome = par[1];
            // @DROP
            market.chegar(new Person(nome));    
        } else if (cmd == "call") { 
            // @COM
            const index = parseInt(par[1]);
            // @DROP
            market.chamar(index);
        } else if (cmd == "finish") { 
            // @COM
            const index = parseInt(par[1]);
            // @DROP
            market.finalizar(index);
        } else {
            console.log("fail: comando invalido");
        }
    }
}
main() 
