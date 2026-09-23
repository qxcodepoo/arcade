enum class EnterResult {
    OK,
    TOO_OLD,
    BUSY,
}

enum class DriveResult {
    OK,
    BUY_TIME_FIRST,
    EMPTY_MOTORCYCLE,
    TIME_FINISHED,
}

class Person(name: String, age: Int) {
    private val name: String = name
    private val age: Int = age

    fun getName(): String = name
    fun getAge(): Int = age
    fun canDrive(maxAge: Int): Boolean = age <= maxAge
    override fun toString(): String = "$name:$age"
}

class Motorcycle(size: Int) {
    private var person: Person? = null
    private val size: Int = size
    private var remainingMinutes: Int = 0

    fun getSize(): Int = size

    fun getTime(): Int = remainingMinutes

    fun getPerson(): Person? = person

    fun enter(person: Person): EnterResult {
        if (this.person != null) {
            return EnterResult.BUSY
        }
        if (!person.canDrive(size)) {
            return EnterResult.TOO_OLD
        }
        this.person = person
        return EnterResult.OK
    }

    fun leave(): Person? {
        val currentPerson: Person = person ?: return null
        person = null
        return currentPerson
    }

    fun buy(minutes: Int): Unit {
        remainingMinutes += minutes
    }

    fun drive(minutes: Int): DriveResult {
        if (remainingMinutes == 0) {
            return DriveResult.BUY_TIME_FIRST
        }
        if (person == null) {
            return DriveResult.EMPTY_MOTORCYCLE
        }
        if (remainingMinutes < minutes) {
            remainingMinutes = 0
            return DriveResult.TIME_FINISHED
        }

        remainingMinutes -= minutes
        return DriveResult.OK
    }

    override fun toString(): String {
        val personText: String = person?.toString() ?: "empty"
        return "size:$size, time:$remainingMinutes, person:($personText)"
    }
}

fun main(): Unit {
    var motorcycle: Motorcycle = Motorcycle(10)

    val driveMessages: Map<DriveResult, String> = mapOf(
        DriveResult.BUY_TIME_FIRST to "fail: buy time first",
        DriveResult.EMPTY_MOTORCYCLE to "fail: empty motorcycle",
        DriveResult.TIME_FINISHED to "fail: time finished",
    )
    
    val enterMessages: Map<EnterResult, String> = mapOf(
        EnterResult.TOO_OLD to "fail: too old to drive",
        EnterResult.BUSY to "fail: busy motorcycle",
    )

    while (true) {
        val line: String = readLine() ?: break
        println("$" + line)

        val parts: List<String> = line.trim().split(Regex("\\s+"))
        when (parts[0]) {
            "end" -> break
            "init" -> motorcycle = Motorcycle(parts[1].toInt())
            "show" -> println(motorcycle)
            "enter" -> {
                val result: EnterResult = motorcycle.enter(Person(parts[1], parts[2].toInt()))
                if (result != EnterResult.OK) {
                    println(enterMessages[result])
                }
            }
            "leave" -> {
                val person: Person? = motorcycle.leave()
                if (person == null) {
                    println("fail: empty motorcycle")
                } else {
                    println(person)
                }
            }
            "buy" -> motorcycle.buy(parts[1].toInt())
            "drive" -> {
                val result: DriveResult = motorcycle.drive(parts[1].toInt())
                if (result != DriveResult.OK) {
                    println(driveMessages[result])
                }
            }
            else -> println("arg inválido")
        }
    }
}
