class Pessoa {
    private nome: string;
    constructor(nome: string) {
        this.nome = nome;
    }
    public getNome(): string {
        return this.nome;
    }
    public setNome(nome: string): void {
        this.nome = nome;
    }
}

class Mercantil {
    caixas: Array<Pessoa | null>;
    espera: Array<Pessoa>;

    constructor(nCaixas: number) {
        this.caixas = [];
        for (let i = 0; i < nCaixas; i++) {
            this.caixas.push(null);
        }
        this.espera = [];
    }
    chegar(pessoa: Pessoa): void {
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
                    .map(x => x == null ? "-----" : x.getNome())
                    .join(", ")
        let espera = this.espera
                    .map(x => x.getNome())
                    .join(", ");
        return "Caixas: [" + caixas + "]\nEspera: [" + espera + "]";
    }
}

class Adapter {
    constructor() {
    }
    init(nCaixas: number): void {
    }
    arrive(nome: string): void {
    }
    call(index: number): void {
    }
    finish(index: number): void {
    }
    show(): string {
        return "";

    }
}

export { Adapter };