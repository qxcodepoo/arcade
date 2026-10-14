enum class CallResult {
    OK,
    BUSY_COUNTER,
    EMPTY_WAITING,
}

class Person(val name: String) {
    override fun toString(): String = name
}

class CounterNotFoundException : Exception()

class Market(counterCount: Int) {
    private val counters: Array<Person?> = Array(counterCount) { null }
    private val waiting: MutableList<Person> = mutableListOf()

    private fun validateCounter(index: Int): Unit {
        if (index < 0 || index >= counters.size) {
            throw CounterNotFoundException()
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

    fun finish(index: Int): Boolean {
        validateCounter(index)
        if (counters[index] == null) {
            return false
        }
        counters[index] = null
        return true
    }

    fun cutInLine(sneaky: Person, targetName: String): Boolean {
        val index: Int = waiting.indexOfFirst { it.name == targetName }
        if (index == -1) {
            return false
        }
        waiting.add(index, sneaky)
        return true
    }

    fun giveUp(name: String): Boolean {
        val index: Int = waiting.indexOfFirst { it.name == name }
        if (index == -1) {
            return false
        }
        waiting.removeAt(index)
        return true
    }

    override fun toString(): String {
        val counterState: String = counters.joinToString(", ") { person ->
            person?.toString() ?: "-----"
        }
        val waitingState: String = waiting.joinToString(", ")
        return "Caixas: [$counterState]\nEspera: [$waitingState]"
    }
}

// --------------------------- INTERFACE ---------------------------

class Shell {
    private var market: Market = Market(2)
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")
        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(market)
            "init" -> market = Market(args[1].toInt())
            "arrive" -> market.arrive(Person(args[1]))
            "call" -> {
                when (market.call(args[1].toInt())) {
                    CallResult.OK -> Unit
                    CallResult.BUSY_COUNTER -> println("fail: caixa ocupado")
                    CallResult.EMPTY_WAITING -> println("fail: sem clientes")
                }
            }
            "finish" -> {
                if (!market.finish(args[1].toInt())) {
                    println("fail: caixa vazio")
                }
            }
            "cutInLine" -> {
                if (!market.cutInLine(Person(args[1]), args[2])) {
                    println("fail: pessoa nao esta na fila")
                }
            }
            "giveUp" -> {
                if (!market.giveUp(args[1])) {
                    println("fail: pessoa nao esta na fila")
                }
            }
            else -> println("cmd invalido")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: NumberFormatException) {
                println("fail: conversao invalida")
            } catch (_: CounterNotFoundException) {
                println("fail: caixa inexistente")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: parametros insuficientes")
            }
        }
    }
}

fun main(): Unit = Shell().main()
