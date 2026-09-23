const val GAME_OVER_MSG: String = "game is over"
const val INVALID_COMMAND_MSG: String = "invalid command"

enum class EventType {
    MOVED,
    TRAPPED,
    RELEASED,
    STAYED_TRAPPED,
    WON,
}

data class RoundEvent(
    val eventType: EventType,
    val playerLabel: Int,
    val position: Int,
)

data class Player(
    val label: Int,
    var position: Int = 0,
    var trapped: Boolean = false,
)

class Board(private val boardSize: Int, playerCount: Int) {
    private val traps: MutableList<Int> = mutableListOf()
    private var running: Boolean = true
    private val players: MutableList<Player> =
        List(playerCount) { index -> Player(index + 1) }.toMutableList()

    fun addTrap(position: Int): Unit {
        traps.add(position)
    }

    fun rollDice(value: Int): List<RoundEvent> {
        if (!running) {
            return emptyList()
        }

        val player: Player = players.removeAt(0)
        val events: MutableList<RoundEvent> = mutableListOf()
        val finishPosition: Int = boardSize

        if (player.trapped) {
            if (value % 2 == 0) {
                player.trapped = false
                events.add(RoundEvent(EventType.RELEASED, player.label, player.position))
            } else {
                events.add(
                    RoundEvent(EventType.STAYED_TRAPPED, player.label, player.position),
                )
            }
        } else if (player.position + value >= finishPosition) {
            player.position = finishPosition
            running = false
            events.add(RoundEvent(EventType.WON, player.label, player.position))
        } else {
            player.position += value
            events.add(RoundEvent(EventType.MOVED, player.label, player.position))
            if (traps.contains(player.position)) {
                player.trapped = true
                events.add(RoundEvent(EventType.TRAPPED, player.label, player.position))
            }
        }

        players.add(player)
        return events
    }

    override fun toString(): String {
        val lines: MutableList<String> = mutableListOf()
        for (player in players) {
            val squares: MutableList<String> = MutableList(boardSize + 1) { "." }
            squares[player.position] = player.label.toString()
            lines.add("player${player.label}: ${squares.joinToString("")}")
        }

        val trapSquares: MutableList<String> = MutableList(boardSize + 1) { "." }
        for (trap in traps) {
            trapSquares[trap] = "x"
        }
        lines.add("traps__: ${trapSquares.joinToString("")}")
        return lines.joinToString("\n")
    }
}

fun printEvents(events: List<RoundEvent>): Unit {
    for (event in events) {
        val player: String = "player${event.playerLabel}"
        when (event.eventType) {
            EventType.MOVED -> println("$player andou para ${event.position}")
            EventType.TRAPPED -> println("$player caiu em uma armadilha")
            EventType.RELEASED -> println("$player se libertou")
            EventType.STAYED_TRAPPED -> println("$player continua preso")
            EventType.WON -> println("$player ganhou")
        }
    }
}

fun main(): Unit {
    var board: Board = Board(10, 2)

    while (true) {
        val line: String = readLine() ?: break
        println("$" + line)

        val parts: List<String> = line.trim().split(Regex("\\s+"))
        when (parts[0]) {
            "end" -> break
            "init" -> board = Board(parts[2].toInt(), parts[1].toInt())
            "addTrap" -> board.addTrap(parts[1].toInt())
            "roll" -> {
                val events: List<RoundEvent> = board.rollDice(parts[1].toInt())
                if (events.isEmpty()) {
                    println(GAME_OVER_MSG)
                } else {
                    printEvents(events)
                }
            }
            "show" -> println(board.toString())
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
