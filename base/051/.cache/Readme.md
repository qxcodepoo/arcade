## @051 Instalando e configurando o tk e o fn.cpp

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/051/cover.jpg)

## fn.hpp

[LINK](https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp)

- Opção 1: colocar na pasta /usr/local/include
- Opção 2: colocar na pasta do projeto usando o include entre aspas para indicar que é um arquivo local.
- Para compilar um código com o fn.hpp, usar o comando `g++ -std=c++17 main.cpp -o main`

```cpp
#include <fn.hpp>

int main() {
    fn::write("Hello, World!");
    return 0;
}
```

## tk

- baixar o tk [LINK](https://raw.githubusercontent.com/senapk/tk/master/tk.py)
- se estiver no linux, renomear para `tk` e habilitar execução `chmod +x tk`
- baixar o tk e colocar dentro de algum path executável
  - /usr/local/bin
  - ~/bin

```py
$ tk -h
usage: tk [-h] {list,exec,run,build,update,down,gui} ...

options:
  -h, --help            show this help message and exit

subcommands:
```
