function input() { return ""; }
export {};

function main(): void {
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        // else if (cmd == "show") { 
        // }
        // else if (cmd == "setDriver") { 
        //     const name = par[1];
        //     const money = parseInt(par[2]);
        // }
        // else if (cmd == "setPass") { 
        //     const name = par[1];
        //     const money = parseInt(par[2]);
        // }
        // else if (cmd == "drive") { 
        //     const distance = parseInt(par[1]);
        // }
        // else if (cmd == "leavePass") { 
        // }
        else {
            console.log("fail: command not found");
        }
    }
}

main();
