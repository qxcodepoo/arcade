const input = () => "";
export {};

// @DROP
interface IProduct {
    getPrice(): number;
    getLabel(): string;
}

// Produto concreto
class Product implements IProduct {
    private nome: string;
    private preco: number;

    constructor(nome: string, preco: number) {
        this.nome = nome;
        this.preco = preco;
    }

    getPrice(): number {
        return this.preco;
    }

    getLabel(): string {
        return this.nome;
    }
}

// Pacote (Composto)
class Bundle implements IProduct {
    private products: IProduct[] = [];

    constructor(produtos: IProduct[] = []) {
        this.products = produtos;
    }

    getPrice(): number {
        let total = 0;
        for (let product of this.products) {
            total += product.getPrice();
        }
        return total;
    }

    getLabel(): string {
        return "[" + this.products.map(p => p.getLabel()).join(", ") + "]";
    }
}

// Decorator
class DescountedProduct implements IProduct {
    private product: IProduct;
    private discount: number;

    constructor(product: IProduct, discount: number) {
        this.product = product;
        this.discount = discount;
    }

    getPrice(): number {
        return this.product.getPrice() * (100 - this.discount) / 100;
    }

    getLabel(): string {
        return this.product.getLabel() + "(" + this.discount + "% OFF)";
    }
}

class Manager {
    private products: IProduct[] = [];

    constructor() {
        this.products = [];
    }

    addProduct(label: string, price: number) {
        this.products.push(new Product(label, price));
    }

    addBundle(indexes: number[]) {
        let produtos: IProduct[] = [];
        for (let index of indexes) {
            produtos.push(this.products[index]);
        }
        this.products.push(new Bundle(produtos));
    }

    addDiscount(index: number, discount: number) {
        let product = new DescountedProduct(this.products[index], discount);
        this.products.push(product);

    }

    toString(): string {
        let output: string[] = this.products.map((product, index) => {
            return `${String(index).padStart(2, "0")}:${product.getLabel()}:${product.getPrice().toFixed(2)}`;
        });
        return output.join("\n");
    }    
}

function main() {
    const manager = new Manager();

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        else if (cmd == "add") {
            const label = par[1];
            const price = parseFloat(par[2]);
            manager.addProduct(label, price);
        }
        else if (cmd == "bundle") {
            const indexes = par.slice(1).map(p => parseInt(p));
            manager.addBundle(indexes);
        }
        else if (cmd == "discount") {
            const index = parseInt(par[1]);
            const discount = parseFloat(par[2]);
            manager.addDiscount(index, discount);
        }
        else if (cmd == "show") {
            console.log(manager.toString());
        }
        else {
            console.log("Comando inválido");
        }
    }
}

main();