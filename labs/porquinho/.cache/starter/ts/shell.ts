const input = () => ""; // MODO_TESTE
export {};

function main() {
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        else if (cmd == "init") {
            // const volume = parseInt(par[1]);
        }
        else if (cmd == "show") {
        }
        else if (cmd == "addCoin") {
            // const value = parseInt(par[1]);
        }
        else if (cmd == "addItem") {
            // const label = par[1];
            // const volume = parseInt(par[2]);
        }
        else if (cmd == "break") {
        }
        else if (cmd == "extractCoins") {
        }
        else if (cmd == "extractItems") {
        }
        else {
            console.log("fail: invalid command");
        }
    }
}

main();
