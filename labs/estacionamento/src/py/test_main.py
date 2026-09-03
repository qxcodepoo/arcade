import unittest

from main import (
    Bike,
    Car,
    Motorcycle,
    ParkingLot,
    VehicleAlreadyParkedError,
    VehicleNotFoundError,
)


class ParkingLotTest(unittest.TestCase):
    def test_vehicles_are_parked_at_the_current_time(self) -> None:
        parking = ParkingLot()
        parking.advance_time(30)
        parking.park(Bike("elias"))

        self.assertEqual("______Bike : _____elias : 30\nHora atual: 30", str(parking))

    def test_each_vehicle_calculates_its_own_price(self) -> None:
        parking = ParkingLot()
        parking.park(Bike("b"))
        parking.park(Motorcycle("m"))
        parking.park(Car("c"))
        parking.advance_time(100)

        self.assertEqual("Bike chegou 0 saiu 100. Pagar R$ 3.00", parking.pay("b"))
        self.assertEqual("Moto chegou 0 saiu 100. Pagar R$ 5.00", parking.pay("m"))
        self.assertEqual("Carro chegou 0 saiu 100. Pagar R$ 10.00", parking.pay("c"))

    def test_duplicate_and_missing_identifiers_are_rejected(self) -> None:
        parking = ParkingLot()
        parking.park(Car("abc"))

        with self.assertRaises(VehicleAlreadyParkedError):
            parking.park(Bike("abc"))
        with self.assertRaises(VehicleNotFoundError):
            parking.pay("missing")
        self.assertIn("abc", str(parking))


if __name__ == "__main__":
    unittest.main()
