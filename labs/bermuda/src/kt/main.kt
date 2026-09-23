const val INVALID_COMMAND_MSG: String = "fail: invalid command"
const val INVALID_SIZE_MSG: String = "fail: invalid size"

class Bermuda(size: String) {
    companion object {
        const val DEFAULT_SIZE: String = "P"
        private val ALLOWED_SIZES: List<String> = listOf("P", "M", "G", "GG")

        private fun validateSize(size: String): Unit {
            require(size in ALLOWED_SIZES)
        }

        fun getAllowedSizes(): List<String> = ALLOWED_SIZES.toList()
    }

    private var size: String

    init {
        validateSize(size)
        this.size = size
    }

    fun getSize(): String = size

    fun setSize(size: String): Unit {
        validateSize(size)
        this.size = size
    }

    override fun toString(): String = "size: ($size)"
}

fun main(): Unit {
    var bermuda: Bermuda = Bermuda(Bermuda.DEFAULT_SIZE)

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        try {
            val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
            when {
                parts == listOf("end") -> break
                parts == listOf("show") -> println(bermuda)
                parts.size == 2 && parts[0] == "init" -> bermuda = Bermuda(parts[1])
                parts.size == 2 && parts[0] == "size" -> bermuda.setSize(parts[1])
                else -> println(INVALID_COMMAND_MSG)
            }
        } catch (_: IllegalArgumentException) {
            println(INVALID_SIZE_MSG)
        }
    }
}
