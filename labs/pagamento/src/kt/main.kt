import java.util.Locale

open class PaymentError(message: String) : Exception(message)

class InvalidAmountError : PaymentError("invalid amount")

class InsufficientLimitError : PaymentError("insufficient credit limit")

abstract class PaymentMethod {
    abstract fun process(amount: Double): String
}

class CreditCard(val holder: String, var limit: Double) : PaymentMethod() {
    override fun process(amount: Double): String {
        if (amount > limit) {
            throw InsufficientLimitError()
        }
        limit -= amount
        return "Payment approved for $holder. Remaining limit: ${limit.money()}"
    }
}

class Pix(val key: String, val bank: String) : PaymentMethod() {
    override fun process(amount: Double): String =
        "PIX sent through $bank using key $key"
}

class Boleto(val barcode: String, val dueDate: String) : PaymentMethod() {
    override fun process(amount: Double): String =
        "Boleto generated. Waiting for payment..."
}

class Payment(
    val amount: Double,
    val description: String,
    private val method: PaymentMethod,
) {
    fun process(): String {
        if (amount <= 0.0) {
            throw InvalidAmountError()
        }
        val result: String = method.process(amount)
        return "Payment of R$ ${amount.money()}: $description\n$result"
    }
}

fun processPayments(payments: List<Payment>): List<String> {
    val results: MutableList<String> = mutableListOf()
    for (payment in payments) {
        try {
            results.add(payment.process())
        } catch (error: PaymentError) {
            results.add("Error: ${error.message}")
        }
    }
    return results
}

fun Double.money(): String = String.format(Locale.US, "%.2f", this)

fun main(): Unit {
    val clientYCard: CreditCard = CreditCard("Client Y", 700.0)
    val payments: List<Payment> = listOf(
        Payment(150.0, "Sports shirt", Pix("email@example.com", "XPTO")),
        Payment(400.0, "Sports shoes", CreditCard("Client X", 500.0)),
        Payment(89.9, "Kotlin book", Boleto("123", "2026-01-10")),
        Payment(800.0, "Notebook", clientYCard),
        Payment(700.0, "Client Y notebook", clientYCard),
        Payment(25.0, "Coffee", Pix("key", "Bank")),
        Payment(0.0, "Invalid", Pix("key", "Bank")),
    )

    for (result in processPayments(payments)) {
        println(result)
    }
}
