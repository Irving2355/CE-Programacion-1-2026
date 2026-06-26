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
                n = pedirCantidadProductos();
                llenarInventario(inventario, n);
                break;

            case 2:
                // Aqui se mostrara el inventario
                mostrarInventario(inventario, n);
                break;

            case 3:
                // Aqui se buscara un producto por codigo
                cout << "Dame el codigo: ";
                int codigo;
                cin >> codigo;
                int existe = buscarProductoPorCodigo(inventario, n, codigo);
                if(existe == 1){
                    cout << "Si existe";
                }else{
                    cout << "No esta";
                }
                break;

            case 4:
                // Aqui se mostrara el reporte
                mostrarReporte(inventario, n);
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
    int n;

    do{
        cout << endl << "Dame la cantidad de productos: ";
        cin >> n;

        if(n <= 0 || n > MAX_PRODUCTOS){
            cout << "\nCantidad invalida. Debe de estar entre 1 y " << MAX_PRODUCTOS << endl;
        }
    }while(n <= 0 || n > MAX_PRODUCTOS);
    return n;
}

bool precioValido(float precio) {
    bool verificar;
    if(precio >= 0){
        verificar = true;
    }else{
        verificar = false;
    }
    return verificar;
    //return precio >= 0;
}

bool existenciaValida(int existencia) {
    return existencia >= 0;
}

void capturarProducto(Producto inventario[], int indice) {
    do{
        cout << "Codigo: ";
        cin >> inventario[indice].codigo;

        if(inventario[indice].codigo <= 0){
            cout << "El codigo debe de ser mayor a 0\n";
        }
    }while(inventario[indice].codigo <= 0);

    do{
        cout << "Precio: ";
        cin >> inventario[indice].precio;

        if(!precioValido(inventario[indice].precio)){
            cout << "El precio es invalido";
        }
    }while(!precioValido(inventario[indice].precio));

    do{
        cout << "Existencia: ";
        cin >> inventario[indice].existencia;

        if(!existenciaValida(inventario[indice].existencia)){
            cout << "Existencia invalida mayor a 0";
        }
    }while(!existenciaValida(inventario[indice].existencia));

    cout << "Nombre producto: ";
    cin >> inventario[indice].nombre;
}

void llenarInventario(Producto inventario[], int n) {
    for(int i=0; i<n; i++){
        cout << "\nProducto " << i+1 << endl;
        capturarProducto(inventario, i);
    }
}

void mostrarProducto(Producto p) {
    cout << "Codigo: " << p.codigo << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Precio: " << p.precio << endl;
    cout << "Existencia: " << p.existencia << endl;
    cout << "Valor en inventario: " << calcularValorProducto(p) << endl;
}

void mostrarInventario(Producto inventario[], int n) {
    cout << "Inventario: \n";
    for(int i=0; i<n; i++){
        mostrarProducto(inventario[i]);
    }
}

float calcularValorProducto(Producto p) {
    float total;
    total = p.precio * p.existencia;
    return total;
}

int buscarProductoPorCodigo(Producto inventario[], int n, int codigo) {
    for(int i=0; i<n; i++){
        if(inventario[i].codigo == codigo){
            return 1;
        }
    }
    return -1;
}

int contarAgotados(Producto inventario[], int n) {
    int contador = 0;
    for(int i=0; i<n; i++){
        if(inventario[i].existencia == 0){
            contador++; //contador = contador + 1; contador += 1;
        }
    }
    return contador;
}

int obtenerIndiceMayorValor(Producto inventario[], int n) {
    int indice = 0;
    float mayorValor = calcularValorProducto(inventario[0]);

    for(int i=1; i<n; i++){
        float valorActual = calcularValorProducto(inventario[i]);

        if(valorActual > mayorValor){
            mayorValor = valorActual;
            indice = i;
        }
    }
    return indice;
}

void mostrarReporte(Producto inventario[], int n) {
    int agotados = contarAgotados(inventario, n);
    int indiceMayor = obtenerIndiceMayorValor(inventario, n);

    cout << "<\nReporte";
    cout << "Cantidad de productos: " << n << endl;
    cout << "Productos agotados: " << agotados << endl;
    cout << "Producto con mayor valor " << endl; 
    mostrarProducto(inventario[indiceMayor]);

}