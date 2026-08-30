const input = () => ""; // MODO_TESTE
export {};

// @DROP

class Player {
    private label: number;     // indice do player   
    private pos: number;       // posição dele no tabuleiro
    private free: boolean;

    constructor(label: number) {
        this.label = label;
        this.free = true;
        this.pos = 0;
    }

    public getLabel(): number {
        return this.label;
    }

    public getPos(): number {
        return this.pos;
    }

    public setPos(pos: number) {
        this.pos = pos;
    }

    public setFree(free: boolean): void {
        this.free = free;
    }

    public isFree(): boolean {
        return this.free;
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
        this.trapList.push(pos);
    }

    rollDice(value: number) {
        if (!this.running) {
            console.log("game is over");
            return;
        }
        
        let finish = this.size - 1;
        let player = this.players.shift()!;
        if (!player.isFree()) {
            if (value % 2 == 0) {
                player.setFree(true);
                console.log("player" + player.getLabel() + " se libertou")
            } else {
                console.log("player" + player.getLabel() + " continua preso")
            }
        } else if (player.getPos() + value >= finish) {
            console.log("player" + player.getLabel() + " ganhou")
            player.setPos(finish);
            this.running = false;
        } else {
            player.setPos(player.getPos() + value);
            console.log("player" + player.getLabel() + " andou para " + player.getPos())
            if (this.trapList.indexOf(player.getPos()) != -1) {
                player.setFree(false);
                console.log("player" + player.getLabel() + " caiu em uma armadilha")
            }
        }
        this.players.push(player);
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

// @KEEP

function main() {
    // @DROP
    let board = new Board(2, 10);
    // @KEEP

    while (true) {
        let line = input();
        console.log("$" + line);

        let args = line.split(" ");
        let cmd = args[0];
        
        if (cmd == "end") {
            break;
        }
        else if (cmd == "init") {
            // @COM
            let nPlayers = parseInt(args[1]);
            let size = parseInt(args[2]);
            // @DROP
            board = new Board(nPlayers, size);
        }
        else if (cmd == "addTrap") {
            // @COM
            let pos = parseInt(args[1]);
            // @DROP
            board.addTrap(pos);
        }
        else if (cmd == "roll") {
            // @COM
            let value = parseInt(args[1]);
            // @DROP
            board.rollDice(value);
        }
        else if (cmd == "show") {
            // @DROP
            console.log(board.toString());
        }  
        else {
            console.log("Comando inválido");
        }
    }
}

main()
