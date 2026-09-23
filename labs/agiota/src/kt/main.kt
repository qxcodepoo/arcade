class LoanError(message: String) : RuntimeException(message)

class Client(
    val codename: String,
    val creditLimit: Int,
) {
    private var currentDebt: Int = 0

    val debt: Int
        get() = currentDebt

    fun borrow(amount: Int): Unit {
        requirePositive(amount)
        if (amount > creditLimit - currentDebt) {
            throw LoanError("credit limit exceeded")
        }
        currentDebt += amount
    }

    fun pay(amount: Int): Unit {
        requirePositive(amount)
        if (amount > currentDebt) {
            throw LoanError("payment exceeds debt")
        }
        currentDebt -= amount
    }

    private fun requirePositive(amount: Int): Unit {
        if (amount <= 0) {
            throw LoanError("amount must be positive")
        }
    }

    override fun toString(): String = "$codename $debt/$creditLimit"
}

class LendingOffice {
    private val clientsByCodename: MutableMap<String, Client> = linkedMapOf()

    private fun requireClient(codename: String): Client =
        clientsByCodename[codename] ?: throw LoanError("client not found")

    fun addClient(codename: String, creditLimit: Int): Unit {
        if (clientsByCodename.containsKey(codename)) {
            throw LoanError("client already exists")
        }
        clientsByCodename[codename] = Client(codename, creditLimit)
    }

    fun borrow(codename: String, amount: Int): Unit {
        requireClient(codename).borrow(amount)
    }

    fun pay(codename: String, amount: Int): Unit {
        requireClient(codename).pay(amount)
    }

    fun removeClient(codename: String): Unit {
        requireClient(codename)
        clientsByCodename.remove(codename)
    }

    fun clients(): List<Client> =
        clientsByCodename.values.sortedBy { it.codename }
}

fun main(): Unit {
    val office: LendingOffice = LendingOffice()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$${line.trimEnd()}")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts == listOf("end") -> break
                parts == listOf("show") -> {
                    for (client in office.clients()) {
                        println(":) $client")
                    }
                }
                parts.size == 3 && parts[0] == "addClient" ->
                    office.addClient(parts[1], parts[2].toInt())
                parts.size == 3 && parts[0] == "borrow" ->
                    office.borrow(parts[1], parts[2].toInt())
                parts.size == 3 && parts[0] == "pay" ->
                    office.pay(parts[1], parts[2].toInt())
                parts.size == 2 && parts[0] == "removeClient" ->
                    office.removeClient(parts[1])
                else -> println("fail: invalid command")
            }
        } catch (error: LoanError) {
            println("fail: ${error.message}")
        } catch (error: NumberFormatException) {
            println("fail: invalid command")
        }
    }
}
