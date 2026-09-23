const val INVALID_COMMAND_MSG: String = "fail: comando invalido"
const val INVALID_COUNTER_MSG: String = "fail: caixa inexistente"
const val BUSY_COUNTER_MSG: String = "fail: caixa ocupado"
const val EMPTY_WAITING_MSG: String = "fail: sem clientes"
const val EMPTY_COUNTER_MSG: String = "fail: caixa vazio"
const val PERSON_NOT_WAITING_MSG: String = "fail: pessoa nao esta na fila"

enum class CallResult {
    OK,
    INVALID_COUNTER,
    BUSY_COUNTER,
    EMPTY_WAITING,
}

enum class FinishResult {
    OK,
    INVALID_COUNTER,
    EMPTY_COUNTER,
}

class Person(val name: String) {
    override fun toString(): String = name
}

class Market(counterCount: Int) {
    private val counters: Array<Person?> = Array(counterCount) { null }
    private val waiting: MutableList<Person> = mutableListOf()

    private fun validateCounter(index: Int): Boolean = index in counters.indices

    fun arrive(person: Person): Unit {
        waiting.add(person)
    }

    fun call(index: Int): CallResult {
        if (!validateCounter(index)) {
            return CallResult.INVALID_COUNTER
        }
        if (counters[index] != null) {
            return CallResult.BUSY_COUNTER
        }
        if (waiting.isEmpty()) {
            return CallResult.EMPTY_WAITING
        }
        counters[index] = waiting.removeAt(0)
        return CallResult.OK
    }

    fun finish(index: Int): Pair<Person?, FinishResult> {
        if (!validateCounter(index)) {
            return null to FinishResult.INVALID_COUNTER
        }
        val person: Person = counters[index] ?: return null to FinishResult.EMPTY_COUNTER
        counters[index] = null
        return person to FinishResult.OK
    }

    fun cutInLine(sneaky: Person, targetName: String): Boolean {
        val index: Int = waiting.indexOfFirst { it.name == targetName }
        if (index == -1) {
            return false
        }
        waiting.add(index, sneaky)
        return true
    }

    fun giveUp(name: String): Person? {
        val index: Int = waiting.indexOfFirst { it.name == name }
        if (index == -1) {
            return null
        }
        return waiting.removeAt(index)
    }

    override fun toString(): String {
        val counterState: String = counters.joinToString(", ") { person ->
            person?.toString() ?: "-----"
        }
        val waitingState: String = waiting.joinToString(", ")
        return "Caixas: [$counterState]\nEspera: [$waitingState]"
    }
}

fun main(): Unit {
    var market: Market = Market(0)

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(market)
            parts.size == 2 && parts[0] == "init" -> market = Market(parts[1].toInt())
            parts.size == 2 && parts[0] == "arrive" -> market.arrive(Person(parts[1]))
            parts.size == 2 && parts[0] == "call" -> {
                when (market.call(parts[1].toInt())) {
                    CallResult.OK -> Unit
                    CallResult.INVALID_COUNTER -> println(INVALID_COUNTER_MSG)
                    CallResult.BUSY_COUNTER -> println(BUSY_COUNTER_MSG)
                    CallResult.EMPTY_WAITING -> println(EMPTY_WAITING_MSG)
                }
            }
            parts.size == 2 && parts[0] == "finish" -> {
                when (market.finish(parts[1].toInt()).second) {
                    FinishResult.OK -> Unit
                    FinishResult.INVALID_COUNTER -> println(INVALID_COUNTER_MSG)
                    FinishResult.EMPTY_COUNTER -> println(EMPTY_COUNTER_MSG)
                }
            }
            parts.size == 3 && parts[0] == "cutInLine" -> {
                if (!market.cutInLine(Person(parts[1]), parts[2])) {
                    println(PERSON_NOT_WAITING_MSG)
                }
            }
            parts.size == 2 && parts[0] == "giveUp" -> {
                if (market.giveUp(parts[1]) == null) {
                    println(PERSON_NOT_WAITING_MSG)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
