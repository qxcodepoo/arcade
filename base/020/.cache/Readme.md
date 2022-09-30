## @020 Lapiseira & Com vários grafites utilizando lista

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/020/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

Faça o modelo de uma lapiseira que pode conter vários.

## Intro
- Iniciar lapiseira
    - Inicia uma lapiseira de determinado calibre sem grafite.
    - Lapiseiras possuem um bico e um tambor.
    - O bico guarda o grafite que está em uso. 
    - O tambor guarda os grafites reservas.
- Inserir grafite
    - Insere um grafite passando
        - o calibre: float.
        - a dureza: string.
        - o tamanho em mm: int.
    - Não deve aceitar um grafite de calibre não compatível.
    - O grafite é colocado como o ÚLTIMO grafite do tambor.
- Puxar grafite
    - Puxa o grafite do tambor para o bico.
    - Se já tiver um grafite no bico, esse precisa ser removido primeiro.
- Remover grafite
    - Retira o grafite do bico.
- Escrever folha
    - Não é possível escrever se não há grafite no bico.
    - Quanto mais macio o grafite, mais rapidamente ele se acaba. Para simplificar, use a seguinte regra:
        - Grafite HB: 1mm por folha.
        - Grafite 2B: 2mm por folha.
        - Grafite 4B: 4mm por folha.
        - Grafite 6B: 6mm por folha.
        
    - O último centímetro de um grafite não pode ser aproveitado, quando o grafite estiver com 10mm, não é mais possível escrever e o grafite deve ser retirado.
    - Se não houver grafite suficiente para terminar a folha, avise que o texto ficou incompleto.
    - Avise quando o grafite acabar.


***
## Guide
![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/020/diagrama.png)

- [Solver.java](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/020/.cache/draft.java)
- [Solver.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/020/.cache/draft.cpp)
***
## Shell

```bash
#__case inserindo grafites
$init 0.5
$show
calibre: 0.5, bico: [], tambor: {}
#__case calibre errado
$insert 0.7 2B 50
fail: calibre incompatível
#__case calibre certo
$insert 0.5 2B 50
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:50]}
#__case mais de um grafite
$insert 0.5 2B 30
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:50][0.5:2B:30]}
#__case puxando grafite
$pull
$show
calibre: 0.5, bico: [0.5:2B:50], tambor: {[0.5:2B:30]}
#__case puxando ocupado
$pull
fail: ja existe grafite no bico
#__case removendo do bico
$remove
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:30]}
$end
```


```bash
#__case escrevendo 
$init 0.9
$insert 0.9 4B 14
$insert 0.9 4B 16
#__case sem grafite no bico
$write
fail: nao existe grafite no bico
#__case puxando grafite
$pull
$show
calibre: 0.9, bico: [0.9:4B:14], tambor: {[0.9:4B:16]}
#__case gastando grafite
$write
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: {[0.9:4B:16]}
#__case puxando novo
$remove
$pull
$show
calibre: 0.9, bico: [0.9:4B:16], tambor: {}
$write
$show
calibre: 0.9, bico: [0.9:4B:12], tambor: {}
#__case folha incompleta
$write
fail: folha incompleta
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: {}
#__case tamanho insuficiente
$write
fail: tamanho insuficiente
$end
```





