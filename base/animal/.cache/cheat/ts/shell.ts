import { Adapter } from "./student";

function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};


function main(): void {
    let adp: Adapter = new Adapter("", "");

    while (true) {
        write("$", "");
        const line: string = input();
        const args: string[] = line.split(' ');

        if      (args[0] === "end"  ) { break;                               }

        else if (args[0] === "init" ) { adp = new Adapter(args[1], args[2]); }
        else if (args[0] === "grow" ) { adp.grow(parseInt(args[1]));         }
        else if (args[0] === "noise") { adp.noise();                         }
        else if (args[0] === "show" ) { adp.show();                          }

        else                          { write("fail: comando invalido");     }
    }
}

main();