# @clinica Clínica Veterinária

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/clinica/Readme.md)

<!-- toch -->
[Intro](#intro) | [Shell](#shell) | [Guide](#guide)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/clinica/cover.jpg)

Você foi contratado por uma clínica veterinária para implementar um sistema que vai administrar os hóspedes.
Na clínica em que você trabalha os veterinários querem um sistema que tem como objetivo diminuir a saudade dos donos enquanto seus queridos pets estão hospedados na sua clínica.
A grande sacada da gestão da clinica foi mandar áudios, videos ou fotos dos animaizinhos para que os donos possam matar um pouco da saudade dos seus tão amados animaizinhos.

## Intro

- Criar o PetShop com X goiolas
- Cadastrar uma pet pelo nome.
  - nome do pet é único
  - o tipo do animal
- Mostrar todos os pets
- gravar um áudio, video ou foto do pet
- Cada pet tem seu próprio som e ação

Especie | Som | Ação
:--- | :--- | :---
cachorro | auau | balança o rabo
gato | miau | não faz nada
papagaio | seu nome 2x| balança a cabeça
preguiça | sem som | não faz nada

## Shell

```sh
#__case criar o petShop
# init _size
$init 8
#__case cadastro pet
# addPet _nome _tipo
$addPet Beethoven cachorro
$addPet Emma gato
$addPet Loro papagaio
$addPet Emma preguica
fail: pet Emma ja existe
$pets
0[Beethoven]
1[Emma]
2[Loro]

#__case registrar atitude do pet
# getAtitude _index
$getAtitude 0
[Beethoven emite um som "auau" e balança o rabo]- video
$getAtitude 1
[Emma emite um som "miau"]- audio
$getAtitude 2
[Loro emite um som "LoroLoro" e balança a cabeça]- video
$getAtitude 3
fail: não tem nenhum animal nessa jaula
$addPet Aluno preguiça
$getAtitude 3
[Aluno]- foto
# getAllAtitudes.
$getAllAtitudes
0[Beethoven emite um som "auau" e balança o rabo]- video
1[Emma emite um som "miau"]- audio
2[Loro emite um som "LoroLoro" e balança a cabeça]- video
3[Aluno]- foto

$end
```

***

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/clinica/diagrama.png)
