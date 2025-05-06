# Leitura arrays

## Visão Geral

Em TypeScript, assim como em JavaScript, um array é uma estrutura de dados que armazena uma coleção de elementos. Cada elemento em um array é acessado por meio de um índice numérico, começando do índice 0 para o primeiro elemento, 1 para o segundo e assim por diante. Arrays podem conter elementos de qualquer tipo, incluindo tipos primitivos como números, strings, booleanos, bem como objetos complexos e até mesmo outros arrays.

Aqui está um exemplo simples de como criar e usar arrays em TypeScript:

```typescript
// Declarando um array de números
let numeros: number[] = [1, 2, 3, 4, 5];

// Declarando um array de strings
let nomes: string[] = ["Alice", "Bob", "Charlie"];

// Acessando elementos do array
console.log(numeros[0]);  // Saída: 1
console.log(nomes[1]);    // Saída: "Bob"

// Modificando elementos do array
numeros[2] = 10;  // Agora, o array é [1, 2, 10, 4, 5]

// Obtendo o comprimento do array
console.log(numeros.length);  // Saída: 5

// Iterando por todos os elementos do array
for (let i = 0; i < numeros.length; i++) {
    console.log(numeros[i]);
}
```

Além disso, TypeScript fornece muitas funcionalidades para trabalhar com arrays, como métodos de array embutidos e recursos de tipos mais avançados. Alguns exemplos de métodos de array incluem:

```typescript
let frutas: string[] = ["maçã", "banana", "laranja"];

// Adicionando um elemento no final do array
frutas.push("uva");  // Agora, o array é ["maçã", "banana", "laranja", "uva"]

// Removendo o último elemento do array
frutas.pop();  // Agora, o array é ["maçã", "banana", "laranja"]

// Encontrando o índice de um elemento no array
let indice = frutas.indexOf("banana");  // Retorna 1

// Removendo um elemento pelo índice
frutas.splice(1, 1);  // Remove o elemento no índice 1

// Concatenando arrays
let outrasFrutas: string[] = ["pêssego", "pera"];
let todasFrutas: string[] = frutas.concat(outrasFrutas);  // ["maçã", "laranja", "pêssego", "pera"]
```

Lembre-se de que TypeScript também fornece recursos de tipo que podem ser usados para declarar arrays com tipos específicos, tornando seu código mais seguro e legível. Por exemplo:

```typescript
let numeros: Array<number> = [1, 2, 3];
let nomes: string[] = ["Alice", "Bob"];
```

Espero que isso tenha te dado uma boa compreensão de como os arrays funcionam em TypeScript!

## Modificando

Claro, vou listar alguns dos principais métodos para inserir e remover elementos de um array em TypeScript, juntamente com o que eles retornam:

**Inserção de Elementos:**

1. **push(item1, item2, ...)**: Adiciona um ou mais elementos no final do array. Retorna o novo comprimento do array.

```typescript
let arr = [1, 2, 3];
let newLength = arr.push(4, 5); // Retorna 5, arr agora é [1, 2, 3, 4, 5]
```

2. **unshift(item1, item2, ...)**: Adiciona um ou mais elementos no início do array. Retorna o novo comprimento do array.

```typescript
let arr = [2, 3, 4];
let newLength = arr.unshift(0, 1); // Retorna 5, arr agora é [0, 1, 2, 3, 4]
```

**Remoção de Elementos:**

1. **pop()**: Remove e retorna o último elemento do array.

```typescript
let arr = [1, 2, 3, 4, 5];
let lastElement = arr.pop(); // Retorna 5, arr agora é [1, 2, 3, 4]
```

2. **shift()**: Remove e retorna o primeiro elemento do array.

```typescript
let arr = [1, 2, 3, 4, 5];
let firstElement = arr.shift(); // Retorna 1, arr agora é [2, 3, 4, 5]
```

3. **splice(startIndex, deleteCount, item1, item2, ...)**: Remove elementos de uma posição específica e, opcionalmente, insere novos elementos no lugar. Retorna um array contendo os elementos removidos.

```typescript
let arr = [1, 2, 3, 4, 5];
let removedElements = arr.splice(1, 2, 6, 7); // Retorna [2, 3], arr agora é [1, 6, 7, 4, 5]
```

4. **slice(startIndex, endIndex)**: Retorna uma cópia superficial dos elementos entre os índices `startIndex` (incluído) e `endIndex` (não incluído) do array original.

```typescript
let arr = [1, 2, 3, 4, 5];
let subArray = arr.slice(1, 4); // Retorna [2, 3, 4]
```

Lembre-se de que esses são apenas alguns dos métodos disponíveis para manipulação de arrays em TypeScript. Existem muitos outros métodos úteis, como `concat`, `splice`, `sort`, `reverse`, entre outros. Certifique-se de consultar a documentação do TypeScript ou do JavaScript para obter informações completas sobre os métodos de arrays.

## Interando

Existem várias formas de iterar sobre um array em TypeScript. Vou mostrar algumas das formas mais comuns de fazer isso:

1. **For Loop Tradicional:**

```typescript
let arr = [1, 2, 3, 4, 5];
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}
```

2. **For...of Loop:**
   
O `for...of` itera sobre os valores dos elementos do array, em vez dos índices.

```typescript
let arr = [1, 2, 3, 4, 5];
for (let element of arr) {
    console.log(element);
}
```

3. **For...in Loop:**

Embora menos comum para arrays, o `for...in` itera sobre as propriedades enumeráveis de um objeto, e você pode usá-lo para iterar sobre os índices de um array.

```typescript
let arr = [1, 2, 3, 4, 5];
for (let index in arr) {
    console.log(arr[index]);
}
```

Lembre-se de escolher a abordagem mais adequada para sua situação, considerando a legibilidade do código, a complexidade da lógica e as necessidades específicas do seu projeto.

## Limitações do `for of`

O `for...of` loop não é projetado para alterar os elementos de um array durante a iteração. Isso ocorre porque o loop `for...of` itera sobre os valores dos elementos, não sobre os índices ou referências dos elementos reais no array. Isso faz com que a atribuição a uma variável de iteração não afete diretamente os elementos do array original.

Por exemplo, considere o seguinte código:

```typescript
let arr = [1, 2, 3, 4, 5];
for (let element of arr) {
    element = element * 2; // Isso não altera o array original
}
console.log(arr); // [1, 2, 3, 4, 5]
```

Nesse caso, o valor de `element` é apenas uma cópia do valor do elemento do array, e a atribuição `element = element * 2` não tem efeito sobre o array original `arr`.

Se você quiser alterar os elementos de um array durante a iteração, o `for` loop tradicional é mais apropriado, pois você terá acesso aos índices e, assim, poderá modificar os elementos diretamente. Veja um exemplo:

```typescript
let arr = [1, 2, 3, 4, 5];
for (let i = 0; i < arr.length; i++) {
    arr[i] = arr[i] * 2; // Isso altera o array original
}
console.log(arr); // [2, 4, 6, 8, 10]
```

Lembre-se de que, ao usar o `for` loop tradicional para alterar elementos, você está manipulando os elementos no próprio array original, o que pode ter consequências importantes dependendo do contexto. Certifique-se de entender como as operações afetam seus dados antes de realizar modificações em massa.
