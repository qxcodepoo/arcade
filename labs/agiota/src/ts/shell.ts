const input = () => ""; // MODO_TESTE
export {};

// @DROP
enum Label {
    GIVE = "give",
    TAKE = "take",
    PLUS = "plus"
}

class Operation {
    private id: number;
    private name: string;
    private label: Label;
    private value: number;

    constructor(id: number, name: string, label: Label, value: number) {
        this.id = id;
        this.name = name;
        this.label = label;
        this.value = value;
    }

    getName(): string {
        return this.name;
    }

    getLabel(): Label {
        return this.label;
    }

    getValue(): number {
        return this.value;
    }

    str(): string {
        return `id:${this.id} ${this.label}:${this.name} ${this.value}`;
    }
}

class Client {
    private name: string;
    private limite: number;
    private operations: Operation[] = [];

    constructor(name: string, limite: number) {
        this.name = name;
        this.limite = limite;
    }

    getName(): string {
        return this.name;
    }

    getLimite(): number {
        return this.limite;
    }

    getBalance(): number {
        return this.operations.reduce((sum, op) => {
            return sum + (op.getLabel() === Label.TAKE ? -op.getValue() : op.getValue());
        }, 0);
    }

    addOperation(op: Operation): void {
        this.operations.push(op);
    }

    getOperations(): Operation[] {
        return this.operations;
    }

    str(): string {
        return `${this.name} ${this.getBalance()}/${this.limite}`;
    }
}

class Agiota {
    private aliveList: Client[] = [];
    private deathList: Client[] = [];
    private aliveOper: Operation[] = [];
    private deathOper: Operation[] = [];
    private nextOpId: number = 0;

    findClient(name: string): Client | null {
        return this.aliveList.find(cli => cli.getName() === name) || null;
    }

    private pushOperation(cli: Client, label: Label, value: number): void {
        const op = new Operation(this.nextOpId++, cli.getName(), label, value);
        this.aliveOper.push(op);
        cli.addOperation(op);
    }

    addClient(name: string, limite: number): void {
        if (this.findClient(name)) {
            console.log("fail: cliente ja existe");
            return;
        }
        this.aliveList.push(new Client(name, limite));
        this.aliveList.sort((a, b) => a.getName().localeCompare(b.getName()));
    }

    give(name: string, value: number): void {
        const cli = this.findClient(name);
        if (!cli) {
            console.log("fail: cliente nao existe");
            return;
        }
        if (cli.getBalance() + value > cli.getLimite()) {
            console.log("fail: limite excedido");
            return;
        }
        this.pushOperation(cli, Label.GIVE, value);
    }

    take(name: string, value: number): void {
        const cli = this.findClient(name);
        if (!cli) {
            console.log("fail: cliente nao existe");
            return;
        }
        this.pushOperation(cli, Label.TAKE, value);
    }

    plus(): void {
        const toDie: string[] = [];
        for (const cli of this.aliveList) {
            const increment = Math.ceil(cli.getBalance() * 0.1);
            this.pushOperation(cli, Label.PLUS, increment);
            if (cli.getBalance() > cli.getLimite()) {
                toDie.push(cli.getName());
            }
        }
        toDie.forEach(name => this.kill(name));
    }

    kill(name: string): void {
        const cli = this.findClient(name);
        if (!cli) {
            console.log("fail: cliente nao existe");
            return;
        }
        this.deathList.push(cli);
        this.aliveList = this.aliveList.filter(c => c !== cli);

        const remaining: Operation[] = [];
        for (const op of this.aliveOper) {
            if (op.getName() === name) {
                this.deathOper.push(op);
            } else {
                remaining.push(op);
            }
        }
        this.aliveOper = remaining;
    }

    str(): string {
        const sb: string[] = [];
        this.aliveList.forEach(cli => sb.push(`:) ${cli.str()}`));
        this.aliveOper.forEach(op => sb.push(`+ ${op.str()}`));
        this.deathList.forEach(cli => sb.push(`:( ${cli.str()}`));
        this.deathOper.forEach(op => sb.push(`- ${op.str()}`));
        return sb.join("\n");
    }
}

// @KEEP
function main() {
    const agiota = new Agiota(); // @DROP

    while (true) {
        const line = input(); // Assume input() is defined elsewhere
        console.log(`$${line}`);

        const parts = line.split(" ");
        const cmd = parts[0];

        if (cmd === "end") {
            break;
        } else if (cmd === "show") {
            // @DROP
            console.log(agiota.str());
        } else if (cmd === "addCli") {
            // @COM
            const name = parts[1];
            const limite = parseInt(parts[2]);
            // @DROP
            agiota.addClient(name, limite);
        } else if (cmd === "showCli") {
            // @COM
            const name = parts[1];
            // @DROP
            const cli = agiota.findClient(name);
            if (cli) {
                console.log(cli.str());
                cli.getOperations().forEach(op => console.log(op.str()));
            }
        } else if (cmd === "kill") {
            // @COM
            const name = parts[1];
            // @DROP
            agiota.kill(name);
        } else if (cmd === "give") {
            // @COM
            const name = parts[1];
            const value = parseInt(parts[2]);
            // @DROP
            agiota.give(name, value);
        } else if (cmd === "take") {
            // @COM
            const name = parts[1];
            const value = parseInt(parts[2]);
            // @DROP
            agiota.take(name, value);
        } else if (cmd === "plus") {
            // @DROP
            agiota.plus();
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
