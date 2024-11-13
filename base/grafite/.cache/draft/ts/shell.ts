import {Student} from "./student";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let adp = new Student(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if      (args[0] === "init")  { adp = new Student(+args[1]);                }
        else if (args[0] === "show")  { adp.show();                                 }
        else if (args[0] === "insert"){ adp.insert(+args[1], args[2], +args[3]);    }
        else if (args[0] === "remove"){ adp.remove();                               }
        else if (args[0] === "write") { adp.writePage();                            }
        else if (args[0] === "end")   { break;                                      }
        else                          { write("fail: comando invalido");            }
    }
}

main();