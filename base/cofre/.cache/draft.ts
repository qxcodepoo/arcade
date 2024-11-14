
function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let pig = new Pig(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");
        try {
            if (args[0] == "end") {
                break;
            }
            else if (args[0] == "init") {
                pig = new Pig(+args[1]);
            }
            else if (args[0] == "addCoin") {
                let value = parseInt(args[1]);
                if      (value == 10) { pig.addValuable(Coin.C10); } 
                else if (value == 25) { pig.addValuable(Coin.C25); } 
                else if (value == 50) { pig.addValuable(Coin.C50); }
                else if (value == 100) { pig.addValuable(Coin.C100); }
            }
            else if (args[0] == "addItem") {
                pig.addValuable(new Item(args[1], +args[2], +args[3]));
            }
            else if (args[0] == "break") {
                pig.breakPig();
            }
            else if (args[0] == "extractCoins") {
                let coins = pig.extractCoins();
                console.log("[" + coins.join(", ") + "]");
            }
            else if (args[0] == "extractItems") {
                let itens = pig.extractItems();
                console.log("[" + itens.join(", ") + "]");
            }
            else if (args[0] == "show") {
                console.log(pig.toString());
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
