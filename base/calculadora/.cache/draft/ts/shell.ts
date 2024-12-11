class Adapter {
    public init(batteryMax: number): void {
    }

    public show(): void {
    }

    public charge(value: number): void {
    }

    public sum(a: number, b: number): void {
    }

    public div(a: number, b: number): void {
    }
}


function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }

function main() {
    let adp: Adapter = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line);
        let args = line.split(" ");

        if      (args[0] == "show"  ) { adp.show();                                  }
        else if (args[0] == "init"  ) { adp.init(+args[1]);                          }
        else if (args[0] == "charge") { adp.charge(+args[1]);                        }
        else if (args[0] == "sum"   ) { adp.sum(+args[1], +args[2]);                 }
        else if (args[0] == "div"   ) { adp.div(+args[1], +args[2]);                 }
        else if (args[0] == "end"   ) { break;                                       }
        else                          { console.log("fail: comando nao encontrado"); }
    }
}

main()
