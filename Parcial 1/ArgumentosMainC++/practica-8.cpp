#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Alumno
{
    int id;
    char nombre[40];
    float promedio;
};


int main(int argc, char *argv[]){
    Alumno alumno;
    
    alumno.id = atoi(argv[1]);
    //alumno.nombre = argv[2]; esto esta mal
    strcpy(alumno.nombre, argv[2]);
    alumno.promedio = atof(argv[3]);

    cout << "id: " << alumno.id << "\nnombre: " << alumno.nombre << "\npromedio: " << alumno.promedio << endl;
    return 0;
}