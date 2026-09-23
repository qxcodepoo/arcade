import java.util.Locale

class ClinicError(message: String) : RuntimeException(message)

data class Pet(
    val id: Int,
    val name: String,
    val species: String,
) {
    override fun toString(): String = "$id:$name:$species"
}

class Client(val id: String, val name: String) {
    private val petsByName: MutableMap<String, Pet> = linkedMapOf()

    fun addPet(pet: Pet): Unit {
        if (petsByName.containsKey(pet.name)) {
            throw ClinicError("animal ${pet.name} ja existe")
        }
        petsByName[pet.name] = pet
    }

    fun getPet(name: String): Pet =
        petsByName[name] ?: throw ClinicError("animal $name nao existe")

    fun pets(): List<Pet> = petsByName.values.toList()

    override fun toString(): String {
        val petText: String = pets().joinToString(separator = "") { "[$it]" }
        return "$id:$name$petText"
    }
}

data class Service(val id: String, val price: Double) {
    override fun toString(): String = "$id:${String.format(Locale.US, "%.1f", price)}"
}

data class Sale(
    val id: Int,
    val clientId: String,
    val petName: String,
    val serviceId: String,
    val price: Double,
) {
    override fun toString(): String = "$id:$clientId:$petName:$serviceId"
}

class Clinic {
    private val clients: MutableMap<String, Client> = linkedMapOf()
    private val services: MutableMap<String, Service> = linkedMapOf()
    private val sales: MutableList<Sale> = mutableListOf()
    private var nextPetId: Int = 1
    private var nextSaleId: Int = 0

    private fun requireClient(id: String): Client =
        clients[id] ?: throw ClinicError("cliente $id nao existe")

    private fun requireService(id: String): Service =
        services[id] ?: throw ClinicError("servico $id nao existe")

    fun addClient(id: String, name: String): Unit {
        if (clients.containsKey(id)) {
            throw ClinicError("cliente $id ja cadastrado.")
        }
        clients[id] = Client(id, name)
    }

    fun getClient(id: String): Client = requireClient(id)

    fun deleteClient(id: String): Unit {
        requireClient(id)
        clients.remove(id)
    }

    fun addPet(clientId: String, name: String, species: String): Unit {
        val client: Client = requireClient(clientId)
        val pet: Pet = Pet(nextPetId, name, species)
        client.addPet(pet)
        nextPetId += 1
    }

    fun addService(id: String, price: Double): Unit {
        if (services.containsKey(id)) {
            throw ClinicError("servico $id ja cadastrado.")
        }
        services[id] = Service(id, price)
    }

    fun sell(clientId: String, petName: String, serviceId: String): Unit {
        val client: Client = requireClient(clientId)
        client.getPet(petName)
        val service: Service = requireService(serviceId)
        sales.add(Sale(nextSaleId, clientId, petName, serviceId, service.price))
        nextSaleId += 1
    }

    fun clientsText(): String = clients.values.joinToString(separator = "\n")

    fun servicesText(): String = services.values.joinToString(separator = "\n")

    fun salesText(): String = sales.joinToString(separator = "\n")

    fun balance(): Double = sales.sumOf { it.price }
}

fun main(): Unit {
    val clinic: Clinic = Clinic()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$${line.trimEnd()}")
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                parts == listOf("end") -> break
                parts == listOf("show") -> println(clinic.clientsText())
                parts.size == 2 && parts[0] == "getcli" -> println(clinic.getClient(parts[1]))
                parts.size >= 3 && parts[0] == "addcli" ->
                    clinic.addClient(parts[1], parts.drop(2).joinToString(" "))
                parts.size == 2 && parts[0] == "delcli" -> clinic.deleteClient(parts[1])
                parts.size == 4 && parts[0] == "addpet" ->
                    clinic.addPet(parts[1], parts[2], parts[3])
                parts.size == 3 && parts[0] == "addser" ->
                    clinic.addService(parts[1], parts[2].toDouble())
                parts == listOf("listser") -> println(clinic.servicesText())
                parts.size == 4 && parts[0] == "sell" ->
                    clinic.sell(parts[1], parts[2], parts[3])
                parts == listOf("listsell") -> println(clinic.salesText())
                parts == listOf("balance") ->
                    println(String.format(Locale.US, "%.1f", clinic.balance()))
                else -> println("fail: comando invalido")
            }
        } catch (error: ClinicError) {
            println("fail: ${error.message}")
        } catch (error: NumberFormatException) {
            println("fail: comando invalido")
        }
    }
}
