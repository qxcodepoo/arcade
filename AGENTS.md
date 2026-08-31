# Orientações para atividades

Estas regras orientam a criação, revisão e manutenção das atividades de código deste repositório. Para o modelo detalhado, consulte:

- [Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [Modelo com Shell](wiki/atividade_codigo/modelo.md)
- [Modelo de implementação orientada](wiki/atividade_codigo/modelo_orientada.md)

## Estrutura da atividade

- Use título, `toc-table`, capa, `Intro`, `Regras`, `Diagrama` e `Guide`.
- Atividades `eval=test` devem ter `Shell` com casos `#TEST_CASE`, comandos iniciados por `$` e encerramento `$end`.
- Atividades `eval=self` devem descrever métodos, retornos, limites e um roteiro de verificação; não exigem `Shell`.
- Use `Draft` quando houver starter ou esqueleto mantido pelo `tko`.
- Escreva primeiro o comportamento observável e depois os detalhes de implementação.
- Mantenha mensagens, formatos de saída, pontuação e acentuação exatamente iguais entre regras, exemplos, testes e código.

## Domínio e interface

- Classes de domínio devem guardar estado e regras do problema.
- Classes de domínio não devem ler entrada nem imprimir saída.
- O `Shell` deve ler comandos, converter argumentos, chamar o domínio e imprimir os resultados.
- Falhas devem ser representadas por valores, objetos de resultado, booleanos ou enums conforme o contrato da atividade.
- Não mova regra de negócio para o `Shell` apenas para simplificar a interação.
- Avalie se uma classe concentra regras de componentes diferentes. Separe responsabilidades quando isso melhorar a coesão e tornar explícitos os ciclos de vida dos objetos.

## Modelagem e boas práticas

- Evite God Objects: não concentre em uma única classe estado, validações, cálculos, persistência, interface e coordenação de vários componentes.
- Prefira classes pequenas, coesas e com uma razão clara para existir.
- Mantenha as regras de um componente dentro do próprio componente.
- Use classes coordenadoras para orquestrar objetos, sem absorver as responsabilidades deles.
- Não crie classes artificiais apenas para aumentar a quantidade de arquivos; a divisão deve melhorar coesão, manutenção ou testabilidade.
- Ao propor uma divisão, identifique explicitamente o estado, as regras e o ciclo de vida de cada componente.

Toda atividade que introduzir uma divisão de classes deve explicar ao aluno:

- por que a classe original foi dividida;
- qual é o objetivo de cada componente;
- quais estados e regras pertencem a cada classe;
- como a divisão melhora manutenção, reutilização e testes;
- qual relação existe entre os componentes;
- quais objetos possuem ciclos de vida independentes.

No `Guide`, apresente essa justificativa junto da sequência de implementação e do diagrama, para que a divisão seja entendida como uma decisão de projeto e não apenas como uma exigência estrutural.

## Princípios trabalhados

O README deve indicar quais princípios estão sendo praticados na atividade e quais ainda não fazem parte do objetivo do bloco.

- **KISS**: mantenha a solução simples e evite abstrações que não sejam necessárias ao problema.
- **DRY**: evite duplicar regras e validações; mantenha uma única fonte de verdade para cada comportamento.
- **SOLID**: introduza primeiro responsabilidade única e, conforme a progressão da disciplina justificar, separação de dependências e interfaces.
- Não exija a aplicação integral de todos os princípios em atividades introdutórias; a complexidade deve ser proporcional ao objetivo pedagógico.

## Boas práticas essenciais

Use Clean Code como referência para legibilidade e manutenção, não como uma lista rígida de regras. Toda prática deve servir ao domínio e reduzir complexidade ou risco real.

- Use nomes expressivos para classes, métodos e variáveis; evite abreviações e nomes genéricos quando não revelarem a intenção.
- Mantenha métodos pequenos e com uma responsabilidade clara; não misture leitura, validação, cálculo, alteração de estado e impressão na mesma operação.
- Busque alta coesão e baixo acoplamento: cada classe deve reunir comportamentos relacionados e conhecer apenas as dependências necessárias.
- Proteja o estado interno e faça a classe responsável garantir suas próprias invariantes.
- Evite complexidade prematura; não introduza abstrações, padrões ou camadas sem uma necessidade concreta.
- Defina falhas e retornos explicitamente no contrato da atividade; evite valores mágicos e mensagens espalhadas pelo código.
- Favoreça métodos determinísticos e componentes que possam ser testados sem depender da interface, de estado global ou de dependências desnecessárias.
- Use comentários para explicar decisões, regras não óbvias e motivos de uma divisão; não repita no comentário o que o código já expressa.

O `Guide` deve indicar brevemente quais boas práticas estão sendo introduzidas na atividade, quais decisões as demonstram e quais práticas ainda não fazem parte do objetivo do bloco. Explique como elas melhoram manutenção, extensão ou testes.

## Revisão da modelagem

Ao criar ou revisar uma atividade, verifique:

1. Se alguma classe conhece ou executa regras de componentes diferentes.
2. Se o `Shell` contém lógica que deveria estar no domínio.
3. Se a divisão reduz responsabilidades ou apenas aumenta o número de arquivos.
4. Se o diagrama representa as responsabilidades e relações do código.
5. Se o README explica as decisões de modelagem em linguagem acessível e apresenta o vocabulário técnico.
6. Se os componentes podem ser testados isoladamente quando possuem regras ou ciclo de vida próprios.
7. Se os casos de erro pertencem à classe que conhece a regra de validação.
8. Se os nomes revelam a intenção do domínio.
9. Se cada método possui uma responsabilidade clara.
10. Se as invariantes são protegidas pela classe correta.
11. Se a solução está simples para o nível da atividade.
12. Se comentários explicam decisões em vez de repetir o código.
13. Se a atividade explica quais boas práticas estão sendo trabalhadas.

## Convenção dos diagramas

Os diagramas usam uma convenção de tipos baseada em TypeScript para servir como notação comum entre Python, TypeScript, Java, Kotlin, C++ e Go. Isso é uma convenção didática, não código para compilação direta.

- Use `number`, `boolean`, `string` e `void`.
- Use `Array<T>` para coleções indexadas de tamanho variável.
- Use `Map<K, V>` para estruturas chave-valor.
- Use `T | null` para atributos ou retornos que possam representar ausência.
- Use multiplicidades UML nas associações, como `0..1` e `0..*`.
- Não use `None`, `Optional`, `undefined`, ponteiros ou coleções específicas de uma linguagem.
- Não use tuplas como padrão. Quando os valores tiverem significado próprio, modele uma classe com atributos nomeados.
- Use `Array<T>` para coleção variável. Reserve uma notação específica para tamanho fixo somente quando esse for um requisito do problema.
- Preserve os modificadores UML `+`, `-` e `#`.

Cada atividade com diagrama deve manter:

- `assets/diagrama.puml` como fonte;
- a imagem gerada a partir dessa fonte;
- classes, atributos, métodos, relações e multiplicidades coerentes com o enunciado e o código.

Gere o diagrama dentro da pasta `assets` com:

```bash
plantuml diagrama.puml
```

Se o ambiente não tiver suporte gráfico, use a mesma execução em modo headless sem alterar o arquivo fonte.

## Implementação

- Respeite os padrões já usados na atividade e evite refatorações não relacionadas.
- As soluções padrão mantidas no repositório são Java e Python; não reintroduza `src/cpp` ou `src/ts` sem solicitação explícita.
- Ao alterar uma atividade avaliada por testes, preserve o contrato do `Shell` e atualize os testes somente quando a regra do problema realmente mudar.
- Ao alterar uma atividade tutorial, mantenha exemplos e orientações alinhados ao modelo conceitual, sem transformar o tutorial em contrato de testes.
- Preserve alterações preexistentes no worktree e revise cuidadosamente arquivos gerados pelo `tko` antes de incluí-los.

## Verificação

Antes de concluir uma alteração:

1. Confira a estrutura do README e os links locais.
2. Gere ou valide `assets/diagrama.puml` e sua imagem.
3. Compile e execute o código da linguagem disponível, quando houver.
4. Para `eval=test`, execute os cenários de sucesso, falha e estado após falha.
5. Para `eval=self`, valide os exemplos e o roteiro de verificação documentados.
6. Execute `tko util mdpp README.md` quando o README for alterado.
7. Execute `git diff --check`.
8. Use `make all` somente quando for necessário atualizar o índice ou artefatos gerados, e revise o diff completo depois.
