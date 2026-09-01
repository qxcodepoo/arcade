enum class DriveResult {
    OK,
    NO_PASSENGERS,
    INCOMPLETE,
    NO_GAS,
}

class Car {
    var pass: Int = 0
    val passMax: Int = 2
    var gas: Int = 0
    val gasMax: Int = 100
    var km: Int = 0

    fun enter(): Boolean {
        if (pass < passMax) {
            pass += 1
            return true
        }

        return false
    }

    fun leave(): Boolean {
        if (pass > 0) {
            pass -= 1
            return true
        }

        return false
    }

    fun fuel(increment: Int) {
        gas += increment

        if (gas > gasMax) {
            gas = gasMax
        }
    }

    fun drive(distance: Int): DriveResult {
        if (pass == 0) {
            return DriveResult.NO_PASSENGERS
        }

        if (gas == 0) {
            return DriveResult.NO_GAS
        }

        if (gas < distance) {
            km += gas
            gas = 0
            return DriveResult.INCOMPLETE
        }

        gas -= distance
        km += distance
        return DriveResult.OK
    }

    override fun toString(): String {
        return "pass: $pass, gas: $gas, km: $km"
    }
}

private const val CAR_FULL_MSG = "fail: limite de pessoas atingido"
private const val CAR_EMPTY_MSG = "fail: nao ha ninguem no carro"
private const val NO_GAS_MSG = "fail: tanque vazio"
private const val INCOMPLETE_TRIP_MSG = "fail: viagem incompleta"
private const val INVALID_COMMAND_MSG = "fail: comando invalido"

fun main() {
    val car = Car()

    while (true) {
        val line = readLine() ?: break
        println("\$$line")

        val parts = line.split(" ")
        val cmd = parts[0]

        when (cmd) {
            "end" -> break
            "show" -> println(car)
            "enter" -> {
                if (!car.enter()) {
                    println(CAR_FULL_MSG)
                }
            }
            "leave" -> {
                if (!car.leave()) {
                    println(CAR_EMPTY_MSG)
                }
            }
            "fuel" -> car.fuel(parts[1].toInt())
            "drive" -> when (car.drive(parts[1].toInt())) {
                DriveResult.NO_PASSENGERS -> println(CAR_EMPTY_MSG)
                DriveResult.NO_GAS -> println(NO_GAS_MSG)
                DriveResult.INCOMPLETE -> println(INCOMPLETE_TRIP_MSG)
                DriveResult.OK -> Unit
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
