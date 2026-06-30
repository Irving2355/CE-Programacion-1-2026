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
    Producto producto;
    int codigoBuscar, nuevaExistencia;
    bool encontrado = false;

    cout << "Codigo a modificar:";
    cin >> codigoBuscar;

    fstream archivo("producto.dat", ios::in | ios::out | ios::binary);

    while(!encontrado && 
    archivo.read(reinterpret_cast<char *>(&producto), sizeof(producto))){
        if(producto.codigo == codigoBuscar){
            cout << "Producto encontrado: \n";
            mostrarProducto(producto);

            cout << "\n\nNueva existencia:";
            cin >> nuevaExistencia;

            producto.existencia = nuevaExistencia;

            archivo.seekp(-static_cast<int>(sizeof(Producto)), ios::cur);

            archivo.write(reinterpret_cast<const char*>(&producto), sizeof(Producto));

            encontrado = true;
        }
    }
    return 0;
}