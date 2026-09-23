const val DRIVER_ALREADY_SET_MSG: String = "fail: driver is already set"
const val DRIVER_NOT_SET_MSG: String = "fail: driver is not set"
const val PASSENGER_ALREADY_SET_MSG: String = "fail: passenger is already set"
const val PASSENGER_NOT_SET_MSG: String = "fail: passenger is not set"
const val PASSENGER_CANNOT_PAY_MSG: String = "fail: passenger does not have enough money"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

enum class SetPassengerResult {
    OK,
    DRIVER_NOT_SET,
    ALREADY_SET,
}

enum class LeaveResult {
    OK,
    DRIVER_NOT_SET,
    PASSENGER_NOT_SET,
    INSUFFICIENT_MONEY,
}

class Person(name: String, money: Int) {
    private val name: String = name
    private var money: Int = money

    fun getName(): String = name

    fun getMoney(): Int = money

    fun pay(amount: Int): Int {
        val paid: Int = minOf(money, amount)
        money -= paid
        return paid
    }

    fun addMoney(amount: Int): Unit {
        money += amount
    }

    override fun toString(): String = "$name:$money"
}

class Uber {
    private var driver: Person? = null
    private var passenger: Person? = null
    private var tripCost: Int = 0

    fun setDriver(driver: Person): Boolean {
        if (this.driver != null) {
            return false
        }
        this.driver = driver
        return true
    }

    fun setPassenger(passenger: Person): SetPassengerResult {
        if (driver == null) {
            return SetPassengerResult.DRIVER_NOT_SET
        }
        if (this.passenger != null) {
            return SetPassengerResult.ALREADY_SET
        }

        this.passenger = passenger
        tripCost = 0
        return SetPassengerResult.OK
    }

    fun drive(distance: Int): Boolean {
        if (driver == null) {
            return false
        }
        if (passenger != null) {
            tripCost += distance
        }
        return true
    }

    fun leave(): Pair<Person?, LeaveResult> {
        val currentDriver: Person = driver ?: return null to LeaveResult.DRIVER_NOT_SET
        val currentPassenger: Person = passenger ?: return null to LeaveResult.PASSENGER_NOT_SET

        val cost: Int = tripCost
        val paid: Int = currentPassenger.pay(cost)
        currentDriver.addMoney(cost)
        val result: LeaveResult = if (paid < cost) {
            LeaveResult.INSUFFICIENT_MONEY
        } else {
            LeaveResult.OK
        }
        passenger = null
        tripCost = 0

        return currentPassenger to result
    }

    override fun toString(): String {
        val driverText: String = driver?.toString() ?: "None"
        val passengerText: String = passenger?.toString() ?: "None"
        return "Cost: $tripCost, Driver: $driverText, Passenger: $passengerText"
    }
}

fun main(): Unit {
    val uber: Uber = Uber()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(uber)
            parts.size == 3 && parts[0] == "setDriver" -> {
                val driver: Person = Person(parts[1], parts[2].toInt())
                if (!uber.setDriver(driver)) {
                    println(DRIVER_ALREADY_SET_MSG)
                }
            }
            parts.size == 3 && parts[0] == "setPass" -> {
                val passenger: Person = Person(parts[1], parts[2].toInt())
                when (uber.setPassenger(passenger)) {
                    SetPassengerResult.OK -> Unit
                    SetPassengerResult.DRIVER_NOT_SET -> println(DRIVER_NOT_SET_MSG)
                    SetPassengerResult.ALREADY_SET -> println(PASSENGER_ALREADY_SET_MSG)
                }
            }
            parts.size == 2 && parts[0] == "drive" -> {
                if (!uber.drive(parts[1].toInt())) {
                    println(DRIVER_NOT_SET_MSG)
                }
            }
            parts == listOf("leavePass") -> {
                val (passenger, result) = uber.leave()
                when (result) {
                    LeaveResult.OK -> Unit
                    LeaveResult.DRIVER_NOT_SET -> println(DRIVER_NOT_SET_MSG)
                    LeaveResult.PASSENGER_NOT_SET -> println(PASSENGER_NOT_SET_MSG)
                    LeaveResult.INSUFFICIENT_MONEY -> println(PASSENGER_CANNOT_PAY_MSG)
                }
                passenger?.let { println("$it left") }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
