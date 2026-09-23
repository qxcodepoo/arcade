import java.util.Locale

const val INVALID_COMMAND_MSG: String = "fail: comando invalido"
const val INVALID_INDEX_MSG: String = "fail: indice nao existe"
const val INVALID_QUANTITY_MSG: String = "fail: quantidade invalida"
const val INVALID_CAPACITY_MSG: String = "fail: capacidade invalida"
const val INVALID_VALUE_MSG: String = "fail: valor invalido"
const val INSUFFICIENT_BALANCE_MSG: String = "fail: saldo insuficiente"
const val EMPTY_SLOT_MSG: String = "fail: espiral sem produtos"

enum class BuyResult {
    OK,
    INSUFFICIENT_BALANCE,
    EMPTY_SLOT,
}

data class Slot(
    val name: String = "empty",
    val quantity: Int = 0,
    val price: Double = 0.0,
) {
    init {
        require(quantity >= 0)
    }

    override fun toString(): String =
        String.format(Locale.US, "[%8s :%2d U : %.2f RS]", name, quantity, price)
}

class Machine(capacity: Int) {
    init {
        require(capacity >= 0)
    }

    private val slots: MutableList<Slot> = MutableList(capacity) { Slot() }
    private var cash: Double = 0.0
    private var revenue: Double = 0.0

    private fun validateIndex(index: Int): Unit {
        if (index !in slots.indices) {
            throw IndexOutOfBoundsException("slot index: $index")
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
        if (value <= 0.0) {
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
        if (cash < slot.price) {
            return BuyResult.INSUFFICIENT_BALANCE to null
        }
        if (slot.quantity == 0) {
            return BuyResult.EMPTY_SLOT to null
        }
        slots[index] = slot.copy(quantity = slot.quantity - 1)
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

fun main(): Unit {
    var machine: Machine = Machine(0)

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(machine)
            parts.size == 2 && parts[0] == "init" -> {
                val capacity: Int = parts[1].toInt()
                try {
                    machine = Machine(capacity)
                } catch (_: IllegalArgumentException) {
                    println(INVALID_CAPACITY_MSG)
                }
            }
            parts.size == 5 && parts[0] == "set" -> {
                val index: Int = parts[1].toInt()
                val name: String = parts[2]
                val quantity: Int = parts[3].toInt()
                val price: Double = parts[4].toDouble()
                try {
                    machine.setSlot(index, name, quantity, price)
                } catch (_: IndexOutOfBoundsException) {
                    println(INVALID_INDEX_MSG)
                } catch (_: IllegalArgumentException) {
                    println(INVALID_QUANTITY_MSG)
                }
            }
            parts.size == 2 && parts[0] == "limpar" -> {
                val index: Int = parts[1].toInt()
                try {
                    machine.clearSlot(index)
                } catch (_: IndexOutOfBoundsException) {
                    println(INVALID_INDEX_MSG)
                }
            }
            parts.size == 2 && parts[0] == "dinheiro" -> {
                if (!machine.insertCash(parts[1].toDouble())) {
                    println(INVALID_VALUE_MSG)
                }
            }
            parts == listOf("troco") -> {
                println(String.format(Locale.US, "voce recebeu %.2f RS", machine.withdrawCash()))
            }
            parts.size == 2 && parts[0] == "comprar" -> {
                val index: Int = parts[1].toInt()
                try {
                    val (result: BuyResult, productName: String?) = machine.buyItem(index)
                    when (result) {
                        BuyResult.OK -> println("voce comprou um $productName")
                        BuyResult.INSUFFICIENT_BALANCE -> println(INSUFFICIENT_BALANCE_MSG)
                        BuyResult.EMPTY_SLOT -> println(EMPTY_SLOT_MSG)
                    }
                } catch (_: IndexOutOfBoundsException) {
                    println(INVALID_INDEX_MSG)
                }
            }
            parts == listOf("revenue") -> {
                println(String.format(Locale.US, "arrecadacao: %.2f", machine.getRevenue()))
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
