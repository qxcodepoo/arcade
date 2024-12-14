function input() { return ""; }
export {};


function main() {
    // const car = new Car();
    while(true) {
        let line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "show") {
            // TODO
        } else if (cmd == "enter") {
            // TODO
        } else if (cmd == "leave") {
            // TODO
        } else if (cmd == "fuel") {
            // TODO
            // const increment = parseInt(par[1]);
        } else if (cmd == "drive") {
            // TODO
            // const distance = parseInt(par[1]);
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main()
