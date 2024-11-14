
class Adapter {
    addProduct(label: string, price: number): void {
        this.manager.addProduct(label, price);
    }

    addBundle(indexes: number[]): void {
        this.manager.addBundle(indexes);
    }

    addDiscount(index: number, discount: number) {
        this.manager.addDiscount(index, discount);
    }

    toString(): string {
        return this.manager.toString();
        return "";
    }


}

export { Adapter};