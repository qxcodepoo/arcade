import unittest

from main import Hospital, HospitalError


class HospitalTest(unittest.TestCase):
    def test_link_is_bidirectional_and_specialty_is_unique(self) -> None:
        hospital = Hospital()
        hospital.add_patient("ana", "flu")
        hospital.add_doctor("dr_a", "clinica")
        hospital.add_doctor("dr_b", "clinica")
        hospital.link("dr_a", "ana")
        with self.assertRaises(HospitalError):
            hospital.link("dr_b", "ana")
        self.assertIn("dr_a", hospital.patients["ana"].doctors)


if __name__ == "__main__":
    unittest.main()
