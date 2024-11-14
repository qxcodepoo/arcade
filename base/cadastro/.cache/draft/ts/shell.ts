
function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main(): void {
    let agency = new BankAgency();
    while (true) {
        try {
            const line = input();
            const args = line.split(" ");
            write("$" + line);

            if (line === "end") {
                break;
            } else if (args[0] === "show") {
                write("" + agency);
            } else if (args[0] === "addCli") {
                agency.addClient(args[1]);
            } else if (args[0] === "saque") {
                agency.withdraw(+args[1], +args[2]);
            } else if (args[0] === "deposito") {
                agency.deposit(+args[1], +args[2]);
            } else if (args[0] === "transf") {
                agency.transfer(+args[1], +args[2], +args[3]);
            } else if (args[0] === "update") {
                agency.monthlyUpdate();
            } else {
                write("fail: comando invalido");
            }
        } catch (e) {
            write(e.message);
        }
    }
}

main();
