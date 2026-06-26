#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char liena[120];

    ifstream archivo("alumno.txt");
    if(!archivo){
        cout << "No se pudo abrir alumno.txt";
        return 1;
    }

    cout << "Contenido del archvio\n";

    while (archivo.getline(liena, 120))
    {
        cout << liena << endl;
    }
    
    return 0;
}