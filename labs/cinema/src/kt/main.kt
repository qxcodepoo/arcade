enum class ReserveResult {
    OK,
    OCCUPIED,
    DUPLICATE_CLIENT,
}

class InvalidCapacityException : Exception()

class InvalidSeatIndexException : Exception()

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
    private val seats: Array<Client?>

    init {
        if (capacity < 0) {
            throw InvalidCapacityException()
        }
        seats = Array(capacity) { null }
    }

    private fun search(clientId: String): Int {
        for (index in seats.indices) {
            val client: Client? = seats[index]
            if (client != null && client.getId() == clientId) {
                return index
            }
        }
        return -1
    }

    private fun validateIndex(index: Int): Unit {
        if (index !in seats.indices) {
            throw InvalidSeatIndexException()
        }
    }

    fun reserve(clientId: String, phone: String, index: Int): ReserveResult {
        validateIndex(index)
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

class Shell {
    private var theater: Theater = Theater(0)
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "show" -> println(theater)
            "init" -> theater = Theater(args[1].toInt())
            "reserve" -> {
                when (theater.reserve(args[1], args[2], args[3].toInt())) {
                    ReserveResult.OK -> Unit
                    ReserveResult.OCCUPIED -> println("fail: cadeira ja esta ocupada")
                    ReserveResult.DUPLICATE_CLIENT -> println("fail: cliente ja esta no cinema")
                }
            }
            "cancel" -> {
                if (!theater.cancel(args[1])) {
                    println("fail: cliente nao esta no cinema")
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
            } catch (_: InvalidCapacityException) {
                println("fail: capacidade invalida")
            } catch (_: InvalidSeatIndexException) {
                println("fail: cadeira nao existe")
            }
        }
    }
}

fun main(): Unit = Shell().main()
