#include <iostream>
#include <cstring>

using namespace std;

struct Alumno
{
    int id;
    char nombre[40];
    float promedio;
};


int main(){
    Alumno alumno;
    Alumno *ptrAlumno;

    alumno.id = 101;
    strcpy(alumno.nombre, "Maria");
    alumno.promedio = 8.6;

    ptrAlumno = &alumno;

    cout << "\nUsando el puntero\n";
    cout << "ID: " << (*ptrAlumno).id << endl;
    cout << "Nombre: " << (*ptrAlumno).nombre << endl;
    cout << "Promedio: "<< (*ptrAlumno).promedio << endl;
    cout << "Direccion de memorias\n";
    cout << "Org: " << &alumno << endl;
    cout << "Ptr: " << &ptrAlumno << endl;

    cout << "\ntamanos de structs\n";
    cout << "tamano: " << sizeof(alumno) << endl;
    cout << "tam Struct: " << sizeof(Alumno) << endl;
    cout << "tam ptrAl: " << sizeof(ptrAlumno) << endl;
    int x = 10;
    int *p = &x;
    cout << "tam x: " << sizeof(x) << endl;
    cout << "tam *p: " << sizeof(p) << endl;
    cout << "Dire x: " << &x << endl;

    cout << "\n\nImpresion usando la segunda forma\n";
    cout << "ID: " << ptrAlumno->id << endl;
    cout << "Nombre: " << ptrAlumno->nombre << endl;
    cout << "Promedio: " << ptrAlumno->promedio << endl;

    return 0;
}