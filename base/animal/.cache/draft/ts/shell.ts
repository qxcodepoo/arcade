import { Adapter } from "./student";

// function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); }
function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() }
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }


function main(): void {
    let adp: Adapter = new Adapter("", "");

    while (true) {
        write("$", "");
        const line: string = input();
        const args: string[] = line.split(' ');
        write(line); //_TEST_ONLY_

        if      (args[0] === "end"  ) { break;                               }

        else if (args[0] === "init" ) { adp = new Adapter(args[1], args[2]); }
        else if (args[0] === "grow" ) { adp.grow(parseInt(args[1]));         }
        else if (args[0] === "noise") { adp.noise();                  }
        else if (args[0] === "show" ) { adp.show();                   }

        else                          { write("fail: comando invalido");     }
    }
}

main();
