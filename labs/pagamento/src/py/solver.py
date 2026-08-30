from abc import ABC, abstractmethod

class Pagamento(ABC):
    def __init__(self, valor: float, descricao: str):
        self.valor: float = valor
        self.descricao = descricao
    
    def resumo(self) -> str:
        return f"Pagamento de R$ {self.valor}: {self.descricao}"
    
    def validar_valor(self) -> None:
        if self.valor <= 0:
            raise ValueError("falhou: valor invalido")
    
    @abstractmethod
    def processar(self):
        pass
    
class CartaoCredito(Pagamento): #acoplamento forte
    def __init__(self, num: int, nome: str, limite: float, valor: float, descricao: str):
        super().__init__(valor, descricao)
        self.num = num
        self.nome = nome
        self.limite: float = limite

    def resumo(self):
        return "Cartao de Credito: " + super().resumo()

    def get_limite(self):
        return self.limite

    def processar(self):
        if self.valor > self.limite:
            print("pagamento recusado por limite insuficiente")
            return
        self.limite -= self.valor


def processar_pagamentos(pagamentos: list[Pagamento]):
    for pag in pagamentos:
        pag.validar_valor()
        print(pag.resumo())
        pag.processar()
        if isinstance(pag, CartaoCredito):
            print(pag.get_limite())

pag: Pagamento = CartaoCredito(nome= "David", descricao="Coxinha", limite=500.00, num=123, valor=0.50)
pagamentos: list[Pagamento] = [pag]
processar_pagamentos(pagamentos)