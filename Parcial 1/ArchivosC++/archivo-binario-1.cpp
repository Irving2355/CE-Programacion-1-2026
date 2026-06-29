#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int numero = 25;

    ofstream archivo("numero.dat", ios::binary);
    //archivo de escritura

    if(!archivo){
        cout << "No se pudo crear el archivo";
        return 1;
    }

    archivo.write(reinterpret_cast<const char*> (&numero), sizeof(numero));
    archivo.close();

    ifstream archivo1("numero.dat", ios::binary);
    int leido;
    archivo1.read(reinterpret_cast<char *>(&leido), sizeof(leido));

    archivo1.close();

    cout << "Numero leido: "<<leido<<endl;
    return 0;
}