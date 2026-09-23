import java.util.Locale

const val ALREADY_HAS_LEAD_MSG: String = "fail: already has lead"
const val WRONG_THICKNESS_MSG: String = "fail: wrong thickness"
const val NO_LEAD_MSG: String = "fail: no lead"
const val INSUFFICIENT_SIZE_MSG: String = "fail: insufficient size"
const val INCOMPLETE_PAGE_MSG: String = "fail: incomplete page"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

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
        if (currentLead.getSize() == Lead.MIN_SIZE) {
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

fun main(): Unit {
    var pencil: Pencil = Pencil(0.5)

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(pencil)
            parts.size == 2 && parts[0] == "init" -> pencil = Pencil(parts[1].toDouble())
            parts.size == 4 && parts[0] == "insert" -> {
                val lead: Lead = Lead(parts[1].toDouble(), parts[2], parts[3].toInt())
                when (pencil.insert(lead)) {
                    InsertResult.OK -> Unit
                    InsertResult.ALREADY_HAS_LEAD -> println(ALREADY_HAS_LEAD_MSG)
                    InsertResult.WRONG_THICKNESS -> println(WRONG_THICKNESS_MSG)
                }
            }
            parts == listOf("remove") -> {
                if (pencil.remove() == null) {
                    println(NO_LEAD_MSG)
                }
            }
            parts == listOf("write") -> {
                when (pencil.writePage()) {
                    WriteResult.OK -> Unit
                    WriteResult.NO_LEAD -> println(NO_LEAD_MSG)
                    WriteResult.INSUFFICIENT -> println(INSUFFICIENT_SIZE_MSG)
                    WriteResult.INCOMPLETE -> println(INCOMPLETE_PAGE_MSG)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
