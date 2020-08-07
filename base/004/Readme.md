## #02_noobie Lapiseira e Grafite sub: Duas classes, agregação, null

Faça o modelo de uma lapiseira que pode conter um único grafite.

## Funcionalidade
- Iniciar lapiseira
    - Inicia uma lapiseira de determinado calibre sem grafite.
- Inserir grafite
    - Insere um grafite passando
        - o calibre: float.
        - a dureza: string.
        - o tamanho em mm: int.
    - Não deve aceitar um grafite de calibre não compatível.
- Remover grafite
    - Retira o grafite se houver algum.
- Escrever folha
    - Não é possível escrever se não há grafite.
    - A quantidade de grafite que se gasta pra escrever uma folha é duas vezes o nível de pressão utilizado.
        - 1 - 2mm
        - 2 - 4mm
        - 3 - 6mm
        - ...
    - Se o grafite acabar, defina o objeto grafite como `null`.
    - Se não houver grafite suficiente para terminar a folha avise que a folha ficou pela metade.
    - Avise quando o grafite acabar.


## Testes

```bash
#__case inserindo grafites
$init 0.5
$show
calibre: 0.5, grafite: null
$inserir 0.7 2B 50
fail: calibre incompatível
$inserir 0.5 2B 50
$show
calibre: 0.5, grafite: [0.5:2B:50]
$end
```

```bash
#__case inserindo e removendo
$init 0.3
$inserir 0.3 2B 50
$show
calibre: 0.3, grafite: [0.3:2B:50]
$inserir 0.3 4B 70
fail: ja existe grafite
$show
calibre: 0.3, grafite: [0.3:2B:50]
$remover
$inserir 0.3 4B 70
$show
calibre: 0.3, grafite: [0.3:4B:70]
$end
```

```bash
#__case escrevendo
$init 0.9
$write 10
fail: nao existe grafite
$inserir 0.9 4B 30
$show
calibre: 0.9, grafite: [0.9:4B:30]
$write 6
$show
calibre: 0.9, grafite: [0.9:4B:18]
$write 10
fail: folha ficou pela metade
fail: grafite acabou
$show
calibre: 0.9, grafite: null
$end
```

```bash
#__case escrevendo
$init 0.9
$inserir 0.9 2B 16
$show
calibre: 0.9, grafite: [0.9:2B:16]
$write 4
$show
calibre: 0.9, grafite: [0.9:2B:8]
$write 4
fail: grafite acabou
$show
calibre: 0.9, grafite: null
$end
```