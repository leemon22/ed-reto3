#include <iostream>
#include <VectorPilas.h>
#include <vector>

using namespace std;

int main() {

    // Creo el vector de pilas
    vector<int> tamanios = {2,3,1};
    VectorPilas pilas(tamanios);

    // Añado elementos
    pilas.push(0,5);
    pilas.push(0,4);

    pilas.push(1,7);
    pilas.push(1,3);
    pilas.push(1,9);

    pilas.push(2,6);

    // Los saco
    for(int i = 0; i < pilas.size(); ++i){
        cout << endl << "Pila " << i << ": ";
        while (!pilas.empty(i)){
            cout << pilas.top(i) << " ";
            pilas.pop(i);
        }
    }


    return 0;
}