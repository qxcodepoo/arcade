
class Adapter {
    // private pencil: Pencil;
    public init(thickness: number): void {
        // this.pencil = new Pencil(thickness);
    }

    public insert(calibre: number, dureza: string, tamanho: number): void {
        // this.pencil.insert(new Lead(calibre, dureza, tamanho));
    }

    public remove(): void {
        // this.pencil.remove();
    }

    public pull(): void {
        // this.pencil.pull();
    }

    public writePage(): void {
        // this.pencil.writePage();
    }

    public show(): void {
        // console.log(this.pencil.toString());
    }
}

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let adapter = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line);
        let args = line.split(" ");

        if (args[0] == "end") {
            break;
        } else if (args[0] == "init") {
            adapter.init(+args[1]);
        } else if (args[0] == "insert") {
            adapter.insert(+args[1], args[2], +args[3]);
        } else if (args[0] == "remove") {
            adapter.remove();
        } else if (args[0] == "pull") {
            adapter.pull();
        } else if (args[0] == "write") {
            adapter.writePage();
        } else if (args[0] == "show") {
            adapter.show();
        } else {
            write("fail: comando invalido");
        }
    }
}

main()