from dataclasses import dataclass
from enum import Enum


GAME_OVER_MSG: str = "game is over"
INVALID_COMMAND_MSG: str = "invalid command"


class EventType(Enum):
    MOVED = 0
    TRAPPED = 1
    RELEASED = 2
    STAYED_TRAPPED = 3
    WON = 4


@dataclass
class RoundEvent:
    event_type: EventType
    player_label: int
    position: int


@dataclass
class Player:
    label: int
    position: int = 0
    trapped: bool = False


class Board:
    def __init__(self, player_count: int, board_size: int) -> None:
        self.__board_size: int = board_size
        self.__traps: list[int] = []
        self.__running: bool = True
        self.__players: list[Player] = [
            Player(label) for label in range(1, player_count + 1)
        ]

    def add_trap(self, position: int) -> None:
        self.__traps.append(position)

    def roll_dice(self, value: int) -> list[RoundEvent]:
        if not self.__running:
            return []

        player: Player = self.__players.pop(0)
        events: list[RoundEvent] = []
        finish: int = self.__board_size

        if player.trapped:
            if value % 2 == 0:
                player.trapped = False
                events.append(RoundEvent(EventType.RELEASED, player.label, player.position))
            else:
                events.append(
                    RoundEvent(EventType.STAYED_TRAPPED, player.label, player.position)
                )
        elif player.position + value >= finish:
            player.position = finish
            self.__running = False
            events.append(RoundEvent(EventType.WON, player.label, player.position))
        else:
            player.position += value
            events.append(RoundEvent(EventType.MOVED, player.label, player.position))
            if player.position in self.__traps:
                player.trapped = True
                events.append(RoundEvent(EventType.TRAPPED, player.label, player.position))

        self.__players.append(player)
        return events

    def __str__(self) -> str:
        lines: list[str] = []
        for player in self.__players:
            squares: list[str] = ["."] * (self.__board_size + 1)
            squares[player.position] = str(player.label)
            lines.append(f"player{player.label}: {''.join(squares)}")

        trap_squares: list[str] = ["."] * (self.__board_size + 1)
        for trap in self.__traps:
            trap_squares[trap] = "x"
        lines.append(f"traps__: {''.join(trap_squares)}")
        return "\n".join(lines)


def print_events(events: list[RoundEvent]) -> None:
    for event in events:
        player: str = f"player{event.player_label}"
        if event.event_type == EventType.MOVED:
            print(f"{player} andou para {event.position}")
        elif event.event_type == EventType.TRAPPED:
            print(f"{player} caiu em uma armadilha")
        elif event.event_type == EventType.RELEASED:
            print(f"{player} se libertou")
        elif event.event_type == EventType.STAYED_TRAPPED:
            print(f"{player} continua preso")
        elif event.event_type == EventType.WON:
            print(f"{player} ganhou")


def main() -> None:
    board: Board = Board(2, 10)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", player_count, board_size]:
                board = Board(int(player_count), int(board_size))
            case ["addTrap", position]:
                board.add_trap(int(position))
            case ["roll", value]:
                events: list[RoundEvent] = board.roll_dice(int(value))
                if not events:
                    print(GAME_OVER_MSG)
                else:
                    print_events(events)
            case ["show"]:
                print(board)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
