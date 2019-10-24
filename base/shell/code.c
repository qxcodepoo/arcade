#include <stdio.h>
#include <stdlib.h> //
#include <string.h> //strcmp strcspn __strtok_r
#include <stdbool.h> //true e false

#define MAX 10000

//retorna um token do buffer ou 0 se nao ha mais tokens
//atualiza ptr para proximo token
#define read(ptr) __strtok_r(NULL, " ", &ptr)

//retorna true se as duas strings forem iguais
#define eq(a, b) (strcmp((a), (b)) == 0)

//le uma linha de stding e armazena no buffer line
//descarta o \n do fim da linha se existir
#define readline(line) do{fgets(line, sizeof(line), stdin); line[strcspn(line, "\n")] = '\0';} while(0)


int main(){
    float acc = 0.0;

    char buffer[MAX];         //onde vou guardar a linha lida
    char * ptr;               //como vou navegar pelo buffer
    char * token = NULL;      //onde vou guardar os tokens
    char * cmd = NULL;        //onde vou guardar o comando
    while(true){
        readline(buffer);
        ptr = buffer;
        printf("$%s\n", buffer);
        cmd = read(ptr);
        if(eq(cmd, "end")){
            break;
        }else if(eq(cmd, "show")){
            printf("%.2f\n", acc);
        }else if(eq(cmd, "add")){
            acc += atof(read(ptr));
        }else if(eq(cmd, "mult")){
            acc *= atof(read(ptr));
        }else if(eq(cmd, "div")){
            float value = atof(read(ptr));
            if(value == 0.0)
                puts("fail: division by zero");
            else
                acc /= value;
        }else if(eq(cmd, "addm")){
            while((token = read(ptr))){ //enquanto conseguir retirar tokens
                acc += atoi(token); //converte pra inteiro e imprime
            }
        }else{
            puts("fail: command not found");
        }
    }
    return 0;
}
