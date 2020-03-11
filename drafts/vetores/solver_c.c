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

//mostra o vetor
void vet_show(int *vet, size_t size){
    printf("[ ");
    for(size_t i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}

//adiciona um elemento ao final do vetor
//atualiza o size
void vet_add(int *vet, size_t *size, int value){
//_B
    vet[*size] = value;
    *size += 1;
//_E
}

//retorna o primeiro indice que contem esse valor ou -1
int vet_find(int * vet, size_t size, int value){
//_B
    for(size_t i = 0; i < size; i++)
        if(vet[i] == value)
            return i;
//_E
    return -1;
}

//remove o elemento desse indice se existir
//atualiza o size
void vet_rmi(int * vet, size_t *size, int ind){
//_B
    if(ind < 0 || ind >= *size){
        puts("fail");
        return;
    }
    for(int i = ind; i < *size - 1; i++)
        vet[i] = vet[i + 1];
    *size -= 1;
//_E
}

//remove todos os elementos com esse valor
//atualiza size
void vet_rma(int * vet, size_t *size, int value){
//_B
    for(int i = (*size - 1); i >= 0; i--)
        if(vet[i] == value)
            vet_rmi(vet, size, i);
//_E
}

//mostra os elementos de trás pra frente
void vet_rshow(int * vet, size_t size){
//_B
    printf("[ ");
    for(int i = (size - 1); i >= 0; i--)
        printf("%d ", vet[i]);
    printf("]\n");
//_E
}

// Se o ind for menor que 0, não faça a inserção.
// Se ind for maior que último índice válido, insira na última posição.
// Se ind for um índice válido, desloque todos os elementos a partir dessa posição, uma posição à frente.
void vet_insert(int * vet, size_t *size, int ind, int value){
//_B
    if(ind < 0)
        return;
    if(ind > *size)
        ind = *size;
    for(int i = *size; i >= ind; --i)
        vet[i] = vet[i - 1];
    *size += 1;
    vet[ind] = value;
//_E
}

int main(){
    int vet[MAX];
    size_t size = 0;

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
        }else if(eq(cmd, "add")){
            while((token = read(ptr))){ //enquanto conseguir retirar tokens
                vet_add(vet, &size, atoi(token)); //converte pra inteiro e imprime
            }
        }else if(eq(cmd, "show")){
            vet_show(vet, size);
        }else if(eq(cmd, "rshow")){
            vet_rshow(vet, size);
        }else if(eq(cmd, "find")){
            printf("[ ");
            while((token = read(ptr))){ //enquanto conseguir retirar tokens
                printf("%d ", vet_find(vet, size, atoi(token))); //converte pra inteiro e imprime
            }
            printf("]\n");
        }else if(eq(cmd, "rmi")){
            int ind = atoi(read(ptr));
            vet_rmi(vet, &size, ind);
        }else if(eq(cmd, "ins")){
            int ind = atoi(read(ptr));
            int value = atoi(read(ptr));
            vet_insert(vet, &size, ind, value);
        }else if(eq(cmd, "rma")){
            int value = atoi(read(ptr));
            vet_rma(vet, &size, value);
        }else{
            puts("Comando invalido");
        }
    }
    return 0;
}
