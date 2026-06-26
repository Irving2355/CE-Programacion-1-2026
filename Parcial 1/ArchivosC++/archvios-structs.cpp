#include <iostream>
#include <fstream>
using namespace std;

struct Alumno
{
    int id;
    char nombre[40];
    float promedio;
};


int main(){
    Alumno a1,a2[5];

    a1 = {123, "Maria", 8.5};

    a2[0] = {124, "Maria", 8.5};
    a2[1] = {125, "Maria", 8.5};
    a2[2] = {126, "Maria", 8.5};
    a2[3] = {127, "Maria", 8.5};
    a2[4] = {128, "Maria", 8.5};

    ofstream archivo("resgistro.txt", ios::app);
    if(!archivo){
        cout << "no se creo o abrio correctamente";
        return 1;
    }

    archivo << a1.id << " "
            << a1.nombre << " "
            << a1.promedio << endl;

    for(int i=0; i<5; i++){
        archivo << a2[i].id << " "
            << a2[i].nombre << " "
            << a2[i].promedio << endl;
    }
    return 0;
}