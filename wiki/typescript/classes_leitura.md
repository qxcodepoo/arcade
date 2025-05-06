# Classes Leitura

<!-- toc -->
- [Conceitos](#conceitos)
- [Referências](#referências)
- [Criando e utilizando classes](#criando-e-utilizando-classes)
<!-- toc -->

## Conceitos

1. **Classes:** Uma classe é um modelo ou um plano para criar objetos. Ela define as propriedades (atributos) e comportamentos (métodos) que os objetos desse tipo terão. Uma classe é como um projeto para criar objetos que compartilham características e comportamentos semelhantes.

2. **Objetos:** Um objeto é uma instância de uma classe. É uma entidade que possui atributos e pode executar métodos conforme definidos na classe. Por exemplo, se você tem uma classe "Carro", um objeto dessa classe poderia ser um carro específico com características individuais.

3. **Construtores:** Um construtor é um método especial dentro de uma classe que é chamado quando um objeto é criado. Ele é usado para inicializar as propriedades do objeto e realizar outras ações necessárias durante a criação do objeto.

4. **Atributos:** Atributos (também conhecidos como propriedades) são as características ou dados que um objeto da classe possui. Por exemplo, se estamos falando de uma classe "Pessoa", os atributos podem incluir nome, idade, altura, etc.

5. **Métodos:** Métodos são funções associadas a uma classe que permitem que os objetos daquela classe executem ações específicas. Por exemplo, em uma classe "Conta Bancária", os métodos podem ser "depositar", "sacar", etc.

6. **Abstração:** Abstração é um conceito que permite simplificar complexidades, focando apenas nos detalhes relevantes para o problema em questão. Em programação orientada a objetos, a abstração envolve a criação de classes que encapsulam detalhes internos, expondo apenas as funcionalidades necessárias.

A diferença entre objetos e variáveis é a seguinte:

- **Objetos:** São instâncias de classes, representando entidades com atributos e comportamentos específicos. Eles agrupam dados (atributos) e as ações que podem ser realizadas (métodos) em uma única unidade.

- **Variáveis:** São nomes que referenciam valores em memória. Em relação a objetos, uma variável pode conter uma referência a um objeto. Em outras palavras, a variável aponta para o local onde o objeto está armazenado na memória.

Em TypeScript, você pode criar classes, definir atributos, métodos e construtores, e então criar objetos a partir dessas classes usando a palavra-chave `new`. Isso permite que você modele e organize seu código de forma orientada a objetos e aproveite os benefícios da abstração e da reutilização de código.

## Referências

Em TypeScript (assim como em outras linguagens de programação orientadas a objetos), entender quando duas variáveis representam o mesmo objeto ou objetos diferentes está relacionado ao conceito de referências e igualdade.

1. **Mesmo Objeto (Referência):** Duas variáveis representam o mesmo objeto quando ambas têm a mesma referência de memória. Isso significa que ambas as variáveis apontam para o mesmo local na memória onde o objeto está armazenado. Se você alterar o objeto através de uma variável, a alteração será refletida na outra variável, porque ambas apontam para a mesma área de memória.

```typescript
const objetoA = { valor: 42 };
const objetoB = objetoA; // Ambas as variáveis apontam para o mesmo objeto

objetoA.valor = 100;
console.log(objetoB.valor); // Isso imprimirá 100, pois objetoB aponta para o mesmo objeto que objetoA
```

2. **Objetos Diferentes (Referências Distintas):** Duas variáveis representam objetos diferentes quando elas têm referências de memória distintas. Cada variável aponta para um objeto separado e independente na memória.

```typescript
const objetoA = { valor: 42 };
const objetoB = { valor: 42 }; // Estes são objetos diferentes com valores iguais

console.log(objetoA === objetoB); // Isso imprimirá false, pois são objetos diferentes
```

A comparação de igualdade (`===`) entre objetos verifica se eles possuem a mesma referência de memória. Se você deseja verificar se dois objetos têm os mesmos valores (mesmo conteúdo), você precisará comparar seus atributos individualmente.

```typescript
const objetoA = { valor: 42 };
const objetoB = { valor: 42 };

console.log(objetoA.valor === objetoB.valor); // Isso imprimirá true, pois os valores dos atributos são iguais
```

Em resumo, em TypeScript, duas variáveis representam o mesmo objeto quando ambas têm a mesma referência de memória. Caso contrário, elas representam objetos diferentes, mesmo que os valores dos atributos sejam os mesmos.

## Criando e utilizando classes

Claro, vou fornecer um texto que aborda os temas de "Definindo Classes", "Construtores" e "Métodos" em TypeScript.

---

**Definindo Classes em TypeScript**

Em programação orientada a objetos, uma classe é como um projeto que define a estrutura e o comportamento dos objetos que serão criados a partir dela. Em TypeScript, essa estrutura é uma parte fundamental do desenvolvimento de software, permitindo uma organização eficaz e uma abstração de dados. Ao declarar uma classe em TypeScript, você está criando um modelo a partir do qual os objetos serão instanciados.

Para definir uma classe, utilize a palavra-chave `class`, seguida pelo nome da classe e um bloco de código entre chaves. Dentro dessa estrutura, você pode definir os atributos (ou propriedades) e os métodos que os objetos dessa classe possuirão.

**Exemplo:**

```typescript
class Pessoa {
    nome: string;
    idade: number;

    saudacao() {
        console.log(`Olá, meu nome é ${this.nome} e tenho ${this.idade} anos.`);
    }
}
```

**Construtores em TypeScript**

Os construtores são métodos especiais dentro de uma classe que são chamados automaticamente quando um objeto da classe é criado. Eles permitem que você inicialize as propriedades da classe e configure seu estado inicial. Os construtores são especialmente úteis para garantir que os objetos sejam criados de maneira consistente e estejam prontos para uso imediato.

Para criar um construtor, defina um método chamado `constructor` dentro da classe. Esse método é executado automaticamente quando você instancia um objeto da classe. Você pode passar parâmetros para o construtor para definir os valores iniciais das propriedades.

**Exemplo:**

```typescript
class Pessoa {
    nome: string;
    idade: number;

    constructor(nome: string, idade: number) {
        this.nome = nome;
        this.idade = idade;
    }
}
```

**Métodos em TypeScript**

Métodos em uma classe são funções que definem o comportamento dos objetos dessa classe. Eles permitem que você encapsule a lógica relacionada a esses objetos, tornando o código mais organizado e modular. Métodos podem receber parâmetros, executar ações e retornar valores.

Para criar um método em uma classe, defina uma função dentro da classe. Dentro do método, você pode usar as propriedades da classe, bem como parâmetros passados para o método.

**Exemplo:**

```typescript
class Calculadora {
    somar(a: number, b: number): number {
        return a + b;
    }
}
```

Em resumo, classes, construtores e métodos são conceitos fundamentais em TypeScript que permitem criar objetos com estrutura definida, inicializar propriedades e atribuir comportamentos específicos a esses objetos. Esses conceitos formam a base da programação orientada a objetos e capacitam os desenvolvedores a criar código mais organizado, reutilizável e flexível.
