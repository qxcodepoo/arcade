const val CONTACT_EXISTS_MSG: String = "fail: contact already exists"
const val CONTACT_NOT_FOUND_MSG: String = "fail: contact not found"
const val INVALID_NUMBER_MSG: String = "fail: invalid number"
const val INVALID_INDEX_MSG: String = "fail: invalid index"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

class Phone(val label: String, val number: String) {
    fun isValid(): Boolean =
        number.isNotEmpty() &&
            number.any { it in '0'..'9' } &&
            number.all { it in VALID_CHARS }

    fun matches(pattern: String): Boolean =
        label.contains(pattern) || number.contains(pattern)

    override fun toString(): String = "$label:$number"

    companion object {
        const val VALID_CHARS: String = "0123456789()-."
    }
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

    fun matches(pattern: String): Boolean =
        name.contains(pattern) || phones.any { it.matches(pattern) }

    override fun toString(): String {
        val marker: String = if (favorite) "@" else "-"
        val phoneList: String = phones.joinToString(separator = ", ")
        return "$marker $name [$phoneList]"
    }
}

class Agenda {
    private val contacts: MutableMap<String, Contact> = mutableMapOf()

    fun addContact(name: String): Boolean {
        if (contacts.containsKey(name)) {
            return false
        }
        contacts[name] = Contact(name)
        return true
    }

    fun getContact(name: String): Contact? = contacts[name]

    fun removeContact(name: String): Boolean = contacts.remove(name) != null

    fun search(pattern: String): List<Contact> =
        contacts.values
            .filter { it.matches(pattern) }
            .sortedBy { it.name }

    fun getFavorites(): List<Contact> =
        contacts.values
            .filter { it.favorite }
            .sortedBy { it.name }

    override fun toString(): String =
        contacts.values
            .sortedBy { it.name }
            .joinToString(separator = "\n")
}

fun printContacts(contacts: List<Contact>): Unit {
    for (contact in contacts) {
        println(contact)
    }
}

fun main(): Unit {
    val agenda: Agenda = Agenda()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts.size == 2 && parts[0] == "addContact" -> {
                if (!agenda.addContact(parts[1])) {
                    println(CONTACT_EXISTS_MSG)
                }
            }
            parts.size == 4 && parts[0] == "addPhone" -> {
                val contact: Contact? = agenda.getContact(parts[1])
                if (contact == null) {
                    println(CONTACT_NOT_FOUND_MSG)
                } else if (!contact.addPhone(parts[2], parts[3])) {
                    println(INVALID_NUMBER_MSG)
                }
            }
            parts.size == 3 && parts[0] == "removePhone" -> {
                val contact: Contact? = agenda.getContact(parts[1])
                if (contact == null) {
                    println(CONTACT_NOT_FOUND_MSG)
                } else {
                    val index: Int? = parts[2].toIntOrNull()
                    if (index == null || !contact.removePhone(index)) {
                        println(INVALID_INDEX_MSG)
                    }
                }
            }
            parts.size == 2 && parts[0] == "removeContact" -> {
                if (!agenda.removeContact(parts[1])) {
                    println(CONTACT_NOT_FOUND_MSG)
                }
            }
            parts.size == 2 && parts[0] == "toggleFavorite" -> {
                val contact: Contact? = agenda.getContact(parts[1])
                if (contact == null) {
                    println(CONTACT_NOT_FOUND_MSG)
                } else {
                    contact.toggleFavorite()
                }
            }
            parts == listOf("favorites") -> printContacts(agenda.getFavorites())
            parts.size == 2 && parts[0] == "search" -> printContacts(agenda.search(parts[1]))
            parts == listOf("show") -> {
                val output: String = agenda.toString()
                if (output.isNotEmpty()) {
                    println(output)
                }
            }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
