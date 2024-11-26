function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    // relogio: Time;

    constructor(hour: number = 0, minute: number = 0, second: number = 0) {
        // this.relogio = new Time(hour, minute, second);
    }

    setHour(hour: number): void {
        // this.relogio.setHour(hour);
    }

    setMinute(minute: number): void {
        // this.relogio.setMinute(minute);
    }

    setSecond(second: number): void {
        // this.relogio.setSecond(second);
    }

    nextSecond(): void {
        // this.relogio.nextSecond();
    }

    show(): void {
        // console.log(this.relogio.toString());
    }
}


function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if (args[0] === "show") { 
            adp.show();
        }
        else if (args[0] == "init") { 
            adp = new Adapter(+args[1], +args[2], +args[3]);
        }
        else if (args[0] === "set") { 
            adp.setHour(+args[1]);
            adp.setMinute(+args[2]);
            adp.setSecond(+args[3]);
        }
        else if (args[0] === "next") {
            adp.nextSecond();
        }
        else if (args[0] === "end")   {
            break;
        }
        else {
            write("fail: comando invalido");
        }
    }
}

main()
