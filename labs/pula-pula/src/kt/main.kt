const val INVALID_COMMAND_MSG: String = "fail: invalid command"

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

fun main(): Unit {
    val trampoline: Trampoline = Trampoline()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(trampoline)
            parts.size == 3 && parts[0] == "arrive" -> {
                trampoline.arrive(Kid(parts[1], parts[2].toInt()))
            }
            parts == listOf("enter") -> trampoline.enter()
            parts == listOf("leave") -> trampoline.leave()
            parts.size == 2 && parts[0] == "remove" -> {
                if (trampoline.removeKid(parts[1]) == null) {
                    println("fail: ${parts[1]} nao esta no pula-pula")
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
