import unittest

from main import Animal, Elephant, Lion, Snake, present


class ZooTest(unittest.TestCase):
    def test_present_uses_each_animal_behavior(self) -> None:
        animals: list[Animal] = [Lion("Simba"), Elephant("Babar"), Snake("Kaa")]

        descriptions: list[str] = [present(animal) for animal in animals]

        self.assertEqual(
            descriptions,
            ["Simba: roar, run", "Babar: trumpet, walk", "Kaa: hiss, slither"],
        )

    def test_animal_name_is_shared_behavior(self) -> None:
        self.assertEqual(present(Lion("Simba")), "Simba: roar, run")


if __name__ == "__main__":
    unittest.main()
