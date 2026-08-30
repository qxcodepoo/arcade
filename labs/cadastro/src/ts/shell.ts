const input = () => ""; // MODO_TESTE
export {};

// @DROP

class AccountException extends Error {
    constructor(message: string) {
        super(message);
        this.name = "AccountException";
    }
}

abstract class Account {
    protected id: number;
    protected balance: number;
    protected clientId: string;
    protected type: string; // "CC" or "CP"

    constructor(id: number, clientId: string) {
        this.id = id;
        this.clientId = clientId;
        this.balance = 0;
    }

    abstract monthlyUpdate(): void;

    withdraw(value: number): void {
        if (this.balance >= value) {
            this.balance -= value;
        } else {
            throw new AccountException("fail: saldo insuficiente");
        }
    }

    deposit(value: number): void {
        this.balance += value;
    }

    transfer(other: Account, value: number): void {
        this.withdraw(value);
        other.deposit(value);
    }

    toString(): string {
        return `${this.id}:${this.clientId}:${this.balance.toFixed(2)}:${this.type}`;
    }

    getId(): number {
        return this.id;
    }

    getBalance(): number {
        return this.balance;
    }

    getClientId(): string {
        return this.clientId;
    }

    getType(): string {
        return this.type;
    }
}

class CheckingAccount extends Account {
    constructor(id: number, clientId: string) {
        super(id, clientId);
        this.type = "CC";
    }

    monthlyUpdate(): void {
        this.balance -= 20;
    }
}

class SavingsAccount extends Account {
    constructor(id: number, clientId: string) {
        super(id, clientId);
        this.type = "CP";
    }

    monthlyUpdate(): void {
        this.balance *= 1.01;
    }
}

class Client {
    private clientId: string;
    private accounts: Account[];

    constructor(clientId: string) {
        this.clientId = clientId;
        this.accounts = [];
    }

    addAccount(account: Account): void {
        if (!this.accounts.find(acc => acc.getId() === account.getId())) {
            this.accounts.push(account);
        }
    }

    toString(): string {
        const accountIds = this.accounts.map(account => `${account.getId()}`).join(", ");
        return `${this.clientId} [${accountIds}]`;
    }

    getClientId(): string {
        return this.clientId;
    }

    setClientId(clientId: string): void {
        this.clientId = clientId;
    }

    getAccounts(): Account[] {
        return this.accounts;
    }

    setAccounts(accounts: Account[]): void {
        this.accounts = accounts;
    }
}

class BankAgency {
    private clients: Client[];
    private accounts: Account[];
    private nextAccountId: number;

    constructor() {
        this.clients = [];
        this.accounts = [];
        this.nextAccountId = 0;
    }

    private getAccount(id: number): Account {
        const account = this.accounts.find(acc => acc.getId() === id);
        if (!account) {
            throw new AccountException("fail: conta nao encontrada");
        }
        return account;
    }

    addClient(clientId: string): void {
        if (!this.clients.find(client => client.getClientId() === clientId)) {
            const client = new Client(clientId);
            const cc = new CheckingAccount(this.nextAccountId++, clientId);
            const cp = new SavingsAccount(this.nextAccountId++, clientId);

            this.accounts.push(cc, cp);
            client.addAccount(cc);
            client.addAccount(cp);
            this.clients.push(client);
        }
    }

    withdraw(idConta: number, value: number): void {
        this.getAccount(idConta).withdraw(value);
    }

    deposit(idConta: number, value: number): void {
        this.getAccount(idConta).deposit(value);
    }

    transfer(contaDe: number, contaPara: number, value: number): void {
        const fromAccount = this.getAccount(contaDe);
        const toAccount = this.getAccount(contaPara);
        fromAccount.transfer(toAccount, value);
    }

    monthlyUpdate(): void {
        this.accounts.forEach(acc => acc.monthlyUpdate());
    }

    toString(): string {
        const clientsStr = this.clients.map(client => client.toString()).join("\n");
        const accountsStr = this.accounts.map(account => account.toString()).join("\n");
        return `- Clients\n${clientsStr}\n- Accounts\n${accountsStr}`;
    }
}

// @KEEP

function main(): void {
    let agency = new BankAgency(); // @DROP
    while (true) {
        try {
            const line = input();
            const args = line.split(" ");
            console.log("$" + line);

            if (line === "end") {
                break;
            } else if (args[0] === "show") {
                // @DROP
                console.log("" + agency);
            } else if (args[0] === "addCli") {
                // @COM
                const clientId = args[1];
                // @DROP
                agency.addClient(clientId);
            } else if (args[0] === "saque") {
                // @COM
                const idConta = +args[1];
                const value = +args[2];
                // @DROP
                agency.withdraw(idConta, value);
            } else if (args[0] === "deposito") {
                // @COM
                const idConta = +args[1];
                const value = +args[2];
                // @DROP
                agency.deposit(idConta, value);
            } else if (args[0] === "transf") {
                // @COM
                const idContaDe = +args[1];
                const idContaPara = +args[2];
                const value = +args[3];
                // @DROP
                agency.transfer(idContaDe, idContaPara, value);
            } else if (args[0] === "update") {
                // @DROP
                agency.monthlyUpdate();
            } else {
                console.log("fail: comando invalido");
            }
        } catch (e) {
            console.log(e.message);
        }
    }
}

main();
