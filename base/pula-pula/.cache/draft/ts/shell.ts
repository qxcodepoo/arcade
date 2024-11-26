
function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }

class Adapter {
    // trampoline: Trampoline = new Trampoline();
    arrive(name: string, weight: number): void {
        // this.trampoline.arrive(new Kid(name, weight));
    }

    enter(): void {
        // this.trampoline.enter();
    }

    leave(): void {
        // this.trampoline.leave();
    }

    remove(name: string): void {
        // this.trampoline.removeKid(name);
    }

    show(): void {
        // console.log(this.trampoline.toString());
    }
}

function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if      (args[0] == "end"   ) { break                                   }
        else if (args[0] == "show"  ) { adp.show();                             }
        else if (args[0] == "arrive") { adp.arrive(args[1], +args[2]);          }
        else if (args[0] == "enter" ) { adp.enter();                            }
        else if (args[0] == "leave" ) { adp.leave();                            }
        else if (args[0] == "remove") { adp.remove(args[1]);                    }
        else                          { write("fail: comando invalido");        }
    }
}

main();