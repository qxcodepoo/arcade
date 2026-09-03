from __future__ import annotations
from dataclasses import dataclass

class Product:
    def price(self) -> float: raise NotImplementedError
    def label(self) -> str: raise NotImplementedError
@dataclass(frozen=True)
class SimpleProduct(Product):
    name: str; value: float
    def price(self) -> float: return self.value
    def label(self) -> str: return self.name
class Bundle(Product):
    def __init__(self, products: list[Product]) -> None: self.products=products
    def price(self) -> float: return sum(p.price() for p in self.products)
    def label(self) -> str: return "[" + ", ".join(p.label() for p in self.products) + "]"
class Discount(Product):
    def __init__(self, product: Product, percent: float) -> None: self.product=product; self.percent=percent
    def price(self) -> float: return self.product.price()*(1-self.percent/100)
    def label(self) -> str: return f"{self.product.label()}({self.percent:.0f}% OFF)"
class Catalog:
    def __init__(self) -> None: self.products:list[Product]=[]
    def add(self,name:str,value:float)->None:self.products.append(SimpleProduct(name,value))
    def bundle(self,indexes:list[int])->None:self.products.append(Bundle([self.products[i] for i in indexes]))
    def discount(self,index:int,percent:float)->None:self.products.append(Discount(self.products[index],percent))
    def __str__(self)->str:return "\n".join(f"{i:02d}:{p.label()}:{p.price():.2f}" for i,p in enumerate(self.products))
