#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n = 5;
    
    int *a = (int*)malloc(n * sizeof(int));
    int *b = (int*)calloc(n, sizeof(int));

    cout << "\nValores reservados con malloc: \n";
    for(int i=0; i<n; i++){
        cout << *(a + i) << " ";
    }

    cout << "\nValores reservados con calloc: \n";
    for(int i=0; i<n; i++){
        cout << *(b + i) << " ";
    }
    cout << endl;
    
    return 0;
}