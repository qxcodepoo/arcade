import unittest

from main import Vector


class VectorTest(unittest.TestCase):
    def test_order_duplicates_and_search(self) -> None:
        vector = Vector()
        vector.add([3, 7, 3])
        vector.insert(1, 5)
        self.assertEqual([3, 5, 7, 3], vector.values)
        self.assertEqual([2, -1], vector.find([7, 9]))


if __name__ == "__main__":
    unittest.main()
