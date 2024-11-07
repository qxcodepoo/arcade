import { Student } from "./student";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let game = new Student(0, 0, 0);

    while (true) {
        write("$", "");
        let line = input();
        let args = line.split(" ");
        write(line); // _TEST_ONLY_

        if      (args[0] === "end")   { break;                                                      }
        else if (args[0] === "init")  { game = new Student(+args[1], +args[2], +args[3]);           }
        else if (args[0] === "show")  { game.show();                                                }
        else if (args[0] === "play")  { game.play();                                                }
        else if (args[0] === "eat")   { game.eat();                                                 }
        else if (args[0] === "sleep") { game.sleep();                                               }
        else if (args[0] === "shower"){ game.shower();                                              }
        else                          { write("fail: comando invalido");                            }
    }
}

main();