
interface IProduct {
    getPrice(): number;
    getLabel(): string;
}

// Produto concreto
class Product implements IProduct {
    private nome: string;
    private preco: number;

    constructor(nome: string, preco: number) {
    }

    getPrice(): number {
    }

    getLabel(): string {
    }
}

// Pacote (Composto)
class Bundle implements IProduct {
    private products: IProduct[] = [];

    constructor(produtos: IProduct[] = []) {
    }

    getPrice(): number {
    }

    getLabel(): string {
    }
}

// Decorator
class DescountedProduct implements IProduct {
    private product: IProduct;
    private discount: number;

    constructor(product: IProduct, discount: number) {
    }

    getPrice(): number {
    }

    getLabel(): string {
    }
}

class Manager {
    private products: IProduct[] = [];

    constructor() {
    }

    addProduct(label: string, price: number) {
    }

    addBundle(indexes: number[]) {
    }

    addDiscount(index: number, discount: number) {
    }

    toString() {
        let index = 0;
        for (let product of this.products) {
            console.log(String(index).padStart(2, "0") + ":" + product.getLabel() + ":" + product.getPrice().toFixed(2));
            index++;
        }
    }
}

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = (): string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end: string = "\n") => process.stdout.write("" + text + end);

function main() {
    let manager = new Manager();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if (args[0] === "end") {
            break;
        }
        else if (args[0] === "add") {
            let label = args[1];
            let preco = +args[2];
            manager.addProduct(label, preco);
        }
        else if (args[0] === "addPacote") {
            let indexes = args.slice(1).map(x => +x);
            manager.addBundle(indexes);
        }
        else if (args[0] === "addDesconto") {
            let index = +args[1];
            let desconto = +args[2];
            manager.addDiscount(index, desconto);
        }
        else if (args[0] === "show") {
            manager.toString();
        }
        else {
            write("fail: comando invalido");
        }
    }
}

main();
