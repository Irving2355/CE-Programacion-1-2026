/*
Curso Especial de Programacion I
Clase 2: Struct y arreglos de estructuras
*/

#include <iostream>
using namespace std;

const int MAX_PRODUCTOS = 30;

struct Producto {
int codigo;
char nombre[30];
float precio;
int existencia;
};

// Prototipos
int pedirCantidadProductos();
bool precioValido(float precio);
bool existenciaValida(int existencia);
void capturarProducto(Producto inventario[], int indice);
void llenarInventario(Producto inventario[], int n);
void mostrarProducto(Producto p);
void mostrarInventario(Producto inventario[], int n);
float calcularValorProducto(Producto p);
float calcularValorTotal(Producto inventario[], int n);
int buscarProductoPorCodigo(Producto inventario[], int n, int codigo);
int contarAgotados(Producto inventario[], int n);
int obtenerIndiceMayorValor(Producto inventario[], int n);
void mostrarReporte(Producto inventario[], int n);

int main() {
    Producto inventario[MAX_PRODUCTOS];
    int n = 0;
    int opcion;
    bool datosCapturados = false;


    do {
        cout << "\nMenu" << endl;
        cout << "1. Capturar inventario" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "4. Mostrar reporte" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Aqui se pedira la cantidad y se llenara el arreglo
                break;

            case 2:
                // Aqui se mostrara el inventario
                break;

            case 3:
                // Aqui se buscara un producto por codigo
                break;

            case 4:
                // Aqui se mostrara el reporte
                break;

            case 5:
                cout << "\nSaliendo del programa..." << endl;
                break;

            default:
                cout << "\nOpcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;

}

int pedirCantidadProductos() {
return 0;
}

bool precioValido(float precio) {
return true;
}

bool existenciaValida(int existencia) {
return true;
}

void capturarProducto(Producto inventario[], int indice) {

}

void llenarInventario(Producto inventario[], int n) {

}

void mostrarProducto(Producto p) {

}

void mostrarInventario(Producto inventario[], int n) {

}

float calcularValorProducto(Producto p) {
return 0;
}

float calcularValorTotal(Producto inventario[], int n) {
return 0;
}

int buscarProductoPorCodigo(Producto inventario[], int n, int codigo) {
return -1;
}

int contarAgotados(Producto inventario[], int n) {
return 0;
}

int obtenerIndiceMayorValor(Producto inventario[], int n) {
return -1;
}

void mostrarReporte(Producto inventario[], int n) {

}