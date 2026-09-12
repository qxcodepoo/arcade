---
index_content: |2
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
---
# [INTRO] Desafios de agregação e estados
#