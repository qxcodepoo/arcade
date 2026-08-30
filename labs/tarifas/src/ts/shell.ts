const input = () => ""; // MODO_TESTE
export { };

// @DROP
class Label {
    public static readonly DEPOSIT = new Label("deposit");
    public static readonly FEE = new Label("fee");
    public static readonly OPENING = new Label("opening");
    public static readonly REVERSE = new Label("reverse");
    public static readonly WITHDRAW = new Label("withdraw");
    public static readonly ERROR = new Label("error");

    private name: string;

    private constructor(name: string) {
        this.name = name;
    }

    public getName(): string {
        return this.name;
    }

    public toString(): string {
        return this.name;
    }
}

class Operation {
    private index: number;
    private label: Label;
    private value: number;
    private balance: number;

    constructor(index: number, label: Label, value: number, balance: number) {
        this.index = index;
        this.label = label;
        this.value = value;
        this.balance = balance;
    }

    public getBalance(): number {
        return this.balance;
    }

    public getIndex(): number {
        return this.index;
    }

    public getLabel(): Label {
        return this.label;
    }

    public getValue(): number {
        return this.value;
    }

    public toString(): string {
        let pad = (value: any, length: number) =>
            String(value).padStart(length, " ");
        return (
            pad(this.index, 2) +
            ":" +
            pad(this.label, 9) +
            ":" +
            pad(this.value, 5) +
            ":" +
            pad(this.balance, 5)
        );
    }
}

class BalanceManager {
    private balance: number;
    private extract: Array<Operation>;
    private nextId: number;

    constructor() {
        this.balance = 0;
        this.nextId = 0;
        this.extract = new Array<Operation>();
    }

    public addOperation(label: Label, value: number) {
        this.balance += value;
        this.extract.push(new Operation(this.nextId, label, value, this.balance));
        this.nextId++;
    }

    public getOperation(index: number): Operation {
        if (index < 0 || index > this.extract.length) {
            return new Operation(-1, Label.ERROR, 0, 0);
        }
        return this.extract[index];
    }

    public getExtract(qtdOp: number): Operation[] {
        let init = 0;

        if (qtdOp > 0) {
            init = this.extract.length - qtdOp;
            if (init < 0) {
                init = 0;
            }
        }
        return this.extract.slice(init, this.extract.length);
    }

    public getBalance(): number {
        return this.balance;
    }
}

class Account {
    private balanceManager: BalanceManager;
    private id: number;

    constructor(id: number) {
        this.balanceManager = new BalanceManager();
        this.balanceManager.addOperation(Label.OPENING, 0);
        this.id = id;
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
        this.balanceManager.addOperation(Label.FEE, -value);
        return true;
    }

    public reverse(index: number): void {
        let op = this.balanceManager.getOperation(index);
        if (op.getLabel() == Label.ERROR) {
            console.log("fail: index " + index + " invalid");
            return;
        }
        if (op.getLabel() != Label.FEE) {
            console.log("fail: index " + index + " is not a fee");
            return;
        }

        this.balanceManager.addOperation(Label.REVERSE, -op.getValue());
    }

    public withdraw(value: number): boolean {
        if (value < 0) {
            console.log("fail: invalid value");
            return false;
        }
        if (value > this.balanceManager.getBalance()) {
            console.log("fail: insufficient balance");
            return false;
        }

        this.balanceManager.addOperation(Label.WITHDRAW, -value);
        return true;
    }

    public toString(): string {
        return (
            "account:" + this.id + " balance:" + this.balanceManager.getBalance()
        );
    }

    public getBalanceManager(): BalanceManager {
        return this.balanceManager;
    }
}

// @KEEP
function main() {
    let account = new Account(0); // @DROP

    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");

        if (args[0] == "end") {
            break;
        } else if (args[0] == "init") {
            const id = parseInt(args[1]);
            // @DROP
            account = new Account(id);
        } else if (args[0] == "show") {
            // @DROP
            console.log(account.toString());
        } else if (args[0] == "withdraw") {
            const value = parseInt(args[1]);
            // @DROP
            account.withdraw(value);
        } else if (args[0] == "fee") {
            const value = parseInt(args[1]);
            // @DROP
            account.fee(value);
        } else if (args[0] == "reverse") {
            for (let i = 1; i < args.length; i++) {
                account.reverse(+args[i]); // @DROP
            }
        } else if (args[0] == "deposit") {
            const value = parseInt(args[1]);
            // @DROP
            account.deposit(Label.DEPOSIT, value);
        } else if (args[0] == "extract") {
            const qtdOp = parseInt(args[1]);
            // @DROP
            console.log(account.getBalanceManager().getExtract(qtdOp).join("\n"));
        } else {
            console.log("fail: invalid command");
        }
    }
}

main();
