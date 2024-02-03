class Car{
    private pass: number; // Passageiros
    private passMax: number; // limite de Passageiros
    private gas: number; // tanque
    private gasMax: number; // limite do tanque
    private km: number; // quantidade de quilometragem

    constructor() {
    }

    public setPass(pass: number): void {
    }
    
    public setGas(gas: number): void {
    }

    public setKm(km: number): void {
    }

    public getGas(): number {
    }
    public getKm(): number {
    }
    public getPass(): number {
    }

    public enter() {
        this.setPass(this.pass + 1);
    }

    public leave() {
        this.setPass(this.pass - 1);  
    }

    public fuel(gas: number) {
        this.setGas(this.gas + gas);
    }

    public drive (km: number) {
        if(this.pass == 0) {
            puts("fail: nao ha ninguem no carro");
        } else if(this.gas == 0) {
            puts("fail: tanque vazio");
        } else if(this.gas < km) {
            puts("fail: tanque vazio apos andar " + this.gas + " km");
            this.setKm(this.km + this.gas);
            this.gas = 0;
        } else {
            this.gas = this.gas - km;
            this.km = this.km + km;
        }
    }    

    public toString() {
        return "pass: " + this.pass + ", gas: " + this.gas + ", km: " + this.km;
    }
};


function main() {
    let chain = new Map();
    let param = [];
    let car = new Car();

    chain.set("enter",      () => car.enter());
    chain.set("leave",      () => car.leave());
    chain.set("show",       () => puts(car.toString()));
    chain.set("drive",      () => car.drive(+param[1]));
    chain.set("fuel",       () => car.fuel(+param[1]));
    chain.set("help",       () => puts("show, enter, leave, drive, fuel, help, end"));

    evaluate(chain, param);
}

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

export function evaluate(chain: Map<string, Function>, ui: string[]) {
    while (true) {
        let line = input();
        puts("$" + line);
        ui.splice(0); //apagar tudo
        line.split(" ").forEach((x: string) => ui.push(x));

        let cmd = ui[0];
        if (cmd == "end") {
            return;
        } else if (chain.has(cmd)) {
            chain.get(cmd)!();
        } else {
            puts("fail: command not found");
        }
    }
}

main()

