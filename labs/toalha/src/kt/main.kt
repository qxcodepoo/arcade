class Towel(private val color: String, private val size: String) {
    private var wetness: Int = 0

    fun maxWetness(): Int = when (size) {
        "P" -> 10
        "M" -> 20
        "G" -> 30
        else -> 0
    }

    fun absorb(waterAmount: Int): Boolean {
        if (waterAmount < 0) {
            return false
        }

        wetness += waterAmount
        val capacity: Int = maxWetness()
        if (wetness > capacity) {
            wetness = capacity
            return false
        }
        return true
    }

    fun wringOut(): Unit {
        wetness = 0
    }

    fun isDry(): Boolean = wetness == 0

    override fun toString(): String = "$color $size $wetness"
}

fun main(): Unit {
    val towel: Towel = Towel("Azul", "P")
    println(towel)
    towel.absorb(5)
    println(towel)
    println(towel.isDry())
    towel.wringOut()
    println(towel)
}
