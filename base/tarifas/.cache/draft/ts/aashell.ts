import { Adapter } from "./adapter";

import { readFileSync } from "fs";
let _cin_ = readFileSync(0).toString().split(/\r?\n/);
let input = () => _cin_[0] == undefined ? "" : _cin_.shift()!;
let write = (text: any, end="\n") => process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter(0);

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if (args[0] == "end") { break; }
        else if (args[0] == "init") { adp = new Adapter(+args[1]); }
        else if (args[0] == "show") { write(adp.toString()); }
        else if (args[0] == "withdraw") { adp.withdraw(+args[1]); }
        else if (args[0] == "fee") { adp.fee(+args[1]) }
        else if (args[0] == "reverse") {
            for (let i = 1; i < args.length; i++) {
                adp.reverse(+args[i]);
            }
        }
        else if (args[0] == "deposit") { adp.deposit(Label.DEPOSIT, +args[1]); }
        else if (args[0] == "extract") { write(account.getBalanceManager().getExtract(+args[1]).join("\n")); }
        else { write("fail: invalid command"); }
    }
}

main()