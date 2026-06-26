#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_ALUMNOS = 50;

typedef struct{
    int id;
    char nombre[40];
    float promedio;
}Alumno;

int main(){
    Alumno alumnos[MAX_ALUMNOS];
    int n = 0;
    char nombreBuscar[40];
    int posicion = -1;

    ifstream archivo("registros.txt");
    if(!archivo){
        cout << "No se pudo abrir registros.txt";
        return 1;
    }

    while(n < MAX_ALUMNOS && 
            archivo >> alumnos[n].id
                    >> alumnos[n].nombre
                    >> alumnos[n].promedio)
    {
        n++;
    }
    archivo.close();

    /*cout << "Dame nombre a buscar: ";
    cin >> nombreBuscar;*/
    int id;
    cout << "Dame el id: ";
    cin >> id;

    for(int i=0; i<n; i++){
        /*if(strcmp(alumnos[i].nombre, nombreBuscar) == 0){
            posicion = i;
            break;
        }*/
        if(alumnos[i].id == id){
            posicion = i;
            break;
        }
    }

    if(posicion != -1){
        cout << "\nAlumno encontrado en posicion: " << posicion << endl;
    }else{
        cout << "\nAlumno no encontrado\n";
    }
    return 0;
}