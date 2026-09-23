const val NOT_SLEEPY_MSG: String = "fail: not sleepy"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

enum class DeathCause(val text: String) {
    NONE("none"),
    WEAKNESS("weakness"),
    DIRT("dirt"),
}

class Pet(energyMax: Int, cleanMax: Int) {
    private val energyMax: Int = energyMax
    private val cleanMax: Int = cleanMax
    private var energy: Int = energyMax
    private var clean: Int = cleanMax
    private var age: Int = 0
    private var alive: Boolean = true
    private var deathCause: DeathCause = DeathCause.NONE

    fun isAlive(): Boolean = alive

    fun getEnergy(): Int = energy

    fun getEnergyMax(): Int = energyMax

    fun getClean(): Int = clean

    fun getCleanMax(): Int = cleanMax

    fun getAge(): Int = age

    fun loseEnergy(amount: Int): Unit {
        energy = maxOf(0, energy - amount)
        if (energy == 0) {
            die(DeathCause.WEAKNESS)
        }
    }

    fun loseClean(amount: Int): Unit {
        clean = maxOf(0, clean - amount)
        if (clean == 0) {
            die(DeathCause.DIRT)
        }
    }

    fun advanceAge(amount: Int): Unit {
        if (alive) {
            age += amount
        }
    }

    fun restoreEnergy(): Unit {
        if (alive) {
            energy = energyMax
        }
    }

    fun restoreClean(): Unit {
        if (alive) {
            clean = cleanMax
        }
    }

    private fun die(cause: DeathCause): Unit {
        if (alive) {
            alive = false
            deathCause = cause
        }
    }

    override fun toString(): String {
        val state: String = "energy:$energy/$energyMax, clean:$clean/$cleanMax, age:$age"
        return if (alive) state else "$state, death:${deathCause.text}"
    }
}

class Game(private val pet: Pet) {
    fun isAlive(): Boolean = pet.isAlive()

    fun isSleepy(): Boolean = pet.getEnergyMax() - pet.getEnergy() >= 5

    fun play(): Boolean {
        if (!pet.isAlive()) {
            return false
        }
        pet.advanceAge(1)
        pet.loseEnergy(2)
        pet.loseClean(3)
        return true
    }

    fun shower(): Boolean {
        if (!pet.isAlive()) {
            return false
        }
        pet.advanceAge(2)
        pet.loseEnergy(3)
        pet.restoreClean()
        return true
    }

    fun sleep(): Boolean {
        if (!pet.isAlive()) {
            return true
        }
        if (!isSleepy()) {
            return false
        }
        val lostEnergy: Int = pet.getEnergyMax() - pet.getEnergy()
        pet.advanceAge(lostEnergy)
        pet.restoreEnergy()
        return true
    }

    override fun toString(): String = pet.toString()
}

fun main(): Unit {
    var game: Game = Game(Pet(0, 0))

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(game)
            parts.size == 3 && parts[0] == "init" -> {
                game = Game(Pet(parts[1].toInt(), parts[2].toInt()))
            }
            parts == listOf("play") -> game.play()
            parts == listOf("shower") -> game.shower()
            parts == listOf("sleep") -> {
                if (!game.sleep()) {
                    println(NOT_SLEEPY_MSG)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
