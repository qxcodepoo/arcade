import { Adapter } from "./adapter";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let adp = new Adapter(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "init")  { adp = new Adapter(Number(args[1]));                          }
        else if (args[0] === "show")  { write(adp.toString());                                       }
        else if (args[0] === "addItem")   { adp.addItem(args[1], +args[2]);                          }
        else if (args[0] === "addCoin")   { adp.addCoin(+args[1]);
        }
        else if (args[0] === "extractItems") { 
            write(adp.extractItems());
        }
        else if (args[0] === "extractCoins") { 
            write(adp.extractCoins());
        }
        else if (args[0] === "break")    { adp.breakPig();                                           }
        else                             { write("fail: comando invalido");                          }
    }
}

main();