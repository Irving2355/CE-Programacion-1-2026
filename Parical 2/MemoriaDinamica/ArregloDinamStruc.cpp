#include <iostream>
using namespace std;

typedef struct{
    int codigo;
    char nombre[40];
    float precio;
}Producto;

void capturar(Producto *productos, int n);
void mostrar(Producto *productos, int n);

int main(){
    int n; 
    Producto *productos = nullptr;

    n = 3;

    productos = new Producto[n];

    capturar(productos, n);
    mostrar(productos, n);

    delete[] productos;
    productos = nullptr;
    return 0;
}

void capturar(Producto *productos, int n){
    for(int i=0; i<n; i++){
        cout << "Codigo: ";
        cin >> (productos + i)->codigo;
        cout << "Nombre: ";
        cin >> (productos + i)->nombre;
        cout << "Precio: ";
        cin >> (productos + i)->precio;
    }
}

void mostrar(Producto *productos, int n){
    for(int i=0; i<n; i++){
        cout << "Codigo: " << (productos + i)->codigo << endl;
        cout << "Nombre: " << (productos + i)->nombre << endl;
        cout << "Precio: " << (productos + i)->precio << endl;
    }
}