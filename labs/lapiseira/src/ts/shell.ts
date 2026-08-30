const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Lead {
    private thickness: number;
    private hardness: string;
    private size: number;

    public constructor(calibre: number, dureza:string, tamanho: number) {
        this.thickness = calibre;
        this.hardness = dureza;
        this.size = tamanho;
    }

    public toString(): string {
        return `${this.thickness}:${this.hardness}:${this.size}`;
    }

    public usagePerSheet(): number {
        if (this.hardness === 'HB')
            return 1;
        if (this.hardness === '2B')
            return 2;
        if (this.hardness === '4B')
            return 4;
        return 6;
    }

    public getThickness(): number {
        return this.thickness;
    }

    public getHardness(): string {
        return this.hardness;
    }

    public getSize(): number {
        return this.size;
    }

    public setSize(size: number): void {
        this.size = size;
    }
}


class Pencil {
    private thickness: number;
    private tip: Lead | null; //lead da ponta
    private barrel: Array<Lead> = new Array<Lead>(); //grafites no cano

    public constructor(thickness: number) {
        this.thickness = thickness;
    }

    public insert(lead: Lead): boolean {
        if(this.thickness != lead.getThickness()) {
            console.log("fail: calibre incompatível");
            return false;
        }
        this.barrel.push(lead);
        return true;
    }

    public remove(): Lead | null {
        if(this.tip == null) {
            console.log("fail; nao existe grafite no bico");
            return null;
        }
        let backup = this.tip;
        this.tip = null;
        return backup;
    }

    public pull(): boolean {
        if (this.tip != null) {
            console.log("fail: ja existe grafite no bico");
            return false;
        }
        if (this.barrel.length == 0) {
            console.log("fail: nao existe grafite no barril");
            return false;
        }
        this.tip = this.barrel.shift()!;
        return true;
    }

    public writePage(): void {
        if (this.tip == null) {
            console.log("fail: nao existe grafite no bico");
            return;
        }
        if (this.tip.getSize() == 10) {
            console.log("fail: tamanho insuficiente");
            return;
        }
        let finalSize = this.tip.getSize() - this.tip.usagePerSheet();

        if (finalSize >= 10) {
            this.tip.setSize(finalSize);
        } else {
            this.tip.setSize(10);
            console.log("fail: folha incompleta");
        }
    }

    public toString(): string {
        let saida =  "calibre: " + this.thickness + ", bico: " +
                (this.tip != null ? "[" + this.tip + "]" : "[]") + ", tambor: <";
        for(let g of this.barrel) {
            saida += "[" + g + "]";
        }  
        saida += ">";

        return saida;
    }
}

// @KEEP
function main() {
    // @DROP
    let pencil = new Pencil(0);
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd === "end") {
            break;
        }
        else if (cmd === "show") { 
            // @DROP
            console.log(pencil.toString());
        }
        else if (cmd === "init") { 
            // @COM
            const thickness = parseFloat(par[1]);
            // @DROP
            pencil = new Pencil(thickness);
        }
        else if (cmd === "insert") { 
            // @COM
            const thickness = parseFloat(par[1]);
            const hardness = par[2];
            const size = parseInt(par[3]);
            // @DROP
            pencil.insert(new Lead(thickness, hardness, size));
        }
        else if (cmd === "remove") { 
            // @DROP
            pencil.remove();
        }
        else if (cmd === "write") { 
            // @DROP
            pencil.writePage();
        }
        else if (cmd === "pull") { 
            // @DROP
            pencil.pull();
        }
        else {
            console.log("fail: comando invalido");
        }
    }
}

main();