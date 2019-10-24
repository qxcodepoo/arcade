## Contato Telefônico
### Batman achou um celular na cena do crime e ligou pro único contato que tinha. O Coringa atende e pergunta "porque você está de terno Batman"? Após um silêncio sombrio do Batman ele chuta - você vem de um bat_zado?.
![](figura.png)


O objetivo dessa atividade é implementar uma classe responsável por guardar um **único** contato da agenda telefônica do seu celular. Cada contato pode ter vários telefones.

## Funcionalidades
Seu programa deve:

- **[2.0 P] Definir nome**
    - Poder inicializar o contato passando o nome.
        - Se já houver contato, inicie um novo contato.
        - Se não houver nome, o nome default é "vazio".
- **[2.0 P] Inserir telefones no contato** 
    - Um telefone tem um label e um fone.
    - Labels serão nomes como: casa, fixo, oi.
    - Labels podem ser duplicados.
    - Adapte o print para apresentar os celulares.
- **[2.0 P] Remover telefones do contato.**    
    - Remove os celulares pelo indice.
- **[2.0 P] Atualize o contato em lote.**
    - Inicialize o contato apagando os dados antigos e inserindo todos os telefones passados por parametro.
- **[2.0P] Processando números de telefone.**
    - Processe os telefones para apenas permitir nos telefones os seguintes caracteres "0123456789()."
    - Se o usuário tentar inserir individualmente um telefone invalido, avise e não insira o telefone.
    - Se um telefone inválido estiver na operação em lote, ignore este telefone e continue tentando inserir os outros.

---
## Exemplos

```bash
#__begin__
#######################################
# Iniciar um contato
#######################################
$show
vazio=>
$init david
$show
david=>

#######################################
# Inserir telefones no contato
#######################################
$add oi 88
$add tim 99
$add tim 98
$add vivo 83
$show
david=>[0:oi:88][1:tim:99][2:tim:98][3:vivo:83]

#######################################
# Remover telefones
#######################################

$rm 2
$show
david=>[0:oi:88][1:tim:99][2:vivo:83]
$rm 0
$show
david=>[0:tim:99][1:vivo:83]

#######################################
# Atualizar contato
#######################################
$update mary vivo:1234 home:4321 work:4444 vivo:1235
$show
mary=>[0:vivo:1234][1:home:4321][2:work:4444][3:vivo:1235]

#######################################
# Validate
#######################################
$add tim 9a9
fail: fone invalido
$add tim (85)99.99
$show
mary=>[0:vivo:1234][1:home:4321][2:work:4444][3:vivo:1235][4:tim:(85)99.99]
$update marya vivo:893a casa:(85)88 vivo:8-93 tim:(88)99.99 vivo:b893
$show
marya=>[0:casa:(85)88][1:tim:(88)99.99]
$end
#__end__
```

---
## Raio X

````java
class Fone
+ label: string
+ numero: string
--
+ validate(): bool
+ toString(): string

class Contato
- nome: string
- fones: Fone[]
--
+ addFone(fone: Fone) : boolean
+ rmFone(ind: int) : boolean
--
+ constructor(nome: fone)
````