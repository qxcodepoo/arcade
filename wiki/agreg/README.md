---
index_content: |2
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
    - Princípios relacionados:
      - responsabilidade: cada objeto protege suas próprias regras, e o coordenador apenas organiza a colaboração.
      - delegação: cada componente é responsável por suas próprias regras, e o coordenador apenas organiza a colaboração.
---
# [INTRO] Introdução Agregação e Delegação
#