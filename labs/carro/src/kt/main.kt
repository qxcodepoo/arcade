const val CAR_FULL_MSG: String = "fail: car is full"
const val CAR_EMPTY_MSG: String = "fail: car is empty"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

enum class DriveResult {
    OK,
    NO_PASSENGERS,
    INCOMPLETE,
    NO_GAS,
}

class Car {
    private var passengerCount: Int = 0
    private val maxPassengers: Int = 2
    private var fuelAmount: Int = 0
    private val maxFuel: Int = 100
    private var distanceTraveled: Int = 0

    fun enter(): Boolean {
        if (passengerCount >= maxPassengers) {
            return false
        }
        passengerCount++
        return true
    }

    fun leave(): Boolean {
        if (passengerCount == 0) {
            return false
        }
        passengerCount--
        return true
    }

    fun refuel(liters: Int): Unit {
        fuelAmount += liters
        if (fuelAmount > maxFuel) {
            fuelAmount = maxFuel
        }
    }

    fun drive(distance: Int): DriveResult {
        if (passengerCount == 0) {
            return DriveResult.NO_PASSENGERS
        }
        if (fuelAmount == 0) {
            return DriveResult.NO_GAS
        }
        if (fuelAmount < distance) {
            distanceTraveled += fuelAmount
            fuelAmount = 0
            return DriveResult.INCOMPLETE
        }

        fuelAmount -= distance
        distanceTraveled += distance
        return DriveResult.OK
    }

    override fun toString(): String =
        "pass: $passengerCount, gas: $fuelAmount, km: $distanceTraveled"
}

fun main(): Unit {
    var car: Car = Car()

    while (true) {
        val line: String = readLine() ?: break
        println("$" + line)

        val parts: List<String> = line.trim().split(Regex("\\s+"))
        when (parts[0]) {
            "end" -> break
            "show" -> println(car)
            "enter" -> if (!car.enter()) {
                println(CAR_FULL_MSG)
            }
            "leave" -> if (!car.leave()) {
                println(CAR_EMPTY_MSG)
            }
            "refuel" -> car.refuel(parts[1].toInt())
            "drive" -> when (car.drive(parts[1].toInt())) {
                DriveResult.OK -> Unit
                DriveResult.NO_PASSENGERS -> println(CAR_EMPTY_MSG)
                DriveResult.INCOMPLETE -> println("fail: incomplete trip")
                DriveResult.NO_GAS -> println("fail: empty tank")
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
