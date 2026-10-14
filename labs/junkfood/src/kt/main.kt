import java.util.Locale

class InvalidSlotIndexException : Exception()
class InvalidCapacityException : Exception()
class InvalidQuantityException : Exception()
class InvalidPriceException : Exception()

enum class BuyResult {
    OK,
    INSUFFICIENT_BALANCE,
    EMPTY_SLOT,
}

class Slot(
    val name: String = "empty",
    val quantity: Int = 0,
    val price: Double = 0.0,
) {
    init {
        if (quantity < 0) {
            throw InvalidQuantityException()
        }
        if (!price.isFinite() || price < 0.0) {
            throw InvalidPriceException()
        }
    }

    override fun toString(): String =
        String.format(Locale.US, "[%8s :%2d U : %.2f RS]", name, quantity, price)
}

class Machine(capacity: Int) {
    init {
        if (capacity < 0) {
            throw InvalidCapacityException()
        }
    }

    private val slots: MutableList<Slot> = MutableList(capacity) { Slot() }
    private var cash: Double = 0.0
    private var revenue: Double = 0.0

    private fun validateIndex(index: Int): Unit {
        if (index !in slots.indices) {
            throw InvalidSlotIndexException()
        }
    }

    fun getSlot(index: Int): Slot {
        validateIndex(index)
        return slots[index]
    }

    fun setSlot(index: Int, name: String, quantity: Int, price: Double): Unit {
        validateIndex(index)
        slots[index] = Slot(name, quantity, price)
    }

    fun clearSlot(index: Int): Unit {
        validateIndex(index)
        slots[index] = Slot()
    }

    fun insertCash(value: Double): Boolean {
        if (!value.isFinite() || value <= 0.0 || !(cash + value).isFinite()) {
            return false
        }
        cash += value
        return true
    }

    fun withdrawCash(): Double {
        val withdrawnCash: Double = cash
        cash = 0.0
        return withdrawnCash
    }

    fun getCash(): Double = cash

    fun getRevenue(): Double = revenue

    fun buyItem(index: Int): Pair<BuyResult, String?> {
        validateIndex(index)
        val slot: Slot = slots[index]
        if (slot.quantity == 0) {
            return BuyResult.EMPTY_SLOT to null
        }
        if (cash < slot.price) {
            return BuyResult.INSUFFICIENT_BALANCE to null
        }
        slots[index] = Slot(slot.name, slot.quantity - 1, slot.price)
        cash -= slot.price
        revenue += slot.price
        return BuyResult.OK to slot.name
    }

    override fun toString(): String {
        val cashLine: String = String.format(Locale.US, "saldo: %.2f", cash)
        val slotLines: String = slots.mapIndexed { index, slot -> "$index $slot" }
            .joinToString("\n")
        return if (slotLines.isEmpty()) cashLine else "$cashLine\n$slotLines"
    }
}

class Shell {
    private var machine: Machine = Machine(0)
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(machine)
            "init" -> machine = Machine(args[1].toInt())
            "set" -> machine.setSlot(args[1].toInt(), args[2], args[3].toInt(), args[4].toDouble())
            "limpar" -> machine.clearSlot(args[1].toInt())
            "dinheiro" -> {
                if (!machine.insertCash(args[1].toDouble())) {
                    println("fail: valor invalido")
                }
            }
            "troco" -> println(String.format(Locale.US, "voce recebeu %.2f RS", machine.withdrawCash()))
            "comprar" -> {
                val (result: BuyResult, productName: String?) = machine.buyItem(args[1].toInt())
                when (result) {
                    BuyResult.OK -> println("voce comprou um $productName")
                    BuyResult.INSUFFICIENT_BALANCE -> println("fail: saldo insuficiente")
                    BuyResult.EMPTY_SLOT -> println("fail: espiral sem produtos")
                }
            }
            "revenue" -> println(String.format(Locale.US, "arrecadacao: %.2f", machine.getRevenue()))
            else -> println("fail: comando invalido")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: InvalidSlotIndexException) {
                println("fail: indice nao existe")
            } catch (_: InvalidCapacityException) {
                println("fail: capacidade invalida")
            } catch (_: InvalidQuantityException) {
                println("fail: quantidade invalida")
            } catch (_: InvalidPriceException) {
                println("fail: preco invalido")
            } catch (_: NumberFormatException) {
                println("fail: conversao invalida")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: parametros insuficientes")
            }
        }
    }
}

fun main(): Unit = Shell().main()
