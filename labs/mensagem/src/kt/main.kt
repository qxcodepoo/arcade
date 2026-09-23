class MessagingError(message: String) : Exception(message)

data class Message(val sender: String, val text: String)

class User(val username: String) {
    private val inbox: MutableList<Message> = mutableListOf()

    fun receive(message: Message): Unit {
        inbox.add(message)
    }

    fun readInbox(): List<Message> {
        val messages: List<Message> = inbox.toList()
        inbox.clear()
        return messages
    }
}

class Messaging {
    private val users: MutableMap<String, User> = linkedMapOf()

    fun user(username: String): User =
        users[username] ?: throw MessagingError("fail: usuario nao encontrado")

    fun addUser(username: String): Unit {
        if (!users.containsKey(username)) {
            users[username] = User(username)
        }
    }

    fun send(sender: String, recipient: String, text: String): Unit {
        user(sender)
        user(recipient).receive(Message(sender, text))
    }

    fun inbox(username: String): String {
        val messages: List<Message> = user(username).readInbox()
        return messages.joinToString("\n") { "${it.sender}:${it.text}" }.ifEmpty { EMPTY_INBOX }
    }
}

fun main(): Unit {
    val messaging: Messaging = Messaging()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts.size == 2 && parts[0] == "addUser" -> messaging.addUser(parts[1])
                parts.size >= 3 && parts[0] == "sendMsg" ->
                    messaging.send(parts[1], parts[2], parts.drop(3).joinToString(" "))
                parts.size == 2 && parts[0] == "inbox" -> println(messaging.inbox(parts[1]))
                parts == listOf("end") -> break
            }
        } catch (error: MessagingError) {
            println(error.message)
        }
    }
}

const val EMPTY_INBOX: String = "- empty -"
