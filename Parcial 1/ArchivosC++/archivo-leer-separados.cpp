#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char nombre[40];
    int edad;
    float promedio;

    ifstream archivo("alumnos.txt");
    if(!archivo){
        cout << "No se abrio el archivo alumnos.txt";
        return 1;
    }

    cout << "\nAlumnos\n";

    while (archivo >> nombre >> edad >> promedio)
    {
        cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << endl;
        cout << "**********\n";
    }
    
    return 0;
}