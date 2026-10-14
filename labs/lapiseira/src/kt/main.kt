import java.util.Locale

class InvalidLeadException : RuntimeException()
class InvalidPencilThicknessException : RuntimeException()

enum class WriteResult {
    OK,
    NO_LEAD,
    INSUFFICIENT,
    INCOMPLETE,
}

class Lead(thickness: Double, hardness: String, length: Int) {
    init {
        if (!thickness.isFinite() || thickness <= 0.0 || hardness !in setOf("HB", "2B", "4B", "6B") || length < 10) {
            throw InvalidLeadException()
        }
    }

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
        require(amount >= 0)
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
    init {
        if (!thickness.isFinite() || thickness < 0.0) {
            throw InvalidPencilThicknessException()
        }
    }

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
        if (currentLead.getLength() <= 10) {
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

class Shell {
    private var pencil: Pencil = Pencil(0.0)
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
                if (!pencil.insert(lead)) {
                    println("fail: calibre incompatível")
                }
            }
            "pull" -> {
                val (success, _) = pencil.pull()
                if (!success) {
                    println("fail: nao existe grafite no barril")
                }
            }
            "write" -> {
                when (pencil.writePage()) {
                    WriteResult.OK -> Unit
                    WriteResult.NO_LEAD -> println("fail: nao existe grafite no bico")
                    WriteResult.INSUFFICIENT -> println("fail: tamanho insuficiente")
                    WriteResult.INCOMPLETE -> println("fail: folha incompleta")
                }
            }
            else -> println("fail: comando invalido")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: NumberFormatException) {
                println("fail: conversao invalida")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: parametros insuficientes")
            } catch (_: InvalidPencilThicknessException) {
                println("fail: calibre invalido")
            } catch (_: InvalidLeadException) {
                println("fail: grafite invalido")
            }
        }
    }
}

fun main(): Unit = Shell().main()
