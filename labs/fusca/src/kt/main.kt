const val INVALID_COMMAND_MSG: String = "fail: invalid command"
const val INVALID_SEAT_MSG: String = "fail: invalid seat"
const val OCCUPIED_SEAT_MSG: String = "fail: occupied seat"
const val PERSON_TOO_YOUNG_MSG: String = "fail: person is too young for this seat"
const val DRIVER_NOT_SET_MSG: String = "fail: driver is not set"
const val INVALID_DISTANCE_MSG: String = "fail: distance must be positive"

class OccupiedSeatException : RuntimeException()
class PersonTooYoungException : RuntimeException()
class DriverNotSetException : RuntimeException()

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
            throw IndexOutOfBoundsException("invalid seat index")
        }
    }

    fun enter(person: Person, index: Int): Unit {
        checkSeatIndex(index)
        if (seats[index] != null) {
            throw OccupiedSeatException()
        }
        if (index == 0 && person.age < 18 || index == 1 && person.age < 10) {
            throw PersonTooYoungException()
        }
        seats[index] = person
    }

    fun leave(index: Int): Person? {
        checkSeatIndex(index)
        val person: Person? = seats[index]
        seats[index] = null
        return person
    }

    fun drive(distance: Int): Unit {
        if (seats[0] == null) {
            throw DriverNotSetException()
        }
        require(distance > 0)
        distanceKm += distance
    }

    override fun toString(): String {
        val seatStates: String = seats.mapIndexed { index, person ->
            val value: String = person?.toString() ?: "(empty)"
            "$index:$value"
        }.joinToString(", ")
        return "seats: [$seatStates], km: $distanceKm"
    }
}

fun main(): Unit {
    val fusca: Fusca = Fusca()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        try {
            val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
            when {
                parts == listOf("end") -> break
                parts == listOf("show") -> println(fusca)
                parts.size == 4 && parts[0] == "enter" -> {
                    fusca.enter(Person(parts[1], parts[2].toInt()), parts[3].toInt())
                }
                parts.size == 2 && parts[0] == "leave" -> {
                    fusca.leave(parts[1].toInt())?.let { println(it) }
                }
                parts.size == 2 && parts[0] == "drive" -> fusca.drive(parts[1].toInt())
                else -> println(INVALID_COMMAND_MSG)
            }
        } catch (_: IndexOutOfBoundsException) {
            println(INVALID_SEAT_MSG)
        } catch (_: OccupiedSeatException) {
            println(OCCUPIED_SEAT_MSG)
        } catch (_: PersonTooYoungException) {
            println(PERSON_TOO_YOUNG_MSG)
        } catch (_: DriverNotSetException) {
            println(DRIVER_NOT_SET_MSG)
        } catch (_: NumberFormatException) {
            println(INVALID_COMMAND_MSG)
        } catch (_: IllegalArgumentException) {
            println(INVALID_DISTANCE_MSG)
        }
    }
}
