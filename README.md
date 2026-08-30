# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros. Descrição do marcadores[LINK](https://github.com/senapk/tko/blob/master/wiki/Marcadores-e-Tipos.md)

## Configuração de ambiente <!-- @env -->

- [ ] `@+git            gain=1 type=read eval=self              ` [Introdução ao git](wiki/git/README.md)
- [ ] `@+relacionamento gain=0 type=read eval=self              ` [Relacionamentos](wiki/relacionamento/README.md)
- [ ] `@+uml            gain=0 type=read eval=self              ` [Relacionamentos Resumo](wiki/uml/README.md)
- [ ] `@+relatorio      gain=0 type=read eval=self              ` [Como fazer os códigos e relatórios](wiki/relatorio/README.md)
- [ ] `@+atividade      gain=0 type=read eval=self              ` [Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [ ] `@+main           gain=0 type=read eval=self              ` [Criando a Main](wiki/main/README.md)

## Primeiras Classes <!-- @intro -->

- [ ] `@toalha          gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Toalha, o item mais útil do universo](labs/toalha/README.md)
- [ ] `@animal          gain=1 hard=1 size=1 type=make eval=test` [[GUIA] Animal que nasce, cresce, morre](labs/animal/README.md)
- [ ] `@carro           gain=1 hard=1 size=1 type=make eval=test` [Um carro simples](labs/carro/README.md)
- [ ] `@enxugar         gain=1 hard=1 size=1 type=make eval=test` [Toalha com testes](labs/enxugar/README.md)
- [ ] `@calculadora     gain=1 hard=1 size=1 type=make eval=test` [Uma calculadora com bateria](labs/calculadora/README.md)

## Modificadores de Acesso <!-- @access deps=@intro -->

- [ ] `@chinela         gain=1 hard=1 size=1 type=make eval=self` [Comprando uma chinela 40/41](labs/chinela/README.md)
- [ ] `@camisa          gain=1 hard=1 size=1 type=make eval=self` [Comprando uma camisa XG](labs/camisa/README.md)
- [ ] `@roupa           gain=1 hard=1 size=1 type=make eval=test` [Roupa com testes](labs/roupa/README.md)
- [ ] `@relogio         gain=1 hard=1 size=1 type=make eval=test` [Garante uma hora válida no relógio](labs/relogio/README.md)

## Agregação Simples <!-- @agreg deps=@access -->

- [ ] `@motoca          gain=1 hard=1 size=1 type=make eval=test` [Crianças andando de motoca](labs/motoca/README.md)
- [ ] `@grafite         gain=1 hard=1 size=1 type=make eval=test` [Porta minas de um grafite só](labs/grafite/README.md)
- [ ] `@motouber        gain=1 hard=1 size=1 type=make eval=test` [MotoUber com motorista e passageiro](labs/motouber/README.md)
- [ ] `@notebook        gain=1 hard=1 size=1 type=make eval=self` [Notebook com carregador e bateria](labs/notebook/README.md)
- [ ] `@charger         gain=1 hard=1 size=1 type=make eval=test` [Notebook com TESTES](labs/charger/README.md)
- [ ] `@tamagotchi      gain=1 hard=1 size=1 type=make eval=test` [Alimente, brinque e mate](labs/tamagotchi/README.md)

## Listas e Arrays <!-- @arrays deps=@agreg -->

- [ ] `@array           gain=3 hard=1 size=1 type=make eval=self` [Manipulações em Arrays](labs/array/README.md)
- [ ] `@budega          gain=2 hard=1 size=1 type=make eval=test` [Gerencie a fila de espera e atendimento](labs/budega/README.md)
- [ ] `@lapiseira       gain=1 hard=1 size=1 type=make eval=test` [Lapiseira com múltiplos grafites](labs/lapiseira/README.md)
- [ ] `@pula-pula       gain=1 hard=1 size=1 type=make eval=test` [Gerenciando entradas e saídas do pula pula](labs/pula-pula/README.md)
- [ ] `@cinema          gain=1 hard=1 size=1 type=make eval=test` [Gerenciando reservas e cancelamentos de uma sala de cinema](labs/cinema/README.md)
- [ ] `@tabuleiro       gain=1 hard=1 size=1 type=make eval=test` [Jogo de tabuleiro e armadilhas](labs/tabuleiro/README.md)
- [ ] `@junkfood        gain=1 hard=1 size=1 type=make eval=test` [Comprando comida cara e duvidosa](labs/junkfood/README.md)

## CRUD com mapas e enumerações <!-- @crud deps=@arrays -->

- [ ] `@contato         gain=1 hard=1 size=1 type=make eval=test` [Gerenciando telefones de um único contato](labs/contato/README.md)
- [ ] `@agenda          gain=1 hard=1 size=1 type=make eval=test` [Gerencie os vários contatos de uma agenda](labs/agenda/README.md)
- [ ] `@agiota          gain=1 hard=1 size=1 type=make eval=test` [Gerencie os empréstimos do agiota](labs/agiota/README.md)
- [ ] `@petshop         gain=1 hard=1 size=1 type=make eval=test` [Meu Petshop](labs/petshop/README.md)
- [ ] `@porquinho       gain=1 hard=1 size=1 type=make eval=test` [Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)

## Herança I <!-- @polimorfismo deps=@crud -->

- [ ] `@zoo             gain=1 hard=1 size=1 type=make eval=self` [Sistema de Animais no Zoológico](labs/zoo/README.md)
- [ ] `@pagamento       gain=1 hard=1 size=1 type=make eval=self` [Sistema de Pagamentos de um Marketplace](labs/pagamento/README.md)
- [ ] `@shapes          gain=2 hard=1 size=1 type=make eval=test` [Utilizando interface em círculos e retângulos](labs/shapes/README.md)
- [ ] `@estacionamento  gain=3 hard=1 size=1 type=make eval=test` [Cobrando o valor de carros e motos](labs/estacionamento/README.md)
- [ ] `@cofre           gain=3 hard=1 size=1 type=make eval=test` [Seu porquinho cresceu](labs/cofre/README.md)
- [ ] `@cadastro        gain=3 hard=1 size=1 type=make eval=test` [Crie as contas poupança e corrente](labs/cadastro/README.md)

## CPP <!-- @cpp_intro lang=cpp lang=c -->

- [ ] `@cpp             gain=1 type=read eval=self              ` [Pesquisa sobre C++](wiki/cpp/README.md)
- [ ] `@memoria         gain=1 hard=1 size=1 type=make eval=self` [Pesquisa sobre alocação de memória](labs/memoria/README.md)

## TODO <!-- @todo lang=X -->

- [ ] `@twitter         gain=1 hard=1 size=1 type=make eval=test` [Twitter antes de ser bloqueado](labs/twitter/README.md)
- [ ] `@salario         gain=1 hard=1 size=1 type=make eval=test` [@salario](labs/salario/README.md)
- [ ] `@comunicador     gain=1 hard=1 size=1 type=make eval=test` [@comunicador](labs/comunicador/README.md)
- [ ] `@paciente        gain=1 hard=1 size=1 type=make eval=test` [@paciente](labs/paciente/README.md)
- [ ] `@whatsapp        gain=1 hard=1 size=1 type=make eval=test` [@whatsapp](labs/whatsapp/README.md)
- [ ] `@grupo           gain=1 hard=1 size=1 type=make eval=test` [@grupo](labs/grupo/README.md)
- [ ] `@mensagem        gain=1 hard=1 size=1 type=make eval=test` [@mensagem](labs/mensagem/README.md)
- [ ] `@vetores         gain=1 hard=1 size=1 type=make eval=test` [@vetores](labs/vetores/README.md)
- [ ] `@ligacao         gain=1 hard=1 size=1 type=make eval=test` [@ligacao](labs/ligacao/README.md)
- [ ] `@anotacoes       gain=1 hard=1 size=1 type=make eval=test` [Adicione título e texto em @anotacoes](labs/anotacoes/README.md)
- [ ] `@favoritos       gain=1 hard=1 size=1 type=make eval=test` [Cache e redundância em @favoritos](labs/favoritos/README.md)
- [ ] `@trem            gain=1 hard=1 size=1 type=make eval=test` [@trem](labs/trem/README.md)
- [ ] `@produto         gain=1 hard=1 size=1 type=make eval=test` [@produto - Padrão Composite e Decorator](labs/produto/README.md)
- [ ] `@git_pratica     gain=1 hard=1 size=1 type=make eval=test` [Prática git](labs/git_pratica/README.md)
- [ ] `@+ts_install     gain=1 type=read eval=self              ` [Instalação TS](wiki/ts_install/README.md)
- [ ] `@tarifas         gain=1 hard=1 size=1 type=make eval=test` [Operações de saque, depósito, extrato](labs/tarifas/README.md)

## labs <!-- @labs -->
