# Comunicador — envio autorizado por composição

<toc-table />

## Intro

Pacientes e médicos precisam trocar mensagens, mas somente com pessoas que
possuem vínculo. O objetivo é extrair a lógica comum de inbox e envio para um
componente `Communicator`, mantendo a autorização como uma relação explícita.

## Regras

- uma mensagem tem remetente e texto;
- somente um receiver conhecido pode receber;
- ler o inbox devolve e remove as mensagens pendentes.

## Guide

Use composição para que os objetos do hospital tenham um comunicador. A lista
de possíveis receivers vem do vínculo médico-paciente; não deve ser duplicada
como uma segunda regra no Shell. Isso amplia `Paciente` sem transformar a
classe original em um objeto responsável por mensagens, usuários e interface.

## Verificação

Execute `python3 -m unittest discover src/py`.
