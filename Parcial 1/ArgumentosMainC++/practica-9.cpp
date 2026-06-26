#include <iostream>
#include <cstring>
using namespace std;

enum EstadoAlumno{
    ACTIVO,
    BAJA,
    EGRESADO,
    DESCONOCIDO
};

int main(int argc, char *argv[]){
    EstadoAlumno estado;

    if(strcmp(argv[1], "activo") == 0){
        estado = ACTIVO;
    }else if(strcmp(argv[1], "baja") == 0){
        estado = BAJA;
    }else if(strcmp(argv[1], "egresado") == 0){
        estado = EGRESADO;
    }else{
        estado = DESCONOCIDO;
    }

    switch(estado){
        case ACTIVO:
        cout << "Activo";
        break;
        case BAJA:
        cout << "Baja";
        break;
        case EGRESADO:
        cout << "Egresado";
        break;
        default:
        cout << "Desconocido";
    }
    return 0;
}