#include <iostream>
#include <cstdlib>
using namespace std;

void menu();
void agregarNumero(int **datos, int*n, int nuevoValor);
void mostrarNumeros(int *datos, int n);
float calcularPromedio(int *datos, int n);
void liberarMemoria(int **datos, int *n);

int main(){
    int opcion;
    int n = 0;
    int valor;
    int *datos = nullptr;
    do
    {
        menu();
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cout << "Numero a agregar: ";
            cin >> valor;

            agregarNumero(&datos, &n, valor);
            break;
        
        case 2:
            mostrarNumeros(datos, n);
            break;
        
        case 3: 
            cout << "\nPromedio: " << calcularPromedio(datos,n) << endl;
            break;
        
        case 4:
            liberarMemoria(&datos, &n);
            cout << "\nMemoria liberada...\n";
            break;
        
        default:
            cout << "\nOpcion invalida\n";
        }
    } while (opcion != 5);
    
    return 0;
}

void menu(){
    cout << "\nLista dinamica\n";
    cout << "1. Agregar numero\n";
    cout << "2. Mostrar numeros\n";
    cout << "3. Calcular promedio\n";
    cout << "4. Liberar memoria\n";
    cout << "5. Salir.\n";
}

void agregarNumero(int **datos, int*n, int nuevoValor){
    int nuevoTamano = *n + 1;

    int *temporal = (int*)realloc(*datos, nuevoTamano * sizeof(int));

    *datos = temporal;

    *(*datos + *n) = nuevoValor;

    *n = nuevoTamano;
}

void mostrarNumeros(int *datos, int n){
    cout << "\nNumeros capturados: \n";
    for(int i=0; i<n; i++){
        cout << *(datos + i) << " ";
    }
    cout << endl;
}

float calcularPromedio(int *datos, int n){
    int suma = 0;

    for(int i=0; i<n; i++){
        suma = suma + *(datos + i);
    }

    return (float)suma/n;
}

void liberarMemoria(int **datos, int *n){
    if(*datos != nullptr){
        free(*datos);
        *datos = nullptr;
    }
    *n = 0;
}
