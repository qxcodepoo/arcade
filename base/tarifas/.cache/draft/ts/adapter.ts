
class Adapter {
    private account: Account;

    constructor(id: number) {
        this.account = new Account(id);
    }

    public deposit(value: number): void {
        this.account.deposit(Label.DEPOSIT, value);
    }

    public fee(value: number): void {
        this.account.fee(value);
    }

    public reverse(index: number): void {
        this.account.reverse(index);
    }

    public withdraw(value: number): void {
        this.account.withdraw(value);
    }

    public extract(qtdOp: number): void {
        console.log(this.account.getBalanceManager().getExtract(qtdOp).join("\n"));
    }

    public show(): void{
        console.log(this.account.toString());
    }
}

export { Adapter };