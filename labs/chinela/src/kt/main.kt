const val INVALID_SIZE_MSG: String = "fail: invalid size"

class Slipper {
    companion object {
        const val MIN_SIZE: Int = 20
        const val MAX_SIZE: Int = 50
    }

    private var size: Int = MIN_SIZE

    fun getSize(): Int = size

    fun setSize(size: Int): Boolean {
        if (size < MIN_SIZE || size > MAX_SIZE || size % 2 != 0) {
            return false
        }
        this.size = size
        return true
    }
}

fun main(): Unit {
    val slipper: Slipper = Slipper()

    while (true) {
        println("Enter slipper size")
        val size: Int = readln().toInt()
        if (!slipper.setSize(size)) {
            println(INVALID_SIZE_MSG)
        } else {
            break
        }
    }

    println("Congratulations, you bought a slipper size ${slipper.getSize()}")
}
