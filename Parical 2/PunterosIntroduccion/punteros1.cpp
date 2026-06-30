#include <iostream>
using namespace std;

int main(){
    int x = 5;
    int *y = &x;
    cout << endl << x << endl << &x << endl; 

    cout << "Variable Y\n";
    cout << y << endl << &y << endl << *y << endl;

    x = 10;
    cout << "Variable Y\n";
    cout << y << endl << &y << endl << *y << endl;

    *y = 1;
    cout << "\nValor de X: " << x << endl;
    return 0;
}