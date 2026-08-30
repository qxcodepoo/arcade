const input = () => ""; // MODO_TESTE
export {};

function main() {
    
    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");
        
        try {
            if (args[0] == "end") {
                break;
            }
            else if (args[0] == "show") {
            }
            else if (args[0] == "init") {
                // const volumeMax = parseInt(args[1]);
            }
            else if (args[0] == "addCoin") {
                // let value = parseInt(args[1]);
            }
            else if (args[0] == "addItem") {
                // const label = args[1];
                // const value = parseInt(args[2]);
                // const volume = parseInt(args[3]);
            }
            else if (args[0] == "break") {
            }
            else if (args[0] == "extractCoins") {
            }
            else if (args[0] == "extractItems") {
            }
            else {
                console.log("fail: invalid command");
            }
        } catch (e) {
            console.log(e.message);
        }
    }
}

main();
