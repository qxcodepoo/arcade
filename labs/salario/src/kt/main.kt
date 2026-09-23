import java.util.Locale

open class PayrollError(message: String) : Exception(message)

class DailyLimitError : PayrollError("fail: limite de diarias atingido")
class DailyNotAllowedError : PayrollError("fail: terc nao pode receber diaria")
class EmployeeNotFoundError : PayrollError("fail: funcionario nao encontrado")

abstract class Employee(val name: String) {
    var dailyCount: Int = 0
        private set

    abstract fun baseSalary(): Double
    abstract val typeCode: String
    abstract fun dailyLimit(): Int
    abstract fun details(): String

    fun addDaily(): Unit {
        val limit: Int = dailyLimit()
        if (limit == 0) {
            throw DailyNotAllowedError()
        }
        if (dailyCount >= limit) {
            throw DailyLimitError()
        }
        dailyCount += 1
    }

    fun salary(bonus: Double, totalEmployees: Int): Double {
        val sharedBonus: Double = if (totalEmployees > 0) bonus / totalEmployees else 0.0
        return baseSalary() + dailyCount * 100.0 + sharedBonus
    }
}

class Professor(name: String, val level: String) : Employee(name) {
    override fun baseSalary(): Double =
        SALARIES[level] ?: throw NoSuchElementException()

    override val typeCode: String = "prof"
    override fun dailyLimit(): Int = 2
    override fun details(): String = "$typeCode:$name:$level"

    companion object {
        private val SALARIES: Map<String, Double> = mapOf(
            "A" to 3000.0,
            "B" to 5000.0,
            "C" to 7000.0,
            "D" to 9000.0,
            "E" to 11000.0,
        )
    }
}

class Staff(name: String, val level: Int) : Employee(name) {
    override fun baseSalary(): Double = 3000.0 + 300.0 * level
    override val typeCode: String = "sta"
    override fun dailyLimit(): Int = 1
    override fun details(): String = "$typeCode:$name:$level"
}

class Contractor(name: String, val hours: Int, val unhealthy: Boolean) : Employee(name) {
    override fun baseSalary(): Double = hours * 4.0 + if (unhealthy) 500.0 else 0.0
    override val typeCode: String = "ter"
    override fun dailyLimit(): Int = 0
    override fun details(): String = "$typeCode:$name:$hours:${if (unhealthy) "sim" else "nao"}"
}

class Payroll {
    private val employees: MutableMap<String, Employee> = linkedMapOf()
    private var bonus: Double = 0.0

    fun add(employee: Employee): Unit {
        if (!employees.containsKey(employee.name)) {
            employees[employee.name] = employee
        }
    }

    fun remove(name: String): Unit {
        employees.remove(name)
    }

    fun addDaily(name: String): Unit {
        (employees[name] ?: throw EmployeeNotFoundError()).addDaily()
    }

    fun setBonus(value: Double): Unit {
        bonus = value
    }

    fun show(name: String? = null): String {
        val selected: List<Employee> = if (name == null) {
            employees.values.toList()
        } else {
            listOf(employees[name] ?: throw EmployeeNotFoundError())
        }
        return selected.joinToString("\n") { employee ->
            "${employee.details()}:${employee.salary(bonus, employees.size).wholeMoney()}"
        }
    }
}

fun main(): Unit {
    val payroll: Payroll = Payroll()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts.size == 3 && parts[0] == "addProf" ->
                    payroll.add(Professor(parts[1], parts[2]))
                parts.size == 3 && parts[0] == "addSta" ->
                    payroll.add(Staff(parts[1], parts[2].toInt()))
                parts.size == 4 && parts[0] == "addTer" ->
                    payroll.add(Contractor(parts[1], parts[2].toInt(), parts[3] == "sim"))
                parts.size == 2 && parts[0] == "rm" -> payroll.remove(parts[1])
                parts.size == 2 && parts[0] == "addDiaria" -> payroll.addDaily(parts[1])
                parts.size == 2 && parts[0] == "setBonus" -> payroll.setBonus(parts[1].toDouble())
                parts.size == 2 && parts[0] == "show" -> println(payroll.show(parts[1]))
                parts == listOf("showAll") -> println(payroll.show())
                parts == listOf("end") -> break
            }
        } catch (_: NumberFormatException) {
            println(INVALID_ARGUMENT_MSG)
        } catch (error: PayrollError) {
            println(error.message ?: INVALID_ARGUMENT_MSG)
        } catch (_: NoSuchElementException) {
            println("fail: funcionario nao encontrado")
        }
    }
}

fun Double.wholeMoney(): String = String.format(Locale.US, "%.0f", this)

const val INVALID_ARGUMENT_MSG: String = "fail: argumento invalido"
