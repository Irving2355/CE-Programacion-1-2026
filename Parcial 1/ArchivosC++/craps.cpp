#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int tirarDado(){
    return rand() % 6 + 1;
}

int tirarDados(){
    int dado1, dado2, suma;

    dado1 = tirarDado();
    dado2 = tirarDado();
    suma = dado1 + dado2;

    cout << "Dado 1: " << dado1 << endl;
    cout << "Dado 2: " << dado2 << endl;
    cout << "Suma: " << suma << endl;

    return suma;
}

int main(){
    srand(time(0));

    int suma, punto, sigueJugando;
    cout << "Primer lanzamiento\n";
    suma = tirarDados();
    
    if(suma == 7 || suma == 11){
        cout << "Ganaste\n";
        sigueJugando = 0;
    }else if(suma == 2 || suma == 3 || suma == 12){
        cout << "Perdiste\n";
        sigueJugando = 2;
    }else{
        cout << "Punto\n";
        sigueJugando = 1;
        punto = suma;
    }

    while(sigueJugando == 1){
        cout << "\nDebes sacar " << punto <<" Antes de sacar 7 "<< endl;
        cout << "Presiona Enter para tirar...";
        cin.ignore();
        cin.get();

        suma = tirarDados();

        if(suma == punto){
            cout << "Ganaste\n";
            sigueJugando = 0;
        }else if(suma == 7){
            cout << "Perdiste\n";
            sigueJugando = 0;
        }else{
            cout << "Sigue la partida";
        }
    }
    return 0;
}