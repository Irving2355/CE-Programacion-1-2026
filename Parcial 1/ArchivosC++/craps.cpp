#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum EstadoPartida{
    NUEVA,//0
    JUGANDO_PUNTO,//1
    GANO,//2
    PERDIO//3
};

struct Partida
{
    char jugador[30];
    int saldo;
    int apuesta;
    int punto;
    int rondas;
    EstadoPartida estado;
};


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

int pedirApuesta(int saldo){
    int apuesta;

    do{
        cout << "Saldo actual $"<<saldo<<endl;
        cout << "Ingresa tu apuesta: ";
        cin >> apuesta;

        if(apuesta <= 0){
            cout << "La apuesta debe de ser mayor a 0\n";
        }

        if(apuesta > saldo){
            cout << "La apuesta no puede ser mayor al saldo\n";
        }
    }while(apuesta <= 0 || apuesta > saldo);

    return apuesta;
}

Partida crearPartida(){
    Partida variablePartida;
    cout << "Nombre del jugador: ";
    cin.getline(variablePartida.jugador, 30);
    variablePartida.saldo = 1000;
    variablePartida.apuesta = 0;
    variablePartida.punto = 0;
    variablePartida.rondas = 0;
    variablePartida.estado = NUEVA;

    return variablePartida;
}

void mostrarPartida(Partida variableInterna){
    cout << endl;
    cout << "Jugador: " << variableInterna.jugador << endl;
    cout << "Saldo: " << variableInterna.saldo << endl;
    cout << "Apuesta: " << variableInterna.apuesta << endl;
    cout << "Punto: " << variableInterna.punto << endl;
    cout << "Rondas: " << variableInterna.rondas << endl;
}

int main(){
    srand(time(0));

    int suma, punto;
    int saldo, apuesta;
    EstadoPartida estado;

    punto = 0;
    //sigueJugando = 1;
    estado = NUEVA;
    saldo = 1000;

    apuesta = pedirApuesta(saldo);

    cout << "Primer lanzamiento\n";
    suma = tirarDados();
    
    if(suma == 7 || suma == 11){
        saldo = saldo + apuesta;
        cout << "Ganaste $"<<apuesta<<endl;
        //sigueJugando = 0;
        estado = GANO;
    }else if(suma == 2 || suma == 3 || suma == 12){
        saldo = saldo - apuesta;
        cout << "Perdiste $"<<apuesta<<endl;
        //sigueJugando = 2;
        estado = PERDIO;
    }else{
        cout << "Punto\n";
        //sigueJugando = 1;
        estado = JUGANDO_PUNTO;
        punto = suma;
    }

    while(/*sigueJugando == 1*/ estado = JUGANDO_PUNTO){
        cout << "\nDebes sacar " << punto <<" Antes de sacar 7 "<< endl;
        cout << "Presiona Enter para tirar...";
        cin.ignore();
        cin.get();

        suma = tirarDados();

        if(suma == punto){
            saldo = saldo + apuesta;
            cout << "Ganaste\n";
            //sigueJugando = 0;
            estado = GANO;
        }else if(suma == 7){
            saldo -= apuesta;
            //saldo = saldo - apuesta;
            cout << "Perdiste\n";
            //sigueJugando = 0;
            estado = PERDIO;
        }else{
            cout << "Sigue la partida";
            estado = JUGANDO_PUNTO;
        }
    }

    cout << "\nSaldo final: $"<<saldo<<endl;
    return 0;
}