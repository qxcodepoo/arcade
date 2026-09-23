const val INVALID_SIZE_MSG: String = "fail: invalid size"

class Shirt {
    companion object {
        const val DEFAULT_SIZE: String = "P"

        fun getAllowedSizes(): List<String> = mutableListOf("PP", "P", "M", "G", "GG", "XG")
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
}

fun main(): Unit {
    val shirt: Shirt = Shirt(Shirt.DEFAULT_SIZE)

    while (true) {
        println("Enter shirt size")
        val size: String = readln()
        if (shirt.setSize(size)) {
            break
        }
        println(INVALID_SIZE_MSG)
        println("Allowed sizes are: ${Shirt.getAllowedSizes().joinToString(", ")}")
    }

    println("Congratulations, you bought a shirt size ${shirt.getSize()}")
}
