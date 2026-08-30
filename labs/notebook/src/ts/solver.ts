class Carregador {
    private potencia: number;
    constructor(potencia: number) {
        this.potencia = potencia;
    }
    setPotencia(valor: number): void {
        this.potencia = valor;
    }
    getPotencia(): number {
        return this.potencia;
    }
}
class Bateria {
    private capacidade: number;
    private carga: number;
    constructor(capacidade: number) {
        this.capacidade = capacidade;
        this.carga = 0;
    }
    estaCarregada(): boolean {
        return this.carga > 0;
    }
    carregar(carregador: Carregador, tempo: number): void {
        this.carga += tempo * carregador.getPotencia();
        if (this.carga > this.capacidade) {
            this.carga = this.capacidade;
        }
    }
    descarregar(tempo: number): void {
        this.carga -= tempo;
        if (this.carga <= 0) {
            this.carga = 0;
        }
    }
}
class Notebook {
    private carregador: Carregador | null;
    private bateria: Bateria | null;
    private ligado: boolean;
    constructor() {
        this.carregador = null;
        this.bateria = null;
        this.ligado = false;
    }
    setCarregador(carregador: Carregador) {
        this.carregador = carregador;
    }
    setBateria(bateria: Bateria) {
        this.bateria = bateria;
    }
    ligar(): boolean {
        if (this.ligado) {
            console.log("Falhou: ja esta ligado");
            return false;
        }
        if (this.carregador != null) {
            this.ligado = true;
            return true;
        }
        if (this.bateria != null && this.bateria.estaCarregada()) {
            this.ligado = true;
            return true;
        }
        return false;
    }
    usar(tempo: number) {
        if (!this.ligado) {
            console.log("Ligue o notebook primeiro");
            return;
        }
        if (this.carregador != null && this.bateria == null) {
            console.log("Conseguiu usar com sucesso")
            return;
        }
        if (this.carregador != null && this.bateria != null) {
            console.log("Conseguiu usar com sucesso")
            this.bateria.carregar(this.carregador, tempo);
            return;
        }
        this.bateria?.descarregar(tempo);
        if (this.bateria?.estaCarregada()) {
            console.log("Conseguiu usar com sucesso");
        } else {
            console.log("Bateria descarregou durante o uso");
        }
    }
}
