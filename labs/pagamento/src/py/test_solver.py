import unittest

from solver import (
    Boleto,
    CreditCard,
    InvalidAmountError,
    Payment,
    Pix,
    process_payments,
)


class PaymentTest(unittest.TestCase):
    def test_processes_different_methods_through_one_contract(self) -> None:
        payments: list[Payment] = [
            Payment(150.0, "Sports shirt", Pix("email@example.com", "XPTO")),
            Payment(400.0, "Sports shoes", CreditCard("Client X", 500.0)),
            Payment(89.9, "Python book", Boleto("123", "2026-01-10")),
        ]

        results: list[str] = process_payments(payments)

        self.assertIn("PIX sent", results[0])
        self.assertIn("Remaining limit: 100.00", results[1])
        self.assertIn("Waiting for payment", results[2])

    def test_insufficient_limit_does_not_change_card(self) -> None:
        card: CreditCard = CreditCard("Client Y", 700.0)
        results: list[str] = process_payments(
            [Payment(800.0, "Notebook", card)]
        )

        self.assertEqual(results, ["Error: insufficient credit limit"])
        self.assertEqual(card.limit, 700.0)

    def test_invalid_amount_is_a_payment_error(self) -> None:
        payment: Payment = Payment(0.0, "Invalid", Pix("key", "Bank"))

        with self.assertRaises(InvalidAmountError):
            payment.process()


if __name__ == "__main__":
    unittest.main()
