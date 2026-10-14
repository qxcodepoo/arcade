class InvalidSeatIndexException : RuntimeException()

enum class EnterResult {
    OK,
    OCCUPIED_SEAT,
    PERSON_TOO_YOUNG,
}

enum class DriveResult {
    OK,
    DRIVER_NOT_SET,
    INVALID_DISTANCE,
}

data class Person(val name: String, val age: Int) {
    override fun toString(): String = "$name:$age"
}

class Fusca {
    companion object {
        const val SEAT_COUNT: Int = 4
    }

    private val seats: Array<Person?> = arrayOfNulls(SEAT_COUNT)
    private var distanceKm: Int = 0

    private fun checkSeatIndex(index: Int): Unit {
        if (index !in seats.indices) {
            throw InvalidSeatIndexException()
        }
    }

    fun enter(person: Person, index: Int): EnterResult {
        checkSeatIndex(index)
        if (seats[index] != null) {
            return EnterResult.OCCUPIED_SEAT
        }
        if (index == 0 && person.age < 18 || index == 1 && person.age < 10) {
            return EnterResult.PERSON_TOO_YOUNG
        }
        seats[index] = person
        return EnterResult.OK
    }

    fun leave(index: Int): Person? {
        checkSeatIndex(index)
        val person: Person? = seats[index]
        seats[index] = null
        return person
    }

    fun drive(distance: Int): DriveResult {
        if (seats[0] == null) {
            return DriveResult.DRIVER_NOT_SET
        }
        if (distance <= 0) {
            return DriveResult.INVALID_DISTANCE
        }
        distanceKm += distance
        return DriveResult.OK
    }

    override fun toString(): String {
        val seatStates: String = seats.mapIndexed { index, person ->
            val value: String = person?.toString() ?: "(empty)"
            "$index:$value"
        }.joinToString(", ")
        return "seats: [$seatStates], km: $distanceKm"
    }
}

class Shell {
    private val fusca: Fusca = Fusca()
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(fusca)
            "enter" -> {
                when (fusca.enter(Person(args[1], args[2].toInt()), args[3].toInt())) {
                    EnterResult.OK -> Unit
                    EnterResult.OCCUPIED_SEAT -> println("fail: occupied seat")
                    EnterResult.PERSON_TOO_YOUNG -> println("fail: person is too young for this seat")
                }
            }
            "leave" -> fusca.leave(args[1].toInt())?.let { println(it) }
            "drive" -> {
                when (fusca.drive(args[1].toInt())) {
                    DriveResult.OK -> Unit
                    DriveResult.DRIVER_NOT_SET -> println("fail: driver is not set")
                    DriveResult.INVALID_DISTANCE -> println("fail: distance must be positive")
                }
            }
            else -> println("fail: invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: NumberFormatException) {
                println("fail: invalid conversion")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: insufficient parameters")
            } catch (_: InvalidSeatIndexException) {
                println("fail: invalid seat")
            }
        }
    }
}

fun main(): Unit = Shell().main()
