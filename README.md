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

- [ ] `@toalha          gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Toalha: estado e comportamento em uma classe coesa](labs/toalha/README.md)
- [ ] `@animal          gain=1 hard=1 size=1 type=make eval=test` [[GUIA] Animal: estado, comportamento e ciclo de vida](labs/animal/README.md)
- [ ] `@carro           gain=1 hard=1 size=1 type=make eval=test` [Carro: separação inicial entre domínio e Shell](labs/carro/README.md)
- [ ] `@enxugar         gain=1 hard=1 size=1 type=make eval=test` [Enxugar: comportamento observável e Shell](labs/enxugar/README.md)
- [ ] `@calculadora     gain=1 hard=1 size=1 type=make eval=test` [Calculadora: resultados de operação e mensagens no Shell](labs/calculadora/README.md)

## Encapsulamento e Invariantes <!-- @access deps=@intro -->

- Conceitos abordados neste módulo:
  - atributos privados;
  - estado válido;
  - validação dentro da classe responsável;
  - operações que preservam invariantes;
  - falhas e estado após falhas;
  - diferença entre encapsular e criar getters/setters para tudo.
- Conceitos principais: encapsulamento, invariante e contrato.

- [ ] `@chinela         gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Chinela: setter validador e invariante numérica](labs/chinela/README.md)
- [ ] `@camisa          gain=1 hard=1 size=1 type=make eval=self` [[GUIA] Camisa: setter validador e conjunto permitido](labs/camisa/README.md)
- [ ] `@roupa           gain=1 hard=1 size=1 type=make eval=test` [Roupa: extensão testável de Camisa](labs/roupa/README.md)
- [ ] `@relogio         gain=1 hard=1 size=1 type=make eval=test` [Relógio: invariantes de tempo e atualização coordenada](labs/relogio/README.md)

## Relações entre objetos: agregação e delegação <!-- @agreg deps=@access -->

- Conceitos abordados neste módulo:
 - agregação;
 - posse e colaboração;
 - delegação;
 - multiplicidade;
 - ciclos de vida independentes.
- Conceitos principais: agregação, delegação e multiplicidade.

- [ ] `@motoca          gain=1 hard=1 size=1 type=make eval=test` [Motoca: agregação opcional simples](labs/motoca/README.md)
- [ ] `@grafite         gain=1 hard=1 size=1 type=make eval=test` [Grafite: agregação opcional e delegação](labs/grafite/README.md)
- [ ] `@motouber        gain=1 hard=1 size=1 type=make eval=test` [MotoUber: colaboração entre objetos e transferência de recurso](labs/motouber/README.md)

## Aprofundamento <!-- @aprofundamento -->

- [ ] `@notebook        gain=1 hard=1 size=1 type=make eval=self` [Notebook: agregação de componentes e coordenação](labs/notebook/README.md)
- [ ] `@charger         gain=1 hard=1 size=1 type=make eval=test` [Charger: agregação com contrato testável](labs/charger/README.md)
- [ ] `@tamagotchi      gain=1 hard=1 size=1 type=make eval=test` [Tamagotchi: coordenação, invariantes e estado terminal](labs/tamagotchi/README.md)

## Coleções lineares <!-- @arrays deps=@agreg -->

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

- [ ] `@array           gain=3 hard=1 size=1 type=make eval=self` [Operações fundamentais com coleções lineares](labs/array/README.md)
- [ ] `@contato         gain=1 hard=1 size=1 type=make eval=test` [Contato: coleção de telefones e validação](labs/contato/README.md)
- [ ] `@pula-pula       gain=1 hard=1 size=1 type=make eval=test` [Pula-pula: filas e movimentação de crianças](labs/pula-pula/README.md)
- [ ] `@lapiseira       gain=1 hard=1 size=1 type=make eval=test` [Lapiseira: extensão do grafite com tambor](labs/lapiseira/README.md)

## Posições fixas e ausência <!-- @slots deps=@arrays -->

- Conceitos abordados neste módulo:
  - vetor de tamanho fixo;
  - índice como informação do domínio;
  - posição ocupada e posição vazia;
  - uso de `T | null` para representar ausência;
  - busca em vetor com posições vazias;
  - comparação entre ausência por `null` e objeto vazio.
- Conceitos principais: posição, ausência, nulidade e busca.

- [ ] `@cinema          gain=1 hard=1 size=1 type=make eval=test` [Cinema: posições fixas e ausência](labs/cinema/README.md)
- [ ] `@budega          gain=2 hard=1 size=1 type=make eval=test` [Budega: fila e posições fixas](labs/budega/README.md)
- [ ] `@junkfood        gain=1 hard=1 size=1 type=make eval=test` [Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md)


## Desafio coleções <!-- @desafio-coleções -->

- [ ] `@tabuleiro       gain=1 hard=1 size=1 type=make eval=test` [Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)

## Mapas e Exceções <!-- @crud deps=@slots -->

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
