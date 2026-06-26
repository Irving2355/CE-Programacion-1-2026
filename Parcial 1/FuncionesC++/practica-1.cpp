#include <iostream>

using namespace std;

const int MAX_ALUMNOS = 50;

int pedirCantidadAlumnos();

bool calificacionValida(float calificacion);
//calificacion entre 0 y 10
void llenarCalificaciones(float calificaciones[], int n);
//usa calificacionValida para llenar el vector de calificaciones

float calcularPromedio(float calificaciones[], int n);

float obtenerMayor(float calificaciones[], int n);
float obtenerMenor(float calificaciones[], int n);

void mostrarReporte(float calificaciones[], int n);
//mostrar la cantidad de aprobados y reprobados
//mostrar la mayor y menor calificacion

//la calificacion minima es 6.5
int contarAprobados(float calificaciones[], int n);
int contarReprobados(float calificaciones[], int n);

int main(){
    cout << "Sitema de calificaciones" << endl;
    float calificaciones[MAX_ALUMNOS];
    int n, opcion;
    bool datosCapturados = false; 

    /*
    for (int i=0; i<5; i++) ->
    (dato inicicial; condicion; aumento)
    while (i<5) -> (condicion)
    do-while hace y despues (condicion)
    */

    do
    {
        /* code */
        cout << endl << "Escribe del 1 al 4 una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            /* code */
            cout << "\nCaptura calificaciones.\n";
            break;
        case 2:
            cout << "\nMostrar calificaciones.\n";
            break;
        case 3:
            cout << "\nReporte calificaciones.\n";
            break;
        case 4:
            cout << "\nSaliendo del sistema.\n";
            break;
        default:
            cout << "\nOpcion invalida\n";
        }
    } while (opcion != 4);
    

    return 0;
}

int pedirCantidadAlumnos(){
    int n;

    do{
        cout << "\nIngresa la cantidad de alumnos: ";
        cin >> n;

        if (n <= 0 || n > MAX_ALUMNOS){
            cout << "Cantidad invalida debe de ser entre 1 y " << MAX_ALUMNOS << "." << endl;
        }
    }while(n <= 0 || n > MAX_ALUMNOS);

    return n;
}

float obtenerMayor(float calificaciones[], int n){
    float mayor = calificaciones[0];
    for(int i=1; i<n; i++){
        if(mayor <= calificaciones[i]){
            mayor = calificaciones[i];
        }
    }

    return mayor;
}

float obtenerMenor(float calificaciones[], int n){
    float menor = calificaciones[0];
    for(int i=1; i<n; i++){
        if(menor >= calificaciones[i]){
            menor = calificaciones[i];
        }
    }

    return menor;
}