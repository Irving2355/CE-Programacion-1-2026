#include <iostream>
using namespace std;

int main(){
    int *numero = nullptr;
    cout << "\nDespues de nullptr: " << numero << endl;
    //cout << "\nDespues de nullptr con *: " << *numero << endl;
    
    //reservamos la memoria
    numero = new int;
    cout << "\nDespues del new int: " << numero << endl;
    cout << "\nDespues del new int con *: " << *numero << endl;

    //guardamos un valor en la memoria
    *numero = 25;

    cout << "\nDireccion guradada en numero: " << numero << endl;

    cout << "\nValor guardado: " << *numero << endl;

    delete numero;
    numero = nullptr;

    cout << "\nDespues de nullptr: " << numero << endl;
    return 0;
}