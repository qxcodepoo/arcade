import unittest

from main import Coin, Item, Pig, PigBrokenError, PigFullError


class PigTest(unittest.TestCase):
    def test_common_contract_accepts_coins_and_items(self) -> None:
        pig = Pig(5)
        pig.add(Coin.M10)
        pig.add(Item("gold", 50.0, 3))
        self.assertEqual(4, pig.volume)
        self.assertEqual(50.1, pig.value)

    def test_capacity_and_broken_state_preserve_contents(self) -> None:
        pig = Pig(2)
        pig.add(Coin.M10)
        with self.assertRaises(PigFullError):
            pig.add(Coin.M50)
        pig.break_pig()
        with self.assertRaises(PigBrokenError):
            pig.add(Item("ticket", 0.0, 1))
        self.assertEqual([Coin.M10], pig.extract_coins())

    def test_extraction_requires_breaking_and_keeps_other_values(self) -> None:
        pig = Pig(10)
        pig.add(Coin.M25)
        pig.add(Item("ticket", 0.0, 2))
        with self.assertRaises(PigBrokenError):
            pig.extract_items()
        pig.break_pig()
        self.assertEqual([Item("ticket", 0.0, 2)], pig.extract_items())
        self.assertEqual([Coin.M25], pig.extract_coins())


if __name__ == "__main__":
    unittest.main()
