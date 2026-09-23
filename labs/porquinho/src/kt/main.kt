import java.util.Locale

const val INVALID_COMMAND_MSG: String = "fail: invalid command"
const val INVALID_COIN_MSG: String = "fail: invalid coin"

class PigError(message: String) : RuntimeException(message)

data class Coin(val value: Double, val volume: Int, val label: String) {
    override fun toString(): String = String.format(Locale.US, "%.2f:%d", value, volume)
}

data class Item(val label: String, val volume: Int) {
    override fun toString(): String = "$label:$volume"
}

class Pig(private val capacity: Int) {
    private val coins: MutableList<Coin> = mutableListOf()
    private val items: MutableList<Item> = mutableListOf()
    private var broken: Boolean = false

    private fun checkCanAdd(volume: Int): Unit {
        if (broken) {
            throw PigError("the pig is broken")
        }
        if (this.volume() + volume > capacity) {
            throw PigError("the pig is full")
        }
    }

    fun addCoin(coin: Coin): Unit {
        checkCanAdd(coin.volume)
        coins.add(coin)
    }

    fun addItem(item: Item): Unit {
        checkCanAdd(item.volume)
        items.add(item)
    }

    fun breakPig(): Unit {
        if (broken) {
            throw PigError("the pig is already broken")
        }
        broken = true
    }

    fun extractCoins(): List<Coin> {
        if (!broken) {
            throw PigError("you must break the pig first")
        }
        val extractedCoins: List<Coin> = coins.toList()
        coins.clear()
        return extractedCoins
    }

    fun extractItems(): List<Item> {
        if (!broken) {
            throw PigError("you must break the pig first")
        }
        val extractedItems: List<Item> = items.toList()
        items.clear()
        return extractedItems
    }

    fun value(): Double = coins.sumOf { it.value }

    fun volume(): Int {
        if (broken) {
            return 0
        }
        return coins.sumOf { it.volume } + items.sumOf { it.volume }
    }

    override fun toString(): String {
        val state: String = if (broken) "broken" else "intact"
        val coinText: String = coins.joinToString(", ")
        val itemText: String = items.joinToString(", ")
        val valueText: String = String.format(Locale.US, "%.2f", value())
        return "state=$state : coins=[$coinText] : items=[$itemText] : value=$valueText : volume=${volume()}/$capacity"
    }
}

private val COINS: Map<String, Coin> = mapOf(
    "10" to Coin(0.10, 1, "C10"),
    "25" to Coin(0.25, 2, "C25"),
    "50" to Coin(0.50, 3, "C50"),
    "100" to Coin(1.00, 4, "C100"),
)

private fun listText(objects: List<Any>): String = objects.joinToString(", ", "[", "]")

fun main(): Unit {
    var pig: Pig? = null

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        try {
            val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
            val activePig: Pig? = pig
            when {
                parts == listOf("end") -> break
                parts.size == 2 && parts[0] == "init" -> pig = Pig(parts[1].toInt())
                parts == listOf("show") && activePig != null -> println(activePig)
                parts.size == 2 && parts[0] == "addCoin" && activePig != null -> {
                    val coin: Coin? = COINS[parts[1]]
                    if (coin == null) {
                        println(INVALID_COIN_MSG)
                    } else {
                        activePig.addCoin(coin)
                    }
                }
                parts.size == 3 && parts[0] == "addItem" && activePig != null -> {
                    activePig.addItem(Item(parts[1], parts[2].toInt()))
                }
                parts == listOf("break") && activePig != null -> activePig.breakPig()
                parts == listOf("extractCoins") && activePig != null -> {
                    println(listText(activePig.extractCoins()))
                }
                parts == listOf("extractItems") && activePig != null -> {
                    println(listText(activePig.extractItems()))
                }
                else -> println(INVALID_COMMAND_MSG)
            }
        } catch (error: PigError) {
            println("fail: ${error.message}")
        } catch (_: NumberFormatException) {
            println(INVALID_COMMAND_MSG)
        }
    }
}
