
class Label {
    public static readonly DEPOSIT  = new Label('deposit');
    public static readonly FEE      = new Label('fee');
    public static readonly OPENING  = new Label('opening');
    public static readonly REVERSE  = new Label('reverse');
    public static readonly WITHDRAW = new Label('withdraw');
    public static readonly ERROR    = new Label('error');

    private name: string;

    private constructor(name: string) {
    }

    public getName(): string {
    }

    public toString(): string {
    }
}

class Operation {
    private index: number;
    private label: Label;
    private value: number;
    private balance: number;

    constructor(index: number, label: Label, value: number, balance: number) {

    }

    
    public getBalance(): number {
    }

    public getIndex(): number {
    }

    public getLabel(): Label {
    }

    public getValue(): number {
    }

    public toString(): string {
    }
}

class BalanceManager {

    private balance: number;
    private extract: Array<Operation>;
    private nextId: number;

    constructor() {
    }

    public addOperation(label: Label, value: number) {
    }

    public getOperation(index: number): Operation {
    }


    public getExtract(qtdOp: number): Operation[] {

    }

    public getBalance(): number {
    }
}


class Account {
    private balanceManager: BalanceManager;
    private id: number;

    constructor(id: number) {
    }
    public deposit(label: Label, value: number): boolean {
        if (value < 0) {
            console.log("fail: invalid value");
            return false;
        }
        this.balanceManager.addOperation(label, value);
        return true;
    }
    public fee(value: number): boolean {
    }

    public reverse(index: number): void {

    }

    public withdraw(value: number): boolean {

    }

    public toString(): string {
    }

    public getBalanceManager(): BalanceManager {
    }
}




function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let account = new Account(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if (args[0] == "end") { break; }
        else if (args[0] == "init") { account = new Account(+args[1]); }
        else if (args[0] == "show") { write(account); }
        else if (args[0] == "withdraw") { account.withdraw(+args[1]); }
        else if (args[0] == "fee") { account.fee(+args[1]) }
        else if (args[0] == "reverse") {
            for (let i = 1; i < args.length; i++) {
                account.reverse(+args[i]);
            }
        }
        else if (args[0] == "deposit") { account.deposit(Label.DEPOSIT, +args[1]); }
        else if (args[0] == "extract") { write(account.getBalanceManager().getExtract(+args[1]).join("\n")); }
        else { write("fail: invalid command"); }
    }
}

main()