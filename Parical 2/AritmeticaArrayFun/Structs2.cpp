#include <iostream>
#include <cstring>
using namespace std;

typedef struct{
    int codigo;
    char nombre[40];
    float precio;
}Producto;

void mostrar(Producto *productos, int n);
int buscarPorCodigo(Producto *productos, int n, int codigo);

int main(){
    Producto productos[3];
    Producto *p = productos;

    productos[0] = {101,"Lapiz", 5.5};
    productos[1] = {102,"Cuaderno", 25.0};
    productos[2] = {103,"Borrador", 8.0};

    mostrar(productos, 3);

    int pos = buscarPorCodigo(productos, 3 , 102);

    if(pos != -1){
        cout << "\nProducto encontrado.\n";
    }else{
        cout << "\nNo se encontro.\n";
    }

    return 0;
}

void mostrar(Producto *productos, int n){
    for(int i=0; i<n; i++){
        cout << "\nProducto " << i+1 << endl;
        cout << "Codigo: " << (productos + i)->codigo << endl;
        cout << "Nombre: " << (productos + i)->nombre << endl;
        cout << "Precio: " << (productos + i)->precio << endl;
    }
}

int buscarPorCodigo(Producto *productos, int n, int codigo){
    for(int i=0; i<n; i++){
        if((productos + i)->codigo == codigo){
            return i;
        }
    }
    return -1;
}