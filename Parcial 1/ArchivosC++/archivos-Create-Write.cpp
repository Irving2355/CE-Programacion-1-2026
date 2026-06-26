//crear y escribir un archivo
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream archivo("salida.txt");

    if(!archivo){
        cout << "No se pudo crear o abrir";
        return 1;
    }

    archivo << "Hola mundo" << endl;
    archivo << "Curso especial Prog 1" << endl;
    archivo << "Se uso la libreria fstream" << endl;

    archivo.close();
    return 0;
}