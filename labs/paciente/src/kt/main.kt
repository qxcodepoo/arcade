class HospitalError(message: String) : Exception(message)

class Patient(
    val identifier: String,
    val diagnosis: String,
) {
    val doctors: MutableMap<String, Doctor> = linkedMapOf()
}

class Doctor(
    val identifier: String,
    val specialty: String,
) {
    val patients: MutableMap<String, Patient> = linkedMapOf()
}

class Hospital {
    private val patients: MutableMap<String, Patient> = linkedMapOf()
    private val doctors: MutableMap<String, Doctor> = linkedMapOf()

    fun addPatient(identifier: String, diagnosis: String): Unit {
        if (!patients.containsKey(identifier)) {
            patients[identifier] = Patient(identifier, diagnosis)
        }
    }

    fun addDoctor(identifier: String, specialty: String): Unit {
        if (!doctors.containsKey(identifier)) {
            doctors[identifier] = Doctor(identifier, specialty)
        }
    }

    fun link(doctorId: String, patientId: String): Unit {
        val doctor: Doctor = doctors[doctorId] ?: throw NoSuchElementException(doctorId)
        val patient: Patient = patients[patientId] ?: throw NoSuchElementException(patientId)

        if (patient.doctors.values.any { it.specialty == doctor.specialty }) {
            throw HospitalError("fail: ja existe outro medico da especialidade ${doctor.specialty}")
        }

        doctor.patients[patientId] = patient
        patient.doctors[doctorId] = doctor
    }

    override fun toString(): String {
        val patientLines: String = patients.values
            .sortedBy { it.identifier }
            .joinToString("\n") { patient ->
                "Pac: ${patient.identifier}:${patient.diagnosis}        Meds: " +
                    "[${patient.doctors.keys.sorted().joinToString(", ")}]"
            }
        val doctorLines: String = doctors.values
            .sortedBy { it.identifier }
            .joinToString("\n") { doctor ->
                "Med: ${doctor.identifier}:${doctor.specialty} Pacs: " +
                    "[${doctor.patients.keys.sorted().joinToString(", ")}]"
            }
        return "$patientLines\n$doctorLines"
    }
}

fun main(): Unit {
    val hospital: Hospital = Hospital()
    hospital.addPatient("ana", "flu")
    hospital.addDoctor("dr_a", "clinica")
    hospital.addDoctor("dr_b", "cardio")
    hospital.addDoctor("dr_c", "clinica")
    hospital.link("dr_a", "ana")
    hospital.link("dr_b", "ana")

    try {
        hospital.link("dr_c", "ana")
    } catch (error: HospitalError) {
        println(error.message)
    }

    println(hospital)
}
