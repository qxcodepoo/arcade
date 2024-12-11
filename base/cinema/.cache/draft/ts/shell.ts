function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }

class Adapter {
    init(capacity: number) {
    }

    reserve(id: string, phone: number, ind: number): void {
    }

    cancel(id: string): void {
    }

    show(): void {
    }

}


function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line);
        let args = line.split(" ");

        if      (args[0] == "end")     { break; }
        else if (args[0] == "init")    { adp.init(+args[1]); }
        else if (args[0] == "show")    { adp.show(); }
        else if (args[0] == "reserve") { adp.reserve(args[1], +args[2], +args[3]); }
        else if (args[0] == "cancel")  { adp.cancel(args[1]); }
        else                           { console.log("fail: comando invalido"); }
    }
}



main();