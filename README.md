# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

## Configuração de ambiente <!-- @env -->

- [ ] `@+git            gain=1 type=read eval=self              ` [Introdução ao git](wiki/git/README.md)
- [ ] `@+relacionamento gain=0 type=read eval=self              ` [Relacionamentos](wiki/relacionamento/README.md)
- [ ] `@+uml            gain=0 type=read eval=self              ` [Relacionamentos Resumo](wiki/uml/README.md)
- [ ] `@+relatorio      gain=0 type=read eval=self              ` [Como fazer os códigos e relatórios](wiki/relatorio/README.md)
- [ ] `@+atividade      gain=0 type=read eval=self              ` [Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [ ] `@+main           gain=0 type=read eval=self              ` [Criando a Main](wiki/main/README.md)

## Classes e Objetos <!-- @intro -->

- Conceitos abordados neste módulo:
  - classe, objeto, atributo e método;
  - estado e comportamento;
  - construtor;
  - identidade entre objetos;
  - testes do comportamento observável;
  - separação inicial entre domínio e Shell.
- Princípio citado somente quando útil: responsabilidade.

- [ ] `@toalha          gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Toalha, o item mais útil do universo](labs/toalha/README.md)
- [ ] `@animal          gain=1 hard=1 size=1 type=make eval=test` [[GUIA] Animal que nasce, cresce, morre](labs/animal/README.md)
- [ ] `@carro           gain=1 hard=1 size=1 type=make eval=test` [Um carro simples](labs/carro/README.md)
- [ ] `@enxugar         gain=1 hard=1 size=1 type=make eval=test` [Toalha com testes](labs/enxugar/README.md)
- [ ] `@calculadora     gain=1 hard=1 size=1 type=make eval=test` [Uma calculadora com bateria](labs/calculadora/README.md)

## Encapsulamento e Invariantes <!-- @access deps=@intro -->

- Conceitos abordados neste módulo:
  - atributos privados;
  - estado válido;
  - validação dentro da classe responsável;
  - operações que preservam invariantes;
  - falhas e estado após falhas;
  - diferença entre encapsular e criar getters/setters para tudo.
- Conceitos principais: encapsulamento, invariante e contrato.

- [ ] `@chinela         gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Comprando uma chinela 40/41](labs/chinela/README.md)
- [ ] `@camisa          gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Comprando uma camisa XG](labs/camisa/README.md)
- [ ] `@roupa           gain=1 hard=1 size=1 type=make eval=test` [Roupa com testes](labs/roupa/README.md)
- [ ] `@relogio         gain=1 hard=1 size=1 type=make eval=test` [Garante uma hora válida no relógio](labs/relogio/README.md)

## Relações entre objetos: agregação e delegação <!-- @agreg deps=@access -->

- Conceitos abordados neste módulo:
 - agregação;
 - posse e colaboração;
 - delegação;
 - multiplicidade;
 - ciclos de vida independentes.
- Conceitos principais: agregação, delegação e multiplicidade.

- [ ] `@motoca          gain=1 hard=1 size=1 type=make eval=test` [Motoca: agregação opcional simples](labs/motoca/README.md)
- [ ] `@grafite         gain=1 hard=1 size=1 type=make eval=test` [Grafite: agregação opcional + delegação](labs/grafite/README.md)
- [ ] `@motouber        gain=1 hard=1 size=1 type=make eval=test` [MotoUber: coordenação entre papéis + transferência de recurso + resultado composto.](labs/motouber/README.md)

## Aprofundamento <!-- @aprofundamento -->

- [ ] `@notebook        gain=1 hard=1 size=1 type=make eval=self` [Notebook: múltiplos componentes agregados + coordenação](labs/notebook/README.md)
- [ ] `@charger         gain=1 hard=1 size=1 type=make eval=test` [Charger: notebook com contrato testável](labs/charger/README.md)
- [ ] `@tamagotchi      gain=1 hard=1 size=1 type=make eval=test` [Tamagotchi: coordenação sobre um objeto de domínio com invariantes fortes e estado terminal](labs/tamagotchi/README.md)

## Coleções de objetos <!-- @arrays deps=@agreg -->

- Conceitos abordados neste módulo:
  - Array<T> ou lista de objetos;
  - multiplicidade 0..*;
  - adicionar, remover, buscar e percorrer;
  - ordem e posição;
  - encapsular a coleção;
  - evitar devolver uma coleção interna mutável;
  - separar operações sobre um item de operações sobre o conjunto.
- Conceitos principais: coleção, multiplicidade e coordenação.

- [ ] `@array           gain=3 hard=1 size=1 type=make eval=self` [Manipulações em Arrays](labs/array/README.md)
- [ ] `@budega          gain=2 hard=1 size=1 type=make eval=test` [Gerencie a fila de espera e atendimento](labs/budega/README.md)
- [ ] `@lapiseira       gain=1 hard=1 size=1 type=make eval=test` [Lapiseira com múltiplos grafites](labs/lapiseira/README.md)
- [ ] `@pula-pula       gain=1 hard=1 size=1 type=make eval=test` [Gerenciando entradas e saídas do pula pula](labs/pula-pula/README.md)
- [ ] `@cinema          gain=1 hard=1 size=1 type=make eval=test` [Gerenciando reservas e cancelamentos de uma sala de cinema](labs/cinema/README.md)
- [ ] `@tabuleiro       gain=1 hard=1 size=1 type=make eval=test` [Jogo de tabuleiro e armadilhas](labs/tabuleiro/README.md)
- [ ] `@junkfood        gain=1 hard=1 size=1 type=make eval=test` [Comprando comida cara e duvidosa](labs/junkfood/README.md)


## Mapas e Excessões <!-- @crud deps=@arrays -->

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

- [ ] `@contato         gain=1 hard=1 size=1 type=make eval=test` [Gerenciando telefones de um único contato](labs/contato/README.md)
- [ ] `@agenda          gain=1 hard=1 size=1 type=make eval=test` [Gerencie os vários contatos de uma agenda](labs/agenda/README.md)
- [ ] `@agiota          gain=1 hard=1 size=1 type=make eval=test` [Gerencie os empréstimos do agiota](labs/agiota/README.md)
- [ ] `@petshop         gain=1 hard=1 size=1 type=make eval=test` [Meu Petshop](labs/petshop/README.md)
- [ ] `@porquinho       gain=1 hard=1 size=1 type=make eval=test` [Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)

## Índices e Redundância <!-- @cache deps=@crud -->

Neste bloco, você aprenderá a manter diferentes formas de acesso aos mesmos objetos, preservando uma única fonte de verdade e a consistência entre as estruturas.

- [ ] `@favoritos       gain=1 hard=1 size=1 type=make eval=test` [Cache e redundância em @favoritos](labs/favoritos/README.md)
- [ ] `@ligacao         gain=1 hard=1 size=1 type=make eval=test` [@ligacao](labs/ligacao/README.md)

## Polimorfismo <!-- @polimorfismo deps=@crud -->

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

- [ ] `@zoo             gain=1 hard=1 size=1 type=make eval=self` [Sistema de Animais no Zoológico](labs/zoo/README.md)
- [ ] `@pagamento       gain=1 hard=1 size=1 type=make eval=self` [Sistema de Pagamentos de um Marketplace](labs/pagamento/README.md)
- [ ] `@shapes          gain=2 hard=1 size=1 type=make eval=test` [Utilizando interface em círculos e retângulos](labs/shapes/README.md)
- [ ] `@estacionamento  gain=3 hard=1 size=1 type=make eval=test` [Cobrando o valor de carros e motos](labs/estacionamento/README.md)
- [ ] `@cofre           gain=3 hard=1 size=1 type=make eval=test` [Seu porquinho cresceu](labs/cofre/README.md)
- [ ] `@cadastro        gain=3 hard=1 size=1 type=make eval=test` [Crie as contas poupança e corrente](labs/cadastro/README.md)


## TODO <!-- @todo lang=X -->

- [ ] `@twitter         gain=1 hard=1 size=1 type=make eval=test` [Twitter antes de ser bloqueado](labs/twitter/README.md)
- [ ] `@salario         gain=1 hard=1 size=1 type=make eval=test` [@salario](labs/salario/README.md)
- [ ] `@comunicador     gain=1 hard=1 size=1 type=make eval=test` [@comunicador](labs/comunicador/README.md)
- [ ] `@paciente        gain=1 hard=1 size=1 type=make eval=test` [@paciente](labs/paciente/README.md)
- [ ] `@whatsapp        gain=1 hard=1 size=1 type=make eval=test` [@whatsapp](labs/whatsapp/README.md)
- [ ] `@grupo           gain=1 hard=1 size=1 type=make eval=test` [@grupo](labs/grupo/README.md)
- [ ] `@mensagem        gain=1 hard=1 size=1 type=make eval=test` [@mensagem](labs/mensagem/README.md)
- [ ] `@vetores         gain=1 hard=1 size=1 type=make eval=test` [@vetores](labs/vetores/README.md)
- [ ] `@anotacoes       gain=1 hard=1 size=1 type=make eval=test` [Adicione título e texto em @anotacoes](labs/anotacoes/README.md)
- [ ] `@trem            gain=1 hard=1 size=1 type=make eval=test` [@trem](labs/trem/README.md)
- [ ] `@produto         gain=1 hard=1 size=1 type=make eval=test` [@produto - Padrão Composite e Decorator](labs/produto/README.md)
- [ ] `@git_pratica     gain=1 hard=1 size=1 type=make eval=test` [Prática git](labs/git_pratica/README.md)
- [ ] `@+ts_install     gain=1 type=read eval=self              ` [Instalação TS](wiki/ts_install/README.md)
- [ ] `@tarifas         gain=1 hard=1 size=1 type=make eval=test` [Operações de saque, depósito, extrato](labs/tarifas/README.md)

## labs <!-- @labs -->
- [ ] `@memoria         gain=1 hard=1 size=1 type=make eval=test` [Pesquisa sobre alocação de memória](labs/memoria/README.md)
