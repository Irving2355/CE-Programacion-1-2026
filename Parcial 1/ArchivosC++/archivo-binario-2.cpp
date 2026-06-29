#include <iostream>
#include <fstream>
using namespace std;

struct Producto{
    int codigo;
    char nombre[40];
    float precio;
    int existencia;
};

int main(){
    //para usarlos de ecritura y lectura
    fstream archivo("datos.dat", ios::in | ios::out | ios::binary); 

    Producto producto,producto2;
    producto = {123, "coca", 24, 48};

    ofstream archivo("producto.dat", ios::binary);
    
    archivo.write(reinterpret_cast<const char*>(&producto), sizeof(producto));

    archivo.close();

    ifstream archivoLectura("producto.dat", ios::binary);

    archivoLectura.read(reinterpret_cast<char *>(&producto2), sizeof(producto2));
    archivoLectura.close();

    cout<< "Nombre: " <<producto2.nombre<<endl;
    return 0;
}