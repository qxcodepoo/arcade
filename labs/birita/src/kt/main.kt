const val INVALID_COMMAND_MSG: String = "fail: comando invalido"
const val INVALID_COUNTER_MSG: String = "fail: caixa inexistente"
const val BUSY_COUNTER_MSG: String = "fail: caixa ocupado"
const val EMPTY_WAITING_MSG: String = "fail: sem clientes"
const val EMPTY_COUNTER_MSG: String = "fail: caixa vazio"

enum class CallResult {
    OK,
    BUSY_COUNTER,
    EMPTY_WAITING,
}

class Person(val name: String) {
    override fun toString(): String = name
}

class Market(counterCount: Int) {
    private val counters: Array<Person?> = Array(counterCount) { null }
    private val waiting: MutableList<Person> = mutableListOf()

    private fun validateCounter(index: Int): Unit {
        if (index !in counters.indices) {
            throw IndexOutOfBoundsException("counter index: $index")
        }
    }

    fun arrive(person: Person): Unit {
        waiting.add(person)
    }

    fun call(index: Int): CallResult {
        validateCounter(index)
        if (counters[index] != null) {
            return CallResult.BUSY_COUNTER
        }
        if (waiting.isEmpty()) {
            return CallResult.EMPTY_WAITING
        }
        counters[index] = waiting.removeAt(0)
        return CallResult.OK
    }

    fun finish(index: Int): Person? {
        validateCounter(index)
        val person: Person = counters[index] ?: return null
        counters[index] = null
        return person
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
                try {
                    when (market.call(parts[1].toInt())) {
                        CallResult.OK -> Unit
                        CallResult.BUSY_COUNTER -> println(BUSY_COUNTER_MSG)
                        CallResult.EMPTY_WAITING -> println(EMPTY_WAITING_MSG)
                    }
                } catch (_: IndexOutOfBoundsException) {
                    println(INVALID_COUNTER_MSG)
                }
            }
            parts.size == 2 && parts[0] == "finish" -> {
                try {
                    if (market.finish(parts[1].toInt()) == null) {
                        println(EMPTY_COUNTER_MSG)
                    }
                } catch (_: IndexOutOfBoundsException) {
                    println(INVALID_COUNTER_MSG)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
