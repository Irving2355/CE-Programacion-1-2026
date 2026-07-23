// Comparacion de C++ y C para memoria dinamica {#ddf,9}
/*
Accion              C++                C
Reservar variable   new int         malloc(sizeof(int))
Liberar variable    delete          free
Reservar array      new int[n]      malloc(n*sizeof(int))
Iniciar en cero     Manualmente     calloc
Cambiar tamaño      Requiere crear  realloc
de un arreglo       otro arreglo
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n;
    cout << "Dame cantidad de datos: ";
    cin >> n;

    // reservemos la memoria {#54a,2}
    int *datos = nullptr;
    datos = (int*)malloc(n * sizeof(int));
    
    if(datos == nullptr){
        cout << "No se pudo reservar la memoria";
        return 1;
    }

    for(int i=0; i<n; i++){
        cout << "Dato: ";
        cin >> *(datos + i);
    }

    for(int i=0; i<n; i++){
        cout << *(datos + i) << " ";
    }
    cout << endl;

    free(datos);
    //delete[] datos;
    datos = nullptr;
    return 0;
}