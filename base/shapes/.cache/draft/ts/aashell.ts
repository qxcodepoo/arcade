import { Adapter } from "./adapter";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "show")  { console.log(adp.toString())                                  }   
        else if (args[0] === "circle") {
            adp.circle(+args[1], +args[2], +args[3]);
        }
        else if (args[0] === "rect") {
            adp.rectange(+args[1], +args[2], +args[3], +args[4]);
        }
        else if (args[0] === "info") {
            console.log(adp.info());
        }
        else {
            write("fail: invalid command");
        }
    }
}

main();