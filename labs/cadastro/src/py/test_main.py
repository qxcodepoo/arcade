import unittest

from main import AccountNotFoundError, BankAgency, InsufficientBalanceError


class BankAgencyTest(unittest.TestCase):
    def test_client_creation_creates_two_polymorphic_accounts(self) -> None:
        agency = BankAgency()
        agency.add_client("Ana")
        self.assertIn("0:Ana:0.00:CC", str(agency))
        self.assertIn("1:Ana:0.00:CP", str(agency))

    def test_operations_and_monthly_updates_are_delegated_to_accounts(self) -> None:
        agency = BankAgency()
        agency.add_client("Ana")
        agency.deposit(0, 100)
        agency.deposit(1, 200)
        agency.transfer(0, 1, 25)
        agency.monthly_update()
        self.assertIn("0:Ana:55.00:CC", str(agency))
        self.assertIn("1:Ana:227.25:CP", str(agency))

    def test_failures_do_not_change_balances(self) -> None:
        agency = BankAgency()
        agency.add_client("Ana")
        with self.assertRaises(InsufficientBalanceError):
            agency.withdraw(0, 1)
        with self.assertRaises(AccountNotFoundError):
            agency.deposit(9, 1)
        self.assertIn("0:Ana:0.00:CC", str(agency))


if __name__ == "__main__":
    unittest.main()
