#include <iostream>
using namespace std;

int main(){
    int numeros[6] = {2,4,6,8,10,12};
    int *p = numeros;

    for(int i=0; i<6; i++){
        *(p+i) = *(p+i)*3;
        //numeros[i] = numeros[i]*3;
    }
    return 0;
}