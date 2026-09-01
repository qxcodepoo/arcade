# Orientações para criação de atividades

Este arquivo orienta agentes que criem, revisem ou mantenham atividades de programação neste repositório. O objetivo não é apenas produzir soluções corretas, mas criar uma progressão didática que ensine o aluno a transformar programas funcionais em código legível, coeso, testável e fácil de modificar.

Para os formatos detalhados, consulte:

- [Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [Modelo com Shell](wiki/atividade_codigo/modelo.md)
- [Modelo de implementação orientada](wiki/atividade_codigo/modelo_orientada.md)

## Público e ponto de partida

Considere que os alunos já dominam variáveis, condicionais, laços, funções e coleções básicas. Eles ainda estão desenvolvendo a capacidade de:

- decompor um problema em responsabilidades;
- distinguir interface, coordenação e regra de negócio;
- modelar estado, comportamento e invariantes;
- reconhecer duplicação, alto acoplamento e baixa coesão;
- escrever código que outra pessoa consiga compreender, testar e alterar;
- justificar decisões de projeto em vez de apenas reproduzir estruturas.

Não trate padrões arquiteturais ou princípios como pré-requisitos. Cada atividade deve introduzir poucas ideias novas, aplicá-las a um problema concreto e tornar visível o benefício obtido. Os nomes formais apresentados neste documento são referências para o planejamento do agente; eles não precisam aparecer em toda atividade.

## Objetivo pedagógico central

As atividades devem desenvolver, de maneira progressiva, estas capacidades:

1. **Correção:** implementar o comportamento solicitado e preservar o estado válido.
2. **Legibilidade:** revelar intenção por meio de nomes, organização e fluxo simples.
3. **Decomposição:** dividir operações e componentes por responsabilidade real.
4. **Encapsulamento:** manter invariantes sob controle do objeto que possui o estado.
5. **Testabilidade:** isolar regras da entrada, saída e de dependências externas.
6. **Evolução:** modificar requisitos sem espalhar mudanças por todo o programa.
7. **Justificativa:** explicar os custos e benefícios das escolhas de modelagem.

Código curto não é necessariamente código simples. Avalie principalmente clareza, quantidade de conceitos simultâneos, dependências e facilidade de mudança.

## Progressão recomendada

Organize as atividades em blocos. Uma atividade pode revisar competências anteriores, mas deve declarar um objetivo principal e, no máximo, dois objetivos secundários.

### 1. Legibilidade local

Trabalhe:

- nomes que revelem intenção;
- constantes no lugar de valores mágicos;
- fluxo de controle simples e retornos antecipados quando reduzirem aninhamento;
- métodos pequenos, com uma operação conceitual;
- remoção de duplicação evidente;
- comentários que expliquem decisões, não instruções já expressas pelo código.

Ainda não exija múltiplas classes, interfaces ou padrões de projeto quando funções e estruturas simples forem suficientes.

### 2. Estado e invariantes

Trabalhe:

- diferença entre estado válido e inválido;
- validação na classe que conhece a regra;
- operações que preservam invariantes;
- efeitos de uma falha sobre o estado;
- encapsulamento e exposição controlada de dados;
- comandos, consultas e retornos explícitos.

Os testes devem verificar não apenas a mensagem de erro, mas também o estado após a operação recusada.

### 3. Separação entre domínio e interface

Trabalhe:

- domínio independente de terminal, arquivos ou interface gráfica;
- `Shell` responsável apenas por interpretar comandos, converter dados, invocar o domínio e apresentar resultados;
- regras de negócio testáveis sem simular entrada e saída;
- contratos explícitos para sucesso e falha.

Não mova regras para o `Shell` para simplificar a interação ou satisfazer um teste.

### 4. Colaboração entre objetos

Trabalhe:

- classes pequenas e coesas;
- composição e relações de posse;
- multiplicidades e ciclos de vida;
- delegação de comportamento ao objeto que possui os dados;
- classes coordenadoras que orquestram sem absorver as regras dos componentes;
- coleções de objetos e busca por identidade.

Toda divisão deve nascer de responsabilidades ou ciclos de vida distintos. Não crie classes apenas para aumentar o número de arquivos.

### 5. Evolução e dependências

Quando a turma estiver preparada, trabalhe:

- substituição de comportamentos;
- interfaces definidas pela necessidade do cliente;
- inversão de dependência em pontos de variação reais;
- injeção de relógio, aleatoriedade, armazenamento ou serviços quando necessária aos testes;
- tratamento de erros sem dependência de mensagens dispersas;
- refatoração orientada por testes.

Introduza padrões de projeto somente depois de o aluno encontrar o problema que o padrão resolve.

## Como elaborar cada atividade

Cada atividade deve deixar explícitos:

- o comportamento observável esperado;
- o conhecimento prévio necessário;
- o objetivo pedagógico principal;
- as restrições do domínio e suas invariantes;
- os critérios de conclusão e verificação;
- uma mudança futura plausível que permita discutir a qualidade da modelagem.

O título e o nome usado no índice devem comunicar o objetivo pedagógico principal da atividade. Podem mencionar no máximo um objetivo secundário quando ele estiver diretamente relacionado ao principal. Evite listar detalhes de implementação, quantidade de classes, formatos de retorno ou consequências da atividade como se fossem objetivos independentes. Em atividades complementares, use a nomeação para deixar clara a diferença de papel entre descoberta, aprofundamento e consolidação testável.

Quando um título ou item de índice já possuir o marcador `[GUIA]`, preserve esse marcador ao renomear a atividade. O marcador indica o formato pedagógico da atividade e não deve ser removido como parte de ajustes de resumo ou nomenclatura.

Não inclua seções enumerando princípios, práticas ou conteúdos fora do escopo por padrão. Cite uma nomenclatura técnica somente quando ela for necessária para compreender, executar ou discutir a atividade.

Prefira problemas pequenos com regras suficientemente ricas para exigir decisões. Não aumente a dificuldade com entrada excessiva, cálculos periféricos ou texto ambíguo.

Quando possível, estruture a aprendizagem neste ciclo:

1. apresentar uma versão simples ou um problema concreto;
2. tornar visível um custo, erro ou dificuldade de mudança;
3. introduzir uma prática que resolva esse problema;
4. aplicar a mudança em passos verificáveis;
5. comparar antes e depois;
6. propor uma pequena extensão para validar a nova estrutura.

Não entregue automaticamente a arquitetura completa quando a descoberta fizer parte do objetivo. O `Guide` pode usar perguntas orientadoras antes de apresentar a solução.

## Estrutura da atividade

- Use título, `toc-table`, capa, `Intro`, `Regras`, `Diagrama` e `Guide`.
- Escreva primeiro o comportamento observável e depois os detalhes de implementação.
- Use `Draft` quando houver starter ou esqueleto mantido pelo `tko`.
- Mantenha mensagens, formatos de saída, pontuação e acentuação idênticos entre regras, exemplos, testes e código.
- O contrato executável deve ser escrito em inglês: identificadores, comandos do `Shell`, mensagens observáveis, enums, constantes e demais valores que apareçam no código ou nos testes.
- As explicações pedagógicas devem permanecer em português: enunciado, regras narrativas, `Guide`, reflexões e justificativas de projeto.
- Ajuste atividades existentes gradualmente quando forem revisadas; não faça migração em massa apenas para trocar idioma.
- Evite requisitos implícitos. Se algo será avaliado, descreva-o no contrato ou no objetivo pedagógico.

Atividades `eval=test` devem possuir `Shell` com casos `#TEST_CASE`, comandos iniciados por `$` e encerramento `$end`.

Atividades `eval=self` não exigem `Shell`, mas devem descrever métodos, retornos, limites, exemplos e um roteiro objetivo de verificação.

## Domínio e interface

- Classes de domínio guardam estado e regras do problema.
- Classes de domínio não leem entrada nem imprimem saída.
- O `Shell` lê comandos, converte argumentos, chama o domínio e imprime resultados.
- Falhas são representadas por valores, objetos de resultado, booleanos, exceções ou enums conforme o contrato e o objetivo da atividade.
- A classe que conhece uma restrição deve ser responsável por garanti-la.
- Consultas não devem alterar estado, salvo quando isso fizer parte explícita do modelo.
- Estado global e dependências ocultas devem ser evitados.

Escolha uma estratégia de erro coerente dentro de cada atividade. Não misture indiscriminadamente exceções, códigos, booleanos e mensagens.

## Modelagem e boas práticas

Use Clean Code, KISS, DRY e SOLID como vocabulário de planejamento e análise, não como uma lista rígida de mandamentos nem como etiquetas obrigatórias no README.

- **KISS:** prefira a solução mais simples que represente corretamente o problema atual.
- **DRY:** evite duplicar conhecimento e regras; não elimine toda semelhança superficial por meio de abstrações artificiais.
- **SRP:** dê a cada componente uma responsabilidade coesa e uma razão principal para mudar.
- **Encapsulamento:** proteja invariantes e evite que clientes manipulem livremente o estado interno.
- **Baixo acoplamento:** limite o conhecimento de cada componente às dependências necessárias.
- **Alta coesão:** mantenha juntos dados e comportamentos que pertencem ao mesmo conceito.
- **YAGNI:** não crie extensibilidade para requisitos apenas imaginados.

Evite:

- God Objects;
- métodos que misturem leitura, validação, cálculo, mutação e impressão;
- dados públicos que permitam quebrar invariantes;
- getters e setters automáticos sem necessidade de domínio;
- booleanos que tornem chamadas ambíguas;
- valores mágicos e mensagens espalhadas;
- herança usada apenas para reutilizar código;
- abstrações com uma única implementação sem ponto de variação real;
- comentários que apenas traduzam o código;
- otimizações prematuras;
- refatorações alheias ao objetivo da atividade.

Não considere quantidade de classes, quantidade de métodos ou tamanho máximo de método como métricas isoladas de qualidade.

## Uso dos princípios e da nomenclatura

Apresente apenas os conceitos diretamente necessários à atividade. O objetivo é dar nome a uma decisão que o aluno esteja praticando, e não antecipar todo o vocabulário de projeto de software.

- Prefira primeiro explicar o problema e a decisão em linguagem concreta.
- Introduza o termo técnico quando ele ajudar o aluno a reconhecer e reutilizar a ideia em outros contextos.
- Destaque, em geral, um conceito principal por atividade; mencione um segundo apenas quando houver relação direta entre eles.
- Não liste KISS, DRY, SOLID, Clean Code ou outros princípios apenas porque a solução é compatível com eles.
- Não cite um princípio que não seja demonstrado por uma decisão, comparação, teste ou refatoração observável na atividade.
- Não exija que o aluno memorize siglas antes de compreender o problema que elas ajudam a resolver.
- Reforce termos já apresentados quando forem novamente relevantes, sem repetir definições completas.
- Reserve discussões de alternativas, custos e exceções para o `Guide`; mantenha as `Regras` centradas no contrato do problema.

Use a nomenclatura conforme a necessidade:

- **legibilidade:** nomes expressivos, fluxo simples e ausência de valores mágicos;
- **responsabilidade e coesão:** quando houver decomposição de métodos ou classes;
- **encapsulamento e invariantes:** quando a atividade possuir estado que precisa permanecer válido;
- **separação de interesses:** quando domínio, `Shell`, persistência ou apresentação precisarem ser distinguidos;
- **acoplamento, composição e delegação:** quando objetos começarem a colaborar;
- **KISS, DRY e YAGNI:** quando houver alternativas concretas de simplificação, duplicação de conhecimento ou abstração prematura;
- **SRP, OCP, LSP, ISP e DIP:** somente em atividades avançadas nas quais o problema correspondente seja observável.

Ao citar um princípio, explique brevemente:

1. qual problema concreto aparece na atividade;
2. qual decisão aplica o princípio;
3. qual benefício ela produz naquele contexto.

Não é necessário apresentar o nome do princípio se a nomenclatura aumentar a carga cognitiva sem ajudar na implementação ou na reflexão.

## Explicação das decisões de projeto

Toda atividade que introduzir uma divisão de classes deve explicar:

- qual problema existia antes da divisão;
- qual é o objetivo de cada componente;
- quais estados, invariantes e comportamentos pertencem a cada classe;
- qual relação existe entre os componentes;
- quais objetos possuem ciclos de vida independentes;
- como a divisão melhora manutenção, extensão ou testes;
- qual custo adicional a divisão introduz.

Apresente essa justificativa no `Guide`, junto da sequência de implementação e do diagrama. A estrutura deve ser compreendida como decisão de projeto, não como exigência burocrática.

## Guide e implementação orientada

O `Guide` deve:

- decompor a implementação em incrementos pequenos e executáveis;
- começar pelo modelo mínimo capaz de representar o domínio;
- indicar o que deve funcionar ao fim de cada etapa;
- relacionar cada passo a uma responsabilidade ou invariante;
- mostrar exemplos essenciais sem entregar mecanicamente toda a solução, salvo quando esse for o formato da atividade;
- incluir perguntas de reflexão sobre alternativas e consequências;
- encerrar com uma verificação e, quando adequado, uma pequena extensão.

Evite passos baseados apenas em edição mecânica, como “crie três classes” sem explicar o motivo. Prefira instruções como “extraia o componente porque ele possui estado e ciclo de vida próprios”.

## Testes como instrumento pedagógico

Os testes devem reforçar o contrato e a modelagem, não premiar detalhes internos acidentais.

Inclua, conforme o objetivo:

- caminho principal;
- valores de fronteira;
- operação inválida;
- estado preservado após falha;
- sequência de operações;
- interação entre componentes;
- independência do domínio em relação ao `Shell`.

Evite testes dependentes da ordem interna de execução, de atributos privados ou de uma decomposição não exigida. Quando a estrutura fizer parte do aprendizado, declare explicitamente o que será inspecionado e por quê.

## Refatoração e comparação

Quando o objetivo for código limpo ou modelagem, prefira atividades que permitam comparar versões. Solicite que o aluno identifique:

- o problema ou code smell observado;
- o risco causado por ele;
- a alteração realizada;
- quais comportamentos permaneceram iguais;
- qual nova mudança ficou mais fácil;
- quais custos ou limitações continuam existindo.

Não apresente todo código antigo como “errado”. Diferencie solução funcional, solução adequada ao contexto e solução preparada para novos requisitos.

## Convenção dos diagramas

Os diagramas usam tipos baseados em TypeScript como notação comum entre Python, TypeScript, Java, Kotlin, C++ e Go. Trata-se de convenção didática, não de código diretamente compilável.

- Use `number`, `boolean`, `string` e `void`.
- Use `Array<T>` para coleções indexadas de tamanho variável.
- Use `Map<K, V>` para estruturas chave-valor.
- Use `T | null` para ausência.
- Use multiplicidades UML, como `0..1` e `0..*`.
- Preserve os modificadores UML `+`, `-` e `#`.
- Não use `None`, `Optional`, `undefined`, ponteiros ou coleções específicas de uma linguagem.
- Não use tuplas como padrão. Quando os valores tiverem significado próprio, modele atributos nomeados.

O diagrama deve comunicar responsabilidades e relações relevantes; não precisa expor detalhes internos sem valor didático.

Quando o ponto de entrada precisar aparecer no diagrama, represente-o como `main(): void`. Não inclua argumentos externos incidentais da linguagem, como `String[] args`, pois as atividades recebem comandos pelo fluxo de entrada e podem ser executadas tanto por interação manual quanto por testes em lote.

A `main` representada no diagrama deve permanecer limpa: mostre apenas o ponto de entrada necessário para explicar a execução, sem parâmetros, detalhes de parsing ou métodos auxiliares de apresentação que não sejam parte do modelo ensinado.

Cada atividade com diagrama deve manter:

- `assets/diagrama.puml` como fonte;
- a imagem gerada a partir da fonte;
- classes, atributos, métodos, relações e multiplicidades coerentes com o enunciado e o código.

Gere o diagrama dentro de `assets` com:

```bash
plantuml diagrama.puml
```

Se necessário, execute o PlantUML em modo headless sem alterar a fonte.

## Implementações de referência

- Cada problema deve possuir uma implementação de resposta canônica em Python.
- A implementação Python canônica deve ser compatível com verificação de tipos em modo strict.
- Em Python, todas as variáveis, atributos, parâmetros e retornos criados na solução devem possuir anotação de tipo explícita.
- Java, Kotlin e outras linguagens devem ser tratadas como transposições da implementação canônica quando forem necessárias; não reintroduza `src/cpp` ou `src/ts` sem solicitação explícita.
- Preserve o mesmo modelo conceitual entre as linguagens, mas use construções idiomáticas de cada uma.
- Não force uma tradução linha a linha.
- Não use recursos avançados da linguagem que ocultem o conceito sendo ensinado.
- Diferencie exigências do domínio de escolhas específicas da linguagem.
- Respeite os padrões existentes e evite refatorações não relacionadas.
- Em código Python com comandos textuais, a `main` deve usar `match/case` diretamente sobre `line.split()`, desestruturando os argumentos nos padrões, como em `case ["drive", distance]`.
- Ao alterar uma atividade `eval=test`, preserve o contrato do `Shell`; altere os testes somente quando a regra do problema mudar.
- Ao alterar uma atividade `eval=self`, mantenha exemplos e roteiro alinhados ao modelo conceitual sem transformar o tutorial em contrato rígido de saída.
- Preserve alterações preexistentes no worktree e revise arquivos gerados pelo `tko` antes de incluí-los.

## Revisão pedagógica e técnica

Ao criar ou revisar uma atividade, verifique:

1. O objetivo pedagógico principal está explícito e compatível com os pré-requisitos?
2. A atividade introduz uma quantidade administrável de conceitos novos?
3. O problema torna perceptível a utilidade da prática ensinada?
4. O comportamento observável está separado dos detalhes de implementação?
5. Alguma classe conhece ou executa regras de componentes diferentes?
6. O `Shell` contém lógica que pertence ao domínio?
7. A divisão melhora coesão e testabilidade ou apenas aumenta arquivos?
8. Estado, invariantes e ciclos de vida pertencem às classes corretas?
9. Os casos de erro são tratados por quem conhece a regra?
10. Nomes revelam a intenção do domínio?
11. Cada método realiza uma operação conceitual clara?
12. Dependências são explícitas e realmente necessárias?
13. Testes verificam comportamento, fronteiras e estado após falhas?
14. O diagrama representa o modelo efetivamente ensinado?
15. O `Guide` explica decisões e consequências em linguagem acessível?
16. Os termos técnicos citados são necessários e aparecem em decisões concretas da atividade?
17. A atividade evita listas decorativas de princípios e siglas?
18. A solução permanece simples para o nível da atividade?
19. Existe oportunidade de aplicar ou avaliar a estrutura por meio de uma pequena mudança?

## Verificação antes de concluir

1. Confira a estrutura do README e os links locais.
2. Verifique a coerência entre regras, exemplos, diagrama, testes e implementações.
3. Gere ou valide `assets/diagrama.puml` e sua imagem.
4. Compile e execute o código das linguagens disponíveis.
5. Para `eval=test`, execute cenários de sucesso, falha, fronteira e estado após falha.
6. Para `eval=self`, valide exemplos e roteiro de verificação.
7. Execute `tko util mdpp README.md` quando o README for alterado.
8. Execute `git diff --check`.
9. Use `make all` apenas quando for necessário atualizar índices ou artefatos gerados e revise o diff completo.

## Conduta esperada do agente

Antes de alterar uma atividade:

1. leia o README, o código, os testes e o diagrama existentes;
2. identifique o objetivo pedagógico atual;
3. aponte inconsistências entre contrato, modelagem e avaliação;
4. proponha a menor alteração capaz de resolver o problema;
5. preserve decisões válidas e mudanças do usuário.

Ao concluir, informe sucintamente:

- o que foi alterado;
- qual objetivo pedagógico foi reforçado;
- quais verificações foram executadas;
- quais limitações ou decisões permanecem abertas.

Se uma mudança exigir redefinir o contrato, a progressão pedagógica ou o nível esperado dos alunos, não presuma a decisão: apresente as alternativas e solicite orientação.
