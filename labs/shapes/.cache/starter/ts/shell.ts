const input = () => ""; // MODO_TESTE
export {};

function main() {
    // const shapes: Shape[] = [];

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        else if (cmd == "show") {
        }
        else if (cmd == "circle") {
            // const x = parseFloat(par[1]);
            // const y = parseFloat(par[2]);
            // const r = parseFloat(par[3]);
        }
        else if (cmd == "rect") {
            // const x1 = parseFloat(par[1]);
            // const y1 = parseFloat(par[2]);
            // const x2 = parseFloat(par[3]);
            // const y2 = parseFloat(par[4]);
        }
        else if (cmd == "info") {
        }
        else {
            console.log("fail: invalid command");
        }
    }
}

main();
