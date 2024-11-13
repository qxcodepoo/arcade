function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main(): void {
    const agenda = new Agenda();
    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        
        let args = line.split(" ");
        
        if (args[0] === "end") {
            break;
        } else if (args[0] === "add") {//name id:fone id:fone ...
            const fones: Fone[] = [];
            for (let i = 2; i < args.length; i++) {
                const parts: string[] = args[i].split(':');
                fones.push(new Fone(parts[0], parts[1]));
            }
            agenda.addContact(args[1], fones);
        } else if (args[0] === "show") {
            write(agenda.toString());
        } else if (args[0] === "rmFone") {//id index
            const contato: Contact | null = agenda.getContact(args[1]);
            if (contato !== null) {
                contato.rmFone(Number(args[2]));
            }
        } else if (args[0] === "rm") {//id
            agenda.rmContact(args[1]);
        } else if (args[0] === "tfav") {
            const contato: Contact | null = agenda.getContact(args[1]);
            if (contato !== null) {
                contato.toogleFavorited();
            }
        } else if (args[0] === "search") {//pattern
            write(agenda.search(args[1]).join("\n"));
        } else if (args[0] === "favs") {//pattern
            write(agenda.getFavorited().join("\n"));
        } else {
            write("fail: comando invalido");
        }
    }
}


main();