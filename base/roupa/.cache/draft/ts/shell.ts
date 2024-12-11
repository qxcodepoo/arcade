function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
//function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

class Adapter {
    constructor() {
    }
    size(size: string): void {
    }

    show(): void {
    }
}

function main(): void {
    const adapter: Adapter = new Adapter();

    while (true) {
        write("$", "");
        const line: string = input();
        const args: string[] = line.split(" ");
        write(line);

        if      (args[0] === "end")  { break;                           }
        else if (args[0] === "size") { adapter.size(args[1]);           }
        else if (args[0] === "show") { adapter.show();                  }
        else                         { write("fail: Comando inválido"); }
    }
}

main();