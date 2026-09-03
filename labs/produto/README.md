# Produto — Composite e Decorator

<toc-table />

## Intro

Produtos simples, pacotes e produtos com desconto devem ser usados por um
catálogo uniforme. O objetivo é praticar composição e adição de comportamento.

## Regras

- produto simples tem nome e preço;
- pacote soma os preços dos produtos;
- desconto reduz o preço do produto envolvido;
- pacotes e descontos podem envolver qualquer `Product`.

## Guide

`Bundle` aplica Composite e `Discount` aplica Decorator: ambos atendem o mesmo
contrato. O catálogo cria e indexa objetos, mas não calcula preços por tipo.

## Verificação

Execute `python3 -m unittest discover src/py`.
