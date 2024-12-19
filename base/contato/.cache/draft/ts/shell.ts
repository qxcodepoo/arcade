const input = () => ""; // MODO_TESTE
export {};


function main() {
    while (true) {
        let line = input();
        console.log("$" + line);
        const args = line.split(" ");
        const cmd = args[0];
        
        if (cmd === "end") {
            break;
        } else if (cmd === "init") {
            const name = args[1];
        } else if (cmd === "add") {
            const id = args[1];
            const number = args[2];
        } else if (cmd === "rm") {
            const index = +args[1];
        } else if (cmd === "tfav") {
        } else if (cmd === "show") {
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
