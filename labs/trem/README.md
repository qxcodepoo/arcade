# Trem — composição e alocação de passageiros

<toc-table />

## Intro

Modele um trem composto por vagões, assentos e passageiros. O objetivo é
praticar composição, busca sequencial, capacidade e histórico de eventos.

## Regras

- o trem limita a quantidade de vagões;
- passageiros entram no primeiro assento livre;
- um passageiro não pode estar duas vezes no trem;
- sair libera o assento e registra o evento.

## Guide

`Train` coordena vagões e histórico. Teste entrada, lotação, repetição, saída
e reutilização de assento.

## Verificação

Execute `python3 -m unittest discover src/py`.
