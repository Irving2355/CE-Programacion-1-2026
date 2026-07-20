#include <iostream>
using namespace std;

int main(){
    int datos[5] = {5,8,13,21,34};
    int *p = datos;

    cout << "\nDireccion de memoria de datos: " << &datos << endl;
    cout << "\nDireccion que guarda *p: " << p << endl;
    cout << "\nDireccion de datos[0]: " << &datos[0] << endl;

    cout << endl << endl;
    for(int i=0; i<5; i++){
        cout << "p + " << i << " = " << p+i << endl;
    }
    return 0;
}