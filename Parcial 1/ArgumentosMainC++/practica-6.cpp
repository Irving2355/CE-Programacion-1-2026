#include <iostream>
#include <cstdlib> //atoi y atof
/*
atoi convierte texto a entero
atof convierte texto a decimal
*/
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "uso correcto: "<<endl;
        cout << "Nombre.exe nombre edad promedio"<<endl;
        return 1;
    }

    int edad = atoi(argv[2]); //"22" a 22
    float promedio = atof(argv[3]); //"8.5" a 8.5

    if(edad > 18){
        cout << "Es un adulto\n";
    }else{
        cout << "Es menor\n";
    }
    if(promedio > 6.5){
        cout << "Paso la materia\n";
    }else{
        cout << "Reprobo\n";
    }
    return 0;
}