# Tamagotchi: coordenação, invariantes e estado terminal

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Esta atividade modela um pet que brinca, toma banho, dorme e pode morrer quando sua energia ou limpeza chega a zero.

O objetivo principal é separar o objeto que guarda os atributos e invariantes (`Pet`) do objeto que coordena as ações do jogo (`Game`).

## Regras

- `Pet` guarda `energyMax`, `cleanMax`, `energy`, `clean`, `age`, `alive` e `deathCause`.
- O construtor recebe `energyMax` e `cleanMax`; energia e limpeza começam no máximo, e idade começa em zero.
- `DeathCause` possui `NONE`, `WEAKNESS` e `DIRT`.
- `Pet` mantém energia e limpeza entre zero e seus respectivos máximos.
- `loseEnergy(amount)` reduz a energia e registra `WEAKNESS` quando ela chega a zero.
- `loseClean(amount)` reduz a limpeza e registra `DIRT` quando ela chega a zero.
- Depois de morto, `Game` não inicia novas ações que alterem o estado do pet.
- `advanceAge(amount)` aumenta a idade sem permitir alterações posteriores à morte.
- `restoreEnergy()` e `restoreClean()` levam o atributo ao máximo enquanto o pet estiver vivo.
- Um pet vivo mostra `energy:{energy}/{energyMax}, clean:{clean}/{cleanMax}, age:{age}`.
- Um pet morto acrescenta `, death:{deathCause}` usando os textos `weakness` ou `dirt`.
- `Game` agrega um `Pet` recebido no construtor e coordena `play`, `shower` e `sleep`.
- `play()` reduz energia em 2, limpeza em 3 e avança a idade em 1.
- `shower()` reduz energia em 3, restaura a limpeza ao máximo e avança a idade em 2.
- `sleep()` exige pelo menos 5 unidades de energia perdidas, restaura a energia e avança a idade pela energia perdida.
- `play()` e `shower()` retornam `false` se o pet já estava morto; caso contrário, retornam `true`, mesmo que a ação cause a morte.
- `sleep()` retorna `false` somente quando o pet está vivo e não está com sono. Para um pet morto, dormir retorna `true` sem alterar o estado.
- As classes de domínio não leem entrada nem imprimem mensagens. O `Shell` interpreta retornos e apresenta falhas.

### Contrato observável

Os comandos são `$init`, `$show`, `$play`, `$shower`, `$sleep` e `$end`.

A única falha de interação exibida é `fail: not sleepy`. Comandos desconhecidos exibem `fail: invalid command`.

## Diagrama

![diagram](assets/diagrama.png)

## Guide

Implemente uma etapa e execute os testes correspondentes antes de avançar.

### 1. Pet e estado inicial

Crie `DeathCause` e `Pet`. Inicialize energia e limpeza no máximo, idade em zero e o pet como vivo. Implemente `toString` e as consultas necessárias para que o estado inicial possa ser conferido.

### 2. Invariantes e morte

Substitua setters genéricos por operações que expressem o domínio: `loseEnergy`, `loseClean`, `advanceAge`, `restoreEnergy` e `restoreClean`. Cada operação deve proteger o estado e registrar a primeira causa de morte.

### 3. Coordenação do Game

Crie `Game` recebendo um `Pet` já existente. Implemente `play` e `shower`, delegando as alterações ao pet. Verifique a vida antes de iniciar uma ação e preserve o estado quando ela não puder começar.

### 4. Sono e estado terminal

Implemente `isSleepy` e `sleep`. O jogo deve devolver `false` para uma tentativa de dormir sem sono, mas aceitar dormir depois da morte como uma operação sem efeito. O `Shell` deve imprimir a mensagem somente quando `sleep` retornar `false`.

Reflita: por que `Pet` deve controlar a morte? O que fica mais difícil de preservar quando o cliente pode alterar `energy`, `clean` ou `age` diretamente?

## Shell

```bash
#TEST_CASE initial state
$init 20 15
$show
energy:20/20, clean:15/15, age:0
$init 10 50
$show
energy:10/10, clean:50/50, age:0
$end
```

___

```bash
#TEST_CASE play and shower
$init 20 15
$play
$show
energy:18/20, clean:12/15, age:1
$play
$play
$show
energy:14/20, clean:6/15, age:3
$sleep
$show
energy:20/20, clean:6/15, age:9
$shower
$show
energy:17/20, clean:15/15, age:11
$end
```

___

```bash
#TEST_CASE sleep without sleepiness
$init 20 15
$sleep
fail: not sleepy
$show
energy:20/20, clean:15/15, age:0
$play
$sleep
fail: not sleepy
$show
energy:18/20, clean:12/15, age:1
$end
```

___

```bash
#TEST_CASE death by dirt
$init 20 15
$play
$play
$play
$play
$play
$show
energy:10/20, clean:0/15, age:5, death:dirt
$play
$shower
$show
energy:10/20, clean:0/15, age:5, death:dirt
$end
```

___

```bash
#TEST_CASE death by weakness
$init 5 10
$play
$play
$play
$show
energy:0/5, clean:1/10, age:3, death:weakness
$end
```

___

```bash
#TEST_CASE eternal sleep
$init 5 10
$play
$play
$play
$sleep
$show
energy:0/5, clean:1/10, age:3, death:weakness
$end
```

___

```bash
#TEST_CASE invalid actions after death
$init 5 10
$play
$play
$play
$play
$play
$play
$show
energy:0/5, clean:1/10, age:3, death:weakness
$sleep
$play
$shower
$show
energy:0/5, clean:1/10, age:3, death:weakness
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
