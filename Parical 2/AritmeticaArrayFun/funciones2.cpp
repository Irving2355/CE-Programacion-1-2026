#include <iostream>
using namespace std;

void swap(int *a, int *b);

void calcular( int *datos, int n,
int *suma,
float *promedio,
int * mayor,
int *menor);

int main(){
    int x = 10;
    int y = 20;

    int aux;
    aux = x;
    x = y;
    y = aux;
    swap(x,y);

    cout << "X: " << x << " Y: " << y << endl;

    int datos[6] = {8,4,10,7,6,9};
    int suma = 0,mayor = 0,menor = 0;
    float promedio = 0;
    
    calcular(datos, 6, &suma, &promedio, &mayor, &menor);

    cout << "\nSuma: " << suma << endl;

    return 0;
}

void swap(int *a, int *b){
    int temporal;

    temporal = *a;
    *a = *b;
    *b = temporal;
}

void calcular( int *datos, int n,
int *suma,
float *promedio,
int * mayor,
int *menor){

    *mayor = *datos;
    *menor = *datos;

    for(int i=0; i<n; i++){
        *suma = *suma + *(datos + i);
        
        if(*(datos+i) > *mayor){
            *mayor = *(datos +i);
        }

        if(*(datos+i) < *menor){
            *menor = *(datos +i);
        }
    }

    *promedio = *suma/n;
}