class InvalidPhoneIndexException : Exception()

class Phone(val label: String, val number: String) {
    companion object {
        const val VALID_CHARS: String = "0123456789()-."
    }

    fun isValid(): Boolean =
        number.isNotEmpty() &&
            number.any { it in '0'..'9' } &&
            number.all { it in VALID_CHARS }

    override fun toString(): String = "$label:$number"
}

class Contact(val name: String) {
    var favorite: Boolean = false

    private val phones: MutableList<Phone> = mutableListOf()

    fun addPhone(label: String, number: String): Boolean {
        val phone: Phone = Phone(label, number)
        if (!phone.isValid()) {
            return false
        }
        phones.add(phone)
        return true
    }

    fun removePhone(index: Int): Unit {
        if (index !in phones.indices) {
            throw InvalidPhoneIndexException()
        }
        phones.removeAt(index)
    }

    fun toggleFavorite(): Unit {
        favorite = !favorite
    }

    override fun toString(): String {
        val marker: String = if (favorite) "@" else "-"
        val phoneList: String = phones.joinToString(separator = ", ")
        return "$marker $name [$phoneList]"
    }
}

class Shell {
    private var contact: Contact = Contact("")
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")

        val args: List<String> = line.split(" ")
        when (args[0]) {
            "end" -> running = false
            "init" -> contact = Contact(args[1])
            "addPhone" -> {
                if (!contact.addPhone(args[1], args[2])) {
                    println("fail: invalid number")
                }
            }
            "removePhone" -> contact.removePhone(args[1].toInt())
            "toggleFavorite" -> contact.toggleFavorite()
            "show" -> println(contact)
            else -> println("fail: invalid command")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: NumberFormatException) {
                println("fail: invalid conversion")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: insufficient parameters")
            } catch (_: InvalidPhoneIndexException) {
                println("fail: invalid index")
            }
        }
    }
}

fun main(): Unit = Shell().main()
