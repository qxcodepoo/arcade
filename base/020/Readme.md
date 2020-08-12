## Agenda 7 - Login Multiusuário

## Shell

```bash
#__iniciando sistema

# O sistema é iniciado com a senha do admin
#init _admin_pass
$init pickachu

#adduser _username _senha
$adduser mariana banana
$adduser fabiola supino
$adduser sampaio fofura

$showusers
[ admin mariana fabiola sampaio ]

#__case login e logout
$login mariana capricho
fail: senha incorreta
$login sampaio fofura
$login fabiola supino
fail: ja existe um usuario logado
$logout
$login fabiola supino
```

