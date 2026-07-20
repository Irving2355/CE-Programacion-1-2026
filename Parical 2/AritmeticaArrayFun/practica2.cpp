#include <iostream>
using namespace std;

int main(){
    int datos[5] = {5,8,13,21,34};
    int *p = datos;

    for(int i=0; i<5; i++){
        cout << "p + " << i << " = " << p+i << endl;
        cout << "Valor *(p + " << i <<"): " << *(p+i)<<endl << endl;
    }

    *(p + 0) = 10;
    *(p + 2) = 30;
    *(p + 4) = 50;

    for(int i=0; i<5; i++){
        cout << datos[i] << " ";
    }

    cout << "\n puntero con ++ \n";
    for(int i=0; i<5; i++){
        cout << "Valor *(p + " << i <<"): " << *(p++)<<endl << endl;
    }
    cout << "\nDireccion final de p: " << p << endl;
    cout << "\nValor de *p: " << *p << endl;

    p = &datos[0];
    //p = datos;
    //p = p - 5;  

    cout << "\nDireccion de p: " << p << endl;
    cout << "\nValor de *p: " << *p << endl;
    return 0;
}