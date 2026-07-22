#include <iostream>
using namespace std;

int pedirCantidad();
void capturarDatos(int *datos, int n);
void mostrar(int *datos, int n);
int sumarDatos(int *datos, int n);

int main(){
    int n;
    int *datos = nullptr;
    int suma;

    n = pedirCantidad();

    datos = new int[n];
    capturarDatos(datos, n);
    mostrar(datos,n);
    suma = sumarDatos(datos,n);
    cout << "\nSuma: " << suma << endl;
    return 0;
}

int pedirCantidad(){
    int n; 

    do{
        cout << "Cantidad de datos: ";
        cin >> n;

        if(n <= 0){
            cout << "La cantidad debe de ser mayor a 0" << endl;
        }
    }while (n <= 0);
    
    return n;
}

void capturarDatos(int *datos, int n){
    for(int i=0; i<n; i++){
        cout << "Dato:";
        cin >> *(datos + i);
    }
}

void mostrar(int *datos, int n){
    cout << "\nDatos: ";
    for(int i=0; i<n; i++){
        cout << *(datos + i) << " "; 
    }
    cout << endl;
}

int sumarDatos(int *datos, int n){
    int suma = 0;
    for(int i=0; i<n; i++){
        suma = suma + *(datos + i);
    }
    return suma;
}