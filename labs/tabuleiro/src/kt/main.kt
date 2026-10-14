class InvalidBoardSizeException : Exception()
class InvalidPlayerCountException : Exception()
class InvalidTrapPositionException : Exception()
class InvalidRollException : Exception()

enum class EventType {
    MOVED,
    TRAPPED,
    RELEASED,
    STAYED_TRAPPED,
    WON,
}

class RoundEvent(
    val eventType: EventType,
    val playerLabel: Int,
    val position: Int,
)

class Player(
    val label: Int,
    var position: Int = 0,
    var trapped: Boolean = false,
)

class Board(private val boardSize: Int, playerCount: Int) {
    init {
        if (boardSize <= 0) {
            throw InvalidBoardSizeException()
        }
        if (playerCount <= 0) {
            throw InvalidPlayerCountException()
        }
    }

    private val traps: MutableList<Int> = mutableListOf()
    private var running: Boolean = true
    private val players: MutableList<Player> =
        List(playerCount) { index -> Player(index + 1) }.toMutableList()

    fun addTrap(position: Int): Unit {
        if (position !in 1 until boardSize) {
            throw InvalidTrapPositionException()
        }
        traps.add(position)
    }

    fun rollDice(value: Int): List<RoundEvent> {
        if (!running) {
            return emptyList()
        }
        if (value <= 0) {
            throw InvalidRollException()
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
        } else if (value >= finishPosition - player.position) {
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

class Shell {
    private var board: Board = Board(10, 2)
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "init" -> board = Board(args[2].toInt(), args[1].toInt())
            "addTrap" -> board.addTrap(args[1].toInt())
            "roll" -> {
                val events: List<RoundEvent> = board.rollDice(args[1].toInt())
                if (events.isEmpty()) {
                    println("game is over")
                }
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
            "show" -> println(board)
            else -> println("invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: InvalidBoardSizeException) {
                println("fail: invalid board size")
            } catch (_: InvalidPlayerCountException) {
                println("fail: invalid player count")
            } catch (_: InvalidTrapPositionException) {
                println("fail: invalid trap position")
            } catch (_: InvalidRollException) {
                println("fail: invalid roll")
            } catch (_: NumberFormatException) {
                println("fail: invalid conversion")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: insufficient parameters")
            }
        }
    }
}

fun main(): Unit = Shell().main()
