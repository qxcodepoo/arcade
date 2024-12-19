const input = () => ""; // MODO_TESTE
export {};

function main() {
    while (true) {
        const line = input();
        console.log("$" + line);

        var par = line.split(" ");
        var cmd = par[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "show") { 
        } else if (cmd == "init") { 
            // const nCaixas = parseInt(par[1]);
        } else if (cmd == "arrive") { 
            // const nome = par[1];
        } else if (cmd == "call") { 
            // const index = parseInt(par[1]);
        } else if (cmd == "finish") { 
            // const index = parseInt(par[1]);
        } else {
            console.log("fail: comando invalido");
        }
    }
}
main() 
