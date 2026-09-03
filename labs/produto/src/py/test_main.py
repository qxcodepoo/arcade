import unittest
from main import Bundle, Discount, SimpleProduct
class ProductTest(unittest.TestCase):
    def test_composite_and_decorator_are_uniform(self)->None:
        bundle=Bundle([SimpleProduct("shirt",40),SimpleProduct("hat",20)])
        self.assertEqual(60,bundle.price()); self.assertEqual(48,Discount(bundle,20).price())
if __name__ == "__main__":unittest.main()
