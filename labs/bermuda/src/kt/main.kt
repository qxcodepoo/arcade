class InvalidSizeException : Exception()

class Bermuda(size: String) {
    companion object {
        const val DEFAULT_SIZE: String = "P"
        private val ALLOWED_SIZES: List<String> = listOf("P", "M", "G", "GG")

        private fun validateSize(size: String): Unit {
            if (size !in ALLOWED_SIZES) {
                throw InvalidSizeException()
            }
        }

        fun getAllowedSizes(): List<String> = ALLOWED_SIZES.toList()
    }

    private var size: String
    private var quantity: Int = 0

    init {
        validateSize(size)
        this.size = size
    }

    fun getSize(): String = size

    fun setSize(size: String): Unit {
        validateSize(size)
        this.size = size
    }

    fun setQuantity(quantity: Int): Boolean {
        if (quantity < 0) {
            return false
        }
        this.quantity = quantity
        return true
    }

    override fun toString(): String = "size: ($size)\nquantity: ($quantity)"
}

class Shell {
    private var bermuda: Bermuda = Bermuda(Bermuda.DEFAULT_SIZE)
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")
        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(bermuda)
            "init" -> bermuda = Bermuda(args[1])
            "size" -> bermuda.setSize(args[1])
            "setQuantity" -> {
                if (!bermuda.setQuantity(args[1].toInt())) {
                    println("fail: invalid quantity")
                }
            }
            else -> println("fail: invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: InvalidSizeException) {
                println("fail: invalid size")
            } catch (_: NumberFormatException) {
                println("fail: invalid conversion")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: insufficient parameters")
            }
        }
    }
}

fun main(): Unit = Shell().main()
