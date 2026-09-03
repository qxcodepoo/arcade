# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

Marcadores pedagógicos

- GUIDE — leitura, referência ou exemplo guiado
- TRAIN — prática com consulta
- ALONE — tentativa independente
- CHECK — verificação do domínio

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
    - responsabilidade.
- [ ] `@toalha          type=self gain=2 hard=1 size=1` [[GUIDE] Toalha: estado e comportamento em uma classe coesa](labs/toalha/README.md)
  - Descrição: a toalha deve controlar seu estado de umidade e fornecer métodos para enxugar, torcer e consultar seu estado.
  - Domínio: o quanto a toalha enxuga depende do seu tamanho e ela não pode suportar água além de sua capacidade.
  - Objetivo: identificar estado e comportamento em uma classe coesa.
- [ ] `@animal          type=diff gain=2 hard=1 size=1` [[GUIDE] Animal: estado, comportamento e ciclo de vida](labs/animal/README.md)
  - Descrição: gerenciar um animal que nasce, cresce e morre. Faz barulho diferente conforme a espécie e o estado de vida.
  - Domínio: Envelhecer faz o animal morrer, impede ele de continuar envelhecendo e de fazer barulho após a morte.
  - Objetivo: modelar o ciclo de vida de um objeto por seu estado.
- [ ] `@enxugar         type=diff gain=2 hard=1 size=2` [[TRAIN] Enxugar: comportamento observável e interface](labs/enxugar/README.md)
  - Descrição: evolução da atividade da toalha, mas agora com a camada de testes de requisição e resposta.
  - Domínio: o mesmo da toalha.
  - Objetivo: manipular entrada e saída de forma separada do domínio, testando apenas o comportamento observável.
- [ ] `@carro           type=diff gain=3 hard=2 size=2` [[ALONE] Carro: separação inicial entre domínio e interface](labs/carro/README.md)
  - Descrição: o carro gerencia entrada, saída de pessoas, combustível e kilomentragem.
  - Domínio: o carro não pode controla o limite de pessoas e possui regras para que a ação de dirigir seja completada.
  - Objetivo: manipular erros como enumerações e treinar técnicas de `early return`.
- [ ] `@calculadora     type=diff gain=3 hard=2 size=2` [[CHECK] Calculadora: resultados de operação e mensagens na interface](labs/calculadora/README.md)
  - Descrição: a calculadora possui bateria, realiza operações matemáticas e as guarda no display.
  - Domínio: A calculadora não pode realizar operações sem bateria e nem dividir por zero.
  - Objetivo: manipular erros como enumerações e treinar técnicas de `early return`.

Projetos               | toalha | animal | enxugar | carro | calculadora
-----------------------|--------|--------|---------|-------|------------
ciclo de vida          | ❌      | ✅      | ❌       | ❌     | ❌
falhas como enumeração | ❌      | ❌      | ❌       | ✅     | ✅
testes automáticos     | ❌      | ❌      | ✅       | ✅     | ✅
early return           | ❌      | ❌      | ❌       | ✅     | ✅

---

## Encapsulamento e Invariantes <!-- @access -->

- Introdução
  - Habilidades trabalhadas:
    - atributos privados;
    - estado válido;
    - validação dentro da classe responsável;
    - operações que preservam invariantes;
    - falhas e estado após falhas;
    - diferença entre encapsular e criar getters/setters para tudo.
  - Conceitos principais: encapsulamento, invariante e contrato.
- [ ] `@chinela         type=self gain=1 hard=1 size=1` [[GUIDE] Comprando uma chinela 40/41](labs/chinela/README.md)
  - Objetivo: preservar uma regra simples de compra dentro do objeto.
  - Conceitos: encapsulamento, invariante e operação válida.
  - Técnicas: validar no componente responsável e manter o estado após falha.
  - Pré-requisito: classes, atributos e métodos básicos.
- [ ] `@camisa          type=self gain=1 hard=1 size=1` [[TRAIN] Comprando uma camisa XG](labs/camisa/README.md)
  - Objetivo: preservar a invariante de tamanho válido em uma camisa.
  - Conceitos: encapsulamento, atributo privado, getter, setter e invariante.
  - Técnicas: validar antes de alterar, retornar cópias e preservar o estado após falha.
  - Pré-requisito: classes, atributos privados e validação básica.
- [ ] `@roupa           type=diff gain=2 hard=1 size=1` [[TRAIN] Roupa: extensão testável de Camisa](labs/roupa/README.md)
  - Objetivo: tornar a regra de tamanho testável por uma interface separada.
  - Conceitos: domínio, Shell, separação de interesses, getter, setter e invariante.
  - Técnicas: isolar regras da entrada e saída e testar estado preservado após falha.
  - Pré-requisito: encapsulamento, validação e funções básicas.
- [ ] `@relogio         type=diff gain=3 hard=2 size=2` [[ALONE] Relógio: invariantes de tempo e atualização coordenada](labs/relogio/README.md)
  - Objetivo: proteger uma hora válida e atualizá-la de forma coordenada.
  - Conceitos: invariantes, setters validadores, transição de estado e representação.
  - Técnicas: validar campos independentemente, coordenar virada de minuto e separar estado de exibição.
  - Pré-requisito: encapsulamento, validação e condicionais.


## Relações entre objetos: agregação e delegação <!-- @agreg -->

- Conceitos abordados neste módulo:
  - agregação;
  - posse e colaboração;
  - delegação;
  - multiplicidade;
  - ciclos de vida independentes.
- Conceitos principais: agregação, delegação e multiplicidade.


___
- [ ] `@motoca          type=diff gain=3 hard=2 size=3` [[GUIDE] Motoca: agregação opcional e delegação](labs/motoca/README.md)
  - Objetivo: modelar uma agregação opcional entre uma motoca e uma pessoa.
  - Conceitos: agregação, posse, multiplicidade e delegação.
  - Técnicas: controlar referências opcionais, retornar objetos removidos e separar domínio do Shell.
  - Pré-requisito: classes, encapsulamento e referências opcionais.
- [ ] `@grafite         type=diff gain=3 hard=3 size=3` [[TRAIN] Grafite: agregação opcional e delegação](labs/grafite/README.md)
  - Objetivo: delegar ao grafite as regras de desgaste durante a escrita.
  - Conceitos: agregação, delegação, responsabilidade e resultados de domínio.
  - Técnicas: dividir responsabilidades entre componentes e testar cada falha observável.
  - Pré-requisito: agregação, delegação e encapsulamento.
- [ ] `@motouber        type=diff gain=3 hard=3 size=3` [[ALONE] MotoUber: colaboração entre objetos e transferência de recurso](labs/motouber/README.md)
  - Objetivo: coordenar uma corrida entre pessoas sem transferir a posse de seus dados.
  - Conceitos: colaboração, agregação, delegação e transferência de recurso.
  - Técnicas: manter dinheiro em `Person`, coordenar pagamentos e representar resultados.
  - Pré-requisito: objetos colaborativos, delegação e condicionais.


## Aprofundamento <!-- @aprofundamento -->


- [ ] `@charger         type=diff gain=3 hard=3 size=3` [[TRAIN] Charger: agregação e coordenação por etapas](labs/charger/README.md)
  - Objetivo: coordenar o uso de bateria e carregador em etapas incrementais.
  - Conceitos: agregação, coordenação, invariantes e ciclos de vida independentes.
  - Técnicas: delegar consumo e recarga, preservar capacidade e testar transições.
  - Pré-requisito: agregação, delegação e invariantes.
- [ ] `@tamagotchi      type=diff gain=3 hard=3 size=3` [[CHECK] Tamagotchi: coordenação, invariantes e estado terminal](labs/tamagotchi/README.md)
  - Objetivo: coordenar ações sobre um pet que pode alcançar um estado terminal.
  - Conceitos: composição, invariante, causa de morte e estado terminal.
  - Técnicas: delegar alterações ao pet e bloquear ações depois da morte.
  - Pré-requisito: composição, delegação e invariantes.


## Coleções lineares <!-- @arrays -->

- Conceitos abordados neste módulo:
  - Array<T> ou lista de objetos;
  - multiplicidade 0..*;
  - adicionar, remover, buscar e percorrer;
  - ordem de chegada e ordem de remoção;
  - fila e pilha como usos simples de uma lista;
  - encapsular a coleção;
  - evitar devolver uma coleção interna mutável;
  - separar operações sobre um item de operações sobre o conjunto.
- Conceitos principais: coleção, multiplicidade, busca e coordenação.


___
- [ ] `@+listas         type=wiki gain=1 hard=1 size=1` [[GUIDE] Listas em Python: ações mais comuns](wiki/listas/README.md)
  - Objetivo: consultar e manipular listas de forma idiomática em Python.
  - Conceitos: lista, índice, mutação, cópia, ordenação e filtragem.
  - Técnicas: percorrer, inserir, remover, buscar, filtrar e escolher entre cópia e alteração local.
  - Pré-requisito: laços, funções e coleções básicas.
- [ ] `@array           type=diff gain=2 hard=1 size=1` [[GUIDE] Array: manipulação direta de uma coleção de pessoas](labs/array/README.md)
  - Objetivo: aplicar diretamente as operações fundamentais em uma coleção linear.
  - Conceitos: lista de objetos, posição, extremidades, busca e filtro.
  - Técnicas: inserir, remover, percorrer, interromper buscas e preservar fronteiras.
  - Pré-requisito: listas, laços e condicionais.
- [ ] `@contato         type=diff gain=2 hard=1 size=2` [[TRAIN] Contato: encapsulamento de uma coleção de telefones](labs/contato/README.md)
  - Objetivo: encapsular uma coleção pertencente a um contato.
  - Conceitos: composição, coleção interna, validação e estado válido.
  - Técnicas: dividir responsabilidades, preservar invariantes e retornar cópias.
  - Pré-requisito: listas, classes e encapsulamento básico.
- [ ] `@pula-pula       type=diff gain=1 hard=1 size=1` [[TRAIN] Pula-pula: filas e movimentação de crianças](labs/pula-pula/README.md)
  - Objetivo: modelar uma fila com entradas, saídas e movimentação.
  - Conceitos: ordem, posição, fila e operações sobre coleções.
  - Técnicas: atualizar estado em sequências e testar fronteiras da coleção.
  - Pré-requisito: listas, filas e atualização de estado.
- [ ] `@lapiseira       type=diff gain=1 hard=1 size=1` [[ALONE] Lapiseira: extensão do grafite com tambor](labs/lapiseira/README.md)
  - Objetivo: estender um objeto existente sem quebrar suas regras.
  - Conceitos: composição, delegação, capacidade e estado compartilhado.
  - Técnicas: reutilizar uma classe coesa e coordenar operações entre objetos.
  - Pré-requisito: listas, composição e delegação.


## Posições fixas e ausência <!-- @slots -->

- Conceitos abordados neste módulo:
  - vetor de tamanho fixo;
  - índice como informação do domínio;
  - posição ocupada e posição vazia;
  - uso de `T | null` para representar ausência;
  - busca em vetor com posições vazias;
  - comparação entre ausência por `null` e objeto vazio.
- Conceitos principais: posição, ausência, nulidade e busca.

___
- [ ] `@cinema          type=diff gain=1 hard=1 size=1` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md)
  - Objetivo: representar posições fixas e lugares ainda vazios.
  - Conceitos: índice, capacidade, ausência e vetor de tamanho fixo.
  - Técnicas: validar limites, distinguir vazio de objeto e expor cópias.
  - Pré-requisito: listas, índices e validação de limites.
- [ ] `@budega          type=diff gain=2 hard=1 size=1` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md)
  - Objetivo: combinar fila de espera com posições fixas de atendimento.
  - Conceitos: fila, índice, ocupação, remoção e movimentação.
  - Técnicas: coordenar coleções relacionadas e testar entrada no meio e desistência.
  - Pré-requisito: filas, índices e coleções de tamanho fixo.
- [ ] `@junkfood        type=diff gain=1 hard=1 size=1` [[ALONE] Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md)
  - Objetivo: modelar uma máquina com compartimentos fixos e produto vazio.
  - Conceitos: ausência, objeto vazio, capacidade e invariantes.
  - Técnicas: encapsular posições, rejeitar operações inválidas e calcular receita.
  - Pré-requisito: vetores de tamanho fixo, ausência e invariantes.



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
