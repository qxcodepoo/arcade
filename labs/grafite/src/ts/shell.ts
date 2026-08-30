function input() { return ""; }
export {};

// @DROP
class Lead {
    private thickness: number;
    private hardness: string;
    private size: number;
    
    
    public constructor(thickness: number, hardness: string, size: number) {
        this.thickness = thickness;
        this.hardness = hardness;
        this.size = size;
    }
    public usagePerSheet(): number {
        if (this.hardness === 'HB') {
            return 1;
        } else if (this.hardness === '2B') {
            return 2;
        } else if (this.hardness === '4B') {
            return 4;
        } else if (this.hardness === '6B') {
            return 6;
        }
        return 0;
    }
    public toString(): string {
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

class Pencil {
    private thickness: number;
    private tip: Lead | null;

    public constructor(thickness: number) { 
        this.thickness = thickness;
        this.tip = null;
    }

    public hasLead(): boolean {
        return this.tip != null;
    }

    public insert(lead: Lead): boolean {
        if (this.tip != null) {
            console.log("fail: ja existe grafite");
            return false;
        }
        if (lead.getThickness() != this.thickness) {
            console.log("fail: calibre incompativel");
            return false;
        }
        this.tip = lead;
        return true;
    }

    public remove(): Lead | null {
        if (this.tip == null) {
            console.log("fail: nao existe grafite");
            return null;
        }
        let grafite = this.tip;
        this.tip = null;
        return grafite;
    }

    writePage(): void {
        if (this.tip == null) {
            console.log("fail: nao existe grafite");
            return;
        }
        if (this.tip.getSize() <= 10) {
            console.log("fail: tamanho insuficiente");
            return;
        }
        if (this.tip.getSize() - this.tip.usagePerSheet() < 10) {
            this.tip.setSize(10);
            console.log("fail: folha incompleta");
            return;
        }
        this.tip.setSize(this.tip.getSize() - this.tip.usagePerSheet());
    }

    public toString(): string {
        let ponta = this.tip != null ? "[" + this.tip.toString() + "]" : "null";
        return "calibre: " + this.thickness + ", grafite: " + ponta;
    }

}

// @KEEP
function main() {
    // @DROP
    let pencil = new Pencil(0.5);
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        // @COM
        else if (cmd == "init") { 
            const thickness = parseFloat(par[1]);
            // @DROP
            pencil = new Pencil(thickness);
        }
        else if (cmd == "show") { 
            // @DROP
            console.log(pencil.toString());
        }
        else if (cmd == "insert") { 
            const thickness = parseFloat(par[1]);
            const hardness = par[2];
            const size = parseInt(par[3]);
            // @DROP
            const lead = new Lead(thickness, hardness, size);
            pencil.insert(lead);
        }
        else if (cmd == "remove") { 
            // @DROP
            pencil.remove();
        }
        else if (cmd == "write") { 
            // @DROP
            pencil.writePage();
        }
        // @KEEP
        else {
            console.log("fail: comando invalido");
        }
    }
}

main();
