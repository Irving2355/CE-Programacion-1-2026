#include <iostream>
#include <cstring>
using namespace std;

typedef struct{
    int codigo;
    char nombre[40];
    float precio;
}Producto;

struct Fecha
{
    int dia;
    int mes;
    int anio;
    Producto *productoFecha;
};

typedef struct
{
    char nombre[40];
    int edad;
    Fecha fechaNacimiento;
    Producto *producto;
}Alumno;

int main(){
    Producto productos[3];
    Producto *p = productos;

    productos[0] = {101,"Lapiz", 5.5};
    productos[1] = {102,"Cuaderno", 25.0};
    productos[2] = {103,"Borrador", 8.0};

    for(int i=0; i<3; i++){
        cout << "\nProducto " << i+1 << endl;
        cout << "Codigo: " << (p + i)->codigo << endl;
        cout << "Nombre: " << (p + i)->nombre << endl;
        cout << "Precio: " << (p + i)->precio << endl;
    }

    Alumno al;
    Alumno *ptrAl = &al; 

    ptrAl->edad = 22;
    strcpy(ptrAl->nombre, "Maria");
    ptrAl->fechaNacimiento.dia = 22;
    ptrAl->fechaNacimiento.mes = 7;
    ptrAl->fechaNacimiento.anio = 2004;
    ptrAl->producto->codigo = 202;

    ptrAl->fechaNacimiento.productoFecha->precio = 20.0;

    return 0;
}