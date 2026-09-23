import java.util.Locale

const val INVALID_COMMAND_MSG: String = "fail: comando invalido"
const val WRONG_THICKNESS_MSG: String = "fail: calibre incompatível"
const val BARREL_EMPTY_MSG: String = "fail: nao existe grafite no barril"
const val NO_LEAD_MSG: String = "fail: nao existe grafite no bico"
const val INSUFFICIENT_SIZE_MSG: String = "fail: tamanho insuficiente"
const val INCOMPLETE_PAGE_MSG: String = "fail: folha incompleta"

enum class WriteResult {
    OK,
    NO_LEAD,
    INSUFFICIENT,
    INCOMPLETE,
}

class Lead(thickness: Double, hardness: String, length: Int) {
    private val thickness: Double = thickness
    private val hardness: String = hardness
    private var length: Int = length

    fun getWearPerPage(): Int = when (hardness) {
        "HB" -> 1
        "2B" -> 2
        "4B" -> 4
        else -> 6
    }

    fun getLength(): Int = length

    fun getThickness(): Double = thickness

    fun consume(amount: Int): Boolean {
        val finalLength: Int = length - amount
        if (finalLength < 10) {
            length = 10
            return false
        }
        length = finalLength
        return true
    }

    override fun toString(): String {
        val thicknessText: String = String.format(Locale.US, "%.1f", thickness)
        return "$thicknessText:$hardness:$length"
    }
}

class Pencil(thickness: Double) {
    private val thickness: Double = thickness
    private var tip: Lead? = null
    private val barrel: MutableList<Lead> = mutableListOf()

    fun insert(lead: Lead): Boolean {
        if (thickness != lead.getThickness()) {
            return false
        }
        barrel.add(lead)
        return true
    }

    fun pull(): Pair<Boolean, Lead?> {
        val removedLead: Lead? = tip
        if (removedLead != null) {
            tip = null
            return true to removedLead
        }
        if (barrel.isEmpty()) {
            return false to null
        }
        tip = barrel.removeAt(0)
        return true to null
    }

    fun writePage(): WriteResult {
        val currentLead: Lead = tip ?: return WriteResult.NO_LEAD
        if (currentLead.getLength() == 10) {
            return WriteResult.INSUFFICIENT
        }
        if (!currentLead.consume(currentLead.getWearPerPage())) {
            return WriteResult.INCOMPLETE
        }
        return WriteResult.OK
    }

    override fun toString(): String {
        val thicknessText: String = String.format(Locale.US, "%.1f", thickness)
        val tipText: String = tip?.let { "[$it]" } ?: "[]"
        val barrelText: String = barrel.joinToString(separator = "") { "[$it]" }
        return "calibre: $thicknessText, bico: $tipText, tambor: <$barrelText>"
    }
}

fun main(): Unit {
    var pencil: Pencil = Pencil(0.0)

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
                if (!pencil.insert(lead)) {
                    println(WRONG_THICKNESS_MSG)
                }
            }
            parts == listOf("pull") -> {
                val (success, _) = pencil.pull()
                if (!success) {
                    println(BARREL_EMPTY_MSG)
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
