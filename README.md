---
args = [g, d, s]
expr = "(g * d * s)"
---
# Repositório de POO

Este repositório é uma coleção de exercícios e projetos relacionados à Programação Orientada a Objetos (POO). Ele é organizado em diferentes seções, cada uma focada em um aspecto específico da POO, como classes, objetos, herança, polimorfismo, entre outros.

## Marcadores pedagógicos <!-- @marcadores-pedagógicos -->

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

## Material de referência <!-- @refs -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Competências trabalhadas](wiki/competencias/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Trabalhos futuros](wiki/trabalhos_futuros/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução ao git](wiki/git/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Relacionamentos](wiki/relacionamento/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Relacionamentos Resumo](wiki/uml/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Como fazer os códigos e relatórios](wiki/relatorio/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Padrão para atividades de código](wiki/atividade_codigo/README.md) <!-- DONE -->
- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Criando a Main](wiki/main/README.md) <!-- DONE -->

## Classes e Objetos <!-- @intro -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Classes e Objetos](wiki/intro/README.md) <!-- DONE -->
- [ ] `eval=self g=2 l=1 s=1` [[GUIDE] Toalha que enxuga](labs/toalha/README.md) <!-- DONE -->
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Animal que morre](labs/animal/README.md) <!-- DONE -->
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Enxugar: Toalha com testes](labs/enxugar/README.md) <!-- DONE -->
- [ ] `eval=diff g=3 l=2 s=1` [[ALONE] Carro dirigível](labs/carro/README.md) <!-- DONE -->
- [ ] `eval=diff g=3 l=2 s=2` [[CHECK] Calculadora à bateria](labs/calculadora/README.md) <!-- DONE -->

| Projetos              | toalha | animal | enxugar | carro | calculadora |
|-----------------------|--------|--------|---------|-------|-------------|
| ciclo de vida         | .      | SIM    | .       | .     | .           |
| early return          | .      | .      | .       | SIM   | SIM         |
| testes automáticos    | .      | .      | SIM     | SIM   | SIM         |
| erros comunicados via | bool   | bool   | bool    | enum  | enum        |
| esforço               | mínima | baixo  | baixo   | médio | médio       |

---

## Encapsulamento e Invariantes <!-- @access -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Encapsulamento e Invariantes](wiki/access/README.md) <!-- DONE -->
- [ ] `eval=self g=1 l=1 s=1` [[GUIDE] Chinela de números pares](labs/chinela/README.md) <!-- DONE -->
- [ ] `eval=self g=1 l=1 s=2` [[TRAIN] Camisa de tamanho fixo](labs/camisa/README.md) <!-- DONE -->
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Roupa: camisa com testes](labs/roupa/README.md) <!-- DONE -->
- [ ] `eval=diff g=3 l=2 s=2` [[ALONE] Hora 24h ou AM/PM](labs/relogio/README.md) <!-- DONE -->

| Projetos                | chinela | camisa | roupa | relógio |
|-------------------------|---------|--------|-------|---------|
| validação de construtor | .       | SIM    | SIM   | SIM     |
| uso de arrays internos  | -       | SIM    | SIM   | .       |
| testes automáticos      | .       | SIM    | SIM   | SIM     |
| erros comunicados por   | bool    | bool   | bool  | bool    |
| esforço                 | mínima  | baixo  | baixo | médio   |


## Relações entre objetos: agregação e delegação <!-- @agreg -->

- [ ] `eval=none g=1 l=1 s=1` [[INTRO] Introdução Agregação e Delegação](wiki/agreg/README.md) <!-- DONE -->
- [ ] `eval=diff g=3 l=2 s=3` [[GUIDE] Criança andando de Motoca](labs/motoca/README.md) <!-- DONE -->
- [ ] `eval=diff g=3 l=3 s=3` [[TRAIN] Lapiseira de um Grafite](labs/grafite/README.md) <!-- DONE -->
- [ ] `eval=diff g=3 l=4 s=3` [[ALONE] Passeando e pagando o MotoUber](labs/motouber/README.md) <!-- DONE -->

| Projetos                  | motoca    | grafite   | motouber   |
|---------------------------|-----------|-----------|------------|
| agregação nullable        | SIM       | SIM       | SIM        |
| objeto removido devolvido | SIM       | SIM       | SIM        |
| regra delegada            | SIM       | SIM       | SIM        |
| testes automáticos        | SIM       | SIM       | SIM        |
| erros comunicados por     | enum/null | enum/null | enum/null  |
| esforço                   | baixo     | médio     | médio-alto |


## Desafios de agregação e estados <!-- @agchal -->

- [ ] `eval=none            ` [[INTRO] Desafios de agregação e estados](wiki/agcha/README.md) <!-- DONE -->
- [ ] `eval=diff g=1 l=1 s=1` [[CHECK] Brinque até matar o Tamagotchi](labs/tamagotchi/README.md) <!-- DONE -->
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Notebook com bateria e carregador](labs/charger/README.md) <!-- DONE -->

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
- [ ] `eval=none            ` [[GUIDE] Listas em Python](wiki/listas/README.md) <!-- DONE -->
- [ ] `eval=diff g=2 l=1 s=1` [[GUIDE] Coleção de pessoas](labs/array/README.md) <!-- DONE -->
- [ ] `eval=diff g=2 l=1 s=2` [[TRAIN] Contato com telefones](labs/contato/README.md) <!-- DONE -->
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Pula-pula com crianças](labs/pula-pula/README.md) <!-- DONE -->
- [ ] `eval=diff g=1 l=1 s=1` [[ALONE] Lapiseira com tambor de grafites](labs/lapiseira/README.md) <!-- DONE -->

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
- [ ] `eval=diff g=1 l=1 s=1` [[GUIDE] Cinema: posições fixas e ausência](labs/cinema/README.md) <!-- DONE -->
- [ ] `eval=diff g=2 l=1 s=1` [[TRAIN] Budega: fila e posições fixas](labs/budega/README.md) <!-- DONE -->
- [ ] `eval=diff g=1 l=1 s=1` [[ALONE] Junkfood: posições fixas e objeto vazio](labs/junkfood/README.md) <!-- DONE -->

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

- [ ] `eval=none            ` [[INTRO] Exceções](wiki/exception/README.md)
- [ ] `eval=diff g=3 l=1 s=1` [[TRAIN] Bermuda: exceções para invariantes de tamanho](labs/bermuda/README.md)
- [ ] `eval=diff g=3 l=2 s=1` [[TRAIN] Fusca: posições, exceções e direção](labs/fusca/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[TRAIN] Guardando moedas e itens em um cofrinho](labs/porquinho/README.md)
- [ ] `eval=diff g=1 l=1 s=1` [[CHECK] Tabuleiro: coleções na simulação de turnos](labs/tabuleiro/README.md)


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
- [ ] `eval=diff g=1 l=1 s=1` [Gerencie os empréstimos do agiota](labs/agiota/README.md)
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
- [ ] `eval=none            ` [Pesquisa sobre C++](wiki/cpp/README.md)
- [ ] `eval=none            ` [NÃO TEM TÍTULO](wiki/fixas/README.md)
