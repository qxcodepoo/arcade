# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

- Marcadores pedagógicos
  - Tipo de atividade
    - GUIDE — leitura, referência ou exemplo guiado
    - TRAIN — prática com consulta
    - ALONE — tentativa independente
    - CHECK — verificação do domínio
  - Nível de complexidade lógica
    - 1 - Mínima: aplicação direta de uma regra.
    - 2 - Baixa: poucas decisões independentes.
    - 3 - Média: combinação de condições ou operações.
    - 4 - Média-alta: regras interdependentes e casos especiais.
    - 5 - Alta: decisões encadeadas e necessidade de decomposição.
    - 6 - Muito alta: várias regras coordenadas, estados ou estratégias possíveis.

## Material de referência <!-- @refs -->

- [ ] `@+competencias   type=wiki gain=0 hard=1 size=1` [Competências trabalhadas](wiki/competencias/README.md)
- [ ] `@+futuros        type=wiki gain=0 hard=1 size=1` [Trabalhos futuros](wiki/trabalhos_futuros/README.md)
- [ ] `@+git            type=wiki gain=1 hard=1 size=1` [[GUIDE] Introdução ao git](wiki/git/README.md)
- [ ] `@+relacionamento type=wiki gain=0 hard=1 size=1` [[GUIDE] Relacionamentos](wiki/relacionamento/README.md)
- [ ] `@+uml            type=wiki gain=0 hard=1 size=1` [[GUIDE] Relacionamentos Resumo](wiki/uml/README.md)
- [ ] `@+relatorio      type=wiki gain=0 hard=1 size=1` [[GUIDE] Como fazer os códigos e relatórios](wiki/relatorio/README.md)
- [ ] `@+atividade      type=wiki gain=0 hard=1 size=1` [[GUIDE] Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [ ] `@+main           type=wiki gain=0 hard=1 size=1` [[GUIDE] Criando a Main](wiki/main/README.md)

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
- [ ] `@toalha          type=self gain=2 hard=1 size=1` [[GUIDE] Toalha: estado e comportamento em uma classe coesa](labs/toalha/README.md)
  - Descrição: a toalha deve controlar seu estado de umidade e fornecer métodos para enxugar, torcer e consultar seu estado.
  - Domínio: o quanto a toalha enxuga depende do seu tamanho e ela não pode suportar água além de sua capacidade.
  - Objetivos: identificar estado e comportamento em uma classe coesa.
- [ ] `@animal          type=diff gain=2 hard=1 size=1` [[GUIDE] Animal: estado, comportamento e ciclo de vida](labs/animal/README.md)
  - Descrição: gerenciar um animal que nasce, cresce e morre. Faz barulho diferente conforme a espécie e o estado de vida.
  - Domínio: Envelhecer faz o animal morrer, impede ele de continuar envelhecendo e de fazer barulho após a morte.
  - Objetivos: modelar o ciclo de vida de um objeto por seu estado.
- [ ] `@enxugar         type=diff gain=2 hard=1 size=2` [[TRAIN] Enxugar: comportamento observável e interface](labs/enxugar/README.md)
  - Descrição: evolução da atividade da toalha, mas agora com a camada de testes de requisição e resposta.
  - Domínio: o mesmo da toalha.
  - Objetivos: manipular entrada e saída de forma separada do domínio, testando apenas o comportamento observável.
- [ ] `@carro           type=diff gain=3 hard=2 size=2` [[ALONE] Carro: separação inicial entre domínio e interface](labs/carro/README.md)
  - Descrição: o carro gerencia entrada, saída de pessoas, combustível e kilomentragem.
  - Domínio: o carro não pode controla o limite de pessoas e possui regras para que a ação de dirigir seja completada.
  - Objetivos: manipular erros como enumerações e treinar técnicas de `early return`.
- [ ] `@calculadora     type=diff gain=3 hard=2 size=2` [[CHECK] Calculadora: resultados de operação e mensagens na interface](labs/calculadora/README.md)
  - Descrição: a calculadora possui bateria, realiza operações matemáticas e as guarda no display.
  - Domínio: A calculadora não pode realizar operações sem bateria e nem dividir por zero.
  - Objetivos: manipular erros como enumerações e treinar técnicas de `early return`.

| Projetos              | toalha | animal | enxugar | carro | calculadora |
|-----------------------|--------|--------|---------|-------|-------------|
| erros comunicados via | bool   | bool   | bool    | enum  | enum        |
| testes automáticos    | .      | .      | SIM     | SIM   | SIM         |
| ciclo de vida         | .      | SIM    | .       | .     | .           |
| early return          | .      | .      | .       | SIM   | SIM         |
| lógica                | mínima | baixa  | baixa   | média | média       |

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
- [ ] `@chinela         type=self gain=1 hard=1 size=1` [[GUIDE] Comprando uma chinela 40/41](labs/chinela/README.md)
  - Descrição: a chinela controla seu tamanho por meio de operações de consulta e alteração.
  - Domínio: o tamanho deve ser par e permanecer entre 20 e 50; uma tentativa inválida não pode alterar o valor atual.
  - Objetivo: proteger uma regra simples com atributo privado, getter e setter validador.
- [ ] `@camisa          type=self gain=1 hard=2 size=1` [[TRAIN] Comprando uma camisa XG](labs/camisa/README.md)
  - Descrição: a camisa guarda um tamanho textual e informa os tamanhos permitidos.
  - Domínio: o objeto começa com um tamanho válido e aceita somente `PP`, `P`, `M`, `G`, `GG` ou `XG`, mantendo o estado anterior em caso de falha.
  - Objetivo: consolidar a validação de um conjunto de valores e a inicialização segura no construtor.
- [ ] `@roupa           type=diff gain=2 hard=2 size=1` [[TRAIN] Roupa: extensão testável de Camisa](labs/roupa/README.md)
  - Descrição: a roupa recebe comandos para consultar e alterar seu tamanho por meio de um `Shell`.
  - Domínio: a classe aceita apenas tamanhos permitidos e retorna falha sem mudar o tamanho anterior; as mensagens pertencem ao `Shell`.
  - Objetivo: tornar a regra de tamanho testável ao separar domínio, comandos e apresentação de falhas.
- [ ] `@relogio         type=diff gain=3 hard=3 size=2` [[ALONE] Relógio: invariantes de tempo e atualização coordenada](labs/relogio/README.md)
  - Descrição: o relógio controla hora, minuto e modo de exibição, além de avançar um minuto por vez.
  - Domínio: atributos com valores válidos; validação individual de cada atributo, passagem do tempo, mostrar a hora em 24h ou AM/PM não altera a hora interna.
  - Objetivo: o validações independentes de cada atributo e manter o estado interno variando a forma como a hora é exibida.

| Projetos                | chinela | camisa | roupa | relógio |
|-------------------------|---------|--------|-------|---------|
| erros comunicados por   | bool    | bool   | bool  | bool    |
| testes automáticos      | .       | SIM    | SIM   | SIM     |
| validação de construtor | .       | SIM    | SIM   | SIM     |
| uso de arrays internos  | -       | SIM    | SIM   | .       |
| lógica                  | mínima  | baixa  | baixa | média   |


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
- [ ] `@motoca          type=diff gain=3 hard=2 size=3` [[GUIDE] Motoca: agregação opcional e delegação](labs/motoca/README.md)
  - Descrição: a motoca controla tempo de uso e a pessoa que a ocupa, permitindo entrar, sair, comprar tempo e dirigir.
  - Domínio: há no máximo uma pessoa na motoca; ela continua existindo depois de sair, e a corrida depende de pessoa, tempo disponível e idade compatível com o tamanho da motoca.
  - Objetivos: modelar uma agregação opcional e delegar à pessoa a verificação de que pode dirigir.
- [ ] `@grafite         type=diff gain=3 hard=3 size=3` [[TRAIN] Grafite: agregação opcional e delegação](labs/grafite/README.md)
  - Descrição: a lapiseira recebe, remove e usa um grafite para escrever páginas.
  - Domínio: ela comporta no máximo um grafite de espessura compatível; o grafite calcula seu desgaste por dureza e nunca pode ficar menor que `10mm`.
  - Objetivos: delegar o desgaste ao grafite e coordenar a escrita por resultados explícitos do domínio.
- [ ] `@motouber        type=diff gain=3 hard=4 size=3` [[ALONE] MotoUber: colaboração e transferência de recurso](labs/motouber/README.md)
  - Descrição: o Uber coordena uma corrida com motorista, passageiro e custo acumulado.
  - Domínio: o motorista permanece associado ao Uber, o passageiro sai ao fim da corrida e cada pessoa mantém seu próprio dinheiro; em caso de saldo insuficiente, o Uber completa o pagamento ao motorista.
  - Objetivos: coordenar a transferência de dinheiro sem retirar essa responsabilidade de `Person` e representar os resultados da corrida.

| Projetos                  | motoca    | grafite   | motouber   |
|---------------------------|-----------|-----------|------------|
| erros comunicados por     | enum/null | enum/null | enum/null  |
| agregação nullable        | SIM       | SIM       | SIM        |
| objeto removido devolvido | SIM       | SIM       | SIM        |
| regra delegada            | SIM       | SIM       | SIM        |
| testes automáticos        | SIM       | SIM       | SIM        |
| lógica                    | baixa     | média     | média-alta |


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
- [ ] `@tamagotchi      type=diff gain=3 hard=3 size=3` [[CHECK] Tamagotchi: coordenação, invariantes e estado terminal](labs/tamagotchi/README.md)
  - Descrição: o jogo coordena brincadeiras, banho e sono de um pet com energia, limpeza e idade.
  - Domínio: o pet mantém energia e limpeza em seus limites, registra a primeira causa de morte e não aceita novas alterações depois de morto.
  - Objetivos: delegar ao pet as transições de estado e coordenar ações que respeitam o estado terminal.
- [ ] `@charger         type=diff gain=3 hard=3 size=3` [[TRAIN] Charger: agregação e coordenação por etapas](labs/charger/README.md)
  - Descrição: o notebook pode receber bateria e carregador, ligar, desligar e acumular tempo de uso.
  - Domínio: bateria e carregador existem fora do notebook; a bateria mantém carga entre zero e sua capacidade, e o notebook muda seu comportamento conforme as fontes de energia conectadas.
  - Objetivos: coordenar consumo e recarga por etapas, delegando os limites de carga à bateria e reagindo à falta de energia.

| Projetos                        | tamagotchi | charger   |
|---------------------------------|------------|-----------|
| agregação de componente externo | SIM        | SIM       |
| invariantes no componente       | SIM        | SIM       |
| coordenação de estados          | SIM        | SIM       |
| testes automáticos              | SIM        | SIM       |
| erros comunidados por           | enum       | enum/null |
| lógica                          | média-alta | alta      |
| transição terminal              | SIM        | .         |




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
- [ ] `@+listas         type=wiki gain=1 hard=1 size=1` [[GUIDE] Listas em Python: ações mais comuns](wiki/listas/README.md)
  - Descrição: uma referência prática para criar, percorrer, inserir, remover, buscar, filtrar, copiar e ordenar listas de pessoas.
  - Domínio: uma lista mantém elementos ordenados por índice; algumas operações a alteram, enquanto cópia, filtro e ordenação podem produzir outra lista.
  - Objetivos: escolher operações idiomáticas de lista e reconhecer quando uma consulta ou alteração modifica a coleção original.
- [ ] `@array           type=diff gain=2 hard=1 size=1` [[GUIDE] Array: manipulação direta de uma coleção de pessoas](labs/array/README.md)
  - Descrição: uma lista de pessoas recebe comandos para inserir e remover nas extremidades, remover pelo nome e filtrar por idade.
  - Domínio: a coleção começa vazia, preserva a ordem e não muda ao remover de uma lista vazia ou buscar um nome inexistente; a remoção por nome afeta apenas a primeira ocorrência.
  - Objetivos: praticar diretamente as operações fundamentais de uma lista antes de encapsulá-las em uma classe.
- [ ] `@contato         type=diff gain=2 hard=1 size=2` [[TRAIN] Contato: encapsulamento de uma coleção de telefones](labs/contato/README.md)
  - Descrição: um contato mantém nome, favorito e uma coleção privada de telefones.
  - Domínio: somente telefones válidos entram na coleção, a ordem só muda pelas operações do contato e uma remoção por índice inválido preserva o estado.
  - Objetivos: encapsular uma coleção, delegar a validação do número a `Phone` e separar o domínio das mensagens do `Shell`.
- [ ] `@pula-pula       type=diff gain=1 hard=1 size=1` [[TRAIN] Pula-pula: filas e movimentação de crianças](labs/pula-pula/README.md)
  - Descrição: o pula-pula controla uma fila de espera e uma lista de crianças brincando.
  - Domínio: as crianças mantêm sua ordem nas listas, entram e saem por operações de fila e podem ser removidas pelo nome em qualquer uma das duas coleções.
  - Objetivos: coordenar movimentos entre coleções lineares e perceber que a posição representa uma ordem variável, não um lugar fixo.
- [ ] `@lapiseira       type=diff gain=1 hard=1 size=1` [[ALONE] Lapiseira: extensão do grafite com tambor](labs/lapiseira/README.md)
  - Descrição: a lapiseira possui um grafite em uso no bico e vários grafites reserva em um tambor.
  - Domínio: grafites compatíveis entram no fim do tambor, o próximo sai do começo para o bico e o grafite em uso preserva suas próprias regras de desgaste e tamanho mínimo.
  - Objetivos: combinar uma referência opcional com uma coleção linear, reutilizando e delegando as regras de `Lead`.

| Projetos                 | listas | array | contato    | pula-pula | lapiseira |
|--------------------------|--------|-------|------------|-----------|-----------|
| relação entre objetos    | .      | .     | composição | agregação | agregação |
| busca ou filtro          | SIM    | SIM   | .          | SIM       | .         |
| erros comunicados por    | .      | .     | bool       | bool/null | enum/null |
| ordem como regra         | SIM    | SIM   | SIM        | SIM       | SIM       |
| coleção encapsulada      | .      | .     | SIM        | SIM       | SIM       |
| movimento entre coleções | .      | .     | .          | SIM       | SIM       |
| testes automáticos       | .      | SIM   | SIM        | SIM       | SIM       |


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
- [ ] `@cinema          type=diff gain=1 hard=1 size=1` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md)
  - Descrição: o cinema reserva, cancela e consulta cadeiras de uma sala.
  - Domínio: cada índice representa uma cadeira fixa que contém um `Client` ou `null`; não é possível reservar uma posição inexistente, já ocupada ou para um cliente que já está na sala.
  - Objetivos: modelar ausência em um vetor de tamanho fixo, validar posições e proteger a coleção interna com uma cópia.
- [ ] `@budega          type=diff gain=2 hard=1 size=1` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md)
  - Descrição: o mercantil controla clientes em uma fila de espera e em caixas de atendimento.
  - Domínio: a fila cresce e diminui, mas os caixas têm quantidade e índices fixos; chamar um cliente remove-o da fila antes de ocupar um caixa, e falhas não mudam nenhuma coleção.
  - Objetivos: comparar uma fila variável com posições fixas e coordenar a movimentação de clientes entre elas.
- [ ] `@junkfood        type=diff gain=1 hard=1 size=1` [[ALONE] Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md)
  - Descrição: a máquina de vendas controla espirais fixas, saldo, compras, troco e arrecadação.
  - Domínio: cada posição sempre contém um `Slot`; uma espiral vazia é um objeto com quantidade zero, e uma compra só reduz saldo e quantidade quando há índice, produto e dinheiro válidos.
  - Objetivos: comparar o objeto vazio com `null`, preservar invariantes de saldo e quantidade e calcular arrecadação sem apagá-la ao devolver o troco.

| Projetos              | cinema | budega | junkfood     |
| --------------------- | ------ | ------ | ------------ |
| erros comunicados por |        |        |              |
| capacidade fixa       | SIM    | SIM    | SIM          |
| tipo de ausência      | null   | null   | objeto vazio |
| fila variável         | .      | SIM    | .            |
| validação de índice   | SIM    | SIM    | SIM          |
| testes automáticos    | SIM    | SIM    | SIM          |
| lógica                | baixa  | média  | média-alta   |



## Exceções <!-- @exception -->


- [ ] `@bermuda         type=diff gain=2 hard=1 size=1` [[TRAIN] Bermuda: exceções para invariantes de tamanho](labs/bermuda/README.md)
  - Objetivo: usar `ValueError` para comunicar uma alteração de estado inválida.
  - Conceitos: exceção padrão, `raise`, `try/except` e invariante.
  - Técnicas: validar no construtor e no setter, preservar estado e traduzir falhas no Shell.
  - Pré-requisito: encapsulamento, invariantes e `try/except` básicos.
- [ ] `@fusca           type=diff gain=2 hard=2 size=2` [[TRAIN] Fusca: posições, exceções e direção](labs/fusca/README.md)
  - Objetivo: aplicar exceções nomeadas a regras de ocupação e direção.
  - Conceitos: posição fixa, composição, `IndexError` e exceção de domínio.
  - Técnicas: receber objetos, preservar posições, validar pré-condições e traduzir falhas no Shell.
  - Pré-requisito: composição, posições fixas e exceções básicas.
- [ ] `@porquinho       type=diff gain=1 hard=1 size=1` [Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)
- [ ] `@tabuleiro       type=diff gain=1 hard=1 size=1` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)
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
- [ ] `@agenda          type=diff gain=3 hard=2 size=3` [Agenda: contatos por identidade em um mapa](labs/agenda/README.md)
  - Objetivo: localizar contatos pela identidade usando um mapa.
  - Conceitos: chave única, mapa, busca por identidade e fonte única de verdade.
  - Técnicas: encapsular dicionários, validar entradas e separar domínio do Shell.
  - Pré-requisito: dicionários, classes e validação básica.
- [ ] `@agiota          type=diff gain=1 hard=1 size=1` [Gerencie os empréstimos do agiota](labs/agiota/README.md)
  - Objetivo: aplicar mapas e exceções a um histórico de operações.
  - Conceitos: mapa, exceção de domínio, histórico, invariante e ciclo de vida.
  - Técnicas: calcular estado derivado, tratar falhas e coordenar mudanças de estado.
  - Pré-requisito: mapas, exceções e cálculo de estado derivado.
- [ ] `@petshop         type=diff gain=1 hard=1 size=1` [Meu Petshop](labs/petshop/README.md)



## Índices e Redundância <!-- @cache -->

Neste bloco, você aprenderá a manter diferentes formas de acesso aos mesmos objetos, preservando uma única fonte de verdade e a consistência entre as estruturas.


___
- [ ] `@favoritos       type=diff gain=1 hard=1 size=1` [[TRAIN] Favoritos: índice secundário e consistência](labs/favoritos/README.md)
  - Objetivo: criar uma forma secundária de acesso sem duplicar os contatos.
  - Conceitos: índice, conjunto, redundância intencional e consistência.
  - Técnicas: manter uma fonte de verdade e sincronizar estruturas relacionadas.
  - Pré-requisito: mapas, conjuntos e encapsulamento.
- [ ] `@ligacao         type=diff gain=1 hard=1 size=1` [[TRAIN] Ligação: composição para histórico e ranking](labs/ligacao/README.md)
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
- [ ] `@zoo             type=self gain=1 hard=1 size=1` [[ALONE] Zoo: contrato comum e comportamento polimórfico](labs/zoo/README.md)
  - Objetivo: tratar espécies diferentes por meio de um contrato comum.
  - Conceitos: classe abstrata, herança, substituição e despacho polimórfico.
  - Técnicas: implementar métodos abstratos e escrever clientes dependentes da abstração.
  - Pré-requisito: classes, herança, composição e delegação.
- [ ] `@pagamento       type=self gain=1 hard=1 size=1` [[TRAIN] Pagamento: composição de métodos de pagamento](labs/pagamento/README.md)
  - Objetivo: aplicar polimorfismo por composição a métodos de pagamento.
  - Conceitos: contrato abstrato, delegação, composição e exceções de domínio.
  - Técnicas: injetar comportamento, processar coleções heterogêneas e isolar falhas.
  - Pré-requisito: classes abstratas, composição e exceções básicas.
- [ ] `@shapes          type=diff gain=2 hard=1 size=1` [[TRAIN] Shapes: interface e substituição geométrica](labs/shapes/README.md)
  - Objetivo: tratar formas geométricas por meio de uma interface comum.
  - Conceitos: interface, contrato, substituição e polimorfismo.
  - Técnicas: usar `Protocol`, manter coleção heterogênea e delegar cálculos às formas.
  - Pré-requisito: contratos, coleções e delegação.
- [ ] `@estacionamento  type=diff gain=3 hard=1 size=1` [Estacionamento — polimorfismo por tipo de veículo](labs/estacionamento/README.md)
  - Objetivo: variar o cálculo da tarifa sem espalhar condicionais na coordenação.
  - Conceitos: classe abstrata, método abstrato, composição e delegação polimórfica.
  - Técnicas: implementar tarifas substituíveis, proteger a coleção por operações do domínio e tratar falhas nomeadas.
  - Pré-requisito: polimorfismo, coleções e exceções básicas.
- [ ] `@cofre           type=diff gain=3 hard=1 size=1` [Cofre — polimorfismo por contrato de valor](labs/cofre/README.md)
  - Objetivo: modelar moedas e itens por um contrato comum em uma coleção heterogênea.
  - Conceitos: protocolo, polimorfismo, enum, imutabilidade e invariantes de estado.
  - Técnicas: filtrar e substituir a coleção, calcular agregados e nomear falhas de domínio.
  - Pré-requisito: contratos, enums, coleções e invariantes.
- [ ] `@cadastro        type=diff gain=3 hard=1 size=1` [Cadastro — contas com regras polimórficas](labs/cadastro/README.md)
  - Objetivo: aplicar regras mensais diferentes sem condicionar a coordenação pelo tipo da conta.
  - Conceitos: classe abstrata, herança, mapas, composição e delegação polimórfica.
  - Técnicas: manter invariantes de saldo, realizar transferência atômica e atualizar uma coleção heterogênea.
  - Pré-requisito: herança, mapas, polimorfismo e invariantes.



## TODO <!-- @todo lang=X -->

- [ ] `@twitter         type=diff gain=4 hard=2 size=2` [Twitter — colaboração entre usuários e timelines](labs/twitter/README.md)
  - Objetivo: coordenar relações entre usuários e distribuição de tweets sem centralizar todas as regras.
  - Conceitos: composição, delegação, relações bidirecionais, coleção compartilhada e estado derivado.
  - Técnicas: encapsular timeline, manter vínculos consistentes e tratar remoção e referências.
  - Pré-requisito: mapas, polimorfismo, coleções e relações bidirecionais.
- [ ] `@salario         type=diff gain=3 hard=2 size=1` [Salário — regras de cálculo polimórficas](labs/salario/README.md)
  - Objetivo: substituir regras de salário por categoria sem condicionais na folha.
  - Conceitos: abstração, herança, método abstrato, delegação e estado derivado.
  - Técnicas: encapsular políticas de cálculo, validar limites e dividir bônus dinamicamente.
  - Pré-requisito: polimorfismo, abstrações e cálculo de valores.
- [ ] `@mensagem        type=diff gain=2 hard=1 size=1` [Mensagem — inbox e leitura destrutiva](labs/mensagem/README.md)
  - Objetivo: separar cadastro, envio e leitura em um modelo pequeno e testável.
  - Conceitos: composição, coleção de objetos, imutabilidade e comando/consulta.
  - Técnicas: consumir uma fila de mensagens, validar identidades e manter o domínio sem impressão.
  - Pré-requisito: classes, coleções e encapsulamento básico.
- [ ] `@comunicador     type=diff gain=3 hard=2 size=1` [Comunicador — envio autorizado por composição](labs/comunicador/README.md)
  - Objetivo: acrescentar mensagens sem misturar inbox e autorização ao domínio hospitalar.
  - Conceitos: composição, delegação, encapsulamento e estado consumível.
  - Técnicas: restringir receivers, entregar mensagens e testar leitura destrutiva.
  - Pré-requisito: composição, autorização e filas de mensagens.
- [ ] `@paciente        type=diff gain=2 hard=1 size=1` [Paciente — vínculos bidirecionais no hospital](labs/paciente/README.md)
  - Objetivo: manter consistente o vínculo entre pacientes e médicos.
  - Conceitos: associação bidirecional, multiplicidade, identidade e invariantes.
  - Técnicas: validar especialidade antes de atualizar os dois lados.
  - Pré-requisito: associações bidirecionais, multiplicidade e invariantes.
- [ ] `@whatsapp        type=diff gain=3 hard=2 size=2` [WhatsApp — grupos e estado de leitura por participante](labs/whatsapp/README.md)
  - Objetivo: modelar mensagens não lidas de forma independente para cada membro de um grupo.
  - Conceitos: composição, multiplicidade, estado derivado e delegação.
  - Técnicas: controlar convites, participação, leitura destrutiva e notificações.
  - Pré-requisito: composição, coleções e leitura destrutiva.
- [ ] `@grupo           type=diff gain=3 hard=2 size=2` [Grupo — contrato comum para chats](labs/grupo/README.md)
  - Objetivo: tratar grupo e conversa individual por um contrato comum de chat.
  - Conceitos: classe abstrata, herança, especialização por comportamento e composição.
  - Técnicas: compartilhar envio/leitura, restringir capacidades e manter estado por participante.
  - Pré-requisito: classes abstratas, herança e polimorfismo.
- [ ] `@vetores         type=diff gain=1 hard=1 size=1` [Vetores — coleção linear e índices](labs/vetores/README.md)
  - Objetivo: preservar ordem e duplicatas em uma coleção linear.
  - Conceitos: sequência, índice, busca e mutação controlada.
  - Técnicas: inserir, alterar, localizar e tratar limites.
  - Pré-requisito: listas, índices e validação de limites.
- [ ] `@anotacoes       type=diff gain=2 hard=1 size=1` [Anotações — sessão e notas privadas](labs/anotacoes/README.md)
  - Objetivo: proteger notas por meio de uma sessão autenticada.
  - Conceitos: encapsulamento, estado de sessão, composição e imutabilidade.
  - Técnicas: validar credenciais, controlar acesso e associar notas ao usuário.
  - Pré-requisito: mapas, encapsulamento e validação de credenciais.
- [ ] `@trem            type=diff gain=1 hard=1 size=1` [Trem — composição e alocação de passageiros](labs/trem/README.md)
- [ ] `@produto         type=diff gain=1 hard=1 size=1` [Produto — Composite e Decorator](labs/produto/README.md)
- [ ] `@git_pratica     type=wiki gain=1 hard=1 size=1` [Git — fluxo de trabalho e recuperação](labs/git_pratica/README.md)
  - Objetivo: compreender commits, histórico, restauração e resolução de conflitos.
  - Conceitos: versionamento, integração e recuperação.
  - Técnicas: usar Git local e remoto e documentar decisões.
  - Pré-requisito: comandos básicos de Git e trabalho com repositórios.
- [ ] `@tarifas         type=diff gain=3 hard=2 size=1` [Operações de saque, depósito, extrato](labs/tarifas/README.md)
  - Objetivo: modelar um histórico financeiro que preserve operações e permita extorno seletivo.
  - Conceitos: encapsulamento, invariantes, comandos e consultas.
  - Técnicas: registrar eventos, validar saldo e operar por índices sem apagar histórico.
  - Pré-requisito: coleções, exceções e encapsulamento.

## labs <!-- @labs -->
