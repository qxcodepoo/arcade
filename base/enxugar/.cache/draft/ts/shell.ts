function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    constructor() {
    }

    public criar(cor: string, tamanho: string): void {
    }

    public enxugar(quantidade: number): void {
    }

    public seca(): void {
    }

    public torcer(): void {
    }

    public mostrar(): void {
    }
}

function main() {
    let adp = new Adapter();
    while (true) {
        write("$", "");
        let line = input();
        let args = line.split(" ");
        write(line); // _TEST_ONLY_
        if      (args[0] === "criar")   { adp.criar(args[1], args[2]); }
        else if (args[0] === "enxugar") { adp.enxugar(+args[1]); }
        else if (args[0] === "seca")    { adp.seca(); }
        else if (args[0] === "torcer")  { adp.torcer(); }
        else if (args[0] === "mostrar") { adp.mostrar(); }
        else if (args[0] === "end")     { break; }
        else                            { console.log("comando invalido"); }
    }
}

main();
