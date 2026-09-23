import java.util.Locale

interface Valuable {
    val label: String
    val value: Double
    val volume: Int
}

open class PigError(message: String) : Exception(message)

class PigBrokenError(message: String = "fail: the pig is broken") : PigError(message)
class PigFullError : PigError("fail: the pig is full")
class PigAlreadyBrokenError : PigError("fail: the pig is already broken")

enum class Coin(
    override val value: Double,
    override val volume: Int,
) : Valuable {
    M10(0.10, 1),
    M25(0.25, 2),
    M50(0.50, 3),
    M100(1.00, 4);

    override val label: String
        get() = name

    override fun toString(): String = "$label:${value.money()}:$volume"
}

data class Item(
    override val label: String,
    override val value: Double,
    override val volume: Int,
) : Valuable {
    override fun toString(): String = "$label:${value.money()}:$volume"
}

class Pig(val maxVolume: Int) {
    var broken: Boolean = false
        private set

    private val valuables: MutableList<Valuable> = mutableListOf()

    val volume: Int
        get() = if (broken) 0 else valuables.sumOf { it.volume }

    val value: Double
        get() = valuables.sumOf { it.value }

    fun add(valuable: Valuable): Unit {
        if (broken) {
            throw PigBrokenError()
        }
        if (volume + valuable.volume > maxVolume) {
            throw PigFullError()
        }
        valuables.add(valuable)
    }

    fun breakPig(): Unit {
        if (broken) {
            throw PigAlreadyBrokenError()
        }
        broken = true
    }

    fun extractCoins(): List<Coin> {
        ensureBroken()
        val extracted: List<Coin> = valuables.filterIsInstance<Coin>()
        valuables.removeAll { it is Coin }
        return extracted
    }

    fun extractItems(): List<Item> {
        ensureBroken()
        val extracted: List<Item> = valuables.filterIsInstance<Item>()
        valuables.removeAll { it is Item }
        return extracted
    }

    private fun ensureBroken(): Unit {
        if (!broken) {
            throw PigBrokenError("fail: you must break the pig first")
        }
    }

    override fun toString(): String {
        val contents: String = valuables.joinToString(", ")
        val status: String = if (broken) "broken" else "intact"
        return "[$contents] : ${value.money()}\$ : $volume/$maxVolume : $status"
    }
}

fun main(): Unit {
    var pig: Pig = Pig(0)

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        when {
            parts.size == 2 && parts[0] == "init" -> pig = Pig(parts[1].toInt())
            parts == listOf("show") -> println(pig)
            parts.size == 2 && parts[0] == "addCoin" -> {
                val coin: Coin? = Coin.entries.firstOrNull { it.name == "M${parts[1]}" }
                if (coin == null) {
                    println(INVALID_COIN_MSG)
                } else {
                    try {
                        pig.add(coin)
                    } catch (error: PigError) {
                        println(error.message)
                    }
                }
            }
            parts.size == 4 && parts[0] == "addItem" -> {
                try {
                    val item: Item = Item(parts[1], parts[2].toDouble(), parts[3].toInt())
                    pig.add(item)
                } catch (_: NumberFormatException) {
                    println(INVALID_ITEM_MSG)
                } catch (error: PigError) {
                    println(error.message)
                }
            }
            parts == listOf("break") -> {
                try {
                    pig.breakPig()
                } catch (error: PigError) {
                    println(error.message)
                }
            }
            parts == listOf("extractCoins") -> {
                try {
                    println(pig.extractCoins().joinToString(prefix = "[", postfix = "]"))
                } catch (error: PigError) {
                    println(error.message)
                }
            }
            parts == listOf("extractItems") -> {
                try {
                    println(pig.extractItems().joinToString(prefix = "[", postfix = "]"))
                } catch (error: PigError) {
                    println(error.message)
                }
            }
            parts == listOf("end") -> break
        }
    }
}

fun Double.money(): String = String.format(Locale.US, "%.2f", this)

const val INVALID_COIN_MSG: String = "fail: invalid coin"
const val INVALID_ITEM_MSG: String = "fail: invalid item"
