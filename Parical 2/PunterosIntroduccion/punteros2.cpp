#include <iostream>
using namespace std;

int main(){
    int edad = 20;
    float promedio = 9.4;
    char letra = 'A';

    int *pEdad = &edad;
    float *pPromedio = &promedio;
    char *pLetra = &letra;

    cout << "Edad: " << *pEdad << endl;
    cout << "Promedio: " << *pPromedio << endl;
    cout << "Letra: " << *pLetra << endl;

    *pEdad = 21;
    *pPromedio = 6.0;
    *pLetra = 'B';

    cout << "\nDespues de modificar\n";
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Letra: " << letra << endl;

    cout << "\nDirecciones de memoria originales\n";
    cout << "Edad: " << &edad << endl;
    cout << "Promedio: " << &promedio << endl;
    cout << "Letra: " << &letra << endl;
    return 0;
}