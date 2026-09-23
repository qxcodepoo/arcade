const val CANNOT_TURN_ON_MSG: String = "fail: cannot turn on"
const val NOTEBOOK_OFF_MSG: String = "fail: notebook is off"
const val BATTERY_DISCHARGED_MSG: String = "fail: battery discharged"
const val CHARGER_ALREADY_CONNECTED_MSG: String = "fail: charger is already connected"
const val NO_BATTERY_MSG: String = "fail: no battery"
const val NO_CHARGER_MSG: String = "fail: no charger"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

enum class UseResult {
    OK,
    NOTEBOOK_OFF,
    DISCHARGED,
}

class Battery(capacity: Int) {
    private val capacity: Int = capacity
    private var charge: Int = capacity

    fun getCapacity(): Int = capacity

    fun getCharge(): Int = charge

    fun consume(minutes: Int): Boolean {
        if (charge < minutes) {
            charge = 0
            return false
        }
        charge -= minutes
        return true
    }

    fun recharge(amount: Int): Unit {
        charge = minOf(capacity, charge + amount)
    }

    override fun toString(): String = "$charge/$capacity"
}

class Charger(power: Int) {
    private val power: Int = power

    fun getPower(): Int = power

    override fun toString(): String = "${power}W"
}

class Notebook {
    private var inUse: Boolean = false
    private var usageMinutes: Int = 0
    private var battery: Battery? = null
    private var charger: Charger? = null

    fun turnOn(): Boolean {
        if (charger == null && (battery == null || battery?.getCharge() == 0)) {
            return false
        }
        inUse = true
        return true
    }

    fun turnOff(): Unit {
        inUse = false
        usageMinutes = 0
    }

    fun use(minutes: Int): UseResult {
        if (!inUse) {
            return UseResult.NOTEBOOK_OFF
        }

        val currentBattery: Battery? = battery
        if (currentBattery == null) {
            usageMinutes += minutes
            return UseResult.OK
        }

        val currentCharger: Charger? = charger
        if (currentCharger != null) {
            usageMinutes += minutes
            currentBattery.recharge(currentCharger.getPower() * minutes)
            return UseResult.OK
        }

        if (currentBattery.consume(minutes)) {
            usageMinutes += minutes
            return UseResult.OK
        }

        inUse = false
        return UseResult.DISCHARGED
    }

    fun setBattery(battery: Battery): Unit {
        this.battery = battery
    }

    fun removeBattery(): Battery? {
        val removedBattery: Battery = battery ?: return null
        battery = null
        if (charger == null && inUse) {
            turnOff()
        }
        return removedBattery
    }

    fun setCharger(charger: Charger): Boolean {
        if (this.charger != null) {
            return false
        }
        this.charger = charger
        return true
    }

    fun removeCharger(): Charger? {
        val removedCharger: Charger = charger ?: return null
        charger = null
        if ((battery == null || battery?.getCharge() == 0) && inUse) {
            turnOff()
        }
        return removedCharger
    }

    override fun toString(): String {
        var status: String = if (inUse) "on" else "off"
        if (inUse) {
            status += " for $usageMinutes min"
        }
        charger?.let { status += ", Charger $it" }
        battery?.let { status += ", Battery $it" }
        return "Notebook: $status"
    }
}

fun main(): Unit {
    val notebook: Notebook = Notebook()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(notebook)
            parts == listOf("turnOn") -> {
                if (!notebook.turnOn()) {
                    println(CANNOT_TURN_ON_MSG)
                }
            }
            parts == listOf("turnOff") -> notebook.turnOff()
            parts.size == 2 && parts[0] == "use" -> {
                when (notebook.use(parts[1].toInt())) {
                    UseResult.OK -> Unit
                    UseResult.NOTEBOOK_OFF -> println(NOTEBOOK_OFF_MSG)
                    UseResult.DISCHARGED -> println(BATTERY_DISCHARGED_MSG)
                }
            }
            parts.size == 2 && parts[0] == "setBattery" -> notebook.setBattery(Battery(parts[1].toInt()))
            parts == listOf("removeBattery") -> {
                val removedBattery: Battery? = notebook.removeBattery()
                if (removedBattery == null) {
                    println(NO_BATTERY_MSG)
                } else {
                    println("Removed $removedBattery")
                }
            }
            parts.size == 2 && parts[0] == "setCharger" -> {
                if (!notebook.setCharger(Charger(parts[1].toInt()))) {
                    println(CHARGER_ALREADY_CONNECTED_MSG)
                }
            }
            parts == listOf("removeCharger") -> {
                val removedCharger: Charger? = notebook.removeCharger()
                if (removedCharger == null) {
                    println(NO_CHARGER_MSG)
                } else {
                    println("Removed $removedCharger")
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
