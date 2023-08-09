
class Player {
    private label: number;     // indice do player   
    private pos: number;       // posição dele no tabuleiro
    private free: boolean;

    constructor(label: number) {
    }

    public getLabel(): number {
    }

    public getPos(): number {
    }

    public setPos(pos: number) {
    }

    public setFree(free: boolean): void {
    }

    public isFree(): boolean {
    }


    toString(): string {
        return "Player " + this.label + " at " + this.pos + " is " + (this.free ? "free" : "free");
    }
}


class Board {
    trapList: number[]; // posição das armadilhas
    running: boolean;   // se o jogo acabou
    size    : number;   // tamanho do tabuleiro
    players : Player[]; // lista de jogadores

    constructor(nPlayers: number, size: number) {
        this.size = size + 1;
        this.trapList = [];
        this.running = true;
        this.players = [];
        for (let i = 1; i <= nPlayers; i++) {
            this.players.push(new Player(i));
        }
    }

    addTrap(pos: number) {
    }

    rollDice(value: number) {
    }
    
    toString() {
        let str = "";
        for(let p of this.players) {
            let line: string[] = Array(this.size).fill(".")
            line[p.getPos()] = "" + p.getLabel();
            str += "player" + p.getLabel() + ": " + line.join("") + "\n";
        }

        let traps = Array(this.size).fill(".")
        for (let t of this.trapList)
            traps[t] = "x";
        str += "traps__: " + traps.join("");
        return str;
    }
};


function main() {
    let chain = new Map();
    let par: string[] = [];
    let board = new Board(0, 0);

    chain.set("init", () => { board = new Board(+par[1], +par[2]); });
    chain.set("addTrap", () => { board.addTrap(+par[1]); });
    chain.set("roll", () => { board.rollDice(+par[1]); });
    chain.set("show", () => { puts(board.toString()); });

    execute(chain, par);
}

// ------------ Funções Auxiliares --------------------
import { readFileSync } from "fs";
let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
let write = (text: any) => process.stdout.write("" + text);
let puts = (text: any) => console.log(text);

function execute(chain: Map<string, Function>, ui: string[]) {
    while (true) {
        let line = input();
        puts("$" + line);
        ui.splice(0); //apagar tudo
        line.split(" ").forEach((x: string) => ui.push(x));

        let cmd = ui[0];
        if (cmd == "end") {
            return;
        } else if (chain.has(cmd)) {
            chain.get(cmd)!();
        } else {
            puts("fail: command not found");
        }
    }
}

main()

