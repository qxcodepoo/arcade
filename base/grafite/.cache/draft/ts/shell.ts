function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    // private pencil: Pencil;
    constructor(thickness: number) {
        // this.pencil = new Pencil(thickness);
    }

    insert(thickness: number, hardness: string, length: number) {
        // let lead = new Lead(thickness, hardness, length);
        // this.pencil.insert(lead);
    }

    remove() {
        // this.pencil.remove();
    }

    writePage() {
        // this.pencil.writePage();
    }

    show() {
        // console.log(this.pencil.toString());
    }
}


function main() {
    let adp = new Adapter(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line);
        let args = line.split(" ");

        if      (args[0] === "init")  { adp = new Adapter(+args[1]);                }
        else if (args[0] === "show")  { adp.show();                                 }
        else if (args[0] === "insert"){ adp.insert(+args[1], args[2], +args[3]);    }
        else if (args[0] === "remove"){ adp.remove();                               }
        else if (args[0] === "write") { adp.writePage();                            }
        else if (args[0] === "end")   { break;                                      }
        else                          { write("fail: comando invalido");            }
    }
}

main();
