class Kid(name: String, age: Int) {
    private val name: String = name
    private val age: Int = age

    fun getName(): String = name

    fun getAge(): Int = age

    override fun toString(): String = "$name:$age"
}

class Trampoline {
    private val waiting: MutableList<Kid> = mutableListOf()
    private val playing: MutableList<Kid> = mutableListOf()

    private fun removeFromList(name: String, kids: MutableList<Kid>): Kid? {
        val index: Int = kids.indexOfFirst { it.getName() == name }
        return if (index < 0) null else kids.removeAt(index)
    }

    fun arrive(kid: Kid): Unit {
        waiting.add(0, kid)
    }

    fun enter(): Unit {
        if (waiting.isNotEmpty()) {
            playing.add(0, waiting.removeAt(waiting.lastIndex))
        }
    }

    fun leave(): Unit {
        if (playing.isNotEmpty()) {
            waiting.add(0, playing.removeAt(playing.lastIndex))
        }
    }

    fun removeKid(name: String): Kid? =
        removeFromList(name, waiting) ?: removeFromList(name, playing)

    override fun toString(): String {
        val waitingText: String = waiting.joinToString(separator = ", ")
        val playingText: String = playing.joinToString(separator = ", ")
        return "[$waitingText] => [$playingText]"
    }
}

class Shell {
    private val trampoline: Trampoline = Trampoline()
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(trampoline)
            "arrive" -> {
                trampoline.arrive(Kid(args[1], args[2].toInt()))
            }
            "enter" -> trampoline.enter()
            "leave" -> trampoline.leave()
            "remove" -> {
                if (trampoline.removeKid(args[1]) == null) {
                    println("fail: ${args[1]} nao esta no pula-pula")
                }
            }
            else -> println("fail: invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: NumberFormatException) {
                println("fail: conversao invalida")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: parametros insuficientes")
            }
        }
    }
}

fun main(): Unit = Shell().main()
