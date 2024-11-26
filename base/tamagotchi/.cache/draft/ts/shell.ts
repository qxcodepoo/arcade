function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    // private game: Game = new Game(new Pet(0, 0, 0));
    init(energy: number, hungry: number, clean: number) {
        // this.game = new Game(new Pet(energy, hungry, clean));
    }

    public show() {
        // console.log(this.game.toString());
    }

    public play() {
        // this.game.play();
    }

    public shower() {
        // this.game.shower();
    }

    public eat() {
        // this.game.eat();
    }
    
    public sleep() {
        // this.game.sleep();
    }
}

function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        let args = line.split(" ");
        write(line); // _TEST_ONLY_

        if      (args[0] === "end")   { break;                                 }
        else if (args[0] === "init")  { adp.init(+args[1], +args[2], +args[3]);}
        else if (args[0] === "show")  { adp.show();                            }
        else if (args[0] === "play")  { adp.play();                            }
        else if (args[0] === "eat")   { adp.eat();                             }
        else if (args[0] === "sleep") { adp.sleep();                           }
        else if (args[0] === "shower"){ adp.shower();                          }
        else                          { write("fail: comando invalido");       }
    }
}

main();
