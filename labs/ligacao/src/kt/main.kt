const val CONTACT_NOT_FOUND_MSG: String = "fail: contact not found"
const val PHONE_NOT_FOUND_MSG: String = "fail: phone not found"
const val NO_PHONE_MSG: String = "fail: contact has no phone"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

data class Phone(val label: String, val number: String) {
    override fun toString(): String = "$label:$number"
}

class Contact(val name: String) {
    private val phones: MutableList<Phone> = mutableListOf()

    fun addPhone(phone: Phone): Unit {
        phones.add(phone)
    }

    fun removePhone(label: String): Boolean {
        val index: Int = phones.indexOfFirst { it.label == label }
        if (index == -1) {
            return false
        }
        phones.removeAt(index)
        return true
    }

    fun getPhones(): List<Phone> = phones.toList()

    fun firstPhone(): Phone? = phones.firstOrNull()

    fun hasNumber(number: String): Boolean = phones.any { it.number == number }

    override fun toString(): String = "- $name [${phones.joinToString(", ")}]"
}

class CallRegistry {
    private val callsByNumber: MutableMap<String, Int> = mutableMapOf()
    private val callsHistory: MutableList<String> = mutableListOf()

    fun register(number: String): Unit {
        callsByNumber[number] = count(number) + 1
        callsHistory.add(number)
    }

    fun count(number: String): Int = callsByNumber[number] ?: 0

    fun history(): List<String> = callsHistory.toList()
}

class Agenda {
    private val contacts: MutableMap<String, Contact> = mutableMapOf()
    private val registry: CallRegistry = CallRegistry()

    fun addContact(contact: Contact): Unit {
        val current: Contact? = contacts[contact.name]
        if (current == null) {
            contacts[contact.name] = contact
        } else {
            contact.getPhones().forEach { current.addPhone(it) }
        }
    }

    fun removeContact(name: String): Boolean = contacts.remove(name) != null

    fun removePhone(name: String, label: String): Boolean =
        contacts[name]?.removePhone(label) ?: false

    fun call(target: String): String? {
        val contact: Contact? = contacts[target]
        val number: String = if (contact != null) {
            contact.firstPhone()?.number ?: return null
        } else {
            target
        }
        registry.register(number)
        return number
    }

    fun callCount(contact: Contact): Int =
        contact.getPhones().sumOf { registry.count(it.number) }

    fun contactForNumber(number: String): Contact? =
        contacts.values
            .filter { it.hasNumber(number) }
            .minByOrNull { it.name }

    fun speedList(): List<Contact> =
        contacts.values
            .filter { callCount(it) > 0 }
            .sortedWith(compareByDescending<Contact> { callCount(it) }.thenBy { it.name })

    fun historyLines(): List<String> = registry.history().map { number ->
        val destination: String = contactForNumber(number)?.name ?: number
        ":call $number - $destination {${registry.count(number)} call}"
    }

    fun allContacts(): List<Contact> = contacts.values.sortedBy { it.name }
}

fun parseContact(arguments: List<String>): Contact {
    val contact: Contact = Contact(arguments.first())
    for (token in arguments.drop(1)) {
        val separator: Int = token.indexOf(':')
        if (separator < 0) {
            continue
        }
        val label: String = token.substring(0, separator)
        val number: String = token.substring(separator + 1)
        contact.addPhone(Phone(label, number))
    }
    return contact
}

fun printContactWithCount(contacts: List<Contact>, agenda: Agenda): Unit {
    for (contact in contacts) {
        val phones: String = contact.getPhones().joinToString(", ")
        println("- ${contact.name} {${agenda.callCount(contact)} call}[$phones]")
    }
}

fun main(): Unit {
    var agenda: Agenda = Agenda()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        when {
            parts == listOf("end") -> break
            parts == listOf("init") -> agenda = Agenda()
            parts.size >= 2 && parts[0] == "add" -> agenda.addContact(parseContact(parts.drop(1)))
            parts.size == 2 && parts[0] == "rm" -> {
                if (!agenda.removeContact(parts[1])) println(CONTACT_NOT_FOUND_MSG)
            }
            parts.size == 3 && parts[0] == "rmFone" -> {
                if (!agenda.removePhone(parts[1], parts[2])) println(PHONE_NOT_FOUND_MSG)
            }
            parts.size == 2 && parts[0] == "call" -> {
                val number: String? = agenda.call(parts[1])
                if (number == null) {
                    println(NO_PHONE_MSG)
                } else {
                    val destination: String = agenda.contactForNumber(number)?.name ?: number
                    println("ligando $destination $number")
                }
            }
            parts == listOf("agenda") -> agenda.allContacts().forEach { println(it) }
            parts == listOf("speedList") -> printContactWithCount(agenda.speedList(), agenda)
            parts == listOf("history") -> agenda.historyLines().forEach { println(it) }
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
