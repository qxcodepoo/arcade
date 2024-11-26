class Adapter {
    // calc: Calculator = new Calculator(0);
    public init(batteryMax: number): void {
        // this.calc = new Calculator(batteryMax);
    }

    public show(): void {
        // console.log(this.calc.toString());
    }

    public charge(value: number): void {
        // this.calc.chargeBattery(value);
    }

    public sum(a: number, b: number): void {
        // this.calc.sum(a, b);
    }

    public div(a: number, b: number): void {
        // this.calc.division(a, b);
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
        write(line); // _TEST_ONLY_
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
