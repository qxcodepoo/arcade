---
args: [g, l, s]
expr: "(g * l * s)"
---

# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

## Material de referência <!-- @refs -->

- [ ] `eval=none            ` [[INTRO] Marcadores pedagógicos](wiki/pedagogic/README.md)
  - `type` = orientação e condição de estudo
    - `INTRO` — leitura introdutória, sem necessidade de prática;
    - `GUIDE` — leitura, referência ou exemplo guiado;
    - `TRAIN` — prática com consulta permitida;
    - `ALONE` — tentativa independente, antes de buscar ajuda;
    - `CHECK` — atividade projetada para ser realizada sem consulta, verificando o domínio do conteúdo.
  - `eval` = Mecanismo de avaliação
    - `none` — material de referência - sem avaliação;
    - `self` — autoavaliação;
    - `diff` — avaliação automática por comparação de entrada e saída.
  - `g` = gain (valor pedagógico);
    - `1` — complementar: variação, redundância ou treino não essencial;
    - `2` — consolidação: reforça ou transfere conceitos importantes;
    - `3` — central: introduz, desenvolve ou verifica uma aprendizagem essencial.
  - `l` = logic (profundidade lógica);
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
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Competências trabalhadas](wiki/competencias/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Trabalhos futuros](wiki/trabalhos_futuros/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução ao git](wiki/git/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Relacionamentos](wiki/relacionamento/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Relacionamentos Resumo](wiki/uml/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Como fazer os códigos e relatórios](wiki/relatorio/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Criando a Main](wiki/main/README.md)

## Classes e Objetos <!-- @intro -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Classes e Objetos](wiki/intro/README.md)
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
  - Princípios relacionados:
    - responsabilidade: a classe que possui o estado também protege suas regras.
- [ ] `eval=self g=2 l=1 s=1` [[GUIDE] Toalha que enxuga](labs/toalha/README.md) <!-- KOTLIN -->
  - Descrição: a toalha deve controlar seu estado de umidade e fornecer métodos para enxugar, torcer e consultar seu estado.
  - Domínio: o quanto a toalha enxuga depende do seu tamanho e ela não pode suportar água além de sua capacidade.
  - Objetivos: identificar estado e comportamento em uma classe coesa.
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Animal que morre](labs/animal/README.md) <!-- KOTLIN -->
  - Descrição: gerenciar um animal que nasce, cresce e morre. Faz barulho diferente conforme a espécie e o estado de vida.
  - Domínio: Envelhecer faz o animal morrer, impede ele de continuar envelhecendo e de fazer barulho após a morte.
  - Objetivos: modelar o ciclo de vida de um objeto por seu estado.
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Enxugar: Toalha com testes](labs/enxugar/README.md) <!-- KOTLIN -->
  - Descrição: evolução da atividade da toalha, mas agora com a camada de testes de requisição e resposta.
  - Domínio: o mesmo da toalha.
  - Objetivos: manipular entrada e saída de forma separada do domínio, testando apenas o comportamento observável.
- [ ] `eval=diff g=3 l=2 s=1` [[ALONE] Carro dirigível](labs/carro/README.md) <!-- KOTLIN -->
  - Descrição: o carro gerencia entrada, saída de pessoas, combustível e kilomentragem.
  - Domínio: o carro não pode controla o limite de pessoas e possui regras para que a ação de dirigir seja completada.
  - Objetivos: manipular erros como enumerações e treinar técnicas de `early return`.
- [ ] `eval=diff g=3 l=2 s=2` [[CHECK] Calculadora à bateria](labs/calculadora/README.md) <!-- KOTLIN -->
  - Descrição: a calculadora possui bateria, realiza operações matemáticas e as guarda no display.
  - Domínio: A calculadora não pode realizar operações sem bateria e nem dividir por zero.
  - Objetivos: manipular erros como enumerações e treinar técnicas de `early return`.

| Projetos              | toalha | animal | enxugar | carro | calculadora |
|-----------------------|--------|--------|---------|-------|-------------|
| ciclo de vida         | .      | SIM    | .       | .     | .           |
| early return          | .      | .      | .       | SIM   | SIM         |
| testes automáticos    | .      | .      | SIM     | SIM   | SIM         |
| erros comunicados via | bool   | bool   | bool    | enum  | enum        |
| esforço               | mínima | baixo  | baixo   | médio | médio       |

---

## Encapsulamento e Invariantes <!-- @access -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Encapsulamento e Invariantes](wiki/access/README.md)
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
  - Princípios relacionados:
    - responsabilidade: a classe que possui o estado também protege suas regras.
    - invariante: a classe deve preservar seu estado válido em todas as operações e não dar acesso externo a atributos privados.
    - dry: don't repeat yourself, não repita a validação em outro lugar que não seja o setter.
- [ ] `eval=self g=1 l=1 s=1` [[GUIDE] Chinela de números pares](labs/chinela/README.md) <!-- KOTLIN -->
  - Descrição: a chinela controla seu tamanho por meio de operações de consulta e alteração.
  - Domínio: o tamanho deve ser par e permanecer entre 20 e 50; uma tentativa inválida não pode alterar o valor atual.
  - Objetivos: proteger uma regra simples com atributo privado, getter e setter validador.
- [ ] `eval=self g=1 l=1 s=2` [[TRAIN] Camisa de tamanho fixo](labs/camisa/README.md) <!-- KOTLIN -->
  - Descrição: a camisa guarda um tamanho textual e informa os tamanhos permitidos.
  - Domínio: o objeto começa com um tamanho válido e aceita somente `PP`, `P`, `M`, `G`, `GG` ou `XG`, mantendo o estado anterior em caso de falha.
  - Objetivos: consolidar a validação de um conjunto de valores e a inicialização segura no construtor.
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Roupa: camisa com testes](labs/roupa/README.md) <!-- KOTLIN -->
  - Descrição: a roupa recebe comandos para consultar e alterar seu tamanho por meio de um `Shell`.
  - Domínio: a classe aceita apenas tamanhos permitidos e retorna falha sem mudar o tamanho anterior; as mensagens pertencem ao `Shell`.
  - Objetivos: tornar a regra de tamanho testável ao separar domínio, comandos e apresentação de falhas.
- [ ] `eval=diff g=3 l=2 s=2` [[ALONE] Hora 24h ou AM/PM](labs/relogio/README.md) <!-- KOTLIN -->
  - Descrição: o relógio controla hora, minuto e modo de exibição, além de avançar um minuto por vez.
  - Domínio: atributos com valores válidos; validação individual de cada atributo, passagem do tempo, mostrar a hora em 24h ou AM/PM não altera a hora interna.
  - Objetivos: o validações independentes de cada atributo e manter o estado interno variando a forma como a hora é exibida.

| Projetos                | chinela | camisa | roupa | relógio |
|-------------------------|---------|--------|-------|---------|
| validação de construtor | .       | SIM    | SIM   | SIM     |
| uso de arrays internos  | -       | SIM    | SIM   | .       |
| testes automáticos      | .       | SIM    | SIM   | SIM     |
| erros comunicados por   | bool    | bool   | bool  | bool    |
| esforço                 | mínima  | baixo  | baixo | médio   |


## Relações entre objetos: agregação e delegação <!-- @agreg -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Agregação e Delegação](wiki/agreg/README.md)
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
  - Princípios relacionados:
    - responsabilidade: cada objeto protege suas próprias regras, e o coordenador apenas organiza a colaboração.
    - delegação: cada componente é responsável por suas próprias regras, e o coordenador apenas organiza a colaboração.
- [ ] `eval=diff g=3 l=2 s=3` [[GUIDE] Criança andando de Motoca](labs/motoca/README.md) <!-- KOTLIN -->
  - Descrição: a motoca controla tempo de uso e a pessoa que a ocupa, permitindo entrar, sair, comprar tempo e dirigir.
  - Domínio: há no máximo uma pessoa na motoca; ela continua existindo depois de sair, e a corrida depende de pessoa, tempo disponível e idade compatível com o tamanho da motoca.
  - Objetivos: modelar uma agregação opcional e delegar à pessoa a verificação de que pode dirigir.
- [ ] `eval=diff g=3 l=3 s=3` [[TRAIN] Lapiseira de um Grafite](labs/grafite/README.md) <!-- KOTLIN -->
  - Descrição: a lapiseira recebe, remove e usa um grafite para escrever páginas.
  - Domínio: ela comporta no máximo um grafite de espessura compatível; o grafite calcula seu desgaste por dureza e nunca pode ficar menor que `10mm`.
  - Objetivos: delegar o desgaste ao grafite e coordenar a escrita por resultados explícitos do domínio.
- [ ] `eval=diff g=3 l=4 s=3` [[ALONE] Passeando e pagando o MotoUber](labs/motouber/README.md) <!-- KOTLIN -->
  - Descrição: o Uber coordena uma corrida com motorista, passageiro e custo acumulado.
  - Domínio: o motorista permanece associado ao Uber, o passageiro sai ao fim da corrida e cada pessoa mantém seu próprio dinheiro; em caso de saldo insuficiente, o Uber completa o pagamento ao motorista.
  - Objetivos: coordenar a transferência de dinheiro sem retirar essa responsabilidade de `Person` e representar os resultados da corrida.

| Projetos                  | motoca    | grafite   | motouber   |
|---------------------------|-----------|-----------|------------|
| agregação nullable        | SIM       | SIM       | SIM        |
| objeto removido devolvido | SIM       | SIM       | SIM        |
| regra delegada            | SIM       | SIM       | SIM        |
| testes automáticos        | SIM       | SIM       | SIM        |
| erros comunicados por     | enum/null | enum/null | enum/null  |
| esforço                   | baixo     | médio     | médio-alto |


## Desafios de agregação e estados <!-- @agchal -->

- [ ] `eval=none            ` [[INTRO] Desafios de agregação e estados](wiki/agcha/README.md)
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
    - delegação: cada componente é responsável por suas próprias regras, e o coordenador apenas organiza a colaboração.
- [ ] `eval=diff g=1 l=1 s=1` [[CHECK] Brinque até matar o Tamagotchi](labs/tamagotchi/README.md) <!-- KOTLIN -->
  - Descrição: o jogo coordena brincadeiras, banho e sono de um pet com energia, limpeza e idade.
  - Domínio: o pet mantém energia e limpeza em seus limites, registra a primeira causa de morte e não aceita novas alterações depois de morto.
  - Objetivos: delegar ao pet as transições de estado e coordenar ações que respeitam o estado terminal.
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Notebook com bateria e carregador](labs/charger/README.md) <!-- KOTLIN -->
  - Descrição: o notebook pode receber bateria e carregador, ligar, desligar e acumular tempo de uso.
  - Domínio: bateria e carregador existem fora do notebook; a bateria mantém carga entre zero e sua capacidade, e o notebook muda seu comportamento conforme as fontes de energia conectadas.
  - Objetivos: coordenar consumo e recarga por etapas, delegando os limites de carga à bateria e reagindo à falta de energia.

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

- [ ] `eval=none            ` [[INTRO] Introdução Coleções lineares](wiki/arrays/README.md)
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
- [ ] `eval=none            ` [[GUIDE] Listas em Python](wiki/listas/README.md)
  - Descrição: uma referência prática para criar, percorrer, inserir, remover, buscar, filtrar, copiar e ordenar listas de pessoas.
  - Domínio: uma lista mantém elementos ordenados por índice; algumas operações a alteram, enquanto cópia, filtro e ordenação podem produzir outra lista.
  - Objetivos: escolher operações idiomáticas de lista e reconhecer quando uma consulta ou alteração modifica a coleção original.
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Coleção de pessoas](labs/array/README.md) <!-- KOTLIN -->
  - Descrição: uma lista de pessoas recebe comandos para inserir e remover nas extremidades, remover pelo nome e filtrar por idade.
  - Domínio: a coleção começa vazia, preserva a ordem e não muda ao remover de uma lista vazia ou buscar um nome inexistente; a remoção por nome afeta apenas a primeira ocorrência.
  - Objetivos: praticar diretamente as operações fundamentais de uma lista antes de encapsulá-las em uma classe.
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Contato com telefones](labs/contato/README.md) <!-- KOTLIN -->
  - Descrição: um contato mantém nome, favorito e uma coleção privada de telefones.
  - Domínio: somente telefones válidos entram na coleção, a ordem só muda pelas operações do contato e uma remoção por índice inválido preserva o estado.
  - Objetivos: encapsular uma coleção, delegar a validação do número a `Phone` e separar o domínio das mensagens do `Shell`.
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Pula-pula com crianças](labs/pula-pula/README.md) <!-- KOTLIN -->
  - Descrição: o pula-pula controla uma fila de espera e uma lista de crianças brincando.
  - Domínio: as crianças mantêm sua ordem nas listas, entram e saem por operações de fila e podem ser removidas pelo nome em qualquer uma das duas coleções.
  - Objetivos: coordenar movimentos entre coleções lineares e perceber que a posição representa uma ordem variável, não um lugar fixo.
- [ ] `eval=diff g=1 l=1 s=1` [[ALONE] Lapiseira com tambor de grafites](labs/lapiseira/README.md) <!-- KOTLIN -->
  - Descrição: a lapiseira possui um grafite em uso no bico e vários grafites reserva em um tambor.
  - Domínio: grafites compatíveis entram no fim do tambor, o próximo sai do começo para o bico e o grafite em uso preserva suas próprias regras de desgaste e tamanho mínimo.
  - Objetivos: combinar uma referência opcional com uma coleção linear, reutilizando e delegando as regras de `Lead`.

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

- [ ] `eval=none            ` [[INTRO] Introdução Posições fixas e ausência](wiki/slots/README.md)
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
- [ ] `eval=diff g=1 l=1 s=1` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md) <!-- KOTLIN -->
  - Descrição: o cinema reserva, cancela e consulta cadeiras de uma sala.
  - Domínio: cada índice representa uma cadeira fixa que contém um `Client` ou `null`; não é possível reservar uma posição inexistente, já ocupada ou para um cliente que já está na sala.
  - Objetivos: modelar ausência em um vetor de tamanho fixo, validar posições e proteger a coleção interna com uma cópia.
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md) <!-- KOTLIN -->
  - Descrição: o mercantil controla clientes em uma fila de espera e em caixas de atendimento.
  - Domínio: a fila cresce e diminui, mas os caixas têm quantidade e índices fixos; chamar um cliente remove-o da fila antes de ocupar um caixa, e falhas não mudam nenhuma coleção.
  - Objetivos: comparar uma fila variável com posições fixas e coordenar a movimentação de clientes entre elas.

| Projetos              | cinema | budega |
| --------------------- | ------ | ------ |
| erros comunicados por | bool   | bool   |
| capacidade fixa       | SIM    | SIM    |
| tipo de ausência      | null   | null   |
| fila variável         | .      | SIM    |
| validação de índice   | SIM    | SIM    |
| testes automáticos    | SIM    | SIM    |
| esforço               | baixo  | médio  |

## Exceções <!-- @exception -->

- [ ] `eval=none            ` [[INTRO] Exceções](wiki/exception/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [[TRAIN] Bermuda: exceções para invariantes de tamanho](labs/bermuda/README.md) <!-- KOTLIN -->
  - Objetivo: usar `IllegalArgumentException` para comunicar uma alteração de estado inválida.
  - Conceitos: exceção padrão, `require`, `try/catch` e invariante.
  - Técnicas: validar no construtor e no setter, preservar estado e traduzir falhas no Shell.
  - Pré-requisito: encapsulamento, invariantes e `try/except` básicos.
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Birita: fila, caixas e exceções](labs/birita/README.md) <!-- KOTLIN -->
  - Descrição: o mercantil controla clientes em uma fila de espera e em caixas de atendimento.
  - Domínio: a fila cresce e diminui; os caixas têm quantidade fixa; índices inexistentes lançam exceção, enquanto resultados esperados são devolvidos pelo domínio.
  - Objetivos: distinguir exceções de resultados normais de uma operação e preservar o estado quando uma operação falha.
- [ ] `eval=diff g=1 l=1 s=1` [[ALONE] Junkfood: exceções e objeto vazio](labs/junkfood/README.md) <!-- KOTLIN -->
  - Descrição: a máquina de vendas controla espirais fixas, saldo, compras, troco e arrecadação.
  - Domínio: cada posição sempre contém um `Slot` imutável; índices e quantidades inválidos lançam exceções, e uma compra só altera saldo, quantidade e arrecadação quando pode ser concluída.
  - Objetivos: distinguir exceções de resultados normais, representar espirais vazias com objetos e preservar o histórico de vendas ao devolver o troco.
- [ ] `eval=diff g=3 l=2 s=1` [[TRAIN] Fusca: posições, exceções e direção](labs/fusca/README.md) <!-- KOTLIN -->
  - Objetivo: aplicar exceções nomeadas a regras de ocupação e direção.
  - Conceitos: posição fixa, composição, exceções padrão e exceções de domínio.
  - Técnicas: receber objetos, preservar posições, validar pré-condições e traduzir falhas no Shell.
  - Pré-requisito: composição, posições fixas e exceções básicas.
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Guardando moedas e itens em um cofrinho](labs/porquinho/README.md) <!-- KOTLIN -->
  - Descrição: o porquinho armazena moedas e itens até sua capacidade e pode ser quebrado para permitir extrações.
  - Domínio: moedas e itens são imutáveis; adições só ocorrem enquanto o porquinho está intacto e há volume disponível; depois da quebra, novas adições falham e moedas ou itens podem ser extraídos separadamente.
  - Objetivos: proteger capacidade e estado terminal, compor coleções de objetos imutáveis e preservar o estado após operações recusadas.
- [ ] `eval=diff g=1 l=1 s=1` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md) <!-- KOTLIN -->
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
- [ ] `eval=diff g=3 l=2 s=1` [Agenda: contatos por identidade em um mapa](labs/agenda/README.md) <!-- KOTLIN -->
  - Objetivo: localizar contatos pela identidade usando um mapa.
  - Conceitos: chave única, mapa, busca por identidade e fonte única de verdade.
  - Técnicas: encapsular dicionários, validar entradas e separar domínio do Shell.
  - Pré-requisito: dicionários, classes e validação básica.
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Agiota: clientes identificados por codenome](labs/agiota/README.md) <!-- KOTLIN -->
  - Objetivo: representar clientes pelo codenome em um mapa.
  - Conceitos: identidade por chave, unicidade, composição e exceções de domínio.
  - Técnicas: localizar um cliente e delegar mudanças de dívida à classe que a possui.
  - Pré-requisito: classes, mapas e exceções.
- [ ] `eval=diff g=1 l=1 s=1` [Meu Petshop](labs/petshop/README.md) <!-- KOTLIN -->



## Índices e Redundância <!-- @cache -->

Neste bloco, você aprenderá a manter diferentes formas de acesso aos mesmos objetos, preservando uma única fonte de verdade e a consistência entre as estruturas.


___
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Favoritos: índice secundário e consistência](labs/favoritos/README.md) <!-- KOTLIN -->
  - Objetivo: criar uma forma secundária de acesso sem duplicar os contatos.
  - Conceitos: índice, conjunto, redundância intencional e consistência.
  - Técnicas: manter uma fonte de verdade e sincronizar estruturas relacionadas.
  - Pré-requisito: mapas, conjuntos e encapsulamento.
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Ligação: composição para histórico e ranking](labs/ligacao/README.md) <!-- KOTLIN -->
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
- [ ] `eval=self g=1 l=1 s=1` [[ALONE] Zoo: contrato comum e comportamento polimórfico](labs/zoo/README.md) <!-- KOTLIN -->
  - Objetivo: tratar espécies diferentes por meio de um contrato comum.
  - Conceitos: classe abstrata, herança, substituição e despacho polimórfico.
  - Técnicas: implementar métodos abstratos e escrever clientes dependentes da abstração.
  - Pré-requisito: classes, herança, composição e delegação.
- [ ] `eval=self g=1 l=1 s=1` [[TRAIN] Pagamento: composição de métodos de pagamento](labs/pagamento/README.md) <!-- KOTLIN -->
  - Descrição: processar pagamentos por cartão, Pix e boleto e continuar após falhas individuais.
  - Domínio: o valor precisa ser positivo, o cartão não pode exceder seu limite e uma falha não altera o limite nem interrompe os pagamentos seguintes.
  - Objetivos: aplicar polimorfismo por composição e tratar falhas específicas sem acoplar o processamento aos métodos concretos.
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Shapes: interface e substituição geométrica](labs/shapes/README.md) <!-- KOTLIN -->
  - Descrição: criar e consultar círculos e retângulos em uma coleção de formas geométricas.
  - Domínio: as coordenadas e dimensões das formas permanecem imutáveis depois da criação.
  - Objetivos: definir uma interface comum e processar formas diferentes por substituição polimórfica.
- [ ] `eval=self g=3 l=1 s=1` [Estacionamento — polimorfismo por tipo de veículo](labs/estacionamento/README.md) <!-- KOTLIN -->
  - Descrição: estacionar veículos, avançar o relógio e cobrar pela permanência conforme o tipo de veículo.
  - Domínio: identifiers devem ser únicos, o tempo não pode retroceder e um pagamento inválido mantém o veículo estacionado.
  - Objetivos: variar as tarifas por herança polimórfica e manter a coordenação do estacionamento independente das fórmulas.
- [ ] `eval=diff g=3 l=1 s=1` [Cofre — polimorfismo por contrato de valor](labs/cofre/README.md) <!-- KOTLIN -->
  - Descrição: guardar moedas e itens no mesmo cofre, respeitando sua capacidade e extrações após a quebra.
  - Domínio: só cofres intactos recebem valores, o volume não excede a capacidade e a quebra preserva o conteúdo.
  - Objetivos: modelar uma coleção heterogênea por interface e manter as invariantes de estado no cofre.
- [ ] `eval=diff g=3 l=1 s=1` [Cadastro — contas com regras polimórficas](labs/cadastro/README.md) <!-- KOTLIN -->
  - Descrição: cadastrar clientes, operar contas correntes e poupanças e aplicar suas regras mensais.
  - Domínio: cada cliente é cadastrado uma vez, saques exigem saldo suficiente e transferências validam as duas contas antes de retirar o valor.
  - Objetivos: delegar atualizações mensais por polimorfismo e localizar clientes e contas por mapas.



## TODO <!-- @todo lang=X -->

- [ ] `eval=diff g=1 l=1 s=1` [Twitter — colaboração entre usuários e timelines](labs/twitter/README.md) <!-- KOTLIN -->
  - Descrição: usuários seguem uns aos outros, publicam tweets e consultam timelines compartilhadas.
  - Domínio: usernames e ids de tweets são únicos, relações de seguir são bidirecionais e remoções limpam vínculos.
  - Objetivos: coordenar objetos colaboradores e manter timelines e curtidas consistentes com tweets compartilhados.
- [ ] `eval=diff g=1 l=1 s=1` [Salário — regras de cálculo polimórficas](labs/salario/README.md) <!-- KOTLIN -->
  - Descrição: calcular salários para professores, servidores e terceirizados, com diárias e bônus compartilhado.
  - Domínio: nomes são únicos, limites de diárias dependem da categoria e o bônus é dividido entre os funcionários atuais.
  - Objetivos: delegar fórmulas por polimorfismo e calcular valores derivados na folha sem condicionar por categoria.
- [ ] `eval=diff g=2 l=1 s=1` [Mensagem — inbox e leitura destrutiva](labs/mensagem/README.md) <!-- KOTLIN -->
  - Descrição: cadastrar usuários, enviar mensagens e consumir cada inbox em ordem de chegada.
  - Domínio: só usuários cadastrados participam do envio e a leitura remove as mensagens que devolve.
  - Objetivos: separar cadastro, envio e leitura em objetos coesos e manter o domínio independente da entrada e saída.
- [ ] `eval=self g=1 l=1 s=1` [Comunicador — envio autorizado por composição](labs/comunicador/README.md) <!-- KOTLIN -->
  - Descrição: enviar mensagens entre comunicadores autorizados e consumir o inbox durante a leitura.
  - Domínio: a autorização é direcional, somente destinatários registrados recebem mensagens e ler esvazia o inbox.
  - Objetivos: separar autorização e armazenamento da operação de envio por composição e delegação.
- [ ] `eval=self g=2 l=1 s=1` [Paciente — vínculos bidirecionais no hospital](labs/paciente/README.md) <!-- KOTLIN -->
  - Descrição: cadastrar pacientes e médicos e relacioná-los em um hospital.
  - Domínio: IDs são únicos, um paciente não se relaciona com dois médicos da mesma especialidade e os dois lados do vínculo permanecem consistentes.
  - Objetivos: modelar uma associação bidirecional e validar suas regras antes de atualizar os objetos relacionados.
- [ ] `eval=diff g=3 l=1 s=1` [WhatsApp — grupos e estado de leitura por participante](labs/whatsapp/README.md)
  - Objetivo: modelar mensagens não lidas de forma independente para cada membro de um grupo.
  - Conceitos: composição, multiplicidade, estado derivado e delegação.
  - Técnicas: controlar convites, participação, leitura destrutiva e notificações.
  - Pré-requisito: composição, coleções e leitura destrutiva.
- [ ] `eval=self g=3 l=1 s=1` [Grupo — contrato comum para chats](labs/grupo/README.md)
  - Objetivo: tratar grupo e conversa individual por um contrato comum de chat.
  - Conceitos: classe abstrata, herança, especialização por comportamento e composição.
  - Técnicas: compartilhar envio/leitura, restringir capacidades e manter estado por participante.
  - Pré-requisito: classes abstratas, herança e polimorfismo.
- [ ] `eval=self g=1 l=1 s=1` [Vetores — coleção linear e índices](labs/vetores/README.md)
  - Objetivo: preservar ordem e duplicatas em uma coleção linear.
  - Conceitos: sequência, índice, busca e mutação controlada.
  - Técnicas: inserir, alterar, localizar e tratar limites.
  - Pré-requisito: listas, índices e validação de limites.
- [ ] `eval=self g=2 l=1 s=1` [Anotações — sessão e notas privadas](labs/anotacoes/README.md)
  - Objetivo: proteger notas por meio de uma sessão autenticada.
  - Conceitos: encapsulamento, estado de sessão, composição e imutabilidade.
  - Técnicas: validar credenciais, controlar acesso e associar notas ao usuário.
  - Pré-requisito: mapas, encapsulamento e validação de credenciais.
- [ ] `eval=self g=1 l=1 s=1` [Trem — composição e alocação de passageiros](labs/trem/README.md)
- [ ] `eval=self g=1 l=1 s=1` [Produto — Composite e Decorator](labs/produto/README.md)
- [ ] `eval=none g=1 l=1 s=1` [Git — fluxo de trabalho e recuperação](labs/git_pratica/README.md)
  - Objetivo: compreender commits, histórico, restauração e resolução de conflitos.
  - Conceitos: versionamento, integração e recuperação.
  - Técnicas: usar Git local e remoto e documentar decisões.
  - Pré-requisito: comandos básicos de Git e trabalho com repositórios.
- [ ] `eval=diff g=3 l=1 s=1` [Operações de saque, depósito, extrato](labs/tarifas/README.md)
  - Objetivo: modelar um histórico financeiro que preserve operações e permita extorno seletivo.
  - Conceitos: encapsulamento, invariantes, comandos e consultas.
  - Técnicas: registrar eventos, validar saldo e operar por índices sem apagar histórico.
  - Pré-requisito: coleções, exceções e encapsulamento.

## labs <!-- @labs -->
## wiki <!-- @wiki -->
- [ ] `eval=none            ` [Pesquisa sobre C++](wiki/cpp/README.md)
- [ ] `eval=none            ` [NÃO TEM TÍTULO](wiki/fixas/README.md)
