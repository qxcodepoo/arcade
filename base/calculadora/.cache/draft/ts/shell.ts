function input() { return ""; }
export {};

function main() {
    // let calc = new Calculator(0);

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "init") {
            //TODO
            // const batteryMax = parseInt(par[1]);
        } else if (cmd == "charge") {
            //TODO
            // const value = parseInt(par[1]);
        } else if (cmd == "sum") {
            //TODO
            // const a = parseInt(par[1]);
            // const b = parseInt(par[2]);
        } else if (cmd == "div") {
            //TODO
            // const num = parseInt(par[1]);
            // const den = parseInt(par[2]);
        } else if (cmd == "show") {
            //TODO
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main()
