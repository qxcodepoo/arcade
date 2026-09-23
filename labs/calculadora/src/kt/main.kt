import java.util.Locale

const val NO_BATTERY_MSG: String = "fail: insufficient battery"
const val DIVISION_BY_ZERO_MSG: String = "fail: division by zero"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

enum class DivisionResult {
    OK,
    NO_BATTERY,
    DIVISION_BY_ZERO,
}

class Calculator(private val maxBattery: Int) {
    private var battery: Int = 0
    private var display: Double = 0.0

    fun charge(amount: Int): Unit {
        if (amount < 0) {
            return
        }

        battery += amount
        if (battery > maxBattery) {
            battery = maxBattery
        }
    }

    fun add(left: Int, right: Int): Boolean {
        if (battery == 0) {
            return false
        }

        battery--
        display = (left + right).toDouble()
        return true
    }

    fun divide(numerator: Int, denominator: Int): DivisionResult {
        if (battery == 0) {
            return DivisionResult.NO_BATTERY
        }

        battery--
        if (denominator == 0) {
            return DivisionResult.DIVISION_BY_ZERO
        }

        display = numerator.toDouble() / denominator
        return DivisionResult.OK
    }

    override fun toString(): String =
        String.format(Locale.US, "display = %.2f, battery = %d", display, battery)
}

fun main(): Unit {
    var calculator: Calculator = Calculator(0)

    while (true) {
        val line: String = readLine() ?: break
        println("$" + line)

        val parts: List<String> = line.trim().split(Regex("\\s+"))
        when (parts[0]) {
            "end" -> break
            "init" -> calculator = Calculator(parts[1].toInt())
            "show" -> println(calculator)
            "charge" -> calculator.charge(parts[1].toInt())
            "sum" -> if (!calculator.add(parts[1].toInt(), parts[2].toInt())) {
                println(NO_BATTERY_MSG)
            }
            "div" -> when (
                calculator.divide(parts[1].toInt(), parts[2].toInt())
            ) {
                DivisionResult.OK -> Unit
                DivisionResult.NO_BATTERY -> println(NO_BATTERY_MSG)
                DivisionResult.DIVISION_BY_ZERO -> println(DIVISION_BY_ZERO_MSG)
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
