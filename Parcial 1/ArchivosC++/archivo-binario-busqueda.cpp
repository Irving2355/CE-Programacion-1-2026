#include <iostream>
#include <fstream>
using namespace std;

struct Producto{
    int codigo;
    char nombre[40];
    float precio;
    int existencia;
};

void mostrarProducto(Producto p) {
    cout << "Codigo: " << p.codigo << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Precio: " << p.precio << endl;
    cout << "Existencia: " << p.existencia << endl;
}

int main(){
    Producto productoVariable;
    int codigoBuscar;
    bool encontrado = false;

    cout << "Codigo a buscar: ";
    cin >> codigoBuscar;

    ifstream archivo("producto.dat", ios::binary);
    if(!archivo){
        cout << "No se pudo abrir producto.dat";
        return 1;
    }

    while(archivo.read(reinterpret_cast<char *>(&productoVariable), sizeof(productoVariable))){
        if(productoVariable.codigo == codigoBuscar){
            cout << "Producto encontrado\n";
            mostrarProducto(productoVariable);
            encontrado = true;
        }
    }

    archivo.close();

    if(!encontrado){
        cout << "No se encontro el producto\n";
    }
    return 0;
}