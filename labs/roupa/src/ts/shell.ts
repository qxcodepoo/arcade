const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Roupa {
    private size: string = "";

    setSize(size: string): void {
        const validSizes: string[] = ["PP", "P", "M", "G", "GG"];
        if (!validSizes.includes(size)) {
            console.log("fail: Valor inválido, tente PP, P, M, G, GG ou XG");
            return;
        }
        this.size = size;
    }

    getSize(): string {
        return this.size;
    }

    toString(): string {
        return `size: (${this.size})`;
    }
}

// @KEEP
function main(): void {
    // CRIE SEU OBJETO AQUI
    // @DROP
    const roupa: Roupa = new Roupa();
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const args = line.split(" ");
        const cmd = args[0];

        if (cmd == "size") { // TENTE ATRIBUIR UM TAMANHO A ROUPA
            // @COM
            const size = args[1];
            // @DROP
            roupa.setSize(size);
        } else if (cmd == "show") { // MOSTRE A ROUPA
            // @DROP
            console.log(roupa.toString());
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: Comando inválido");
        }
    }
}

main();