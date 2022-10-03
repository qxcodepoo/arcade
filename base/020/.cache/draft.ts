
class Lead { //todo
    private thickness: number;
    private hardness: string;
    private size: number;

    public constructor(calibre: number, dureza:string, tamanho: number) { //todo
    }

    public toString(): string { //todo

    }

    public usagePerSheet(): number { //todo
    }

    public getThickness(): number { //todo
    }

    public getHardness(): string { //todo
    }

    public getSize(): number { //todo
    }

    public setSize(size: number): void { //todo
    }
}

class Pencil { //todo
    private thickness: number;
    private tip: Lead | null; //lead da ponta
    private barrel: Array<Lead> = new Array<Lead>(); //grafites no cano

    public constructor(thickness: number) { //todo
    }

    public toString(): string { //todo


    }

    //insere um lead no barril
    public insert(lead: Lead): boolean { //todo
    }

    //remove e retorna o lead da ponta
    public remove(): Lead | null { //todo
    }

    //se a ponta estiver vazia, puxa o próximo lead do barril
    public pull(): boolean { //todo
    }

    //se tiver grafite suficiente no bico, gaste e retorn true
    //lembre que os últimos 10mm não podem ser utilizados
    public writePage(): void { //todo

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

import { readFileSync } from "fs";

let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
export let write = (text: any) => process.stdout.write("" + text);
export let puts = (text: any) => console.log(text);

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