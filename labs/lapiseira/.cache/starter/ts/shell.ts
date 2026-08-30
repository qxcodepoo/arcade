const input = () => ""; // MODO_TESTE
export {};

function main() {

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd === "end") {
            break;
        }
        else if (cmd === "show") { 
        }
        else if (cmd === "init") { 
            // const thickness = parseFloat(par[1]);
        }
        else if (cmd === "insert") { 
            // const thickness = parseFloat(par[1]);
            // const hardness = par[2];
            // const size = parseInt(par[3]);
        }
        else if (cmd === "remove") { 
        }
        else if (cmd === "write") { 
        }
        else if (cmd === "pull") { 
        }
        else {
            console.log("fail: comando invalido");
        }
    }
}

main();
