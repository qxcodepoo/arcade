const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Bateria {
    private capacity: number;
    private charge: number;

    constructor(capacity: number) {
        this.capacity = capacity;
        this.charge = capacity;
    }

    getCapacity(): number {
        return this.capacity;
    }

    getCharge(): number {
        return this.charge;
    }

    setCharge(value: number): void {
        if (value <= 0) {
            this.charge = 0;
        } else if (value >= this.capacity) {
            this.charge = this.capacity;
        } else {
            this.charge = value;
        }
    }

    toString(): string {
        return `${this.charge}/${this.capacity}`;
    }
}

// Classe representando o carregador
class Charger {
    private power: number;

    constructor(power: number) {
        this.power = power;
    }

    getPower(): number {
        return this.power;
    }

    toString(): string {
        return `${this.power}W`;
    }
}

// Classe representando o notebook
class Notebook {
    private inUse: boolean = false;
    private usage: number = 0;
    private battery: Bateria | null = null;
    private charger: Charger | null = null;

    toString(): string {
        let status = `Notebook: `;

        if (!this.inUse) {
            status += "desligado";
        } else {
            status += `ligado por ${this.usage} min`;
        }

        if (this.charger) {
            status += `, Carregador ${this.charger}`;
        }

        if (this.battery) {
            status += `, Bateria ${this.battery}`;
        }

        return status;
    }

    turnOn(): void {
        if (this.charger || (this.battery && this.battery.getCharge() > 0)) {
            this.inUse = true;
        } else {
            console.log("fail: não foi possível ligar");
        }
    }

    turnOff(): void {
        this.inUse = false;
        this.usage = 0;
    }

    use(minutes: number): void {
        if (!this.inUse) {
            console.log("fail: desligado");
            return;
        }

        if (this.charger && !this.battery) {
            this.usage += minutes;
            return;
        }

        if (!this.charger && this.battery) {
            if (this.battery.getCharge() > minutes) {
                this.battery.setCharge(this.battery.getCharge() - minutes);
                this.usage += minutes;
            } else {
                this.battery.setCharge(this.battery.getCharge() - minutes);
                this.inUse = false;
                console.log("fail: descarregou");
            }
            return;
        }

        if (this.charger && this.battery) {
            this.usage += minutes;
            this.battery.setCharge(this.battery.getCharge() + this.charger.getPower() * minutes);
            return;
        }
    }

    setBattery(newBattery: Bateria): void {
        this.battery = newBattery;
    }

    removeBattery(): Bateria | null {
        if (!this.battery) {
            console.log("fail: Sem bateria");
            return null;
        }
        if (!this.charger && this.inUse) {
            this.inUse = false;
        }
        const removedBattery = this.battery;
        this.battery = null;
        return removedBattery;
    }

    setCharger(newCharger: Charger): void {
        if (this.charger) {
            console.log("fail: carregador já conectado");
            return;
        }
        this.charger = newCharger;
    }

    removeCharger(): Charger | null {
        if (!this.charger) {
            console.log("fail: Sem carregador");
            return null;
        }
        if (!this.battery || this.battery.getCharge() === 0) {
            this.inUse = false;
        }
        const removedCharger = this.charger;
        this.charger = null;
        return removedCharger;
    }
}

// @KEEP
function main() {
    // @DROP
    let notebook = new Notebook();
    // @KEEP
    while (true) {
        let line = input();
        console.log("$" + line);

        var par = line.split(" ");
        var cmd = par[0];

        if (cmd == "end") {
            break;
        } 
        // @COM
        else if (cmd == "show") { 
            // @DROP
            console.log(notebook.toString());
        }
        else if (cmd == "turn_on") { 
            // @DROP
            notebook.turnOn();
        }
        else if (cmd == "turn_off") { 
            // @DROP
            notebook.turnOff();
        }
        else if (cmd == "use") { 
            const minutes = parseInt(par[1]);
            // @DROP
            notebook.use(minutes);
        }else if (cmd == "set_charger") {
            // CRIE UM CARREGADOR COM A POTÊNCIA INFORMADA E CONECTE AO NOTEBOOK
            const power = parseInt(par[1]);
            // @DROP
            notebook.setCharger(new Charger(power));
        }
        else if (cmd == "rm_charger") {
            // REMOVA O CARREGADOR DO NOTEBOOK E O IMPRIMA
            // @DROP
            const removedCharger = notebook.removeCharger();
            if (removedCharger) {
                console.log(`Removido ${removedCharger}`);
            }
        } 
        else if (cmd == "set_battery") {
            // CRIE UMA BATERIA COM A CAPACIDADE INFORMADA E CONECTE AO NOTEBOOK
            const capacity = parseInt(par[1]);
            // @DROP
            notebook.setBattery(new Bateria(capacity));
        } 
        else if (cmd == "rm_battery") {
            // REMOVA A BATERIA DO NOTEBOOK E A IMPRIMA
            // @DROP
            const removedBattery = notebook.removeBattery();
            if (removedBattery) {
                console.log(`Removido ${removedBattery}`);
            }
        } 
        // @KEEP
        else {
            console.log("fail: comando inválido");
        }
    }
}

main();
