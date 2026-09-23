import java.util.Locale
import kotlin.math.max

open class ParkingError : Exception()

class VehicleAlreadyParkedError : ParkingError()
class VehicleNotFoundError : ParkingError()
class InvalidTimeError : ParkingError()
class InvalidVehicleTypeError : ParkingError()

abstract class Vehicle(val identifier: String, var entryTime: Int = 0) {
    abstract fun kind(): String
    abstract fun priceFor(minutes: Int): Double

    override fun toString(): String {
        val paddedKind: String = kind().padStart(10, '_')
        val paddedIdentifier: String = identifier.padStart(10, '_')
        return "$paddedKind : $paddedIdentifier : $entryTime"
    }
}

class Bike(identifier: String) : Vehicle(identifier) {
    override fun kind(): String = "Bike"
    override fun priceFor(minutes: Int): Double = 3.0
}

class Motorcycle(identifier: String) : Vehicle(identifier) {
    override fun kind(): String = "Moto"
    override fun priceFor(minutes: Int): Double = minutes / 20.0
}

class Car(identifier: String) : Vehicle(identifier) {
    override fun kind(): String = "Carro"
    override fun priceFor(minutes: Int): Double = max(5.0, minutes / 10.0)
}

class ParkingLot {
    var currentTime: Int = 0
        private set

    private val vehicles: MutableMap<String, Vehicle> = linkedMapOf()

    fun advanceTime(minutes: Int): Unit {
        if (minutes < 0) {
            throw InvalidTimeError()
        }
        currentTime += minutes
    }

    fun park(vehicle: Vehicle): Unit {
        if (vehicles.containsKey(vehicle.identifier)) {
            throw VehicleAlreadyParkedError()
        }
        vehicle.entryTime = currentTime
        vehicles[vehicle.identifier] = vehicle
    }

    fun pay(identifier: String): String {
        val vehicle: Vehicle = vehicles[identifier] ?: throw VehicleNotFoundError()
        val elapsed: Int = currentTime - vehicle.entryTime
        val price: Double = vehicle.priceFor(elapsed)
        vehicles.remove(identifier)
        return "${vehicle.kind()} chegou ${vehicle.entryTime} saiu $currentTime. Pagar R$ ${price.money()}"
    }

    override fun toString(): String {
        val lines: MutableList<String> = vehicles.values.map { it.toString() }.toMutableList()
        lines.add("Hora atual: $currentTime")
        return lines.joinToString("\n")
    }
}

fun createVehicle(kind: String, identifier: String): Vehicle = when (kind) {
    "bike" -> Bike(identifier)
    "moto" -> Motorcycle(identifier)
    "carro" -> Car(identifier)
    else -> throw InvalidVehicleTypeError()
}

fun main(): Unit {
    var parking: ParkingLot = ParkingLot()

    while (true) {
        val line: String = readlnOrNull() ?: break
        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(parking)
            parts == listOf("init") -> parking = ParkingLot()
            parts.size == 2 && parts[0] == "tempo" -> {
                try {
                    parking.advanceTime(parts[1].toInt())
                } catch (_: NumberFormatException) {
                    println(INVALID_TIME_MSG)
                } catch (_: InvalidTimeError) {
                    println(INVALID_TIME_MSG)
                }
            }
            parts.size == 3 && parts[0] == "estacionar" -> {
                try {
                    parking.park(createVehicle(parts[1], parts[2]))
                } catch (_: InvalidVehicleTypeError) {
                    println(INVALID_VEHICLE_MSG)
                } catch (_: VehicleAlreadyParkedError) {
                    println(INVALID_VEHICLE_MSG)
                }
            }
            parts.size == 2 && parts[0] == "pagar" -> {
                try {
                    println(parking.pay(parts[1]))
                } catch (_: VehicleNotFoundError) {
                    println(VEHICLE_NOT_FOUND_MSG)
                }
            }
        }
    }
}

fun Double.money(): String = String.format(Locale.US, "%.2f", this)

const val INVALID_TIME_MSG: String = "fail: invalid time"
const val INVALID_VEHICLE_MSG: String = "fail: vehicle already parked or invalid type"
const val VEHICLE_NOT_FOUND_MSG: String = "fail: vehicle not found"
