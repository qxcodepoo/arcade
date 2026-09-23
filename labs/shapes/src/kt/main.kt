import java.util.Locale
import kotlin.math.abs
import kotlin.math.PI

interface Shape {
    fun name(): String
    fun area(): Double
    fun perimeter(): Double
}

data class Point2D(val x: Double, val y: Double) {
    override fun toString(): String = "(${x.format2()}, ${y.format2()})"
}

data class Circle(val center: Point2D, val radius: Double) : Shape {
    override fun name(): String = "Circ"

    override fun area(): Double = PI * radius * radius

    override fun perimeter(): Double = 2.0 * PI * radius

    override fun toString(): String =
        "${name()}: C=$center, R=${radius.format2()}"
}

data class Rectangle(val p1: Point2D, val p2: Point2D) : Shape {
    override fun name(): String = "Rect"

    private fun width(): Double = abs(p1.x - p2.x)

    private fun height(): Double = abs(p1.y - p2.y)

    override fun area(): Double = width() * height()

    override fun perimeter(): Double = 2.0 * (width() + height())

    override fun toString(): String = "${name()}: P1=$p1 P2=$p2"
}

fun info(shape: Shape): String =
    "${shape.name()}: A=${shape.area().format2()} P=${shape.perimeter().format2()}"

fun main(): Unit {
    val shapes: MutableList<Shape> = mutableListOf()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$${line.trimEnd()}")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts == listOf("end") -> break
                parts == listOf("show") -> println(shapes.joinToString("\n"))
                parts == listOf("info") -> println(shapes.joinToString("\n") { info(it) })
                parts.size == 4 && parts[0] == "circle" -> {
                    shapes.add(
                        Circle(
                            Point2D(parts[1].toDouble(), parts[2].toDouble()),
                            parts[3].toDouble(),
                        ),
                    )
                }
                parts.size == 5 && parts[0] == "rect" -> {
                    shapes.add(
                        Rectangle(
                            Point2D(parts[1].toDouble(), parts[2].toDouble()),
                            Point2D(parts[3].toDouble(), parts[4].toDouble()),
                        ),
                    )
                }
                else -> println(INVALID_COMMAND_MSG)
            }
        } catch (_: NumberFormatException) {
            println(INVALID_COMMAND_MSG)
        }
    }
}

fun Double.format2(): String = String.format(Locale.US, "%.2f", this)

const val INVALID_COMMAND_MSG: String = "fail: invalid command"
