# Sistema de Pagamentos de um Marketplace

Você deverá implementar um sistema orientado a objetos para processar pagamentos em um marketplace. O sistema deve aceitar diversos **métodos de pagamento**, cada um com regras próprias.

A atividade reforça:

* classes abstratas
* atributos e métodos concretos em classe base
* polimorfismo de sobrescrita
* composição de objetos
* listas contendo vários tipos
* validação via métodos
* uso de funções polimórficas para processar objetos distintos

---

## Implementação Inicial: Template Method

### **1. Classe abstrata: `Pagamento`**

Crie uma classe abstrata `Pagamento` com:

#### **Atributos concretos**

* `valor: float`
* `descricao: str`

#### **Métodos concretos**

* `resumo()`
  Imprime:

  ```
  Pagamento de R$ <valor>: <descricao>
  ```
* `validar_valor()`

  * Se o valor for menor ou igual a zero, lança uma exceção.

#### **Métodos abstratos**

* `processar()`:
  Método obrigatório que cada método de pagamento deve implementar.

---

### **2. Subclasses concretas**

Crie três subclasses com regras específicas:

#### **`CartaoCredito`**

Atributos novos:

* `numero`
* `nome_titular`
* `limite_disponivel`

Regras no `processar()`:

* Se o `valor` > `limite_disponivel`, recusar.
* Caso contrário, descontar o valor do limite e confirmar pagamento.

---

#### **`Pix`**

Atributos novos:

* `chave`
* `banco`

Regras no `processar()`:

* Pix é sempre aprovado desde que o valor seja válido.
* Exibir mensagem indicando banco e chave utilizada.

---

#### **`Boleto`**

Atributos novos:

* `codigo_barras`
* `vencimento` (string ou data)

Regras no `processar()`:

* O pagamento não é aprovado imediatamente.
* Deve imprimir mensagem dizendo:
  `"Boleto gerado. Aguardando pagamento..."`

---

### **3. Função polimórfica global: `processar_pagamento(pagamento: Pagamento)`**

Esta função deve:

1. Chamar `pagamento.validar_valor()`
2. Chamar `pagamento.resumo()`
3. Chamar `pagamento.processar()`

A função deve aceitar **qualquer** objeto que herda de `Pagamento`, demonstrando polimorfismo.

---

### **4. Criar um carrinho de pagamentos**

Crie uma lista contendo vários pagamentos de tipos distintos:

```python
pagamentos = [
    Pix(150, "Camisa esportiva", "email@ex.com", "Banco XPTO"),
    CartaoCredito(400, "Tênis esportivo", "1234 5678 9123 4567", "Cliente X", 500),
    Boleto(89.90, "Livro de Python", "123456789000", "2025-01-10"),
    CartaoCredito(800, "Notebook", "9999 8888 7777 6666", "Cliente Y", 700),  # deve falhar
]
```

Percorra a lista e chame `processar_pagamento()` para cada item.

---

### **5. Objetivo**

O aluno deve observar:

* Como **uma única função** (`processar_pagamento`) lida com objetos de tipos distintos.
* Como a **mesma interface abstrata** (`processar()`) produz comportamentos diferentes.
* Que **métodos concretos da classe base** são reaproveitados.
* Como **regras específicas** nas subclasses alteram o fluxo.
* A importância da **validação** e do **lançamento de exceções**.
* Um exemplo realista de **OOP aplicada a domínio**, não apenas brinquedos ou animais.

---

### **Resultado esperado (exemplo simplificado)**

```
Pagamento de R$ 150.0: Camisa esportiva
PIX enviado via Banco XPTO usando chave email@ex.com

Pagamento de R$ 400.0: Tênis esportivo
Pagamento aprovado no cartão Cliente X. Limite restante: 100

Pagamento de R$ 89.9: Livro de Python
Boleto gerado. Aguardando pagamento...

Pagamento de R$ 800.0: Notebook
Erro: Limite insuficiente no cartão 9999 8888 7777 6666
```

![diagrama](diagrama.png)

___

## Implementação sem herança - Strategy Pattern

![diagrama_strategy](diagrama_strategy.png)

Principais Mudanças Conceituais no Diagrama

- Seta de Composição (*-->): Observe a seta com o losango preenchido saindo de Pagamento para MetodoPagamento. Isso diz: "Um Pagamento é composto por um Método de Pagamento".
- Delegação: A classe Pagamento não sabe como o pagamento é feito. Ela apenas chama metodo.realizar_transacao().
- Interface: MetodoPagamento define o contrato. As classes ...Strategy contêm os dados específicos (como número do cartão ou chave pix), limpando a classe Pagamento.

```py
# Criamos a estratégia (o "como")
estrategia_pix = PixStrategy("chave@email", "Nubank")

# Criamos o pagamento injetando a estratégia
p = Pagamento(100, "Livro", estrategia_pix)
p.processar()
```

Na implementação acima, a classe `Pagamento` não é abstrata e não possui subclasses. Em vez disso, ela recebe um objeto de estratégia que define o método de pagamento.

__Vantagens:__
* Flexibilidade para adicionar novos métodos de pagamento sem alterar a hierarquia de classes.
* Redução do acoplamento entre classes.
