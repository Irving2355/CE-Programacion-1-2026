#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

enum EastadoAlumno{
    ACTIVO,
    BAJA,
    EGRESADO,
    ESTADO_INVALIDO
};

enum TipoContacto{
    TELEFONO,
    CORREO,
    CONTACTO_INVALIDO
};

union Contacto{
    int telefono;
    char correo[40];
};

typedef struct
{
    int id;
    char nombre[40];
    float promedio;
    EastadoAlumno estado;
    TipoContacto tipoContacto;
    Contacto contacto;
}Alumno;


int main(int argc, char *argv[]){
    if(argc != 7){
        cout << "programa.exe id nombre promedio estado tipoContacto contacto\n";
        return 1;
    }

    Alumno alumno;

    alumno.id = atoi(argv[1]);
    strcpy(alumno.nombre, argv[2]);
    alumno.promedio = atof(argv[3]);

    if(!strcmp(argv[4], "activo")){
        alumno.estado = ACTIVO;
    }else if(!strcmp(argv[4], "baja")){
        alumno.estado = BAJA;
    }else if(!strcmp(argv[4], "egresado")){
        alumno.estado = EGRESADO;
    }else{
        alumno.estado = ESTADO_INVALIDO;
    }

    if(!strcmp(argv[5], "telefono")){
        alumno.tipoContacto = TELEFONO;
        alumno.contacto.telefono = atoi(argv[6]);
    }else if(!strcmp(argv[5], "correo")){
        alumno.tipoContacto = CORREO;
        strcpy(alumno.contacto.correo, argv[6]);
    }else{
        alumno.tipoContacto = CONTACTO_INVALIDO;
    }

    cout << "id: " << alumno.id << "\nnombre: " << alumno.nombre << "\npromedio: " << alumno.promedio << endl;
    cout << "Estado: ";
    switch (alumno.estado)
    {
    case ACTIVO:
        cout << "Activo";
        break;
    case BAJA:
        cout << "Baja";
        break;
    case EGRESADO:
        cout << "Egreseado";
        break;
    default:
        cout << "Invalido";
        break;
    }
    cout << endl;

    cout << "Contacto: ";
    if(alumno.tipoContacto == TELEFONO){
        cout << alumno.contacto.telefono << endl;
    }else if (alumno.tipoContacto == CORREO){
        cout << alumno.contacto.correo << endl;
    }else{
        cout << "Invalido\n";
    }
    return 0;
}