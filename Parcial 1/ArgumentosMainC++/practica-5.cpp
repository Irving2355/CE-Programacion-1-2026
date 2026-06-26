#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "uso correcto: "<<endl;
        cout << "Nombre.exe nombre edad promedio"<<endl;
        return 1;
    }

    cout << "nombre recibido: " << argv[1] << endl;
    cout << "edad: " <<argv[2]<<endl;
    cout << "promedio: "<<argv[3]<<endl; 
    
    return 0;
}