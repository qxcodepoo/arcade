function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
//function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    // animal: Animal = new Animal("", "");
    init(especie: string, barulho: string): void {
        // this.animal = new Animal(especie, barulho);
    }

    grow(qtd: number): void {
        // this.animal.envelhecer(qtd);
    }

    noise(): void {
        // console.log(this.animal.fazerBarulho());
    }

    // mostra a representação do animal como texto
    // no formato "{especie}:{estagio}:{barulho}"
    show(): void {
        // console.log(this.animal.toString());
    }
}


function main(): void {
    let adp: Adapter = new Adapter();

    while (true) {
        write("$", "");
        const line: string = input();
        const args: string[] = line.split(' ');
        write(line); //_TEST_ONLY_

        if      (args[0] === "end"  ) { break;                               }

        else if (args[0] === "init" ) { adp.init(args[1], args[2]); }
        else if (args[0] === "grow" ) { adp.grow(parseInt(args[1]));         }
        else if (args[0] === "noise") { adp.noise();                         }
        else if (args[0] === "show" ) { adp.show();                          }

        else                          { write("fail: comando invalido");     }
    }
}

main();
