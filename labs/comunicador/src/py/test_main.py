import unittest

from main import Communicator, CommunicationError


class CommunicatorTest(unittest.TestCase):
    def test_send_is_restricted_to_known_receivers_and_inbox_is_consumed(self) -> None:
        doctor = Communicator("doctor")
        patient = Communicator("patient")
        doctor.receivers[patient.identifier] = patient
        doctor.send("patient", "hello")
        self.assertEqual("hello", patient.read()[0].text)
        with self.assertRaises(CommunicationError):
            patient.send("doctor", "reply")


if __name__ == "__main__":
    unittest.main()
