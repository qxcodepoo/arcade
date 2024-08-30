class Adapter {

    constructor() {
    }

    enter(): void {
    }

    leave(): void {
    }

    fuel(gas: number): void {
    }

    drive(km: number): void {
    }

    toString(): string {
        return "";
    }
}
export {Adapter};

if (require.main === module) {
    console.log("Rodando o arquivo do estudante");
}
