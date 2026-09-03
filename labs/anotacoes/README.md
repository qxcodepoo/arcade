# Anotações — sessão e notas privadas

<toc-table />

## Intro

O sistema cadastra usuários, controla a sessão atual e guarda notas privadas.
O objetivo é separar autenticação, sessão e dados do usuário, praticando
encapsulamento e validação de estado.

## Regras

- usernames são únicos;
- somente usuário autenticado cria e consulta notas;
- cada nota possui título e texto;
- logout encerra a sessão.

## Guide

Mantenha `NotesApp` como coordenador da sessão e dos mapas; `Note` é um valor
imutável. Teste credenciais, ausência de sessão e isolamento entre usuários.

## Verificação

Execute `python3 -m unittest discover src/py`.
