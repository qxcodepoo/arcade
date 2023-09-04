
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
    }

    public insert(lead: Lead): boolean {
    }

    public remove(): Lead | null {
    }

    public pull(): boolean {
    }

    public writePage(): void {

    }
    public toString(): string {
        let saida =  "calibre: " + this.thickness + ", bico: " +
                (this.tip != null ? "[" + this.tip + "]" : "[]") + ", tambor: {";
        for(let g of this.barrel) {
            saida += "[" + g + "]";
        }  
        saida += "}";

        return saida;
    }
}

function main() {
    let chain = new Map();
    let param: string[] = [];
    let pencil = new Pencil(0.5);

    chain.set("init",    () => { pencil = new Pencil(+(param[1]))                           });
    chain.set("insert",  () => { pencil.insert(new Lead(+param[1], param[2], +param[3]))    });
    chain.set("remove",  () => { pencil.remove()                                            });
    chain.set("pull",    () => { pencil.pull()                                              });
    chain.set("write",   () => { pencil.writePage()                                         });
    chain.set("show",    () => { console.log(pencil.toString())                             });

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