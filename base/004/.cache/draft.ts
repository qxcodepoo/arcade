
class Lead {
    private thickness: number;
    private hardness: string;
    private size: number;
    
    public constructor(calibre: number, dureza: string, tamanho: number) {
        this.thickness = calibre;
        this.hardness = dureza;
        this.size = tamanho;
    }

    public usagePerSheet(): number {
        if (this.hardness === 'HB')
            return 1;
        if (this.hardness === '2B')
            return 2;
        if (this.hardness === '4B')
            return 4;
        if (this.hardness === '6B')
            return 6;
        return 0;
    }

    public toString(): string {
        //return "Grafite: " + this.calibre + ":" + this.dureza + ":" + this.tamanho;
        return `${this.thickness}:${this.hardness}:${this.size}`;
    }

    public getThickness(): number {
        return this.thickness;
    }
    public getSize(): number {
        return this.size;
    }
    public getHardness(): string {
        return this.hardness;
    }
    public setSize(value: number): void {
        this.size = value;
    }
    public setHardness(value: string): void {
        this.hardness = value;
    }
    public setThickness(value: number): void {
        this.thickness = value;
    }
}



class Pencil { //todo
    private thickness: number;
    private tip: Lead | null;

    public constructor(thickness: number) { //todo 
    }

    public hasGrafite() { //todo
    }

    public insert(grafite: Lead): boolean { //todo
    }

    public remove(): Lead | null { //todo
    }

    writePage(): void { //todo
    }

    public toString(): string {
        return "calibre: " + this.thickness + ", grafite: " +
                (this.tip != null ? "[" + this.tip.toString() + "]" : "null");
    }

}
function main() {
    let chain = new Map();
    let param: string[] = [];
    let pencil = new Pencil(0.5);

    chain.set("show",   () => { puts(pencil.toString())                                   });
    chain.set("init",   () => { pencil = new Pencil(+(param[1]))                          });
    chain.set("insert", () => { pencil.insert(new Lead(+param[1], param[2], +param[3]))});
    chain.set("remove", () => { pencil.remove()                                           });
    chain.set("write",  () => { pencil.writePage()                                        });

    evaluate(chain, param);
}

import { readFileSync } from "fs";

let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
let write = (text: any) => process.stdout.write("" + text);
let puts = (text: any) => console.log(text);

function evaluate(chain: Map<string, Function>, ui: string[]) {
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


