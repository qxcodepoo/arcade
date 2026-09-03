from __future__ import annotations

from dataclasses import dataclass, field


class HospitalError(Exception):
    pass


@dataclass
class Patient:
    identifier: str
    diagnosis: str
    doctors: dict[str, Doctor] = field(default_factory=dict)


@dataclass
class Doctor:
    identifier: str
    specialty: str
    patients: dict[str, Patient] = field(default_factory=dict)


class Hospital:
    def __init__(self) -> None:
        self.patients: dict[str, Patient] = {}
        self.doctors: dict[str, Doctor] = {}

    def add_patient(self, identifier: str, diagnosis: str) -> None:
        self.patients.setdefault(identifier, Patient(identifier, diagnosis))

    def add_doctor(self, identifier: str, specialty: str) -> None:
        self.doctors.setdefault(identifier, Doctor(identifier, specialty))

    def link(self, doctor_id: str, patient_id: str) -> None:
        doctor = self.doctors[doctor_id]
        patient = self.patients[patient_id]
        if any(item.specialty == doctor.specialty for item in patient.doctors.values()):
            raise HospitalError(f"fail: ja existe outro medico da especialidade {doctor.specialty}")
        doctor.patients[patient_id] = patient
        patient.doctors[doctor_id] = doctor

    def __str__(self) -> str:
        patients = "\n".join(f"Pac: {p.identifier}:{p.diagnosis}        Meds: [{', '.join(sorted(p.doctors))}]" for p in sorted(self.patients.values(), key=lambda x: x.identifier))
        doctors = "\n".join(f"Med: {d.identifier}:{d.specialty} Pacs: [{', '.join(sorted(d.patients))}]" for d in sorted(self.doctors.values(), key=lambda x: x.identifier))
        return f"{patients}\n{doctors}"
