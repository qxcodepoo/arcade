const val SOAKED_TOWEL_MSG: String = "fail: towel is soaked"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

class Towel(private val color: String = "", private val size: String = "P") {
    private var wetness: Int = 0

    fun absorb(waterAmount: Int): Boolean {
        val maxWetness: Int = getMaxWetness()
        if (wetness + waterAmount > maxWetness) {
            wetness = maxWetness
            return false
        }

        wetness += waterAmount
        return true
    }

    fun wringOut(): Unit {
        wetness = 0
    }

    fun getMaxWetness(): Int = when (size) {
        "P" -> 10
        "M" -> 20
        "G" -> 30
        else -> 0
    }

    fun isDry(): Boolean = wetness == 0

    override fun toString(): String =
        "Color: $color, Size: $size, Wetness: $wetness"
}

fun main(): Unit {
    var towel: Towel = Towel()

    while (true) {
        val line: String = readLine() ?: break
        println("$" + line)

        val parts: List<String> = line.trim().split(Regex("\\s+"))
        when (parts[0]) {
            "end" -> break
            "create" -> towel = Towel(parts[1], parts[2])
            "show" -> println(towel)
            "dry" -> if (!towel.absorb(parts[1].toInt())) {
                println(SOAKED_TOWEL_MSG)
            }
            "is_dry" -> println(if (towel.isDry()) "yes" else "no")
            "wring_out" -> towel.wringOut()
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
