#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 4){
        cout << "\nUso correcto:\n";
        cout << "Operadores: suma, resta, mult, div\n";
        cout << "programa.exe numero1 operador numero2\n";
    }

    float a = atof(argv[1]);
    float b = atof(argv[3]);

    if(strcmp(argv[2], "suma") == 0){
        cout << "Resultado: " << a+b << endl;
    }else if(strcmp(argv[2], "resta") == 0){
        cout << "Resultado: " <<a-b << endl;
    }else if(strcmp(argv[2], "mult") == 0){
        cout << "Resultado: " <<a*b << endl;
    }else{
        cout << "Resultado: " <<a/b << endl;
    }
    return 0;
}