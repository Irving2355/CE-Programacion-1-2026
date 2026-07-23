#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int tamanoInicial = 3;
    int tamanoFinal = 6;
    int *datos = nullptr;
    int *temporal = nullptr;

    datos = (int*)malloc(tamanoInicial * sizeof(int));

    for(int i=0; i<tamanoInicial; i++){
        *(datos + i) = ((i*3+1)/4)*10;
    }

    // Redimension de vector {#375,9}
    temporal = (int*)realloc(datos, tamanoFinal * sizeof(int));

    datos = temporal;
    free(temporal);
    temporal = nullptr;

    for(int i=0; i<tamanoFinal; i++){
        cout << *(datos + i) << " ";
    }
    cout << endl;
    return 0;
}