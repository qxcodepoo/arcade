const input: () => string = (() => {
    let lines: string[] | undefined;
    let index = 0;
    return (): string => {
        if (process.stdin.isTTY) { const readline = require("readline-sync"); return readline.question(); }
        lines ??= require("fs").readFileSync(0, "utf8").split(/\r?\n/);
        return lines![index++] ?? "";
    };
})();

const GAME_OVER_MSG: string = "game is over";
const INVALID_COMMAND_MSG: string = "invalid command";

const EventType = {
    MOVED: "MOVED",
    TRAPPED: "TRAPPED",
    RELEASED: "RELEASED",
    STAYED_TRAPPED: "STAYED_TRAPPED",
    WON: "WON",
} as const;

type EventType = (typeof EventType)[keyof typeof EventType];

class RoundEvent {
    public readonly eventType: EventType;
    public readonly playerLabel: number;
    public readonly position: number;

    constructor(
        eventType: EventType,
        playerLabel: number,
        position: number,
    ) {
        this.eventType = eventType;
        this.playerLabel = playerLabel;
        this.position = position;
    }
}

class Player {
    public readonly label: number;
    public position: number;
    public trapped: boolean;

    constructor(
        label: number,
        position: number = 0,
        trapped: boolean = false,
    ) {
        this.label = label;
        this.position = position;
        this.trapped = trapped;
    }
}

class Board {
    private readonly boardSize: number;
    private readonly traps: Array<number> = [];
    private running: boolean = true;
    private readonly players: Array<Player>;

    constructor(playerCount: number, boardSize: number) {
        this.boardSize = boardSize;
        this.players = Array.from(
            { length: playerCount },
            (_, index) => new Player(index + 1),
        );
    }

    addTrap(position: number): void {
        this.traps.push(position);
    }

    rollDice(value: number): Array<RoundEvent> {
        if (!this.running) {
            return [];
        }

        const player: Player = this.players.shift()!;
        const events: Array<RoundEvent> = [];
        const finish: number = this.boardSize;

        if (player.trapped) {
            if (value % 2 === 0) {
                player.trapped = false;
                events.push(
                    new RoundEvent(EventType.RELEASED, player.label, player.position),
                );
            } else {
                events.push(
                    new RoundEvent(
                        EventType.STAYED_TRAPPED,
                        player.label,
                        player.position,
                    ),
                );
            }
        } else if (player.position + value >= finish) {
            player.position = finish;
            this.running = false;
            events.push(new RoundEvent(EventType.WON, player.label, player.position));
        } else {
            player.position += value;
            events.push(new RoundEvent(EventType.MOVED, player.label, player.position));
            if (this.traps.includes(player.position)) {
                player.trapped = true;
                events.push(
                    new RoundEvent(EventType.TRAPPED, player.label, player.position),
                );
            }
        }

        this.players.push(player);
        return events;
    }

    toString(): string {
        const lines: Array<string> = [];
        for (const player of this.players) {
            const squares: Array<string> = Array(this.boardSize + 1).fill(".");
            squares[player.position] = String(player.label);
            lines.push(`player${player.label}: ${squares.join("")}`);
        }

        const trapSquares: Array<string> = Array(this.boardSize + 1).fill(".");
        for (const trap of this.traps) {
            trapSquares[trap] = "x";
        }
        lines.push(`traps__: ${trapSquares.join("")}`);
        return lines.join("\n");
    }
}

function printEvents(events: Array<RoundEvent>): void {
    for (const event of events) {
        const player: string = `player${event.playerLabel}`;
        if (event.eventType === EventType.MOVED) {
            console.log(`${player} andou para ${event.position}`);
        } else if (event.eventType === EventType.TRAPPED) {
            console.log(`${player} caiu em uma armadilha`);
        } else if (event.eventType === EventType.RELEASED) {
            console.log(`${player} se libertou`);
        } else if (event.eventType === EventType.STAYED_TRAPPED) {
            console.log(`${player} continua preso`);
        } else if (event.eventType === EventType.WON) {
            console.log(`${player} ganhou`);
        }
    }
}

function main(): void {
    let board: Board = new Board(2, 10);

    while (true) {
        const line: string = input();
        console.log("$" + line);

        const parts: Array<string> = line.trim().split(/\s+/);
        const command: string | undefined = parts[0];

        if (command === "end") {
            break;
        } else if (command === "init" && parts.length === 3) {
            board = new Board(Number(parts[1]), Number(parts[2]));
        } else if (command === "addTrap" && parts.length === 2) {
            board.addTrap(Number(parts[1]));
        } else if (command === "roll" && parts.length === 2) {
            const events: Array<RoundEvent> = board.rollDice(Number(parts[1]));
            if (events.length === 0) {
                console.log(GAME_OVER_MSG);
            } else {
                printEvents(events);
            }
        } else if (command === "show" && parts.length === 1) {
            console.log(board.toString());
        } else {
            console.log(INVALID_COMMAND_MSG);
        }
    }
}

main();
