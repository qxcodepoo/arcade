const val INVALID_COMMAND_MSG: String = "fail: invalid command"

class Person(val name: String, val age: Int) {
    override fun toString(): String = "$name:$age"
}

fun main(): Unit {
    val people: MutableList<Person> = mutableListOf()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts.size == 3 && parts[0] == "pushBack" -> {
                people.add(Person(parts[1], parts[2].toInt()))
            }
            parts.size == 3 && parts[0] == "pushFront" -> {
                people.add(0, Person(parts[1], parts[2].toInt()))
            }
            parts == listOf("popBack") -> {
                if (people.isNotEmpty()) {
                    people.removeAt(people.lastIndex)
                }
            }
            parts == listOf("popFront") -> {
                if (people.isNotEmpty()) {
                    people.removeAt(0)
                }
            }
            parts.size == 2 && parts[0] == "removeName" -> {
                val index: Int = people.indexOfFirst { it.name == parts[1] }
                if (index >= 0) {
                    people.removeAt(index)
                }
            }
            parts.size == 2 && parts[0] == "removeBelowAge" -> {
                val minimumAge: Int = parts[1].toInt()
                people.removeAll { it.age < minimumAge }
            }
            parts == listOf("show") -> {
                println(people.joinToString(prefix = "[", postfix = "]"))
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
