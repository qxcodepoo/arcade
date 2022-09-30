import {evaluate, puts} from "./shell"


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


//agregação
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

    public toString(): string { //todo
    }

}

function main() { //todo
    let chain = new Map();
    let param: string[] = [];
    let pencil = new Pencil(0.5);

    chain.set("show",   () => { //todo puts(pencil.toString())                                   });
    chain.set("init",   () => { //todo pencil = new Pencil(+(param[1]))                          });
    chain.set("insert", () => { //todo pencil.insert(new Lead(+param[1], param[2], +param[3]))});
    chain.set("remove", () => { //todo pencil.remove()                                           });
    chain.set("write",  () => { //todo pencil.writePage()                                        });

    evaluate(chain, param);
}

main()


