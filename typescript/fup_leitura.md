# Revisão de FUP

<!-- toc -->
- [Criação de variáveis](#criação-de-variáveis)
- [Tipos](#tipos)
- [Sempre inicialize suas variáveis](#sempre-inicialize-suas-variáveis)
- [Não existe int e float no typescript](#não-existe-int-e-float-no-typescript)
- [Não existe char em typescript](#não-existe-char-em-typescript)
- [Tipos de dados em TS](#tipos-de-dados-em-ts)
- [A união de Tipos](#a-união-de-tipos)
- [União com null](#união-com-null)
- [Lista de coisas que podem ser nulas](#lista-de-coisas-que-podem-ser-nulas)
- [Funções](#funções)
- [Formatação de Strings](#formatação-de-strings)
- [Boas práticas](#boas-práticas)
- [Conversão de tipos](#conversão-de-tipos)
- [if e ternário](#if-e-ternário)
- [while](#while)
- [for](#for)
<!-- toc -->

## Criação de variáveis

Em TypeScript, tanto `let` quanto `var` são palavras-chave usadas para declarar variáveis, mas existem diferenças importantes entre elas em termos de escopo e tempo de vida da variável.

1. **Escopo de Bloco:**
   - **let:** As variáveis declaradas com `let` têm escopo de bloco, o que significa que elas só são acessíveis dentro do bloco onde foram declaradas, seja um bloco de função, um loop `for`, uma condicional `if`, etc.
   - **var:** As variáveis declaradas com `var` têm escopo de função ou escopo global. Isso significa que elas são acessíveis em todo o corpo da função em que foram declaradas ou, se forem declaradas fora de qualquer função, em todo o escopo global.

2. **Hoisting (Elevação):**
   - **let:** Variáveis declaradas com `let` não são elevadas (hoisted) para o topo do escopo. Isso significa que você não pode acessar uma variável `let` antes de sua declaração no código.
   - **var:** Variáveis declaradas com `var` são elevadas para o topo do escopo em que foram definidas. Isso permite que você as acesse antes de sua declaração no código, mas pode levar a comportamentos inesperados se não for cuidadoso.

Em resumo, a preferência em TypeScript é usar `let` em vez de `var`, pois `let` é mais seguro em termos de escopo e ajuda a evitar erros sutis que podem ocorrer devido ao hoisting e ao escopo global compartilhado das variáveis `var`.

## Tipos

Em TypeScript, você pode usar tipos para definir o formato esperado das variáveis. Isso ajuda a melhorar a verificação de tipos durante a compilação e fornece informações úteis sobre o que é esperado de uma variável em seu código. Aqui estão algumas maneiras de usar tipos em variáveis do TypeScript:

1. **Tipo Explícito:**
Você pode declarar o tipo de uma variável explicitamente ao mesmo tempo em que a declara. Por exemplo:

```typescript
let idade: number = 25;
let nome: string = "João";
```

2. **Inferência de Tipo:**
O TypeScript é capaz de inferir o tipo da variável com base no valor que você atribui a ela. Isso é chamado de inferência de tipo. Por exemplo:

```typescript
let idade = 25;    // TypeScript inferirá que "idade" é do tipo number
let nome = "João"; // TypeScript inferirá que "nome" é do tipo string
```

3. **Tipos Personalizados:**
Além dos tipos básicos como `number`, `string`, etc., você também pode criar seus próprios tipos personalizados usando interfaces, tipos literais, uniões e outros recursos do TypeScript.

```typescript
interface Pessoa {
  nome: string;
  idade: number;
}

let pessoa: Pessoa = {
  nome: "Maria",
  idade: 30,
};
```

4. **Tipos de União:**
Você pode definir uma variável com um tipo que seja uma união de vários tipos. Isso permite que a variável aceite qualquer um dos tipos na união.

```typescript
let idadeOuNome: number | string;
idadeOuNome = 25;     // Válido
idadeOuNome = "João"; // Válido
```

5. **Tipos Nullable:**
Você pode usar o operador `null` ou `undefined` como parte do tipo da variável.

```typescript
let valor: number | null = null;
```

6. **Tipos Constantes:**
Você pode usar a palavra-chave `const` para declarar variáveis com tipos literais, que aceitam apenas um valor específico.

```typescript
const status: "ativo" | "inativo" = "ativo";
```

Essas são apenas algumas das maneiras pelas quais você pode usar tipos em variáveis no TypeScript. A vantagem de usar tipos é que eles ajudam a capturar erros de tipo em tempo de compilação, tornando seu código mais robusto e legível.

## Sempre inicialize suas variáveis

Sim, é possível criar variáveis sem inicializá-las em TypeScript. Quando você declara uma variável sem atribuir um valor a ela, seu tipo será considerado `undefined`. Isso é útil quando você sabe que vai atribuir um valor a essa variável posteriormente no código, mas ainda não tem um valor inicial.

Aqui está um exemplo:

```typescript
let numero: number; // Declaração de variável sem inicialização
numero = 42;        // Atribuição de valor posteriormente
```

Neste exemplo, a variável `numero` é declarada sem ser inicializada. Ela é considerada do tipo `number | undefined`, indicando que ela pode conter um valor numérico ou `undefined`. A atribuição é feita posteriormente, quando um valor numérico é atribuído à variável.

Lembre-se de que, ao usar uma variável declarada sem inicialização, você precisará garantir que ela seja atribuída com um valor adequado antes de tentar usá-la em algum cálculo ou operação. Caso contrário, você pode encontrar erros de tempo de execução devido ao valor `undefined`.

## Não existe int e float no typescript

Para imprimir apenas a parte inteira de um número em TypeScript, você pode usar a função `Math.floor()`, que arredonda um número para baixo para o inteiro mais próximo. Aqui está como você pode fazer isso:

```typescript
const numero: number = 7.83;
const parteInteira: number = Math.floor(numero);

console.log(parteInteira); // Isso imprimirá somente a parte inteira, ou seja, 7
```

Neste exemplo, a variável `numero` contém o valor 7.83. Usando `Math.floor(numero)`, você obtém a parte inteira do número, que é 7. Em seguida, você pode imprimir o valor da variável `parteInteira`, que mostrará apenas a parte inteira do número original.

## Não existe char em typescript

Não, o TypeScript não possui um tipo de dado específico chamado `char`, como em algumas outras linguagens de programação. Em TypeScript, o tipo principal para representar caracteres individuais é o tipo `string`, que representa sequências de caracteres.

Se você deseja trabalhar com um único caractere de uma string, pode acessar o caractere usando um índice, já que em JavaScript e TypeScript, as strings são indexadas como arrays. Por exemplo:

```typescript
const palavra: string = "Hello";
const primeiroCaractere: string = palavra[0]; // "H"
```

No exemplo acima, `palavra[0]` acessa o primeiro caractere da string `"Hello"`.

No entanto, lembre-se de que, embora `palavra[0]` retorne um caractere como uma string de comprimento 1, o tipo é `string`, não `char`.

Se você está interessado em tratar caracteres como valores individuais, geralmente você usa o tipo `string`. Se você precisa trabalhar com códigos Unicode ou operações mais avançadas relacionadas a caracteres, pode ser útil pesquisar funções e bibliotecas que manipulam strings e caracteres em JavaScript ou TypeScript.

## Tipos de dados em TS

O TypeScript fornece vários tipos de dados que você pode usar para declarar variáveis e especificar o tipo de valores que essas variáveis podem conter. Aqui estão alguns dos principais tipos de dados em TypeScript:

- Básicos
  - **number:** Representa números, tanto inteiros quanto números de ponto flutuante.
  - **string:** Representa sequências de caracteres.
  - **boolean:** Representa valores `true` ou `false`.
- Vazios
  - **void:** Representa a ausência de um valor, comumente usado para funções que não retornam nada.
  - **null:** Representa um valor nulo.
  - **undefined:** Representa um valor indefinido.
- Misturas
  - **any:** Representa um tipo de valor dinâmico, permitindo qualquer tipo de valor.
  - **Array:** Representa uma matriz de valores do mesmo tipo.
  - **Tuple:** Representa uma matriz de elementos com tipos fixos e conhecidos.
  - **enum:** Representa um conjunto de valores nomeados.

Além desses tipos básicos, o TypeScript também permite a criação de tipos personalizados usando interfaces, tipos literais, tipos genéricos e muito mais. Essa flexibilidade permite que você modele seus dados de maneira precisa e eficiente, tornando seu código mais seguro e legível.

## A união de Tipos

A união de tipos é um recurso poderoso do TypeScript que permite declarar que uma variável pode ser de mais de um tipo específico. Isso é útil quando você deseja que uma variável possa conter diferentes tipos de valores em diferentes momentos. A sintaxe básica da união de tipos é usar o caractere de barra vertical `|` entre os tipos que você deseja unir. Aqui está como funciona:

```typescript
let valor: number | string;

valor = 42;     // Válido, atribuindo um número
valor = "foo";  // Válido, atribuindo uma string
```

Neste exemplo, a variável `valor` pode conter tanto números quanto strings. Isso permite que você atribua diferentes tipos de valores à mesma variável em momentos diferentes.

A vantagem da união de tipos é que ela ajuda a tornar o código mais flexível, permitindo que as variáveis se adaptem a diferentes tipos de dados. No entanto, você deve estar ciente de que, quando se trabalha com uma variável de união de tipos, só é possível acessar propriedades ou métodos que são comuns a todos os tipos na união. Por exemplo:

```typescript
function imprimirTamanho(texto: number | string) {
    console.log(texto.length); // Isso resultaria em um erro de compilação, pois "length" não é comum a ambos os tipos
}
```

Neste caso, a função `imprimirTamanho` causa um erro de compilação, pois a propriedade `length` não é comum a ambos os tipos (`number` e `string`). Para resolver isso, você pode verificar o tipo usando as verificações de tipo ou os operadores condicionais.

```typescript
function imprimirTamanho(texto: number | string) {
    if (typeof texto === "string") {
        console.log(texto.length); // Isso é seguro, porque agora TypeScript sabe que texto é uma string
    }
}
```

Em resumo, a união de tipos é uma maneira útil de lidar com variáveis que podem conter diferentes tipos de valores. No entanto, você precisa lidar com as diferenças nos tipos ao acessar propriedades ou executar operações específicas a um tipo dentro da união.

## União com null

A união de tipos com `null` é uma maneira de declarar que uma variável pode ter um valor de um tipo específico ou pode ser nula (`null`). Isso é útil quando você quer indicar explicitamente que uma variável pode estar ausente, além de conter valores do tipo especificado. Para fazer uma união com `null`, você simplesmente inclui o tipo `null` na união usando o caractere de barra vertical `|`.

Aqui está como funciona:

```typescript
let valor: number | null;

valor = 42;    // Válido, atribuindo um número
valor = null;  // Válido, atribuindo nulo
```

Neste exemplo, a variável `valor` pode conter valores do tipo `number` ou pode ser `null`.

Lembre-se de que, ao trabalhar com variáveis que possuem tipos de união que incluem `null`, é uma boa prática verificar se a variável é `null` antes de tentar acessar propriedades ou realizar operações nela:

```typescript
if (valor !== null) {
    console.log(valor.toFixed(2)); // Acessar toFixed somente se valor não for nulo
}
```

Essa verificação é importante porque tentar acessar propriedades ou métodos de uma variável nula pode resultar em erros de tempo de execução.

A união com `null` é útil para expressar claramente a possibilidade de ausência de valor em uma variável, o que ajuda a evitar erros de tempo de execução relacionados a valores nulos não esperados.

## Lista de coisas que podem ser nulas

Claro! Aqui está um exemplo de uma lista de elementos que podem ser do tipo `number` ou `null` usando uma união de tipos:

```typescript
let numerosOuNulos: (number | null)[] = [5, null, 10, null, 15];

console.log(numerosOuNulos); // Saída: [5, null, 10, null, 15]
```

Neste exemplo, a variável `numerosOuNulos` é uma matriz de elementos que podem ser do tipo `number` ou `null`. Você pode ver que tanto os valores numéricos quanto os valores nulos foram inseridos na matriz.

Lembre-se de que, ao acessar elementos dessa matriz, é uma boa prática verificar se um elemento é `null` antes de tentar realizar operações que se aplicam apenas a números:

```typescript
for (const elemento of numerosOuNulos) {
    if (elemento !== null) {
        console.log(elemento * 2); // Multiplicar somente se o elemento não for nulo
    }
}
```

Dessa forma, você evita erros de tempo de execução causados por tentar realizar operações matemáticas em valores nulos.

## Funções

Em TypeScript, assim como em JavaScript, funções são blocos de código que podem ser definidos e chamados para executar tarefas específicas. No entanto, o TypeScript adiciona recursos de tipagem estática às funções, permitindo que você especifique os tipos dos parâmetros e o tipo de retorno da função. Isso torna seu código mais seguro, legível e passível de detecção de erros em tempo de compilação.

Aqui está uma explicação sobre os principais conceitos relacionados a funções em TypeScript:

1. **Declaração de Função:**
   Você pode declarar funções usando a seguinte sintaxe:

   ```typescript
   function nomeDaFuncao(parametro1: Tipo, parametro2: Tipo): TipoRetorno {
       // Corpo da função
   }
   ```

2. **Parâmetros e Tipo de Retorno:**
   Você pode definir os tipos dos parâmetros e o tipo de retorno da função:

   ```typescript
   function soma(a: number, b: number): number {
       return a + b;
   }
   ```

3. **Chamando uma Função:**
   Para chamar uma função, você usa seu nome seguido pelos argumentos entre parênteses:

   ```typescript
   const resultado = soma(5, 3); // resultado terá o valor 8
   ```

4. **Funções Anônimas (Expressões de Função):**
   Você também pode usar funções anônimas (ou expressões de função) que são atribuídas a variáveis ou passadas como argumentos para outras funções:

   ```typescript
   const multiplicacao = function(a: number, b: number): number {
       return a * b;
   };

   const resultado = multiplicacao(4, 6); // resultado terá o valor 24
   ```

5. **Arrow Functions:**
   Arrow functions (funções de seta) são uma sintaxe mais concisa para declarar funções:

   ```typescript
   const divisao = (a: number, b: number): number => a / b;

   const resultado = divisao(10, 2); // resultado terá o valor 5
   ```

6. **Parâmetros Opcionais e Padrão:**
   Você pode definir parâmetros como opcionais ou fornecer valores padrão:

   ```typescript
   function saudacao(nome: string = "Visitante"): string {
       return `Olá, ${nome}!`;
   }

   const mensagem = saudacao(); // "Olá, Visitante!"
   ```

Esses são apenas alguns dos conceitos básicos relacionados a funções em TypeScript. Funções desempenham um papel fundamental na programação, permitindo a modularização do código e a reutilização de lógica. O TypeScript enriquece essas funcionalidades adicionando um sistema de tipos forte, o que ajuda a evitar erros comuns e a criar código mais confiável e legível.

## Formatação de Strings

Em TypeScript, você pode formatar strings de várias maneiras usando strings de modelo (template strings) e concatenação. Aqui estão algumas abordagens comuns para formatar strings:

1. **String de Modelo (Template String):**
As strings de modelo são uma maneira conveniente de formatar strings, permitindo que você insira valores diretamente em uma string usando a sintaxe `${}`.

```typescript
const nome = "Alice";
const idade = 30;

const mensagem = `Olá, meu nome é ${nome} e tenho ${idade} anos.`;
console.log(mensagem); // "Olá, meu nome é Alice e tenho 30 anos."
```

2. **Concatenação de Strings:**
Você também pode usar a concatenação de strings para formatar strings, juntando diferentes partes com o operador `+`.

```typescript
const saudacao = "Olá, ";
const nome = "Bob";

const mensagem = saudacao + nome + "!";
console.log(mensagem); // "Olá, Bob!"
```

## Boas práticas

Escrever funções de maneira limpa e eficiente é uma parte fundamental da programação. Aqui estão algumas boas práticas a serem consideradas ao escrever funções em TypeScript:

1. **Nomes Descritivos:**
   Dê nomes descritivos e significativos às suas funções. Isso facilita a compreensão do propósito da função sem precisar examinar o código inteiro.

2. **Limitação do Tamanho:**
   Tente manter suas funções relativamente curtas e focadas em uma única tarefa. Funções muito longas podem se tornar difíceis de entender e manter.

3. **Comentários e Documentação:**
   Forneça comentários internos na função sempre que o código possa não ser imediatamente óbvio. Além disso, é uma boa prática usar comentários de documentação para descrever a finalidade da função, os parâmetros que ela aceita e o tipo de retorno.

4. **Parâmetros e Tipos:**
   Defina claramente os tipos esperados dos parâmetros da função. Isso ajuda a evitar erros de tipos e melhora a legibilidade. Se necessário, adicione verificações de tipos dentro da função para garantir que os parâmetros atendam às expectativas.

5. **Retorno Explícito:**
   É uma boa prática sempre ter um tipo de retorno explicitamente definido para suas funções, a menos que seja uma função que nunca retorna (`void`, por exemplo).

6. **Nível Adequado de Abstração:**
   Procure um bom equilíbrio entre abstração e detalhes. Funções devem encapsular lógica complexa, mas ainda serem compreensíveis sem precisar navegar por várias camadas de chamadas.

7. **Retorno Default (ou Valores Padrão):**
   Não é obrigatório ter um valor de retorno default para todas as funções, mas é uma boa prática definir um valor de retorno padrão, especialmente quando isso faz sentido semântico. Isso pode ajudar a evitar retornos inesperados de `undefined`.

8. **Evite Efeitos Colaterais:**
   Idealmente, as funções devem ser "puras", ou seja, produzir o mesmo resultado para os mesmos argumentos e não causar efeitos colaterais imprevisíveis.

9. **Reutilização:**
    Projete suas funções para serem reutilizáveis sempre que possível. Isso ajuda a evitar a duplicação de código e simplifica a manutenção.

Lembrando que as boas práticas podem variar dependendo do contexto e das necessidades do projeto. A chave é escrever código claro, organizado e que seja fácil de entender para você e outros desenvolvedores.

## Conversão de tipos

Em TypeScript, você pode realizar conversões entre tipos usando várias abordagens, dependendo da situação. Aqui estão algumas das maneiras mais comuns de realizar conversões de tipos:

**Construtores de Tipo:**
Muitos tipos primitivos, como `Number`, `String`, `Boolean`, `Array`, etc., também têm funções construtoras que podem ser usadas para realizar conversões explícitas.

```typescript
let valor: string = "123";
let numero: number = Number(valor); // Conversão para número
let texto: string = String(numero); // Conversão para string
```

**Operações Aritméticas e Lógicas:**

```typescript
let numero: number = +"5";
let texto = "" + 5;
```

## if e ternário

No TypeScript, a sintaxe para o comando `if` e o operador ternário (`? :`) é muito semelhante à sintaxe em JavaScript, uma vez que o TypeScript é uma superset da linguagem. Aqui estão exemplos da sintaxe do `if` e do operador ternário:

1. **Comando `if`:** O `if` é usado para executar um bloco de código condicionalmente, com base em uma expressão booleana.

```typescript
const idade: number = 18;

if (idade >= 18) {
    console.log("Você é maior de idade.");
} else {
    console.log("Você é menor de idade.");
}
```

2. **Operador Ternário (`? :`):** O operador ternário é uma forma compacta de expressar uma estrutura `if-else`. Ele avalia uma condição e retorna um valor com base nessa condição.

```typescript
const idade: number = 20;
const mensagem: string = idade >= 18 ? "Maior de idade" : "Menor de idade";
console.log(mensagem); // "Maior de idade"
```

Aqui está a sintaxe básica do operador ternário:

```c
condicao ? valorSeVerdadeiro : valorSeFalso
```

No exemplo acima, se `idade >= 18` for verdadeiro, a expressão retorna `"Maior de idade"`, caso contrário, retorna `"Menor de idade"`.

Lembre-se de que tanto o `if` quanto o operador ternário podem ser usados no TypeScript para controlar o fluxo condicional em seu código. Escolha aquele que melhor se adapte à legibilidade e à lógica do seu código específico.

## while

A sintaxe do `while` em TypeScript é a mesma que em JavaScript, já que o TypeScript é uma superset da linguagem. Aqui está a sintaxe do `while`, bem como uma explicação sobre como funcionam os comandos `break` e `continue` dentro de um loop `while`:

**Sintaxe do `while`:**

```typescript
while (condicao) {
    // Bloco de código a ser repetido enquanto a condição for verdadeira
}
```

**Exemplo de `while`:**

```typescript
let contador = 0;

while (contador < 5) {
    console.log(contador);
    contador++;
}
```

**Funcionamento do `break`:**
O comando `break` é usado para interromper imediatamente a execução de um loop (seja `while`, `for` ou outro). Ele é usado quando uma determinada condição é atendida e você deseja sair do loop imediatamente.

**Exemplo de `break`:**

```typescript
let contador = 0;

while (true) {
    if (contador === 3) {
        break; // Sai do loop quando o contador é igual a 3
    }
    console.log(contador);
    contador++;
}
```

**Funcionamento do `continue`:**
O comando `continue` é usado para interromper a execução da iteração atual de um loop e passar para a próxima iteração. Ele é usado quando você deseja pular uma iteração em específico, mas continuar o loop.

**Exemplo de `continue`:**

```typescript
let contador = 0;

while (contador < 5) {
    contador++;
    if (contador === 3) {
        continue; // Pula a iteração quando o contador é igual a 3
    }
    console.log(contador);
}
```

No exemplo acima, quando o contador atinge o valor 3, a instrução `continue` é acionada, pulando a iteração onde o valor 3 seria impresso, mas o loop continua com as iterações subsequentes.

Em resumo, o `while` no TypeScript funciona da mesma forma que em JavaScript, e os comandos `break` e `continue` são usados para controlar o fluxo de execução dentro do loop, permitindo sair dele antecipadamente ou pular iterações específicas.

## for

A sintaxe do loop `for` em TypeScript é a mesma que em JavaScript, já que o TypeScript é uma extensão da linguagem JavaScript. Aqui está a sintaxe do `for`:

**Sintaxe do `for`:**

```typescript
for (inicializacao; condicao; incremento) {
    // Bloco de código a ser repetido enquanto a condição for verdadeira
}
```

- `inicializacao`: Uma expressão que é executada antes da primeira iteração do loop e geralmente é usada para inicializar variáveis de controle.
- `condicao`: Uma expressão booleana que determina se o loop deve continuar ou não.
- `incremento`: Uma expressão que é executada após cada iteração do loop e geralmente é usada para incrementar ou decrementar variáveis de controle.

**Exemplo de `for`:**

```typescript
for (let i = 0; i < 5; i++) {
    console.log(i);
}
```

Neste exemplo, o loop `for` irá imprimir os números de 0 a 4, pois a variável `i` é inicializada com 0, a condição é `i < 5`, e a cada iteração, `i` é incrementado em 1.

O loop `for` em TypeScript é muito útil para iterar sobre uma sequência de valores, como índices de arrays ou propriedades de objetos. A sintaxe básica é a mesma que em JavaScript, e você pode usar as mesmas técnicas de controle de fluxo, como `break` e `continue`, para ajustar o comportamento do loop de acordo com suas necessidades.
