const val DEAD_ANIMAL_MSG: String = "warning: animal is dead"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

class Animal(private val species: String, private val noise: String) {
    companion object {
        const val DEAD_STAGE: Int = 4
    }

    private var lifeStage: Int = 0

    fun makeSound(): String = when (lifeStage) {
        0 -> "---"
        DEAD_STAGE -> "RIP"
        else -> noise
    }

    fun grow(stages: Int): Boolean {
        if (lifeStage == DEAD_STAGE) {
            return false
        }

        lifeStage += stages
        if (lifeStage >= DEAD_STAGE) {
            lifeStage = DEAD_STAGE
            return false
        }
        return true
    }

    override fun toString(): String = "$species:$lifeStage:$noise"
}

fun main(): Unit {
    var currentAnimal: Animal = Animal("", "")

    while (true) {
        val line: String = readLine() ?: break
        println("$" + line)

        val parts: List<String> = line.trim().split(Regex("\\s+"))
        when (parts[0]) {
            "end" -> break
            "init" -> currentAnimal = Animal(parts[1], parts[2])
            "show" -> println(currentAnimal)
            "noise" -> println(currentAnimal.makeSound())
            "grow" -> if (!currentAnimal.grow(parts[1].toInt())) {
                println(DEAD_ANIMAL_MSG)
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
