import java.util.Locale

class InvalidLeadException : Exception()

class InvalidPencilThicknessException : Exception()

enum class InsertResult {
    OK,
    ALREADY_HAS_LEAD,
    WRONG_THICKNESS,
}

enum class WriteResult {
    OK,
    NO_LEAD,
    INSUFFICIENT,
    INCOMPLETE,
}

class Lead(thickness: Double, hardness: String, size: Int) {
    companion object {
        const val MIN_SIZE: Int = 10
    }

    init {
        if (!thickness.isFinite() || thickness <= 0.0 || hardness !in setOf("HB", "2B", "4B", "6B") || size < MIN_SIZE) {
            throw InvalidLeadException()
        }
    }

    private val thickness: Double = thickness
    private val hardness: String = hardness
    private var size: Int = size

    fun getThickness(): Double = thickness

    fun getHardness(): String = hardness

    fun getSize(): Int = size

    fun getWearPerPage(): Int = when (hardness) {
        "HB" -> 1
        "2B" -> 2
        "4B" -> 4
        else -> 6
    }

    fun consume(amount: Int): Boolean {
        require(amount >= 0)
        val finalSize: Int = size - amount
        if (finalSize < MIN_SIZE) {
            size = MIN_SIZE
            return false
        }

        size = finalSize
        return true
    }

    override fun toString(): String {
        val thicknessText: String = String.format(Locale.US, "%.1f", thickness)
        return "$thicknessText:$hardness:$size"
    }
}

class Pencil(thickness: Double) {
    init {
        if (!thickness.isFinite() || thickness <= 0.0) {
            throw InvalidPencilThicknessException()
        }
    }

    private val thickness: Double = thickness
    private var lead: Lead? = null

    fun getThickness(): Double = thickness

    fun hasLead(): Boolean = lead != null

    fun insert(lead: Lead): InsertResult {
        if (hasLead()) {
            return InsertResult.ALREADY_HAS_LEAD
        }
        if (thickness != lead.getThickness()) {
            return InsertResult.WRONG_THICKNESS
        }

        this.lead = lead
        return InsertResult.OK
    }

    fun remove(): Lead? {
        val removedLead: Lead? = lead
        lead = null
        return removedLead
    }

    fun writePage(): WriteResult {
        val currentLead: Lead = lead ?: return WriteResult.NO_LEAD
        if (currentLead.getSize() <= Lead.MIN_SIZE) {
            return WriteResult.INSUFFICIENT
        }
        if (!currentLead.consume(currentLead.getWearPerPage())) {
            return WriteResult.INCOMPLETE
        }

        return WriteResult.OK
    }

    override fun toString(): String {
        val thicknessText: String = String.format(Locale.US, "%.1f", thickness)
        val leadText: String = lead?.let { "[$it]" } ?: "null"
        return "thickness: $thicknessText, lead: $leadText"
    }
}

class Shell {
    private var pencil: Pencil = Pencil(0.5)
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(pencil)
            "init" -> pencil = Pencil(args[1].toDouble())
            "insert" -> {
                val lead: Lead = Lead(args[1].toDouble(), args[2], args[3].toInt())
                when (pencil.insert(lead)) {
                    InsertResult.OK -> Unit
                    InsertResult.ALREADY_HAS_LEAD -> println("fail: already has lead")
                    InsertResult.WRONG_THICKNESS -> println("fail: wrong thickness")
                }
            }
            "remove" -> {
                if (pencil.remove() == null) {
                    println("fail: no lead")
                }
            }
            "write" -> {
                when (pencil.writePage()) {
                    WriteResult.OK -> Unit
                    WriteResult.NO_LEAD -> println("fail: no lead")
                    WriteResult.INSUFFICIENT -> println("fail: insufficient size")
                    WriteResult.INCOMPLETE -> println("fail: incomplete page")
                }
            }
            else -> println("fail: invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: InvalidPencilThicknessException) {
                println("fail: invalid thickness")
            } catch (_: InvalidLeadException) {
                println("fail: invalid lead")
            } catch (_: NumberFormatException) {
                println("fail: invalid conversion")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: insufficient parameters")
            }
        }
    }
}

fun main(): Unit = Shell().main()
