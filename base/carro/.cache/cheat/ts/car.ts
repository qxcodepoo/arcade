
class Car{
    pass: number; // Passageiros
    passMax: number; // limite de Passageiros
    gas: number; // tanque
    gasMax: number; // limite do tanque
    km: number; // quantidade de quilometragem

    constructor() {
        this.pass = 0; // Passageiros
        this.passMax = 2; // limite de Passageiros
        this.gas = 0; // tanque
        this.gasMax = 100; // limite do tanque
        this.km = 0; // quantidade de quilometragem
    }

    enter(): void {
        if (this.pass < this.passMax) {
            this.pass += 1;
            return;
        }
        console.log("fail: limite de pessoas atingido");
    }

    leave(): void {
        if (this.pass > 0) {
            this.pass-=1;
            return;
        }
        console.log("fail: nao ha ninguem no carro");
    }

    fuel(gas: number): void {
        this.gas += gas;
        if(this.gas > this.gasMax) {
            this.gas = this.gasMax;
        }
    }
    
    drive (km: number): void {
        if(this.pass == 0) {
            console.log("fail: nao ha ninguem no carro");
            return;
        }
        if(this.gas == 0) {
            console.log("fail: tanque vazio");
            return;
        }
        if(this.gas < km) {
            console.log("fail: tanque vazio apos andar " + this.gas + " km");
            this.km += this.gas;
            this.gas = 0;
            return;
        }
        this.gas = this.gas - km;
        this.km = this.km + km;
    }

    toString(): string {
        return "pass: " + this.pass + ", gas: " + this.gas + ", km: " + this.km;
    }
};

export {Car};