import unittest

from main import Contractor, Payroll, Professor, Staff


class PayrollTest(unittest.TestCase):
    def test_employee_types_calculate_their_base_salary(self) -> None:
        payroll = Payroll()
        payroll.add(Professor("david", "C"))
        payroll.add(Staff("ana", 3))
        payroll.add(Contractor("leo", 40, True))
        self.assertIn("prof:david:C:7000", payroll.show())
        self.assertIn("sta:ana:3:3900", payroll.show())
        self.assertIn("ter:leo:40:sim:660", payroll.show())

    def test_daily_and_shared_bonus_are_recalculated(self) -> None:
        payroll = Payroll()
        payroll.add(Professor("david", "C"))
        payroll.add(Staff("ana", 3))
        payroll.add_daily("david")
        payroll.set_bonus(200)
        self.assertIn("prof:david:C:7200", payroll.show())
        self.assertIn("sta:ana:3:4000", payroll.show())


if __name__ == "__main__":
    unittest.main()
