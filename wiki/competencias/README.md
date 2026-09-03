# Competências trabalhadas

Este documento resume as competências e habilidades desenvolvidas pela
progressão de atividades do repositório.

## Fundamentos de programação orientada a objetos

- criar classes, objetos, atributos e métodos;
- modelar identidade, estado, comportamento e ciclo de vida;
- inicializar objetos com construtores;
- representar objetos de forma legível;
- testar comportamentos observáveis.

## Legibilidade e qualidade de código

- escolher nomes que revelem intenção;
- decompor métodos por responsabilidade;
- simplificar fluxos de controle;
- remover duplicação de regras;
- substituir valores mágicos por constantes;
- aplicar KISS, DRY, YAGNI e Clean Code em situações concretas.

## Encapsulamento e invariantes

- proteger o estado interno;
- validar regras no objeto responsável;
- preservar invariantes após falhas;
- diferenciar comandos e consultas;
- controlar getters, setters e cópias retornadas;
- distinguir ausência, valor vazio e estado inválido.

## Separação de responsabilidades

- separar domínio e interface;
- manter o domínio independente do terminal;
- criar Shells responsáveis por parsing e apresentação;
- testar regras sem simular entrada e saída;
- separar coordenação, apresentação e regra de negócio.

## Coleções e estruturas de dados

- trabalhar com listas, arrays, filas e pilhas;
- preservar ordem e aceitar duplicatas quando necessário;
- inserir, remover, buscar, filtrar e ordenar;
- trabalhar com índices e posições fixas;
- usar mapas para busca por identidade;
- usar conjuntos para eliminar duplicidades;
- manter índices secundários consistentes com uma fonte de verdade.

## Colaboração entre objetos

- modelar agregação, composição e associação;
- representar multiplicidades e ciclos de vida;
- delegar regras ao objeto que possui os dados;
- manter relações bidirecionais consistentes;
- coordenar objetos sem criar classes excessivamente responsáveis;
- preservar baixo acoplamento e alta coesão.

## Exceções e contratos de falha

- usar `ValueError` para valores inválidos;
- criar exceções próprias derivadas de `Exception`;
- distinguir falha excepcional de ausência esperada;
- escolher entre retorno, `null`, resultado e exceção;
- traduzir falhas na camada de interface;
- verificar o estado depois de uma operação recusada.

## Polimorfismo e abstrações

- definir contratos comuns;
- usar classes abstratas e métodos abstratos;
- usar `Protocol` como interface estrutural;
- substituir condicionais por delegação polimórfica;
- processar coleções heterogêneas;
- escolher entre herança e composição;
- aplicar Strategy, Composite e Decorator quando houver um problema real.

## Imutabilidade e estado derivado

- modelar objetos de valor imutáveis;
- retornar cópias de coleções internas;
- calcular valores derivados a partir do estado atual;
- registrar históricos sem apagar operações anteriores;
- modelar transições, limites, capacidade e estados terminais.

## Testes e evolução

- testar caminho principal, fronteiras e falhas;
- testar sequências de operações;
- testar interações entre componentes;
- criar testes de regressão;
- refatorar preservando o comportamento;
- comparar alternativas de modelagem e seus custos.

## Comunicação técnica

- desenhar classes, interfaces e relações em PlantUML;
- representar multiplicidades e tipos de coleção;
- manter código, testes, regras, exemplos e diagramas coerentes;
- explicar decisões de projeto em linguagem acessível.

## Práticas profissionais

- criar commits compreensíveis;
- consultar histórico e restaurar mudanças;
- trabalhar com branches e repositórios remotos;
- resolver conflitos conscientemente;
- documentar decisões, dificuldades e resultados.
