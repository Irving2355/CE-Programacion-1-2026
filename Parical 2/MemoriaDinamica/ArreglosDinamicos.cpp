#include <iostream>
using namespace std;

int main(){
    int n;
    int *datos = nullptr;

    cout << "Cantidad de datos: ";
    cin >> n;

    datos = new int[n];

    for(int i=0; i<n; i++){
        cout << "Dato " << i+1 << ": ";
        //cin >> datos[i];
        cin >> *(datos + i);
    }

    cout << "\nDatos capturados: "  << endl;
    for(int i=0; i<n; i++){
        //cout << datos[i] << " ";
        cout << *(datos + i) << " ";
    }

    delete[] datos;
    datos = nullptr;
    return 0;
}