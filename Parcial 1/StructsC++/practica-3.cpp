#include <iostream>

using namespace std;

struct Producto{
    int codigo;
    char nombre[30];
    float precio;
    int existencia;
};

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int id;
    char nombre[30];
    Fecha nacimiento;
    float promedio;
}Alumno;

void mostrarP(Producto p);
void anidado(Alumno a);

int main(){
    /*Producto p1;
    Alumno a1,a2;

    a1.id = 123;
    a1.promedio = 9;
    
    p1.codigo = 234;
    p1.precio = 400;

    Alumno a3 = {1001, "Maria", 7};

    int id = 2002;
    float promedio = 6.5;
    char nombre[30] = "Juan";

    Alumno a4 = {id, *nombre, promedio};

    cout << "id: " << a4.id;
    cout << "  nombre: " << a4.nombre;
    cout << " promedio: " << a4.promedio << endl;

    mostrar(a3);

    mostrar({
        1001, 
        "Maria", 
        7
    });*/

    Alumno a1,a2,a3;

    a1.nacimiento.dia = 12;
    a1.promedio = 7.0;
    a1.nacimiento.mes = 8;

    a2 = {123, "Pablo", {27,2,2000} ,8.5};

    Fecha f1 = {17,8,1994};
    a3 = {234, "Merlin", f1, 10};


    Producto almacen[10];

    almacen[0].codigo= 202;
    almacen[9].codigo= 909;
    
    almacen[1] = {303, "coca", 24, 48};
    
    almacen[4] = {505};
    
    for(int i=0; i<10; i++){
        mostrarP(almacen[i]);
    }

    /*int i = 5;
    i++;
    cout << i << endl;

    i = 5;
    ++i;
    cout << i << endl;

    i = 5;
    int x;

    x = ++i;
    cout << "i: " << i << endl;
    cout << "x: " << x << endl;

    i = 5;
    x = 0;

    x = i++;
    cout << "i: " << i << endl;
    cout << "x: " << x << endl;

    cout << "\nCiclo for\n";
    for(int i=0; i<5; ++i){
        cout <<"  " << i ;
    }

    cout << "\nCiclo do while\n";
    i = 0;
    do{
        ++i;
        cout << "  " << i;
    }while(i<5);
    cout << endl;*/
    return 0;
}

void mostrar(Alumno a){
    cout << "id: " << a.id;
    cout << "  nombre: " << a.nombre;
    cout << " promedio: " << a.promedio << endl;
}

void mostrarP(Producto p){
    cout << "Codigo: " << p.codigo << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Precio: " << p.precio << endl;
    cout << "Existencia: " << p.existencia << endl;
}

void anidado(Alumno a){
    cout << a.id << a.nombre << a.promedio;
    cout << a.nacimiento.dia << a.nacimiento.mes << a.nacimiento.anio;
}