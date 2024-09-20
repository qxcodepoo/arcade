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

        if (args[0] == "end") { break; }
        else if (args[0] == "init") { adp = new Adapter(+args[1]); }
        else if (args[0] == "show") { adp.show(); }
        else if (args[0] == "withdraw") { adp.withdraw(+args[1]); }
        else if (args[0] == "fee") { adp.fee(+args[1]) }
        else if (args[0] == "reverse") {
            for (let i = 1; i < args.length; i++) {
                adp.reverse(+args[i]);
            }
        }
        else if (args[0] == "deposit") { adp.deposit(+args[1]); }
        else if (args[0] == "extract") { adp.extract(+args[1]); }
        else { write("fail: invalid command"); }
    }
}

main()