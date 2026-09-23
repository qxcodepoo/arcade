const val CONTACT_NOT_FOUND_MSG: String = "fail: contact not found"
const val INVALID_NUMBER_MSG: String = "fail: invalid number"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

data class Phone(val label: String, val number: String) {
    fun isValid(): Boolean =
        number.isNotEmpty() &&
            number.any { it in '0'..'9' } &&
            number.all { it in VALID_CHARS }

    override fun toString(): String = "$label:$number"

    companion object {
        const val VALID_CHARS: String = "0123456789()-."
    }
}

class Contact(val name: String) {
    private val phones: MutableList<Phone> = mutableListOf()

    var starred: Boolean = false
        private set

    fun addPhone(phone: Phone): Boolean {
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

    fun getPhones(): List<Phone> = phones.toList()

    internal fun setStarred(value: Boolean): Unit {
        starred = value
    }

    fun matches(pattern: String): Boolean =
        name.contains(pattern) ||
            phones.any { phone ->
                phone.label.contains(pattern) || phone.number.contains(pattern)
            }

    override fun toString(): String {
        val prefix: String = if (starred) "@" else "-"
        val phoneText: String = phones
            .withIndex()
            .joinToString(separator = " ") { (index, phone) -> "[$index:$phone]" }
        return "$prefix $name ${phoneText.ifEmpty { "[]" }}"
    }
}

class Agenda {
    private val contacts: MutableMap<String, Contact> = mutableMapOf()
    private val favoriteIds: MutableSet<String> = mutableSetOf()

    fun addContact(contact: Contact): Unit {
        val current: Contact? = contacts[contact.name]
        if (current == null) {
            contacts[contact.name] = contact
            return
        }
        for (phone in contact.getPhones()) {
            current.addPhone(phone)
        }
    }

    fun getContact(name: String): Contact? = contacts[name]

    fun removeContact(name: String): Boolean {
        if (contacts.remove(name) == null) {
            return false
        }
        favoriteIds.remove(name)
        return true
    }

    fun star(name: String): Boolean {
        val contact: Contact = contacts[name] ?: return false
        contact.setStarred(true)
        favoriteIds.add(name)
        return true
    }

    fun unstar(name: String): Boolean {
        val contact: Contact = contacts[name] ?: return false
        contact.setStarred(false)
        favoriteIds.remove(name)
        return true
    }

    fun search(pattern: String): List<Contact> =
        contacts.values
            .filter { it.matches(pattern) }
            .sortedBy { it.name }

    fun getStarred(): List<Contact> =
        favoriteIds
            .mapNotNull { name -> contacts[name] }
            .sortedBy { it.name }

    fun getAll(): List<Contact> = contacts.values.sortedBy { it.name }

    override fun toString(): String = getAll().joinToString(separator = "\n")
}

fun printContacts(contacts: List<Contact>): Unit {
    for (contact in contacts) {
        println(contact)
    }
}

fun parseContact(arguments: List<String>): Pair<Contact, Boolean> {
    val contact: Contact = Contact(arguments[0])
    var allValid: Boolean = true

    for (token in arguments.drop(1)) {
        val separator: Int = token.indexOf(':')
        if (separator < 0) {
            throw IllegalArgumentException("invalid phone format")
        }
        val phone: Phone = Phone(token.substring(0, separator), token.substring(separator + 1))
        if (!contact.addPhone(phone)) {
            allValid = false
        }
    }
    return contact to allValid
}

fun main(): Unit {
    var agenda: Agenda = Agenda()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$${line.trimEnd()}")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts == listOf("end") -> break
                parts == listOf("init") -> agenda = Agenda()
                parts.size >= 2 && parts[0] == "add" -> {
                    val parsed: Pair<Contact, Boolean> = parseContact(parts.drop(1))
                    val contact: Contact = parsed.first
                    val allValid: Boolean = parsed.second
                    agenda.addContact(contact)
                    if (!allValid) {
                        println(INVALID_NUMBER_MSG)
                    }
                }
                parts.size == 2 && parts[0] == "rm" -> {
                    if (!agenda.removeContact(parts[1])) {
                        println(CONTACT_NOT_FOUND_MSG)
                    }
                }
                parts.size == 2 && parts[0] == "star" -> {
                    if (!agenda.star(parts[1])) {
                        println(CONTACT_NOT_FOUND_MSG)
                    }
                }
                parts.size == 2 && parts[0] == "unstar" -> {
                    if (!agenda.unstar(parts[1])) {
                        println(CONTACT_NOT_FOUND_MSG)
                    }
                }
                parts == listOf("starred") -> printContacts(agenda.getStarred())
                parts.size == 2 && parts[0] == "search" -> printContacts(agenda.search(parts[1]))
                parts == listOf("show") -> printContacts(agenda.getAll())
                else -> println(INVALID_COMMAND_MSG)
            }
        } catch (error: IllegalArgumentException) {
            println(INVALID_COMMAND_MSG)
        }
    }
}
