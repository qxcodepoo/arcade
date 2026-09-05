# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

## Marcadores pedagógicos <!-- @marcadores-pedagógicos -->

- `type` = orientação e condição de estudo
  - `GUIDE` — leitura, referência ou exemplo guiado;
  - `TRAIN` — prática com consulta permitida;
  - `ALONE` — tentativa independente, antes de buscar ajuda;
  - `CHECK` — atividade projetada para ser realizada sem consulta, verificando o domínio do conteúdo.
- `eval` = Mecanismo de avaliação
  - `none` — material de referência - sem avaliação;
  - `self` — autoavaliação;
  - `diff` — avaliação automática por comparação de entrada e saída.
- `gcs` = compactação dos valores de gain, cost e size
  - `g` = gain (valor pedagógico);
    - `1` — complementar: variação, redundância ou treino não essencial;
    - `2` — consolidação: reforça ou transfere conceitos importantes;
    - `3` — central: introduz, desenvolve ou verifica uma aprendizagem essencial.
  - `c` = cost (esforço lógico base);
    - `1` - Mínimo: aplicação direta de uma regra;
    - `2` - Baixo: poucas decisões independentes;
    - `3` - Médio: combinação de condições ou operações;
    - `4` - Médio-alto: regras interdependentes e casos especiais;
    - `5` - Alto: decisões encadeadas e necessidade de decomposição;
    - `6` - Muito alto: várias regras coordenadas, estados ou estratégias possíveis.
  - `s` = size (tamanho da atividade).
    - `1` — Pequeno: poucos elementos;
    - `2` — Médio: quantidade intermediária de elementos;
    - `3` — Grande: muitos elementos ou componentes

## Material de referência <!-- @refs -->

- [ ] `@+competencias   eval=none gcs=0  ` [Competências trabalhadas](wiki/competencias/README.md) <!-- review=ok -->
- [ ] `@+futuros        eval=none gcs=0  ` [Trabalhos futuros](wiki/trabalhos_futuros/README.md) <!-- review=ok -->
- [ ] `@+git           eval=none gcs=1  ` [[GUIDE] Introdução ao git](wiki/git/README.md) <!-- review=ok -->
- [ ] `@+relacionamento eval=none gcs=0  ` [[GUIDE] Relacionamentos](wiki/relacionamento/README.md) <!-- review=ok -->
- [ ] `@+uml            eval=none gcs=0  ` [[GUIDE] Relacionamentos Resumo](wiki/uml/README.md) <!-- review=ok -->
- [ ] `@+relatorio      eval=none gcs=0  ` [[GUIDE] Como fazer os códigos e relatórios](wiki/relatorio/README.md) <!-- review=ok -->
- [ ] `@+atividade      eval=none gcs=0  ` [[GUIDE] Padrão para atividades de código](wiki/atividade_codigo/README.md) <!-- review=ok -->
- [ ] `@+main           eval=none gcs=0  ` [[GUIDE] Criando a Main](wiki/main/README.md) <!-- review=ok -->

## Classes e Objetos <!-- @intro -->

- Introdução
  - Objetivos de aprendizagem:
    - compreender objetos como entidades com estado e comportamento;
    - distinguir classe, objeto, atributo e método;
    - compreender a separação entre domínio e interface;
    - testar o comportamento observável do modelo por meio de requisições e respostas.
  - Conceitos:
    - classe e objeto;
    - estado e comportamento;
    - identidade;
    - construtor;
    - representação textual;
    - domínio, Shell e interface;
    - requisição, resposta e resultado.
  - Técnicas de programação:
    - controlar o acesso ao estado por meio de métodos;
    - nomear operações segundo suas intenções;
    - separar regras de domínio da apresentação;
    - testar por meio da interface pública;
    - representar falhas com booleanos ou enumerações;
    - utilizar retornos antecipados (`early return`).
  - Princípio relacionado, quando necessário:
    - responsabilidade: a classe que possui o estado também protege suas regras.
- [ ] `@toalha         eval=self gcs=2  ` [[GUIDE] Toalha que enxuga](labs/toalha/README.md) <!-- review=ok -->
- [ ] `@animal         eval=diff gcs=2  ` [[GUIDE] Animal que morre](labs/animal/README.md) <!-- review=ok -->
- [ ] `@enxugar        eval=diff gcs=212` [[TRAIN] Enxugar: Toalha com testes](labs/enxugar/README.md) <!-- review=ok -->
- [ ] `@carro          eval=diff gcs=322` [[ALONE] Carro dirigível](labs/carro/README.md) <!-- review=ok -->
- [ ] `@calculadora    eval=diff gcs=322` [[CHECK] Calculadora à bateria](labs/calculadora/README.md) <!-- review=ok -->

| Projetos              | toalha | animal | enxugar | carro | calculadora |
|-----------------------|--------|--------|---------|-------|-------------|
| ciclo de vida         | .      | SIM    | .       | .     | .           |
| early return          | .      | .      | .       | SIM   | SIM         |
| testes automáticos    | .      | .      | SIM     | SIM   | SIM         |
| erros comunicados via | bool   | bool   | bool    | enum  | enum        |
| esforço               | mínima | baixo  | baixo   | médio | médio       |

---

## Encapsulamento e Invariantes <!-- @access -->

- Introdução
  - Objetivos de aprendizagem:
    - controlar atributos privados por operações do objeto;
    - reconhecer e preservar o estado válido de um objeto;
    - validar alterações na classe que possui a regra;
    - verificar que uma falha não altera o estado anterior;
    - separar a validação do domínio das mensagens da interface.
  - Conceitos:
    - encapsulamento e atributo privado;
    - invariante e estado válido;
    - getter, setter e consulta sem alteração;
    - validação, sucesso e falha;
    - construtor e valor inicial válido;
    - domínio, Shell e interface.
  - Técnicas de programação:
    - inicializar o objeto em um estado válido;
    - validar antes de alterar atributos;
    - retornar sucesso ou falha sem imprimir mensagens no domínio;
    - preservar o estado após uma operação recusada;
    - usar getters para consultas e setters somente quando houver regra de alteração;
    - testar valores válidos, inválidos, limites e sequências de operações.
  - Princípio relacionado, quando necessário:
    - responsabilidade: a classe que possui o estado também protege suas regras.
    - invariante: a classe deve preservar seu estado válido em todas as operações e não dar acesso externo a atributos privados.
    - dry: don't repeat yourself, não repita a validação em outro lugar que não seja o setter.
- [ ] `@chinela        eval=self gcs=1  ` [[GUIDE] Chinela de números pares](labs/chinela/README.md) <!-- review=ok -->
- [ ] `@camisa         eval=self gcs=12 ` [[TRAIN] Camisa de tamanho fixo](labs/camisa/README.md) <!-- review=ok -->
- [ ] `@roupa          eval=diff gcs=22 ` [[TRAIN] Roupa: camisa com testes](labs/roupa/README.md) <!-- review=ok -->
- [ ] `@relogio        eval=diff gcs=332` [[ALONE] Hora 24h ou AM/PM](labs/relogio/README.md) <!-- review=ok -->

| Projetos                | chinela | camisa | roupa | relógio |
|-------------------------|---------|--------|-------|---------|
| validação de construtor | .       | SIM    | SIM   | SIM     |
| uso de arrays internos  | -       | SIM    | SIM   | .       |
| testes automáticos      | .       | SIM    | SIM   | SIM     |
| erros comunicados por   | bool    | bool   | bool  | bool    |
| esforço                 | mínima  | baixo  | baixo | médio   |


## Relações entre objetos: agregação e delegação <!-- @agreg -->

- Introdução
  - Objetivos de aprendizagem:
    - distinguir posse de agregação entre objetos;
    - representar referências opcionais e a multiplicidade de uma relação;
    - delegar uma regra ao objeto que possui os dados necessários;
    - coordenar objetos sem transferir indevidamente seus dados ou responsabilidades;
    - comunicar resultados do domínio sem imprimir mensagens nas classes.
  - Conceitos:
    - agregação, posse e ciclo de vida independente;
    - referência opcional, ausência e multiplicidade `0..1`;
    - colaboração, coordenação e delegação;
    - resultado de domínio, booleano e enumeração;
    - transferência de recurso entre objetos.
  - Técnicas de programação:
    - representar a ausência de um objeto por `T | null`;
    - inserir e remover objetos, devolvendo o objeto removido quando necessário;
    - validar pré-condições antes de alterar o estado;
    - concentrar cálculos e alterações no objeto que possui o estado;
    - usar retornos explícitos para que o `Shell` apresente as falhas;
    - testar falhas, estado preservado e sequências de colaboração.
  - Princípio relacionado, quando necessário:
    - responsabilidade: cada objeto protege suas próprias regras, e o coordenador apenas organiza a colaboração.
- [ ] `@motoca         eval=diff gcs=323` [[GUIDE] Criança andando de Motoca](labs/motoca/README.md) <!-- review=ok -->
- [ ] `@grafite        eval=diff gcs=333` [[TRAIN] Lapiseira de um Grafite](labs/grafite/README.md) <!-- review=ok -->
- [ ] `@motouber       eval=diff gcs=343` [[ALONE] Passeando e pagando o MotoUber](labs/motouber/README.md) <!-- review=ok -->

| Projetos                  | motoca    | grafite   | motouber   |
|---------------------------|-----------|-----------|------------|
| agregação nullable        | SIM       | SIM       | SIM        |
| objeto removido devolvido | SIM       | SIM       | SIM        |
| regra delegada            | SIM       | SIM       | SIM        |
| testes automáticos        | SIM       | SIM       | SIM        |
| erros comunicados por     | enum/null | enum/null | enum/null  |
| esforço                   | baixo     | médio     | médio-alto |


## Desafios de agregação e estados <!-- @aprofundamento -->

- Introdução
  - Objetivos de aprendizagem:
    - coordenar componentes com ciclos de vida independentes;
    - preservar invariantes distribuídas entre objetos que colaboram;
    - modelar transições que dependem da combinação de estados;
    - distinguir um estado temporário de um estado terminal;
    - registrar e preservar a causa de uma transição terminal.
  - Conceitos:
    - agregação, referência opcional e ciclo de vida independente;
    - fonte de energia, capacidade e carga;
    - coordenação de estados e transição condicional;
    - estado terminal, causa de morte e operação sem efeito;
    - enumeração, booleano e resultado de domínio.
  - Técnicas de programação:
    - delegar consumo, recarga e limites ao componente que possui esses dados;
    - coordenar operações sem alterar diretamente o estado interno de outro objeto;
    - validar pré-condições e preservar o estado após uma falha;
    - bloquear ações que não podem ocorrer depois de uma transição terminal;
    - construir e testar o comportamento em etapas, incluindo fronteiras e sequências de operações.
  - Princípio relacionado, quando necessário:
    - responsabilidade: cada componente preserva suas regras, enquanto o objeto coordenador decide quando combiná-las.
- [ ] `@tamagotchi     eval=diff gcs=333` [[CHECK] Brinque até matar o Tamagotchi](labs/tamagotchi/README.md) <!-- review=ok -->
- [ ] `@charger        eval=diff gcs=333` [[TRAIN] Notebook com bateria e carregador](labs/charger/README.md) <!-- review=ok -->

| Projetos                        | tamagotchi | charger   |
|---------------------------------|------------|-----------|
| agregação de componente externo | SIM        | SIM       |
| invariantes no componente       | SIM        | SIM       |
| coordenação de estados          | SIM        | SIM       |
| transição terminal              | SIM        | .         |
| testes automáticos              | SIM        | SIM       |
| erros comunicados por           | enum       | enum/null |
| esforço                         | médio-alto | alto      |


## Coleções lineares <!-- @arrays -->

- Introdução
  - Objetivos de aprendizagem:
    - manipular coleções lineares mantendo ordem, duplicatas e posições;
    - distinguir inserção, remoção, busca, filtro e percurso;
    - escolher entre alterar a lista, devolver um elemento ou criar uma nova coleção;
    - encapsular uma coleção quando ela pertence ao estado de um objeto;
    - coordenar o movimento de objetos entre coleções relacionadas.
  - Conceitos:
    - `Array<T>`, lista de objetos e multiplicidade `0..*`;
    - índice, extremidades, ordem de chegada e ordem de remoção;
    - busca, filtro, cópia rasa e ordenação;
    - fila e operações sobre uma coleção;
    - coleção interna, composição e exposição controlada;
    - referência opcional e coleção de muitos objetos.
  - Técnicas de programação:
    - percorrer elementos diretamente ou com índice quando a posição importar;
    - inserir e remover nas extremidades, validando coleção vazia e limites;
    - interromper a busca após remover a primeira ocorrência;
    - filtrar uma coleção sem modificar indevidamente suas posições;
    - devolver cópias quando a coleção interna não puder ser alterada por clientes;
    - mover objetos entre listas sem recriá-los e delegar regras ao objeto que possui o estado.
  - Princípio relacionado, quando necessário:
    - encapsulamento: a classe proprietária protege a coleção e concentra as regras que mantêm seu estado válido.
- [ ] `@+listas        eval=none gcs=1  ` [[GUIDE] Listas em Python](wiki/listas/README.md) <!-- review=ok -->
- [ ] `@array          eval=diff gcs=2  ` [[GUIDE] Coleção de pessoas](labs/array/README.md) <!-- review=ok -->
- [ ] `@contato        eval=diff gcs=212` [[TRAIN] Contato com telefones](labs/contato/README.md) <!-- review=ok -->
- [ ] `@pula-pula      eval=diff gcs=1  ` [[TRAIN] Pula-pula com crianças](labs/pula-pula/README.md) <!-- review=ok -->
- [ ] `@lapiseira      eval=diff gcs=1  ` [[ALONE] Lapiseira com tambor de grafites](labs/lapiseira/README.md) <!-- review=ok -->

| Projetos                 | listas | array | contato    | pula-pula | lapiseira |
|--------------------------|--------|-------|------------|-----------|-----------|
| relação entre objetos    | .      | .     | composição | agregação | agregação |
| busca ou filtro          | SIM    | SIM   | .          | SIM       | .         |
| ordem como regra         | SIM    | SIM   | SIM        | SIM       | SIM       |
| coleção encapsulada      | .      | .     | SIM        | SIM       | SIM       |
| movimento entre coleções | .      | .     | .          | SIM       | SIM       |
| testes automáticos       | .      | SIM   | SIM        | SIM       | SIM       |
| erros comunicados por    | .      | .     | bool       | bool/null | enum/null |
| esforço                  | mínima | baixo | médio      | médio     | médio     |


## Posições fixas e ausência <!-- @slots -->

- Introdução
  - Objetivos de aprendizagem:
    - representar coleções cuja capacidade e posições são definidas desde a criação;
    - tratar o índice como parte da regra do domínio, e não apenas como detalhe da implementação;
    - distinguir posição ocupada de posição vazia;
    - comparar ausência representada por `T | null` e por um objeto que representa o estado vazio;
    - coordenar uma fila variável com posições fixas sem perder a consistência entre elas.
  - Conceitos:
    - vetor de tamanho fixo, capacidade e índice;
    - ocupação, ausência, nulidade e objeto vazio;
    - busca em uma coleção com posições vazias;
    - fila de espera e posição de atendimento;
    - saldo, quantidade e arrecadação como estados relacionados.
  - Técnicas de programação:
    - inicializar todas as posições com `null` ou com objetos vazios;
    - validar limites e ocupação antes de acessar ou alterar uma posição;
    - preservar o estado quando uma reserva, atendimento ou compra for recusada;
    - devolver cópias de coleções internas quando a capacidade precisar permanecer protegida;
    - movimentar um objeto da fila para uma posição fixa sem duplicá-lo;
    - testar índices inválidos, posições vazias, posições ocupadas e valores de fronteira.
  - Princípio relacionado, quando necessário:
    - encapsulamento: o objeto que possui as posições garante sua capacidade, ocupação e representação de ausência.
- [ ] `@cinema         eval=diff gcs=1  ` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md) <!-- review=ok -->
- [ ] `@budega         eval=diff gcs=2  ` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md) <!-- review=ok -->
- [ ] `@junkfood       eval=diff gcs=1  ` [[ALONE] Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md) <!-- review=ok -->

| Projetos              | cinema | budega | junkfood     |
| --------------------- | ------ | ------ | ------------ |
| erros comunicados por | bool   | bool   | enum/null    |
| capacidade fixa       | SIM    | SIM    | SIM          |
| tipo de ausência      | null   | null   | objeto vazio |
| fila variável         | .      | SIM    | .            |
| validação de índice   | SIM    | SIM    | SIM          |
| testes automáticos    | SIM    | SIM    | SIM          |
| esforço               | baixo  | médio  | médio-alto   |



## Exceções <!-- @exception -->


- [ ] `@bermuda        eval=diff gcs=2  ` [[TRAIN] Bermuda: exceções para invariantes de tamanho](labs/bermuda/README.md)
  - Objetivo: usar `ValueError` para comunicar uma alteração de estado inválida.
  - Conceitos: exceção padrão, `raise`, `try/except` e invariante.
  - Técnicas: validar no construtor e no setter, preservar estado e traduzir falhas no Shell.
  - Pré-requisito: encapsulamento, invariantes e `try/except` básicos.
- [ ] `@fusca          eval=diff gcs=222` [[TRAIN] Fusca: posições, exceções e direção](labs/fusca/README.md)
  - Objetivo: aplicar exceções nomeadas a regras de ocupação e direção.
  - Conceitos: posição fixa, composição, `IndexError` e exceção de domínio.
  - Técnicas: receber objetos, preservar posições, validar pré-condições e traduzir falhas no Shell.
  - Pré-requisito: composição, posições fixas e exceções básicas.
- [ ] `@porquinho      eval=diff gcs=1  ` [Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)
- [ ] `@tabuleiro      eval=diff gcs=1  ` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)
  - Objetivo: coordenar coleções durante uma simulação de turnos.
  - Conceitos: composição, ordem de eventos, estado terminal e invariantes.
  - Técnicas: separar componentes coesos e testar sequências completas de interação.
  - Pré-requisito: coleções, composição, invariantes e sequências de operações.


## Mapas <!-- @crud -->

- Conceitos abordados neste módulo:
  - Map<K, V>;
  - chave única;
  - identidade versus posição;
  - acesso eficiente por identificador;
  - inserção duplicada;
  - remoção e busca por chave;
  - escolha entre lista e mapa;
  - manutenção de uma única fonte de verdade.
- Não é ensinar mapa apenas como nova estrutura, mas discutir:
  - O elemento é localizado por posição, por busca ou por identidade única?
- Conceitos principais: identidade, chave e, quando houver duplicação real, DRY.


___
- [ ] `@agenda         eval=diff gcs=323` [Agenda: contatos por identidade em um mapa](labs/agenda/README.md)
  - Objetivo: localizar contatos pela identidade usando um mapa.
  - Conceitos: chave única, mapa, busca por identidade e fonte única de verdade.
  - Técnicas: encapsular dicionários, validar entradas e separar domínio do Shell.
  - Pré-requisito: dicionários, classes e validação básica.
- [ ] `@agiota         eval=diff gcs=1  ` [Gerencie os empréstimos do agiota](labs/agiota/README.md)
  - Objetivo: aplicar mapas e exceções a um histórico de operações.
  - Conceitos: mapa, exceção de domínio, histórico, invariante e ciclo de vida.
  - Técnicas: calcular estado derivado, tratar falhas e coordenar mudanças de estado.
  - Pré-requisito: mapas, exceções e cálculo de estado derivado.
- [ ] `@petshop        eval=diff gcs=1  ` [Meu Petshop](labs/petshop/README.md)



## Índices e Redundância <!-- @cache -->

Neste bloco, você aprenderá a manter diferentes formas de acesso aos mesmos objetos, preservando uma única fonte de verdade e a consistência entre as estruturas.


___
- [ ] `@favoritos      eval=diff gcs=1  ` [[TRAIN] Favoritos: índice secundário e consistência](labs/favoritos/README.md)
  - Objetivo: criar uma forma secundária de acesso sem duplicar os contatos.
  - Conceitos: índice, conjunto, redundância intencional e consistência.
  - Técnicas: manter uma fonte de verdade e sincronizar estruturas relacionadas.
  - Pré-requisito: mapas, conjuntos e encapsulamento.
- [ ] `@ligacao        eval=diff gcs=1  ` [[TRAIN] Ligação: composição para histórico e ranking](labs/ligacao/README.md)
  - Objetivo: adicionar histórico e ranking por composição.
  - Conceitos: composição, delegação, colaboração e ciclo de vida independente.
  - Técnicas: extrair responsabilidade, manter consistência entre objetos e testar progressivamente.
  - Pré-requisito: índices secundários, composição e coleções.


## Polimorfismo <!-- @polimorfismo -->

- Conceitos abordados neste módulo:
  - contrato comum;
  - implementações diferentes;
  - substituição de condicionais por delegação;
  - composição versus herança;
  - tipos abstratos ou interfaces;
  - extensibilidade;
  - substituição segura.
- Possíveis princípios, apresentados gradualmente:
  - OCP, quando um novo comportamento puder ser adicionado sem alterar a coordenação;
  - LSP, quando houver substituição por subtipos;
  - ISP, apenas quando uma interface estiver grande demais;
  - DIP, quando o domínio precisar deixar de depender de uma implementação concreta.

___
- [ ] `@zoo            eval=self gcs=1  ` [[ALONE] Zoo: contrato comum e comportamento polimórfico](labs/zoo/README.md)
  - Objetivo: tratar espécies diferentes por meio de um contrato comum.
  - Conceitos: classe abstrata, herança, substituição e despacho polimórfico.
  - Técnicas: implementar métodos abstratos e escrever clientes dependentes da abstração.
  - Pré-requisito: classes, herança, composição e delegação.
- [ ] `@pagamento      eval=self gcs=1  ` [[TRAIN] Pagamento: composição de métodos de pagamento](labs/pagamento/README.md)
  - Objetivo: aplicar polimorfismo por composição a métodos de pagamento.
  - Conceitos: contrato abstrato, delegação, composição e exceções de domínio.
  - Técnicas: injetar comportamento, processar coleções heterogêneas e isolar falhas.
  - Pré-requisito: classes abstratas, composição e exceções básicas.
- [ ] `@shapes         eval=diff gcs=2  ` [[TRAIN] Shapes: interface e substituição geométrica](labs/shapes/README.md)
  - Objetivo: tratar formas geométricas por meio de uma interface comum.
  - Conceitos: interface, contrato, substituição e polimorfismo.
  - Técnicas: usar `Protocol`, manter coleção heterogênea e delegar cálculos às formas.
  - Pré-requisito: contratos, coleções e delegação.
- [ ] `@estacionamento eval=diff gcs=3  ` [Estacionamento — polimorfismo por tipo de veículo](labs/estacionamento/README.md)
  - Objetivo: variar o cálculo da tarifa sem espalhar condicionais na coordenação.
  - Conceitos: classe abstrata, método abstrato, composição e delegação polimórfica.
  - Técnicas: implementar tarifas substituíveis, proteger a coleção por operações do domínio e tratar falhas nomeadas.
  - Pré-requisito: polimorfismo, coleções e exceções básicas.
- [ ] `@cofre          eval=diff gcs=3  ` [Cofre — polimorfismo por contrato de valor](labs/cofre/README.md)
  - Objetivo: modelar moedas e itens por um contrato comum em uma coleção heterogênea.
  - Conceitos: protocolo, polimorfismo, enum, imutabilidade e invariantes de estado.
  - Técnicas: filtrar e substituir a coleção, calcular agregados e nomear falhas de domínio.
  - Pré-requisito: contratos, enums, coleções e invariantes.
- [ ] `@cadastro       eval=diff gcs=3  ` [Cadastro — contas com regras polimórficas](labs/cadastro/README.md)
  - Objetivo: aplicar regras mensais diferentes sem condicionar a coordenação pelo tipo da conta.
  - Conceitos: classe abstrata, herança, mapas, composição e delegação polimórfica.
  - Técnicas: manter invariantes de saldo, realizar transferência atômica e atualizar uma coleção heterogênea.
  - Pré-requisito: herança, mapas, polimorfismo e invariantes.



## TODO <!-- @todo lang=X -->

- [ ] `@twitter        eval=diff gcs=322` [Twitter — colaboração entre usuários e timelines](labs/twitter/README.md)
  - Objetivo: coordenar relações entre usuários e distribuição de tweets sem centralizar todas as regras.
  - Conceitos: composição, delegação, relações bidirecionais, coleção compartilhada e estado derivado.
  - Técnicas: encapsular timeline, manter vínculos consistentes e tratar remoção e referências.
  - Pré-requisito: mapas, polimorfismo, coleções e relações bidirecionais.
- [ ] `@salario        eval=diff gcs=32 ` [Salário — regras de cálculo polimórficas](labs/salario/README.md)
  - Objetivo: substituir regras de salário por categoria sem condicionais na folha.
  - Conceitos: abstração, herança, método abstrato, delegação e estado derivado.
  - Técnicas: encapsular políticas de cálculo, validar limites e dividir bônus dinamicamente.
  - Pré-requisito: polimorfismo, abstrações e cálculo de valores.
- [ ] `@mensagem       eval=diff gcs=2  ` [Mensagem — inbox e leitura destrutiva](labs/mensagem/README.md)
  - Objetivo: separar cadastro, envio e leitura em um modelo pequeno e testável.
  - Conceitos: composição, coleção de objetos, imutabilidade e comando/consulta.
  - Técnicas: consumir uma fila de mensagens, validar identidades e manter o domínio sem impressão.
  - Pré-requisito: classes, coleções e encapsulamento básico.
- [ ] `@comunicador    eval=diff gcs=32 ` [Comunicador — envio autorizado por composição](labs/comunicador/README.md)
  - Objetivo: acrescentar mensagens sem misturar inbox e autorização ao domínio hospitalar.
  - Conceitos: composição, delegação, encapsulamento e estado consumível.
  - Técnicas: restringir receivers, entregar mensagens e testar leitura destrutiva.
  - Pré-requisito: composição, autorização e filas de mensagens.
- [ ] `@paciente       eval=diff gcs=2  ` [Paciente — vínculos bidirecionais no hospital](labs/paciente/README.md)
  - Objetivo: manter consistente o vínculo entre pacientes e médicos.
  - Conceitos: associação bidirecional, multiplicidade, identidade e invariantes.
  - Técnicas: validar especialidade antes de atualizar os dois lados.
  - Pré-requisito: associações bidirecionais, multiplicidade e invariantes.
- [ ] `@whatsapp       eval=diff gcs=322` [WhatsApp — grupos e estado de leitura por participante](labs/whatsapp/README.md)
  - Objetivo: modelar mensagens não lidas de forma independente para cada membro de um grupo.
  - Conceitos: composição, multiplicidade, estado derivado e delegação.
  - Técnicas: controlar convites, participação, leitura destrutiva e notificações.
  - Pré-requisito: composição, coleções e leitura destrutiva.
- [ ] `@grupo          eval=diff gcs=322` [Grupo — contrato comum para chats](labs/grupo/README.md)
  - Objetivo: tratar grupo e conversa individual por um contrato comum de chat.
  - Conceitos: classe abstrata, herança, especialização por comportamento e composição.
  - Técnicas: compartilhar envio/leitura, restringir capacidades e manter estado por participante.
  - Pré-requisito: classes abstratas, herança e polimorfismo.
- [ ] `@vetores        eval=diff gcs=1  ` [Vetores — coleção linear e índices](labs/vetores/README.md)
  - Objetivo: preservar ordem e duplicatas em uma coleção linear.
  - Conceitos: sequência, índice, busca e mutação controlada.
  - Técnicas: inserir, alterar, localizar e tratar limites.
  - Pré-requisito: listas, índices e validação de limites.
- [ ] `@anotacoes      eval=diff gcs=2  ` [Anotações — sessão e notas privadas](labs/anotacoes/README.md)
  - Objetivo: proteger notas por meio de uma sessão autenticada.
  - Conceitos: encapsulamento, estado de sessão, composição e imutabilidade.
  - Técnicas: validar credenciais, controlar acesso e associar notas ao usuário.
  - Pré-requisito: mapas, encapsulamento e validação de credenciais.
- [ ] `@trem           eval=diff gcs=1  ` [Trem — composição e alocação de passageiros](labs/trem/README.md)
- [ ] `@produto        eval=diff gcs=1  ` [Produto — Composite e Decorator](labs/produto/README.md)
- [ ] `@git_pratica    eval=none gcs=1  ` [Git — fluxo de trabalho e recuperação](labs/git_pratica/README.md)
  - Objetivo: compreender commits, histórico, restauração e resolução de conflitos.
  - Conceitos: versionamento, integração e recuperação.
  - Técnicas: usar Git local e remoto e documentar decisões.
  - Pré-requisito: comandos básicos de Git e trabalho com repositórios.
- [ ] `@tarifas        eval=diff gcs=32 ` [Operações de saque, depósito, extrato](labs/tarifas/README.md)
  - Objetivo: modelar um histórico financeiro que preserve operações e permita extorno seletivo.
  - Conceitos: encapsulamento, invariantes, comandos e consultas.
  - Técnicas: registrar eventos, validar saldo e operar por índices sem apagar histórico.
  - Pré-requisito: coleções, exceções e encapsulamento.

## labs <!-- @labs -->
