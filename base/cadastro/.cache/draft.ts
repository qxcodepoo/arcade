
class AccountException extends Error {
    constructor(message: string) {
    }
}

abstract class Account {
    protected id: number;
    protected balance: number;
    protected clientId: string;
    protected type: string; // "CC" or "CP"

    constructor(id: number, clientId: string) {
    }

    abstract monthlyUpdate(): void;

    withdraw(value: number): void {
    }

    deposit(value: number): void {
    }

    transfer(other: Account, value: number): void {
    }

    toString(): string {
    }

    getId(): number {
    }

    getBalance(): number {
    }

    getClientId(): string {
    }

    getType(): string {
    }
}

class CheckingAccount extends Account {
    constructor(id: number, clientId: string) {
    }

    monthlyUpdate(): void {
    }
}

class SavingsAccount extends Account {
    constructor(id: number, clientId: string) {
    }

    monthlyUpdate(): void {
    }
}

class Client {
    private clientId: string;
    private accounts: Account[];

    constructor(clientId: string) {
    }

    addAccount(account: Account): void {
    }

    toString(): string {
    }

    getClientId(): string {
    }

    setClientId(clientId: string): void {
    }

    getAccounts(): Account[] {
    }

    setAccounts(accounts: Account[]): void {
    }
}

class BankAgency {
    private clients: Client[];
    private accounts: Account[];
    private nextAccountId: number;

    constructor() {
    }

    private getAccount(id: number): Account {
    }

    addClient(clientId: string): void {

    }

    withdraw(idConta: number, value: number): void {
    }

    deposit(idConta: number, value: number): void {
    }

    transfer(contaDe: number, contaPara: number, value: number): void {
    }

    monthlyUpdate(): void {
    }

    toString(): string {
        const clientsStr = this.clients.map(client => client.toString()).join("\n");
        const accountsStr = this.accounts.map(account => account.toString()).join("\n");
        return `- Clients\n${clientsStr}\n- Accounts\n${accountsStr}`;
    }
}


let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

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
