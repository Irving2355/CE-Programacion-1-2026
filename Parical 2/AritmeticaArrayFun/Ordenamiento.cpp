#include <iostream>
using namespace std;

void mostrar(int *calificaciones, int n);
void swap(int *a, int *b);
void ordenarAscendente(int *datos, int n);

int main(){
    int datos[6] = {7,8,9,6,4,10};
    cout << "Antes de ordenar: " << endl;
    mostrar(datos, 6);

    ordenarAscendente(datos, 6);

    cout << "\nDespues de ordenar: " << endl;
    mostrar(datos, 6);

    return 0;
}

void mostrar(int *calificaciones, int n){
    for(int i=0; i<n; i++){
        cout << *(calificaciones + i) << " ";
        //*(calificaciones + i) = i*3;
        //cin >> *(calificaciones + i);
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temporal;

    temporal = *a;
    *a = *b;
    *b = temporal;
}

void ordenarAscendente(int *datos, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(*(datos + j) < *(datos + i)){
                swap(datos+i, datos+j);
            }
        }
    }
}