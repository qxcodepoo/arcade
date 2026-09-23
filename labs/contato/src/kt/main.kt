const val INVALID_NUMBER_MSG: String = "fail: invalid number"
const val INVALID_INDEX_MSG: String = "fail: invalid index"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

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

    fun removePhone(index: Int): Boolean {
        if (index !in phones.indices) {
            return false
        }
        phones.removeAt(index)
        return true
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

fun main(): Unit {
    var contact: Contact = Contact("")

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts.size == 2 && parts[0] == "init" -> contact = Contact(parts[1])
            parts.size == 3 && parts[0] == "addPhone" -> {
                if (!contact.addPhone(parts[1], parts[2])) {
                    println(INVALID_NUMBER_MSG)
                }
            }
            parts.size == 2 && parts[0] == "removePhone" -> {
                val index: Int? = parts[1].toIntOrNull()
                if (index == null || !contact.removePhone(index)) {
                    println(INVALID_INDEX_MSG)
                }
            }
            parts == listOf("toggleFavorite") -> contact.toggleFavorite()
            parts == listOf("show") -> println(contact)
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
