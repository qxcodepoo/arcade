import unittest
from main import Passenger, Train
class TrainTest(unittest.TestCase):
    def test_first_free_seat_and_history(self) -> None:
        train=Train(2); train.add_car(2); train.add_car(1); train.board(Passenger("a")); train.board(Passenger("b")); train.leave("a")
        self.assertEqual("Trem [ - b ][ - ]", str(train)); self.assertEqual(["a in","b in","a out"], train.history)
if __name__ == "__main__": unittest.main()
