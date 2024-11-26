

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
            write("game is over");
            return;
        }
        
        let finish = this.size - 1;
        let player = this.players.shift()!;
        if (!player.isFree()) {
            if (value % 2 == 0) {
                player.setFree(true);
                write("player" + player.getLabel() + " se libertou")
            } else {
                write("player" + player.getLabel() + " continua preso")
            }
        } else if (player.getPos() + value >= finish) {
            write("player" + player.getLabel() + " ganhou")
            player.setPos(finish);
            this.running = false;
        } else {
            player.setPos(player.getPos() + value);
            write("player" + player.getLabel() + " andou para " + player.getPos())
            if (this.trapList.indexOf(player.getPos()) != -1) {
                player.setFree(false);
                write("player" + player.getLabel() + " caiu em uma armadilha")
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

class Adapter {
    private board: Board = new Board(0, 0);

    init(nPlayers: number, size: number): void {
        this.board = new Board(nPlayers, size);
    }

    public addTrap(pos: number): void {
        this.board.addTrap(pos);
    }

    public rollDice(value: number): void {
        this.board.rollDice(value);
    }

    public show(): void {
        write(this.board.toString());
    }
}

