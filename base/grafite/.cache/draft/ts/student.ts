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

class Student {
    // private pencil: Pencil;
    constructor(thickness: number) {
        // this.pencil = new Pencil(thickness);
    }

    insert(thickness: number, hardness: string, length: number) {
        // let lead = new Lead(thickness, hardness, length);
        // this.pencil.insert(lead);
    }

    remove() {
        // this.pencil.remove();
    }

    writePage() {
        // this.pencil.writePage();
    }

    show() {
        // console.log(this.pencil.toString());
    }
}

export {Student};