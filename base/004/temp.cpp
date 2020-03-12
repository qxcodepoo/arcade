//```
#include <iostream>
using namespace std;

void print_vet(int * vet, int size){
    cout << "[ ";
    for(int i = 0; i < size; i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

void triangulo_de_somas(int * vet, int size) {
    if(size == 0)
        return;
    int novo_vet[size];
    for(int i = 0; i < size - 1; i++)
        novo_vet[i] = vet[i] + vet[i + 1];
    triangulo_de_somas(novo_vet, size - 1);
    print_vet(vet, size);
}

int main() {
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    triangulo_de_somas(arr, n);
    return 0;
}
//```