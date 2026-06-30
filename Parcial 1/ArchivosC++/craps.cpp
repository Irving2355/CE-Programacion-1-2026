#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

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

void guardarHistorial(Partida partida){
    ofstream archivo;

    archivo.open("historial_craps.txt", ios::app);

    if(archivo.is_open()){
        archivo << "Jugador: " << partida.jugador
        << " Rondas: " << partida.rondas
        << " Apuesta: " << partida.apuesta
        << " Saldo final: " << partida.saldo;

        if(partida.estado == GANO){
            archivo << " Resultado: GANO";
        }else if(partida.estado == PERDIO){
            archivo << " Resultado: PERDIO";
        }
        archivo << endl;
        archivo.close();
    }
}

int main(){
    srand(time(0));
    Partida partida;

    partida = crearPartida();

    int suma;
    /*int suma, punto, saldo, apuesta;
    EstadoPartida estado;*/

    //punto = 0;
    //estado = NUEVA;
    //saldo = 1000;

    //apuesta = pedirApuesta(saldo);
    partida.apuesta = pedirApuesta(partida.saldo);

    cout << "Primer lanzamiento\n";
    suma = tirarDados();
    partida.rondas += 1; 
    
    if(suma == 7 || suma == 11){
        //saldo = saldo + apuetsa;
        partida.saldo = partida.saldo + partida.apuesta;
        cout << "Ganaste $"<<partida.apuesta<<endl;
        //sigueJugando = 0;
        partida.estado = GANO;
        guardarHistorial(partida);
    }else if(suma == 2 || suma == 3 || suma == 12){
        partida.saldo = partida.saldo - partida.apuesta;
        cout << "Perdiste $"<<partida.apuesta<<endl;
        //sigueJugando = 2;
        partida.estado = PERDIO;
        guardarHistorial(partida);
    }else{
        cout << "Punto\n";
        partida.estado = JUGANDO_PUNTO;
        partida.punto = suma;
    }

    while(/*sigueJugando == 1*/ partida.estado == JUGANDO_PUNTO){
        cout << "\nDebes sacar " << partida.punto <<" Antes de sacar 7 "<< endl;
        cout << "Presiona Enter para tirar...";
        cin.ignore();
        cin.get();

        suma = tirarDados();
        partida.rondas += 1;

        if(suma == partida.punto){
            partida.saldo = partida.saldo + partida.apuesta;
            cout << "Ganaste\n";
            //sigueJugando = 0;
            partida.estado = GANO;
            guardarHistorial(partida);
        }else if(suma == 7){
            partida.saldo -= partida.apuesta;
            //saldo = saldo - apuesta;
            cout << "Perdiste\n";
            //sigueJugando = 0;
            partida.estado = PERDIO;
            guardarHistorial(partida);
        }else{
            cout << "Sigue la partida";
            partida.estado = JUGANDO_PUNTO;
        }
    }

    //cout << "\nSaldo final: $"<<saldo<<endl;
    mostrarPartida(partida);
    return 0;
}