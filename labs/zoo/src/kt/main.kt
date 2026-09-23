abstract class Animal(val name: String) {
    abstract fun makeSound(): String
    abstract fun move(): String
}

class Lion(name: String) : Animal(name) {
    override fun makeSound(): String = "roar"
    override fun move(): String = "run"
}

class Elephant(name: String) : Animal(name) {
    override fun makeSound(): String = "trumpet"
    override fun move(): String = "walk"
}

class Snake(name: String) : Animal(name) {
    override fun makeSound(): String = "hiss"
    override fun move(): String = "slither"
}

fun present(animal: Animal): String =
    "${animal.name}: ${animal.makeSound()}, ${animal.move()}"

fun main(): Unit {
    val animals: List<Animal> = listOf(
        Lion("Simba"),
        Elephant("Babar"),
        Snake("Kaa"),
    )

    for (animal in animals) {
        println(present(animal))
    }
}
