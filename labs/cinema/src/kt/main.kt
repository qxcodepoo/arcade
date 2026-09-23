const val INVALID_COMMAND_MSG: String = "fail: comando invalido"
const val INVALID_INDEX_MSG: String = "fail: cadeira nao existe"
const val OCCUPIED_SEAT_MSG: String = "fail: cadeira ja esta ocupada"
const val DUPLICATE_CLIENT_MSG: String = "fail: cliente ja esta no cinema"
const val CLIENT_NOT_FOUND_MSG: String = "fail: cliente nao esta no cinema"

enum class ReserveResult {
    OK,
    INVALID_INDEX,
    OCCUPIED,
    DUPLICATE_CLIENT,
}

class Client(id: String, phone: String) {
    private var id: String = id
    private var phone: String = phone

    fun getId(): String = id

    fun setId(clientId: String): Unit {
        id = clientId
    }

    fun getPhone(): String = phone

    fun setPhone(phone: String): Unit {
        this.phone = phone
    }

    override fun toString(): String = "$id:$phone"
}

class Theater(capacity: Int) {
    private val seats: Array<Client?> = Array(capacity) { null }

    private fun search(clientId: String): Int {
        for (index in seats.indices) {
            val client: Client? = seats[index]
            if (client != null && client.getId() == clientId) {
                return index
            }
        }
        return -1
    }

    private fun verifyIndex(index: Int): Boolean = index in seats.indices

    fun reserve(clientId: String, phone: String, index: Int): ReserveResult {
        if (!verifyIndex(index)) {
            return ReserveResult.INVALID_INDEX
        }
        if (seats[index] != null) {
            return ReserveResult.OCCUPIED
        }
        if (search(clientId) != -1) {
            return ReserveResult.DUPLICATE_CLIENT
        }
        seats[index] = Client(clientId, phone)
        return ReserveResult.OK
    }

    fun cancel(clientId: String): Boolean {
        val index: Int = search(clientId)
        if (index == -1) {
            return false
        }
        seats[index] = null
        return true
    }

    fun getSeats(): Array<Client?> = seats.copyOf()

    override fun toString(): String =
        seats.joinToString(separator = " ", prefix = "[", postfix = "]") { client ->
            client?.toString() ?: "-"
        }
}

fun main(): Unit {
    var theater: Theater = Theater(0)

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(theater)
            parts.size == 2 && parts[0] == "init" -> theater = Theater(parts[1].toInt())
            parts.size == 4 && parts[0] == "reserve" -> {
                when (theater.reserve(parts[1], parts[2], parts[3].toInt())) {
                    ReserveResult.OK -> Unit
                    ReserveResult.INVALID_INDEX -> println(INVALID_INDEX_MSG)
                    ReserveResult.OCCUPIED -> println(OCCUPIED_SEAT_MSG)
                    ReserveResult.DUPLICATE_CLIENT -> println(DUPLICATE_CLIENT_MSG)
                }
            }
            parts.size == 2 && parts[0] == "cancel" -> {
                if (!theater.cancel(parts[1])) {
                    println(CLIENT_NOT_FOUND_MSG)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
