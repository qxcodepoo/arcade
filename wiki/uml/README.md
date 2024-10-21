# Relacionamentos Resumo

![_](diagrama.png)

## Relações de Agregação (tem um/has a)

- Casa e moradores: se a casa for destruída, os moradores não serão, eles podem ser realocados.
- Cômodo e móveis: se o cômodo for destruído, os móveis não serão, eles podem ser realocados.
- Tanto móveis quanto moradores podem existir sem a casa ou o cômodo, respectivamente.

## Relações de composição (contém/contains a)

- Casa e cômodos: se a casa for destruída, os cômodos também serão.
- Cômodo e paredes: se o cômodo for destruído, as paredes também serão.
- Ambos os cômodos e as paredes não podem existir sem a casa ou o cômodo, respectivamente.

## Relações de interface (tem a capacidade de/has a capacity to)

- Tanto Pet quanto Pessoa são Moradores.
- Morador é uma interface que define uma atribuição, reponsabilidade ou papel que uma classe pode ter.
- Pessoa e Pet são classes que implementam a interface Morador.

## Relações de herança (é um/is a)

- Tanto Criança quanto Adulto são Pessoas.
- Pessoa é uma classe abstrata, Criança e Adulto são classes concretas.

## Diferenças entre herança e interface

- Flexibilidade: Interfaces são mais flexíveis do que herança, pois permitem que as classes implementem múltiplos contratos, enquanto a herança pode ser mais restritiva com relação a herança múltipla.
- Acoplamento: A herança tende a acoplar mais fortemente a subclasse à superclasse, enquanto interfaces promovem um acoplamento mais fraco.
- Funcionalidade: A herança pode ser usada para herdar implementações de código e estado (atributos), enquanto interfaces apenas especificam um contrato de métodos sem estados.
- Propósito: Herança é usada para modelar uma relação hierárquica entre classes base e derivadas, enquanto interfaces são usadas para definir capacidades comuns entre classes que não necessariamente compartilham uma relação de pai-filho.
