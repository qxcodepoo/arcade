
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


// ------------ Funções Auxiliares --------------------
let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let board = new Board(0, 0);

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if (args[0] == "end") { break; }
        else if (args[0] == "init") { board = new Board(+args[1], +args[2]); }
        else if (args[0] == "addTrap") { board.addTrap(+args[1]); }
        else if (args[0] == "roll") { board.rollDice(+args[1]); }
        else if (args[0] == "show") { write(board.toString()); }
        else { write("comando invalido"); }
    }
}

main()

