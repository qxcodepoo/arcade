# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

Marcadores pedagógicos

- GUIDE — leitura, referência ou exemplo guiado
- TRAIN — prática com consulta
- ALONE — tentativa independente
- CHECK — verificação do domínio


## Configuração de ambiente <!-- @env -->

- [ ] `@+git            type=wiki gain=1 hard=1 size=1` [[GUIDE] Introdução ao git](wiki/git/README.md)
- [ ] `@+relacionamento type=wiki gain=0 hard=1 size=1` [[GUIDE] Relacionamentos](wiki/relacionamento/README.md)
- [ ] `@+uml            type=wiki gain=0 hard=1 size=1` [[GUIDE] Relacionamentos Resumo](wiki/uml/README.md)
- [ ] `@+relatorio      type=wiki gain=0 hard=1 size=1` [[GUIDE] Como fazer os códigos e relatórios](wiki/relatorio/README.md)
- [ ] `@+atividade      type=wiki gain=0 hard=1 size=1` [[GUIDE] Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [ ] `@+main           type=wiki gain=0 hard=1 size=1` [[GUIDE] Criando a Main](wiki/main/README.md)

## Classes e Objetos <!-- @intro -->

- Conceitos abordados neste módulo:
  - classe, objeto, atributo e método;
  - estado e comportamento;
  - construtor e toString;
  - identidade entre objetos;
  - testes do comportamento observável no modelo que requisição e resposta.
  - separação inicial entre domínio (classe implementada) e interface (função que processa requisições).
- Princípio citado somente quando útil: responsabilidade.

---

- [ ] `@toalha          type=self gain=2 hard=1 size=1` [[GUIDE] Toalha: estado e comportamento em uma classe coesa](labs/toalha/README.md)
  - Objetivo: identificar estado e comportamento em uma classe coesa.
  - Conceitos: classe, objeto, atributo, método e responsabilidade.
  - Técnicas: nomear intenções, encapsular estado e testar comportamento observável.
  - Pré-requisitos e posição: atividade inicial do módulo; requer variáveis, funções e coleções básicas.

---

- [ ] `@animal          type=diff gain=2 hard=1 size=1` [[GUIDE] Animal: estado, comportamento e ciclo de vida](labs/animal/README.md)
  - Objetivo: modelar o ciclo de vida de um objeto por seu estado.
  - Conceitos: estado, comportamento, transição e condição válida.
  - Técnicas: proteger mudanças de estado e verificar sequências de operações.
  - Pré-requisitos e posição: depois de Toalha; introduz estado mutável controlado.

---

- [ ] `@enxugar         type=diff gain=2 hard=1 size=2` [[TRAIN] Enxugar: comportamento observável e interface](labs/enxugar/README.md)

---

- [ ] `@carro           type=diff gain=3 hard=2 size=2` [[ALONE] Carro: separação inicial entre domínio e interface](labs/carro/README.md)
  - Objetivo: separar a regra do carro da leitura e apresentação de comandos.
  - Conceitos: domínio, interface, comando e resultado observável.
  - Técnicas: manter a classe independente do Shell e testar sem entrada/saída.
  - Pré-requisitos e posição: depois de Animal e Enxugar; primeira separação entre domínio e interface.

---

- [ ] `@calculadora     type=diff gain=3 hard=2 size=2` [[CHECK] Calculadora: resultados de operação e mensagens na interface](labs/calculadora/README.md)
  - Objetivo: representar resultados de operações e suas falhas de forma explícita.
  - Conceitos: contrato, validação, resultado e mensagem observável.
  - Técnicas: decompor operações, tratar erros e testar sucesso e falha.
  - Pré-requisitos e posição: depois de Carro; consolida domínio e interface.

---

## Encapsulamento e Invariantes <!-- @access -->

- Conceitos abordados neste módulo:
  - atributos privados;
  - estado válido;
  - validação dentro da classe responsável;
  - operações que preservam invariantes;
  - falhas e estado após falhas;
  - diferença entre encapsular e criar getters/setters para tudo.
- Conceitos principais: encapsulamento, invariante e contrato.

---

- [ ] `@chinela         type=self gain=1 hard=1 size=1` [[GUIDE] Comprando uma chinela 40/41](labs/chinela/README.md)

  - Objetivo: preservar uma regra simples de compra dentro do objeto.
  - Conceitos: encapsulamento, invariante e operação válida.
  - Técnicas: validar no componente responsável e manter o estado após falha.
  - Pré-requisitos e posição: depois de Classes e Objetos; introduz invariantes.

---

- [ ] `@camisa          type=self gain=1 hard=1 size=1` [[TRAIN] Comprando uma camisa XG](labs/camisa/README.md)
  - Objetivo: preservar a invariante de tamanho válido em uma camisa.
  - Conceitos: encapsulamento, atributo privado, getter, setter e invariante.
  - Técnicas: validar antes de alterar, retornar cópias e preservar o estado após falha.
  - Pré-requisitos e posição: depois de Chinela; aprofunda validação e encapsulamento.

---

- [ ] `@roupa           type=diff gain=2 hard=1 size=1` [[TRAIN] Roupa: extensão testável de Camisa](labs/roupa/README.md)
  - Objetivo: tornar a regra de tamanho testável por uma interface separada.
  - Conceitos: domínio, Shell, separação de interesses, getter, setter e invariante.
  - Técnicas: isolar regras da entrada e saída e testar estado preservado após falha.
  - Pré-requisitos e posição: depois de Camisa; consolida encapsulamento e inicia a separação de interface.

---

- [ ] `@relogio         type=diff gain=3 hard=2 size=2` [[ALONE] Relógio: invariantes de tempo e atualização coordenada](labs/relogio/README.md)
  - Objetivo: proteger uma hora válida e atualizá-la de forma coordenada.
  - Conceitos: invariantes, setters validadores, transição de estado e representação.
  - Técnicas: validar campos independentemente, coordenar virada de minuto e separar estado de exibição.
  - Pré-requisitos e posição: depois de Roupa; prática independente de consolidação antes das coleções.

---

## Relações entre objetos: agregação e delegação <!-- @agreg -->

- Conceitos abordados neste módulo:
 - agregação;
 - posse e colaboração;
 - delegação;
 - multiplicidade;
- ciclos de vida independentes.
- Conceitos principais: agregação, delegação e multiplicidade.

---

- [ ] `@motoca          type=diff gain=3 hard=2 size=3` [[GUIDE] Motoca: agregação opcional e delegação](labs/motoca/README.md)
  - Objetivo: modelar uma agregação opcional entre uma motoca e uma pessoa.
  - Conceitos: agregação, posse, multiplicidade e delegação.
  - Técnicas: controlar referências opcionais, retornar objetos removidos e separar domínio do Shell.
  - Pré-requisitos e posição: depois de Encapsulamento; introduz colaboração entre objetos.

---

- [ ] `@grafite         type=diff gain=3 hard=3 size=3` [[TRAIN] Grafite: agregação opcional e delegação](labs/grafite/README.md)
  - Objetivo: delegar ao grafite as regras de desgaste durante a escrita.
  - Conceitos: agregação, delegação, responsabilidade e resultados de domínio.
  - Técnicas: dividir responsabilidades entre componentes e testar cada falha observável.
  - Pré-requisitos e posição: depois de Motoca; aprofunda colaboração com estado interno.

---

- [ ] `@motouber        type=diff gain=3 hard=3 size=3` [[ALONE] MotoUber: colaboração entre objetos e transferência de recurso](labs/motouber/README.md)
  - Objetivo: coordenar uma corrida entre pessoas sem transferir a posse de seus dados.
  - Conceitos: colaboração, agregação, delegação e transferência de recurso.
  - Técnicas: manter dinheiro em `Person`, coordenar pagamentos e representar resultados.
  - Pré-requisitos e posição: depois de Grafite; prática independente de colaboração entre objetos.

---

## Aprofundamento <!-- @aprofundamento -->

---

- [ ] `@charger         type=diff gain=3 hard=3 size=3` [[TRAIN] Charger: agregação e coordenação por etapas](labs/charger/README.md)
  - Objetivo: coordenar o uso de bateria e carregador em etapas incrementais.
  - Conceitos: agregação, coordenação, invariantes e ciclos de vida independentes.
  - Técnicas: delegar consumo e recarga, preservar capacidade e testar transições.
  - Pré-requisitos e posição: depois de Motoca, Grafite e MotoUber; aprofunda composição por etapas.

---

- [ ] `@tamagotchi      type=diff gain=3 hard=3 size=3` [[CHECK] Tamagotchi: coordenação, invariantes e estado terminal](labs/tamagotchi/README.md)
  - Objetivo: coordenar ações sobre um pet que pode alcançar um estado terminal.
  - Conceitos: composição, invariante, causa de morte e estado terminal.
  - Técnicas: delegar alterações ao pet e bloquear ações depois da morte.
  - Pré-requisitos e posição: depois de Charger; consolida coordenação e invariantes.

---

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

---

- [ ] `@+listas         type=wiki gain=1 hard=1 size=1` [[GUIDE] Listas em Python: ações mais comuns](wiki/listas/README.md)
  - Objetivo: consultar e manipular listas de forma idiomática em Python.
  - Conceitos: lista, índice, mutação, cópia, ordenação e filtragem.
  - Técnicas: percorrer, inserir, remover, buscar, filtrar e escolher entre cópia e alteração local.
  - Pré-requisitos e posição: referência inicial do bloco; requer laços, funções e coleções básicas.

---

- [ ] `@array           type=diff gain=2 hard=1 size=1` [[GUIDE] Array: manipulação direta de uma coleção de pessoas](labs/array/README.md)
  - Objetivo: aplicar diretamente as operações fundamentais em uma coleção linear.
  - Conceitos: lista de objetos, posição, extremidades, busca e filtro.
  - Técnicas: inserir, remover, percorrer, interromper buscas e preservar fronteiras.
  - Pré-requisitos e posição: depois de Listas; primeira atividade prática de coleções lineares.

---

- [ ] `@contato         type=diff gain=2 hard=1 size=2` [[TRAIN] Contato: encapsulamento de uma coleção de telefones](labs/contato/README.md)
  - Objetivo: encapsular uma coleção pertencente a um contato.
  - Conceitos: composição, coleção interna, validação e estado válido.
  - Técnicas: dividir responsabilidades, preservar invariantes e retornar cópias.
  - Pré-requisitos e posição: depois de Array; prepara a passagem de listas para objetos coesos.

---

- [ ] `@pula-pula       type=diff gain=1 hard=1 size=1` [[TRAIN] Pula-pula: filas e movimentação de crianças](labs/pula-pula/README.md)
  - Objetivo: modelar uma fila com entradas, saídas e movimentação.
  - Conceitos: ordem, posição, fila e operações sobre coleções.
  - Técnicas: atualizar estado em sequências e testar fronteiras da coleção.
  - Pré-requisitos e posição: depois de Contato; consolida listas antes de posições fixas.

---

- [ ] `@lapiseira       type=diff gain=1 hard=1 size=1` [[ALONE] Lapiseira: extensão do grafite com tambor](labs/lapiseira/README.md)
  - Objetivo: estender um objeto existente sem quebrar suas regras.
  - Conceitos: composição, delegação, capacidade e estado compartilhado.
  - Técnicas: reutilizar uma classe coesa e coordenar operações entre objetos.
  - Pré-requisitos e posição: depois de Grafite e das coleções lineares; prática independente.

---

## Posições fixas e ausência <!-- @slots -->

- Conceitos abordados neste módulo:
  - vetor de tamanho fixo;
  - índice como informação do domínio;
  - posição ocupada e posição vazia;
  - uso de `T | null` para representar ausência;
  - busca em vetor com posições vazias;
  - comparação entre ausência por `null` e objeto vazio.
- Conceitos principais: posição, ausência, nulidade e busca.

- [ ] `@cinema          type=diff gain=1 hard=1 size=1` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md)
  - Objetivo: representar posições fixas e lugares ainda vazios.
  - Conceitos: índice, capacidade, ausência e vetor de tamanho fixo.
  - Técnicas: validar limites, distinguir vazio de objeto e expor cópias.
  - Pré-requisitos e posição: depois das coleções lineares; primeira atividade de posições fixas.

---

- [ ] `@budega          type=diff gain=2 hard=1 size=1` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md)
  - Objetivo: combinar fila de espera com posições fixas de atendimento.
  - Conceitos: fila, índice, ocupação, remoção e movimentação.
  - Técnicas: coordenar coleções relacionadas e testar entrada no meio e desistência.
  - Pré-requisitos e posição: depois de Cinema; aprofunda posições e coordenação de coleções.

---

- [ ] `@junkfood        type=diff gain=1 hard=1 size=1` [[ALONE] Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md)
  - Objetivo: modelar uma máquina com compartimentos fixos e produto vazio.
  - Conceitos: ausência, objeto vazio, capacidade e invariantes.
  - Técnicas: encapsular posições, rejeitar operações inválidas e calcular receita.
  - Pré-requisitos e posição: depois de Budega; consolida posições fixas de forma independente.

---


## Desafio coleções <!-- @desafio-coleções -->

- [ ] `@tabuleiro       type=diff gain=1 hard=1 size=1` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)
  - Objetivo: coordenar coleções durante uma simulação de turnos.
  - Conceitos: composição, ordem de eventos, estado terminal e invariantes.
  - Técnicas: separar componentes coesos e testar sequências completas de interação.
  - Pré-requisitos e posição: depois de Cinema, Budega e Junkfood; desafio de consolidação.

---

## Mapas e Exceções <!-- @crud -->

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

- [ ] `@agenda          type=diff gain=3 hard=2 size=3` [Agenda: contatos por identidade em um mapa](labs/agenda/README.md)
  - Objetivo: localizar contatos pela identidade usando um mapa.
  - Conceitos: chave única, mapa, busca por identidade e fonte única de verdade.
  - Técnicas: encapsular dicionários, validar entradas e separar domínio do Shell.
  - Pré-requisitos e posição: depois das coleções lineares; introduz o bloco de mapas.

---

- [ ] `@agiota          type=diff gain=1 hard=1 size=1` [Gerencie os empréstimos do agiota](labs/agiota/README.md)
  - Objetivo: aplicar mapas e exceções a um histórico de operações.
  - Conceitos: mapa, exceção de domínio, histórico, invariante e ciclo de vida.
  - Técnicas: calcular estado derivado, tratar falhas e coordenar mudanças de estado.
  - Pré-requisitos e posição: depois de Agenda; próxima atividade do bloco após sua revisão.

---

- [ ] `@petshop         type=diff gain=1 hard=1 size=1` [Meu Petshop](labs/petshop/README.md)

---

- [ ] `@porquinho       type=diff gain=1 hard=1 size=1` [Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)

---

## Índices e Redundância <!-- @cache -->

Neste bloco, você aprenderá a manter diferentes formas de acesso aos mesmos objetos, preservando uma única fonte de verdade e a consistência entre as estruturas.

- [ ] `@favoritos       type=diff gain=1 hard=1 size=1` [[TRAIN] Favoritos: índice secundário e consistência](labs/favoritos/README.md)
  - Objetivo: criar uma forma secundária de acesso sem duplicar os contatos.
  - Conceitos: índice, conjunto, redundância intencional e consistência.
  - Técnicas: manter uma fonte de verdade e sincronizar estruturas relacionadas.
  - Pré-requisitos e posição: depois do bloco de Mapas e Exceções; prepara composição.

---

- [ ] `@ligacao         type=diff gain=1 hard=1 size=1` [[TRAIN] Ligação: composição para histórico e ranking](labs/ligacao/README.md)
  - Objetivo: adicionar histórico e ranking por composição.
  - Conceitos: composição, delegação, colaboração e ciclo de vida independente.
  - Técnicas: extrair responsabilidade, manter consistência entre objetos e testar progressivamente.
  - Pré-requisitos e posição: depois de Favoritos; encerra o bloco de índices e redundância.

---

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

- [ ] `@zoo             type=self gain=1 hard=1 size=1` [Sistema de Animais no Zoológico](labs/zoo/README.md)

---

- [ ] `@pagamento       type=self gain=1 hard=1 size=1` [Sistema de Pagamentos de um Marketplace](labs/pagamento/README.md)

---

- [ ] `@shapes          type=diff gain=2 hard=1 size=1` [Utilizando interface em círculos e retângulos](labs/shapes/README.md)

---

- [ ] `@estacionamento  type=diff gain=3 hard=1 size=1` [Cobrando o valor de carros e motos](labs/estacionamento/README.md)

---

- [ ] `@cofre           type=diff gain=3 hard=1 size=1` [Seu porquinho cresceu](labs/cofre/README.md)

---

- [ ] `@cadastro        type=diff gain=3 hard=1 size=1` [Crie as contas poupança e corrente](labs/cadastro/README.md)

---


## TODO <!-- @todo lang=X -->

- [ ] `@twitter         type=diff gain=1 hard=1 size=1` [Twitter antes de ser bloqueado](labs/twitter/README.md)

---

- [ ] `@salario         type=diff gain=1 hard=1 size=1` [@salario](labs/salario/README.md)

---

- [ ] `@comunicador     type=diff gain=1 hard=1 size=1` [@comunicador](labs/comunicador/README.md)

---

- [ ] `@paciente        type=diff gain=1 hard=1 size=1` [@paciente](labs/paciente/README.md)

---

- [ ] `@whatsapp        type=diff gain=1 hard=1 size=1` [@whatsapp](labs/whatsapp/README.md)

---

- [ ] `@grupo           type=diff gain=1 hard=1 size=1` [@grupo](labs/grupo/README.md)

---

- [ ] `@mensagem        type=diff gain=1 hard=1 size=1` [@mensagem](labs/mensagem/README.md)

---

- [ ] `@vetores         type=diff gain=1 hard=1 size=1` [@vetores](labs/vetores/README.md)

---

- [ ] `@anotacoes       type=diff gain=1 hard=1 size=1` [Adicione título e texto em @anotacoes](labs/anotacoes/README.md)

---

- [ ] `@trem            type=diff gain=1 hard=1 size=1` [@trem](labs/trem/README.md)

---

- [ ] `@produto         type=diff gain=1 hard=1 size=1` [@produto - Padrão Composite e Decorator](labs/produto/README.md)

---

- [ ] `@git_pratica     type=diff gain=1 hard=1 size=1` [Prática git](labs/git_pratica/README.md)

---

- [ ] `@+ts_install     type=wiki gain=1 hard=1 size=1` [Instalação TS](wiki/ts_install/README.md)

---

- [ ] `@tarifas         type=diff gain=1 hard=1 size=1` [Operações de saque, depósito, extrato](labs/tarifas/README.md)

---

## labs <!-- @labs -->
- [ ] `@memoria         type=diff gain=1 hard=1 size=1` [Pesquisa sobre alocação de memória](labs/memoria/README.md)
