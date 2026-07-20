#include <iostream>
using namespace std;

void mostrar(int *numeros, int n);
void duplicarValores(int *numeros, int n);

int main(){
    int datos[5] = {4,8,15,16,23};

    cout << "Antes de duplicar: \n";
    mostrar(datos, 5);

    duplicarValores(datos, 5);
    cout << "\nDespues de duplicar: \n";
    mostrar(datos, 5);

    cout << "\ndatos[0]: " << datos[0] << endl;

    return 0;
}

void mostrar(int *numeros, int n){
    for(int i=0; i<n; i++){
        cout << "Elemento " << i << ": " << *(numeros + i) <<endl;
    }
}

void duplicarValores(int *numeros, int n){
    for(int i=0; i<n; i++){
        *(numeros + i) = *(numeros + i) * 2;
    }
}