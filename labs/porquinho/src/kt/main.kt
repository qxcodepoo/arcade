import java.util.Locale

class InvalidCapacityException : Exception()
class InvalidItemVolumeException : Exception()

enum class AddResult {
    OK,
    BROKEN,
    FULL,
}

class Coin(val value: Double, val volume: Int, val label: String) {
    init {
        require(value.isFinite() && value > 0.0 && volume > 0)
    }

    override fun toString(): String = String.format(Locale.US, "%.2f:%d", value, volume)
}

class Item(val label: String, val volume: Int) {
    init {
        if (volume <= 0) {
            throw InvalidItemVolumeException()
        }
    }

    override fun toString(): String = "$label:$volume"
}

class Pig(private val capacity: Int) {
    init {
        if (capacity < 0) {
            throw InvalidCapacityException()
        }
    }

    private val coins: MutableList<Coin> = mutableListOf()
    private val items: MutableList<Item> = mutableListOf()
    private var broken: Boolean = false

    private fun checkCanAdd(volume: Int): AddResult {
        if (broken) {
            return AddResult.BROKEN
        }
        if (volume > capacity - volume()) {
            return AddResult.FULL
        }
        return AddResult.OK
    }

    fun addCoin(coin: Coin): AddResult {
        val result: AddResult = checkCanAdd(coin.volume)
        if (result == AddResult.OK) {
            coins.add(Coin(coin.value, coin.volume, coin.label))
        }
        return result
    }

    fun addItem(item: Item): AddResult {
        val result: AddResult = checkCanAdd(item.volume)
        if (result == AddResult.OK) {
            items.add(Item(item.label, item.volume))
        }
        return result
    }

    fun breakPig(): Boolean {
        if (broken) {
            return false
        }
        broken = true
        return true
    }

    fun extractCoins(): List<Coin>? {
        if (!broken) {
            return null
        }
        val extractedCoins: List<Coin> = coins.toList()
        coins.clear()
        return extractedCoins
    }

    fun extractItems(): List<Item>? {
        if (!broken) {
            return null
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

private fun listText(objects: List<*>): String = objects.joinToString(", ", "[", "]")

class Shell {
    private var pig: Pig? = null
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        if (args[0] == "end") {
            running = false
            return
        }
        if (args[0] == "init") {
            pig = Pig(args[1].toInt())
            return
        }

        val currentPig: Pig = pig ?: run {
            println("fail: invalid command")
            return
        }
        when (args[0]) {
            "show" -> println(currentPig)
            "addCoin" -> {
                val coin: Coin? = when (args[1]) {
                    "10" -> Coin(0.10, 1, "C10")
                    "25" -> Coin(0.25, 2, "C25")
                    "50" -> Coin(0.50, 3, "C50")
                    "100" -> Coin(1.00, 4, "C100")
                    else -> null
                }
                if (coin == null) {
                    println("fail: invalid coin")
                } else {
                    when (currentPig.addCoin(coin)) {
                        AddResult.OK -> Unit
                        AddResult.BROKEN -> println("fail: the pig is broken")
                        AddResult.FULL -> println("fail: the pig is full")
                    }
                }
            }
            "addItem" -> {
                when (currentPig.addItem(Item(args[1], args[2].toInt()))) {
                    AddResult.OK -> Unit
                    AddResult.BROKEN -> println("fail: the pig is broken")
                    AddResult.FULL -> println("fail: the pig is full")
                }
            }
            "break" -> {
                if (!currentPig.breakPig()) {
                    println("fail: the pig is already broken")
                }
            }
            "extractCoins" -> {
                val coins: List<Coin>? = currentPig.extractCoins()
                if (coins == null) {
                    println("fail: you must break the pig first")
                } else {
                    println(listText(coins))
                }
            }
            "extractItems" -> {
                val items: List<Item>? = currentPig.extractItems()
                if (items == null) {
                    println("fail: you must break the pig first")
                } else {
                    println(listText(items))
                }
            }
            else -> println("fail: invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: InvalidCapacityException) {
                println("fail: invalid capacity")
            } catch (_: InvalidItemVolumeException) {
                println("fail: invalid volume")
            } catch (_: NumberFormatException) {
                println("fail: invalid conversion")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: insufficient parameters")
            }
        }
    }
}

fun main(): Unit = Shell().main()
