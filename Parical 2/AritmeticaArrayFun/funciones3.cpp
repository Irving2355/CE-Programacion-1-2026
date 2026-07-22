#include <iostream>
using namespace std;

void mostrar(float *calificaciones, int n);
void agregarPuntos(float *calificaciones, int n,
float puntosExtra,
int *modificadas);

int main(){
    float calificaciones[6] = {6.5,7.2,9.0,5.8,8.1,6.9};
    int modificadas = 0;

    cout << "Antes de modificar: " << endl;
    mostrar(&calificaciones, 6);

    agregarPuntos(calificaciones, 6, 0.5, &modificadas);

    cout << "\nDespues de modificar: " << endl;
    mostrar(calificaciones, 6);

    cout << "\nCalificaciones modificadas: " << modificadas <<endl;
    return 0;
}

void mostrar(float *calificaciones, int n){
    for(int i=0; i<n; i++){
        cout << *(calificaciones + i) << " ";
    }
    cout << endl;
}

void agregarPuntos(float *calificaciones, int n,
float puntosExtra,
int *modificadas){
    *modificadas = 0;
    for(int i=0; i<n; i++){
        if(*(calificaciones + i) < 10){
            *(calificaciones + i) += puntosExtra;

            if(*(calificaciones + i) > 10){
                *(calificaciones + i) = 10;
            }
            *modificadas++;
        }
    }
}