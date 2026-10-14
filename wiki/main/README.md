# [INTRO] Criando a Main

![_](assets/cover.webp)

## Guide

Em Kotlin, o `Shell` lê um comando por vez, chama as operações do domínio e
apresenta os resultados. Este exemplo mantém uma lista de números para mostrar
o fluxo da `main`:

```kotlin
import java.util.Locale

class Shell {
    private val numbers: MutableList<Int> = mutableListOf()
    private var running: Boolean = true

    private fun process(): Unit {
        val line: String = readln()
        println("\$$line")
        val args: List<String> = line.split(" ")

        when (args[0]) {
            "end" -> running = false
            "show" -> println(numbers)
            "push" -> numbers.addAll(args.drop(1).map { it.toInt() })
            "erase" -> numbers.removeAt(args[1].toInt())
            "media" -> println(String.format(Locale.US, "%.2f", numbers.average()))
            else -> println("fail: comando invalido")
        }
    }

    fun main(): Unit {
        while (running) {
            try {
                process()
            } catch (_: NumberFormatException) {
                println("fail: conversao invalida")
            } catch (_: IndexOutOfBoundsException) {
                println("fail: indice ou parametro invalido")
            }
        }
    }
}

fun main(): Unit = Shell().main()
```

## Shell

```s
#TEST_CASE teste simples
$show
[]

#TEST_CASE inserindo vários números em lote
$push 1 4 3 2
$show
[1, 4, 3, 2]

#TEST_CASE apagando por índice
$erase 1
$show
[1, 3, 2]

#TEST_CASE calculando a media
$media
2.00

$end
```
