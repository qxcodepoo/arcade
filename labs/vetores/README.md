# Vetores — coleção linear e índices

<toc-table />

## Intro

Modele uma coleção linear que preserva ordem, aceita duplicatas e permite
consulta, alteração, inserção e busca pelo primeiro índice. O objetivo é
praticar operações de sequência sem esconder seus efeitos no contrato.

## Regras

- `add` acrescenta valores ao final;
- `get` e `set` usam índices existentes;
- `ins` ignora índice negativo e insere no final quando o índice ultrapassa o tamanho;
- `find` retorna o primeiro índice ou `-1`.

## Guide

Comece pela lista e pelas operações que preservam ordem. Depois implemente
inserção e busca, testando duplicatas e limites. O Shell apenas converte os
argumentos e apresenta falhas.

## Verificação

Execute `python3 -m unittest discover src/py`.
