#include <iostream>
#include <VectorPilas.h>
#include <vector>

using namespace std;

int main() {

    // Creo el vector de pilas
    vector<int> tamanios = {2,3,1};
    VectorPilas pilas(tamanios);

    // Añado elementos

    cout << endl << "Añado elementos a las pilas:" << endl;
    for(int i = 0; i < 9; ++i){
        if(pilas.push(i%3,i))
            cout << "Elemento " << i << " insertado en la pila " << i%3 << endl;
        else
            cout << "Elemento " << i << " no insertado en la pila " << i%3 << endl;
    }


    // Los saco
    cout << endl << "Saco elementos de las pilas:";
    for(int i = 0; i < pilas.size(); ++i){
        cout << endl << "Pila " << i << ": ";
        while (!pilas.empty(i)){
            cout << pilas.top(i) << " ";
            pilas.pop(i);
        }
    }


    return 0;
}