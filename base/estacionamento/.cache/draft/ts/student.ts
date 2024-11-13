
class Adapter {
    // estacionamento: Estacionamento;
    constructor() {
        // this.estacionamento = new Estacionamento();
    }
    estacionar(tipo: string, id: string): void {
        // if (tipo === "bike") {
        //     this.estacionamento.estacionar(new Bike(id));
        // } else if (tipo === "moto") {
        //     this.estacionamento.estacionar(new Moto(id));
        // } else if (tipo === "carro") {
        //     this.estacionamento.estacionar(new Carro(id));
        // }
    }

    passarTempo(tempo: number): void {
        // this.estacionamento.passarTempo(tempo);
    }

    pagar (id: string): void {
        // this.estacionamento.pagar(id);
    }

    sair(id: string): void {
        // this.estacionamento.sair(id);
    }

    show(): void {
        // console.log(this.estacionamento.toString());
    }
}

export { Adapter };