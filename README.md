# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

Marcadores pedagógicos

- GUIDE — leitura, referência ou exemplo guiado
- TRAIN — prática com consulta
- ALONE — tentativa independente
- CHECK — verificação do domínio


## Configuração de ambiente <!-- @env -->

- [ ] `@+git            gain=1 type=read eval=self              ` [[GUIDE] Introdução ao git](wiki/git/README.md)
- [ ] `@+relacionamento gain=0 type=read eval=self              ` [[GUIDE] Relacionamentos](wiki/relacionamento/README.md)
- [ ] `@+uml            gain=0 type=read eval=self              ` [[GUIDE] Relacionamentos Resumo](wiki/uml/README.md)
- [ ] `@+relatorio      gain=0 type=read eval=self              ` [[GUIDE] Como fazer os códigos e relatórios](wiki/relatorio/README.md)
- [ ] `@+atividade      gain=0 type=read eval=self              ` [[GUIDE] Padrão para atividades de código](wiki/atividade_codigo/README.md)
- [ ] `@+main           gain=0 type=read eval=self              ` [[GUIDE] Criando a Main](wiki/main/README.md)

## Classes e Objetos <!-- @intro -->

- Conceitos abordados neste módulo:
  - classe, objeto, atributo e método;
  - estado e comportamento;
  - construtor e toString;
  - identidade entre objetos;
  - testes do comportamento observável no modelo que requisição e resposta.
  - separação inicial entre domínio (classe implementada) e interface (função que processa requisições).
- Princípio citado somente quando útil: responsabilidade.

- [ ] `@toalha          gain=2 hard=1 size=1 type=make eval=self` [[GUIDE] Toalha: estado e comportamento em uma classe coesa](labs/toalha/README.md)
- [ ] `@animal          gain=2 hard=1 size=1 type=make eval=test` [[GUIDE] Animal: estado, comportamento e ciclo de vida](labs/animal/README.md)
- [ ] `@enxugar         gain=2 hard=1 size=2 type=make eval=test` [[TRAIN] Enxugar: comportamento observável e interface](labs/enxugar/README.md)
- [ ] `@carro           gain=3 hard=2 size=2 type=make eval=test` [[ALONE] Carro: separação inicial entre domínio e interface](labs/carro/README.md)
- [ ] `@calculadora     gain=3 hard=2 size=2 type=make eval=test` [[CHECK] Calculadora: resultados de operação e mensagens na interface](labs/calculadora/README.md)

## Encapsulamento e Invariantes <!-- @access deps=@intro -->

- Conceitos abordados neste módulo:
  - atributos privados;
  - estado válido;
  - validação dentro da classe responsável;
  - operações que preservam invariantes;
  - falhas e estado após falhas;
  - diferença entre encapsular e criar getters/setters para tudo.
- Conceitos principais: encapsulamento, invariante e contrato.

- [ ] `@chinela         gain=1 hard=1 size=1 type=make eval=self` [[GUIDE] Comprando uma chinela 40/41](labs/chinela/README.md)
- [ ] `@camisa          gain=1 hard=1 size=1 type=make eval=self` [[TRAIN] Comprando uma camisa XG](labs/camisa/README.md)
- [ ] `@roupa           gain=2 hard=1 size=1 type=make eval=test` [[TRAIN] Roupa: extensão testável de Camisa](labs/roupa/README.md)
- [ ] `@relogio         gain=3 hard=2 size=2 type=make eval=test` [[ALONE] Relógio: invariantes de tempo e atualização coordenada](labs/relogio/README.md)

## Relações entre objetos: agregação e delegação <!-- @agreg deps=@access -->

- Conceitos abordados neste módulo:
 - agregação;
 - posse e colaboração;
 - delegação;
 - multiplicidade;
 - ciclos de vida independentes.
- Conceitos principais: agregação, delegação e multiplicidade.

- [ ] `@motoca          gain=3 hard=2 size=3 type=make eval=test` [[GUIDE] Motoca: agregação opcional e delegação](labs/motoca/README.md)
- [ ] `@grafite         gain=3 hard=3 size=3 type=make eval=test` [[TRAIN] Grafite: agregação opcional e delegação](labs/grafite/README.md)
- [ ] `@motouber        gain=3 hard=3 size=3 type=make eval=test` [[ALONE] MotoUber: colaboração entre objetos e transferência de recurso](labs/motouber/README.md)

## Aprofundamento <!-- @aprofundamento -->

- [ ] `@charger         gain=3 hard=3 size=3 type=make eval=test` [[TRAIN] Charger: agregação e coordenação por etapas](labs/charger/README.md)
- [ ] `@tamagotchi      gain=3 hard=3 size=3 type=make eval=test` [[CHECK] Tamagotchi: coordenação, invariantes e estado terminal](labs/tamagotchi/README.md)

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

- [ ] `@+listas         gain=1 type=read eval=self              ` [[GUIDE] Listas em Python: ações mais comuns](wiki/listas/README.md)
- [ ] `@array           gain=2 hard=1 size=1 type=make eval=test` [[GUIDE] Array: manipulação direta de uma coleção de pessoas](labs/array/README.md)
- [ ] `@contato         gain=2 hard=1 size=2 type=make eval=test` [[TRAIN] Contato: encapsulamento de uma coleção de telefones](labs/contato/README.md)
- [ ] `@pula-pula       gain=1 hard=1 size=1 type=make eval=test` [[TRAIN] Pula-pula: filas e movimentação de crianças](labs/pula-pula/README.md)
- [ ] `@lapiseira       gain=1 hard=1 size=1 type=make eval=test` [[ALONE] Lapiseira: extensão do grafite com tambor](labs/lapiseira/README.md)

## Posições fixas e ausência <!-- @slots deps=@arrays -->

- Conceitos abordados neste módulo:
  - vetor de tamanho fixo;
  - índice como informação do domínio;
  - posição ocupada e posição vazia;
  - uso de `T | null` para representar ausência;
  - busca em vetor com posições vazias;
  - comparação entre ausência por `null` e objeto vazio.
- Conceitos principais: posição, ausência, nulidade e busca.

- [ ] `@cinema          gain=1 hard=1 size=1 type=make eval=test` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md)
- [ ] `@budega          gain=2 hard=1 size=1 type=make eval=test` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md)
- [ ] `@junkfood        gain=1 hard=1 size=1 type=make eval=test` [[ALONE] Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md)


## Desafio coleções <!-- @desafio-coleções -->

- [ ] `@tabuleiro       gain=1 hard=1 size=1 type=make eval=test` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)

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

- [ ] `@agenda          gain=3 hard=2 size=3 type=make eval=test` [Agenda: contatos por identidade em um mapa](labs/agenda/README.md)
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
