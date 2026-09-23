const val INVALID_SIZE_MSG: String = "fail: invalid size"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

class Garment {
    companion object {
        const val DEFAULT_SIZE: String = "P"

        fun getAllowedSizes(): MutableList<String> = mutableListOf("PP", "P", "M", "G", "GG", "XG")
    }

    private var size: String = DEFAULT_SIZE

    constructor(size: String) {
        setSize(size)
    }

    fun getSize(): String = size

    fun setSize(size: String): Boolean {
        if (size !in getAllowedSizes()) {
            return false
        }

        this.size = size
        return true
    }

    override fun toString(): String = "size: ($size)"
}

fun main(): Unit {
    val garment: Garment = Garment(Garment.DEFAULT_SIZE)

    while (true) {
        val line: String = readLine() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(garment)
            parts.size == 2 && parts[0] == "size" -> {
                if (!garment.setSize(parts[1])) {
                    println(INVALID_SIZE_MSG)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
