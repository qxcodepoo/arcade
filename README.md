---
args: [g, l, s]
expr: "(g * l * s)"
---

# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

## Material de referência <!-- @refs -->

- [ ] `eval=none            ` [[INTRO] Marcadores pedagógicos](wiki/pedagogic/README.md)
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
- [ ] `eval=self g=2 l=1 s=1` [[GUIDE] Toalha que enxuga](labs/toalha/README.md)
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Animal que morre](labs/animal/README.md)
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Enxugar: Toalha com testes](labs/enxugar/README.md)
- [ ] `eval=diff g=3 l=2 s=1` [[ALONE] Carro dirigível](labs/carro/README.md)
- [ ] `eval=diff g=3 l=2 s=2` [[CHECK] Calculadora à bateria](labs/calculadora/README.md)

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
- [ ] `eval=self g=1 l=1 s=1` [[GUIDE] Chinela de números pares](labs/chinela/README.md)
- [ ] `eval=self g=1 l=1 s=2` [[TRAIN] Camisa de tamanho fixo](labs/camisa/README.md)
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Roupa: camisa com testes](labs/roupa/README.md)
- [ ] `eval=diff g=3 l=2 s=2` [[ALONE] Hora 24h ou AM/PM](labs/relogio/README.md)

| Projetos                | chinela | camisa | roupa | relógio |
|-------------------------|---------|--------|-------|---------|
| validação de construtor | .       | SIM    | SIM   | SIM     |
| uso de arrays internos  | -       | SIM    | SIM   | .       |
| testes automáticos      | .       | SIM    | SIM   | SIM     |
| erros comunicados por   | bool    | bool   | bool  | bool    |
| esforço                 | mínima  | baixo  | baixo | médio   |


## Relações entre objetos: agregação e delegação <!-- @agreg -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Agregação e Delegação](wiki/agreg/README.md)
- [ ] `eval=diff g=3 l=2 s=3` [[GUIDE] Criança andando de Motoca](labs/motoca/README.md)
- [ ] `eval=diff g=3 l=3 s=3` [[TRAIN] Lapiseira de um Grafite](labs/grafite/README.md)
- [ ] `eval=diff g=3 l=4 s=3` [[ALONE] Passeando e pagando o MotoUber](labs/motouber/README.md)

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
- [ ] `eval=diff g=1 l=1 s=1` [[CHECK] Brinque até matar o Tamagotchi](labs/tamagotchi/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Notebook com bateria e carregador](labs/charger/README.md)

| Projetos                        | tamagotchi | charger   |
|---------------------------------|------------|-----------|
| agregação de componente externo | SIM        | SIM       |
| invariantes no componente       | SIM        | SIM       |
| coordenação de estados          | SIM        | SIM       |
| transição terminal              | SIM        | .         |
| testes automáticos              | SIM        | SIM       |
| erros comunicados por           | enum       | enum/null |
| esforço                         | médio-alto | alto      |


## Vetores e exceções <!-- @excecoes -->

- [ ] `eval=none            ` [[INTRO] Introdução Vetores e exceções](wiki/arrays/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [[GUIDE] Bermuda: exceções para invariantes de tamanho](labs/bermuda/README.md)
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Budega: fila e posições fixas](labs/budega/README.md)

| Projetos               | bermuda | budega |
|------------------------|---------|--------|
| vetor e índices        | .       | SIM    |
| tamanho fixo           | .       | SIM    |
| fila variável          | .       | SIM    |
| exceções               | SIM     | SIM    |
| estado preservado      | SIM     | SIM    |

## Manipulações em Listas <!-- @arrays -->

- Introdução
  - Objetivos de aprendizagem:
    - manipular listas ordenadas de objetos e mover os mesmos objetos entre coleções;
    - distinguir busca, remoção e transferência sem perder a ordem definida pelo domínio.
  - Conceitos:
    - `MutableList<T>`, ordem, busca e agregação de objetos com vida independente.
  - Técnicas de programação:
    - inserir, remover e localizar elementos;
    - devolver ou transferir o objeto removido sem recriá-lo.
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Coleção de pessoas](labs/array/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Pula-pula com crianças](labs/pula-pula/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[ALONE] Lapiseira com tambor de grafites](labs/lapiseira/README.md)

| Projetos                 | array | pula-pula | lapiseira |
|--------------------------|-------|-----------|-----------|
| agregação                | .     | SIM       | SIM       |
| busca ou filtro          | SIM   | SIM       | .         |
| ordem como regra         | SIM   | SIM       | SIM       |
| coleção encapsulada      | .     | SIM       | SIM       |
| movimento de objetos     | .     | SIM       | SIM       |
| testes automáticos       | SIM   | SIM       | SIM       |
| esforço                  | baixo | médio     | médio     |

## Listas e Composição <!-- @compdel -->

- Introdução
  - Objetivos de aprendizagem:
    - compor objetos que pertencem ao estado de outro objeto;
    - preservar invariantes ao alterar coleções de componentes.
  - Conceitos:
    - composição, ciclo de vida dos componentes e coleção encapsulada.
  - Técnicas de programação:
    - concentrar as alterações na classe proprietária;
    - validar operações antes de substituir ou remover componentes.
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Contato com telefones](labs/contato/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[ALONE] Junkfood: exceções e objeto vazio](labs/junkfood/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)

## Listas de nullable e agregação <!-- @slots -->

- [ ] `eval=none            ` [[INTRO] Introdução Listas nullable e agregação](wiki/slots/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md)
- [ ] `eval=diff g=3 l=2 s=1` [[TRAIN] Fusca: posições, exceções e direção](labs/fusca/README.md)

| Projetos              | cinema | fusca |
|-----------------------|--------|-------|
| capacidade fixa       | SIM    | SIM   |
| tipo de ausência      | null   | null  |
| agregação             | .      | SIM   |
| validação de índice   | SIM    | SIM   |
| testes automáticos    | SIM    | SIM   |
| esforço               | baixo  | médio |

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
- [ ] `eval=diff g=3 l=2 s=1` [Agenda: contatos por identidade em um mapa](labs/agenda/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Agiota: clientes identificados por codenome](labs/agiota/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [Meu Petshop](labs/petshop/README.md)



## Índices e Redundância <!-- @cache -->

Neste bloco, você aprenderá a manter diferentes formas de acesso aos mesmos objetos, preservando uma única fonte de verdade e a consistência entre as estruturas.


___
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Favoritos: índice secundário e consistência](labs/favoritos/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Ligação: composição para histórico e ranking](labs/ligacao/README.md)


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
- [ ] `eval=self g=1 l=1 s=1` [[ALONE] Zoo: contrato comum e comportamento polimórfico](labs/zoo/README.md)
- [ ] `eval=self g=1 l=1 s=1` [[TRAIN] Pagamento: composição de métodos de pagamento](labs/pagamento/README.md)
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Shapes: interface e substituição geométrica](labs/shapes/README.md)
- [ ] `eval=self g=3 l=1 s=1` [Estacionamento — polimorfismo por tipo de veículo](labs/estacionamento/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [Cofre — polimorfismo por contrato de valor](labs/cofre/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [Cadastro — contas com regras polimórficas](labs/cadastro/README.md)



## TODO <!-- @todo lang=X -->

- [ ] `eval=diff g=1 l=1 s=1` [Twitter — colaboração entre usuários e timelines](labs/twitter/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [Salário — regras de cálculo polimórficas](labs/salario/README.md)
- [ ] `eval=diff g=2 l=1 s=1` [Mensagem — inbox e leitura destrutiva](labs/mensagem/README.md)
- [ ] `eval=self g=1 l=1 s=1` [Comunicador — envio autorizado por composição](labs/comunicador/README.md)
- [ ] `eval=self g=2 l=1 s=1` [Paciente — vínculos bidirecionais no hospital](labs/paciente/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [WhatsApp — grupos e estado de leitura por participante](labs/whatsapp/README.md)
- [ ] `eval=self g=3 l=1 s=1` [Grupo — contrato comum para chats](labs/grupo/README.md)
- [ ] `eval=self g=1 l=1 s=1` [Vetores — coleção linear e índices](labs/vetores/README.md)
- [ ] `eval=self g=2 l=1 s=1` [Anotações — sessão e notas privadas](labs/anotacoes/README.md)
- [ ] `eval=self g=1 l=1 s=1` [Trem — composição e alocação de passageiros](labs/trem/README.md)
- [ ] `eval=self g=1 l=1 s=1` [Produto — Composite e Decorator](labs/produto/README.md)
- [ ] `eval=none g=1 l=1 s=1` [Git — fluxo de trabalho e recuperação](labs/git_pratica/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [Operações de saque, depósito, extrato](labs/tarifas/README.md)

## labs <!-- @labs -->
## wiki <!-- @wiki -->
