function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    // motoca: Motoca = new Motoca(1);
    init(potencia: number): void {
        // this.motoca = new Motoca(potencia);
    }

    enter(name: string, age: number): void {
        // this.motoca.inserir(new Pessoa(name, age))
    }

    leave(): void {
        // let pessoa = this.motoca.remover();
        // if (pessoa === null) {
        //     console.log("---");
        // } else {
        //     console.log(pessoa.toString());
        // }
    }

    honk(): void {
        // console.log(this.motoca.buzinar());
    }

    drive(time: number): void {
        // this.motoca.dirigir(time);
    }

    buy(time: number): void {
        // this.motoca.aumentarTempo(time);
    }
    
    show(): void {
        // console.log(this.motoca.toString());
    }
}


function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                          }
        
        else if (args[0] === "show")  { adp.show();                     }
        else if (args[0] === "init")  { adp.init(+args[1]);             }
        else if (args[0] === "enter") { adp.enter(args[1], +args[2]);   }
        else if (args[0] === "leave") { adp.leave();                    }
        else if (args[0] === "honk")  { adp.honk();                     }
        else if (args[0] === "buy")   { adp.buy(+args[1]);              }
        else if (args[0] === "drive") { adp.drive(+args[1]);            }

        else                          { write("fail: comando invalido");}
    }
}

main()