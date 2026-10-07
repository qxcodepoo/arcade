class Pessoa:
    def __init__(self, nome: str):
        self.nome = nome
    def __str__(self) -> str:
        return self.nome

import enum
class Chamar(enum.Enum):
    OK = enum.auto()
    OCUPADO = enum.auto()
    VAZIO = enum.auto()

class CaixaInexistente(Exception):
    pass

class Budega:
    def __init__(self, qtd_caixas: int):
        self.espera: list[Pessoa] = []
        self.caixas: list[Pessoa | None] = [None] * qtd_caixas
        # for _ in range(qtd_caixas):
        #     self.caixas.append(None)

    def chegar(self, pessoa: Pessoa):
        self.espera.append(pessoa)


    def __procurar(self, nome: str) -> int:
        for i, elem in enumerate(self.espera):
            if elem.nome == nome:
                return i
        return -1

    def __procurar_caixas(self, nome: str) -> int:
        for i, elem in enumerate(self.caixas):
            if elem is not None and elem.nome == nome:
                return i
        return -1

    def furar_fila(self, furao: Pessoa, besta: str) -> bool:
        pos = self.__procurar(besta)
        if pos == -1:
            return False
        self.espera.insert(pos, furao)
        return True

    def desistir(self, nome: str) -> bool:
        pos = self.__procurar(nome)
        if pos != -1:
            self.espera.pop(pos)
            return True
        # pos = self.__procurar_caixas(nome)
        # if pos != -1:
        #     self.caixas[pos] = None
        #     return True
        return False


    def __validar_index(self, index: int):
        if index < 0 or index >= len(self.caixas):
            raise CaixaInexistente()

    def chamar(self, index: int) -> Chamar:
        self.__validar_index(index)

        if self.caixas[index] is not None:
            return Chamar.OCUPADO

        if len(self.espera) == 0:
            return Chamar.VAZIO

        self.caixas[index] = self.espera[0]
        self.espera.pop(0)
        return Chamar.OK

    def finalizar(self, index: int) -> bool:
        self.__validar_index(index)

        if self.caixas[index] is None:
            return False
        self.caixas[index] = None
        return True

    def __str__(self):
        def to_str(p: Pessoa | None) -> str:
            return "-----" if p is None else str(p)
        caixas_str = ", ".join([to_str(x) for x in self.caixas])
        espera_str = ", ".join([str(x) for x in self.espera])
        return f"Caixas: [{caixas_str}]\nEspera: [{espera_str}]"

class Shell:
    def __init__(self):
        self.budega = Budega(2)
        self.running = True

        self.map_call: dict[Chamar, str] = {
            Chamar.OK: "",
            Chamar.OCUPADO: "fail: caixa ocupado",
            Chamar.VAZIO: "fail: sem clientes",
        }

    def process(self):
        line = input()
        print("$" + line)
        match line.split():
            case ["end"]:
                self.running = False
            case ["init", qtd]:
                self.budega = Budega(int(qtd))
            case ["arrive", nome]:
                self.budega.chegar(Pessoa(nome))
            case ["call", pos]:
                result = self.budega.chamar(int(pos))
                message = self.map_call[result]
                if message:
                    print(message)
            case ["finish", pos]:
                if not self.budega.finalizar(int(pos)):
                    print("fail: caixa vazio")
            case ["cutInLine", furao, besta]:
                if not self.budega.furar_fila(Pessoa(furao), besta):
                    print("fail: pessoa nao esta na fila")
            case ["giveUp", nome]:
                if not self.budega.desistir(nome):
                    print("fail: pessoa nao esta na fila")
            case ["giveUp"]:
                print("fail: parametros insuficientes")
            case ["show"]:
                print(self.budega)
            case _:
                print("cmd invalido")

    def main(self):
        while self.running:
            try:
                self.process()
            except ValueError:
                print("fail: conversao invalida")
            except CaixaInexistente:
                print("fail: caixa inexistente")


Shell().main()
