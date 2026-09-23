class CommunicationError(message: String) : Exception(message)

data class Message(val sender: String, val text: String)

class Communicator(val identifier: String) {
    private val receivers: MutableMap<String, Communicator> = linkedMapOf()
    private val inbox: MutableList<Message> = mutableListOf()

    fun addReceiver(receiver: Communicator): Unit {
        receivers[receiver.identifier] = receiver
    }

    private fun receive(message: Message): Unit {
        inbox.add(message)
    }

    fun send(receiver: String, text: String): Unit {
        val target: Communicator = receivers[receiver]
            ?: throw CommunicationError("fail:$identifier nao conhece $receiver")
        target.receive(Message(identifier, text))
    }

    fun read(): List<Message> {
        val messages: List<Message> = inbox.toList()
        inbox.clear()
        return messages
    }
}

fun main(): Unit {
    val doctor: Communicator = Communicator("doctor")
    val patient: Communicator = Communicator("patient")
    doctor.addReceiver(patient)
    doctor.send("patient", "hello")

    for (message in patient.read()) {
        println("${message.sender}:${message.text}")
    }

    try {
        patient.send("doctor", "reply")
    } catch (error: CommunicationError) {
        println(error.message)
    }

    val unread: List<Message> = patient.read()
    println(unread.joinToString("\n") { "${it.sender}:${it.text}" }.ifEmpty { EMPTY_INBOX })
}

const val EMPTY_INBOX: String = "- empty -"
