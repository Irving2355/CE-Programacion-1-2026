#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int *p = nullptr;

    // esto esta mal cout << "*p: " << *p << endl;

    if(p == nullptr){
        cout << "Puntero *p no apunta a nada\n";
    }

    //*p = &x; esto es erroneo
    p = &x;

    if (p != nullptr){
        cout << "Valor apuntado: " << *p << endl;
    }
    return 0;
}