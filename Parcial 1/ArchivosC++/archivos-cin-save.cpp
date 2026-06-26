#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char nombre[40];
    int edad;
    float promedio;

    cout << "Nombre:";
    cin >> nombre;
    cout << "Edad:";
    cin >> edad;
    cout << "Promedio:";
    cin >> promedio;

    ofstream file("alumno.txt");
    if(!file){
        cout << "No se creo";
        return 1;
    }

    file << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << endl;

    cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << endl;

    return 0;
}