import { Lead } from "./lead";

class Pencil {
    private thickness: number;
    private tip: Lead | null;

    public constructor(thickness: number) { 
    }

    public hasLead(): boolean {
        return false;
    }

    public insert(lead: Lead): boolean {
        return false;
    }

    public remove(): Lead | null {
        return null;
    }

    writePage(): void {
    }

    public toString(): string {
        let ponta = this.tip != null ? "[" + this.tip.toString() + "]" : "null";
        return "calibre: " + this.thickness + ", grafite: " + ponta;
    }

}

export { Pencil };