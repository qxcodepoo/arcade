class Lead {
    private thickness: number;
    private hardness: string;
    private size: number;
    
    
    public constructor(thickness: number, hardness: string, size: number) {
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
    }

    public getThickness(): number {
    }
    public getSize(): number {
    }
    public getHardness(): string {
    }
    public setSize(value: number): void {
    }
    public setHardness(value: string): void {
    }
    public setThickness(value: number): void {
    }
}



class Pencil {
    private thickness: number;
    private tip: Lead | null;

    public constructor(thickness: number) { 
    }

    public hasLead(): boolean {
    }

    public insert(lead: Lead): boolean {
    }

    public remove(): Lead | null {
    }

    writePage(): void {
    }

    public toString(): string {
        let ponta = this.tip != null ? "[" + this.tip.toString() + "]" : "null";
        return "calibre: " + this.thickness + ", grafite: " + ponta;
    }

}

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let pencil = new Pencil(0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "init")  { pencil = new Pencil(+args[1]);                                    }
        else if (args[0] === "show")  { write(pencil.toString());                                         }
        else if (args[0] === "insert"){ pencil.insert(new Lead(+args[1], args[2], +args[3]));             }
        else if (args[0] === "remove"){ pencil.remove();                                                  }
        else if (args[0] === "write") { pencil.writePage();                                               }
        else if (args[0] === "end")   { break;                                                            }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();


