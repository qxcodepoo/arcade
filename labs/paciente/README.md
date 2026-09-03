# Paciente — vínculos bidirecionais no hospital

<toc-table />

## Intro

Cadastre pacientes e médicos e vincule-os. Um paciente não pode ter dois
médicos da mesma especialidade. O objetivo é praticar relações bidirecionais,
mantendo a consistência nos dois objetos.

## Regras

- ids de pacientes e médicos são únicos;
- o vínculo aparece no paciente e no médico;
- uma especialidade não pode se repetir entre os médicos de um paciente.

## Guide

`Hospital` mantém os mapas globais e coordena a busca. `Patient` e `Doctor`
possuem suas relações. O método de vínculo deve atualizar os dois lados apenas
depois de validar a regra.

## Verificação

Execute `python3 -m unittest discover src/py`.
