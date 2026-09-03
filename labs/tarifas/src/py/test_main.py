import unittest
from main import Account
class AccountTest(unittest.TestCase):
    def test_history_and_reverse(self) -> None:
        account = Account(1); account.deposit(100); account.fee(10); account.reverse([2])
        self.assertEqual(100, account.balance)
        self.assertEqual("reverse", account.operations[-1].kind)
    def test_withdraw_preserves_balance_on_failure(self) -> None:
        account = Account(1)
        with self.assertRaises(ValueError): account.withdraw(1)
        self.assertEqual(0, account.balance)
if __name__ == "__main__": unittest.main()
