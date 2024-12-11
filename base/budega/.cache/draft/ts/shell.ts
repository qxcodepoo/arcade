function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }

class Adapter {
    // private mercantil: Mercantil = new Mercantil(0);
    init(nCaixas: number) {
        // this.mercantil = new Mercantil(nCaixas);
    }

    arrive(nome: string): void {
        // this.mercantil.chegar(new Pessoa(nome));
    }

    call(index: number): void {
        // this.mercantil.chamar(index);
    }

    finish(index: number): void {
        // this.mercantil.finalizar(index);
    }

    show(): void {
        // console.log(this.mercantil.toString());
    }
}


function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line);
        
        let args = line.split(" ");

        if      (args[0] == "end")    { break;                             }
        else if (args[0] == "init")   { adp.init(+args[1]);                }
        else if (args[0] == "show")   { adp.show();                        }
        else if (args[0] == "arrive") { adp.arrive(args[1]);               }
        else if (args[0] == "call")   { adp.call(+args[1]);                }
        else if (args[0] == "finish") { adp.finish(+args[1]);              }
        else                          { write("fail: comando invalido");   }
    }
}
main() 
