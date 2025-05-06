const input = () => ""; // MODO_TESTE
export {};

function main() {

    while (true) {
        const line = input(); // Assume input() is defined elsewhere
        console.log(`$${line}`);

        const parts = line.split(" ");
        const cmd = parts[0];

        if (cmd === "end") {
            break;
        } else if (cmd === "show") {
        } else if (cmd === "addCli") {
            // const name = parts[1];
            // const limite = parseInt(parts[2]);
        } else if (cmd === "showCli") {
            // const name = parts[1];
        } else if (cmd === "kill") {
            // const name = parts[1];
        } else if (cmd === "give") {
            // const name = parts[1];
            // const value = parseInt(parts[2]);
        } else if (cmd === "take") {
            // const name = parts[1];
            // const value = parseInt(parts[2]);
        } else if (cmd === "plus") {
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
