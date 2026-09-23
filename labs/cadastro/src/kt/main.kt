import java.util.Locale

open class AccountError(message: String) : Exception(message)

class AccountNotFoundError : AccountError("fail: conta nao encontrada")
class InsufficientBalanceError : AccountError("fail: saldo insuficiente")

abstract class Account(val identifier: Int, val clientId: String) {
    var balance: Double = 0.0

    abstract val typeCode: String
    abstract fun monthlyUpdate(): Unit

    fun deposit(value: Double): Unit {
        balance += value
    }

    fun withdraw(value: Double): Unit {
        if (balance < value) {
            throw InsufficientBalanceError()
        }
        balance -= value
    }

    fun transferTo(other: Account, value: Double): Unit {
        withdraw(value)
        other.deposit(value)
    }

    override fun toString(): String =
        "$identifier:$clientId:${balance.money()}:$typeCode"
}

class CheckingAccount(identifier: Int, clientId: String) : Account(identifier, clientId) {
    override val typeCode: String = "CC"

    override fun monthlyUpdate(): Unit {
        balance -= 20.0
    }
}

class SavingsAccount(identifier: Int, clientId: String) : Account(identifier, clientId) {
    override val typeCode: String = "CP"

    override fun monthlyUpdate(): Unit {
        balance *= 1.01
    }
}

class Client(val identifier: String) {
    val accounts: MutableList<Account> = mutableListOf()

    fun addAccount(account: Account): Unit {
        if (accounts.none { it.identifier == account.identifier }) {
            accounts.add(account)
        }
    }

    override fun toString(): String =
        "$identifier [${accounts.joinToString(", ") { it.identifier.toString() }}]"
}

class BankAgency {
    private val clients: MutableMap<String, Client> = linkedMapOf()
    private val accounts: MutableMap<Int, Account> = linkedMapOf()
    private var nextAccountId: Int = 0

    fun addClient(clientId: String): Unit {
        if (clients.containsKey(clientId)) {
            return
        }

        val client: Client = Client(clientId)
        val checking: Account = CheckingAccount(nextAccountId, clientId)
        val savings: Account = SavingsAccount(nextAccountId + 1, clientId)
        nextAccountId += 2
        clients[clientId] = client
        accounts[checking.identifier] = checking
        accounts[savings.identifier] = savings
        client.addAccount(checking)
        client.addAccount(savings)
    }

    private fun getAccount(identifier: Int): Account =
        accounts[identifier] ?: throw AccountNotFoundError()

    fun deposit(identifier: Int, value: Double): Unit {
        getAccount(identifier).deposit(value)
    }

    fun withdraw(identifier: Int, value: Double): Unit {
        getAccount(identifier).withdraw(value)
    }

    fun transfer(source: Int, target: Int, value: Double): Unit {
        val sourceAccount: Account = getAccount(source)
        val targetAccount: Account = getAccount(target)
        sourceAccount.transferTo(targetAccount, value)
    }

    fun monthlyUpdate(): Unit {
        accounts.values.forEach { it.monthlyUpdate() }
    }

    override fun toString(): String {
        val clientLines: String = clients.values.joinToString("\n")
        val accountLines: String = accounts.values.joinToString("\n")
        return "- Clients\n$clientLines\n- Accounts\n$accountLines"
    }
}

fun main(): Unit {
    val agency: BankAgency = BankAgency()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts.size == 2 && parts[0] == "addCli" -> agency.addClient(parts[1])
                parts == listOf("show") -> println(agency)
                parts.size == 3 && parts[0] == "saque" ->
                    agency.withdraw(parts[1].toInt(), parts[2].toDouble())
                parts.size == 3 && parts[0] == "deposito" ->
                    agency.deposit(parts[1].toInt(), parts[2].toDouble())
                parts.size == 4 && parts[0] == "transf" ->
                    agency.transfer(parts[1].toInt(), parts[2].toInt(), parts[3].toDouble())
                parts == listOf("update") -> agency.monthlyUpdate()
                parts == listOf("end") -> break
            }
        } catch (_: NumberFormatException) {
            println(INVALID_ARGUMENT_MSG)
        } catch (error: AccountError) {
            println(error.message ?: INVALID_ARGUMENT_MSG)
        }
    }
}

fun Double.money(): String = String.format(Locale.US, "%.2f", this)

const val INVALID_ARGUMENT_MSG: String = "fail: argumento invalido"
