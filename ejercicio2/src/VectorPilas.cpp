#include <vector>
#include <assert.h>
#include <VectorPilas.h>

using namespace std;

void VectorPilas::copiar(const VectorPilas &other) {

    // Eliminamos los datos que tenemos
    eliminar();

    // Copiamos la información del vector de pilas de other
    pilas = other.pilas;

    // Añadimos nueva información en los vectores iteradores
    base.push_back(pilas.begin());
    for(int i = 0; i < other.tope.size(); ++i){
        tope.push_back(base[i] + (other.tope[i] - other.base[i]));
        base.push_back(base[i] + (other.base[i+1] - other.base[i]));
    }
}

void VectorPilas::eliminar() {
    pilas.clear();
    tope.clear();
    base.clear();
}

VectorPilas::VectorPilas(const vector<int> &tamanios) {

    // Creamos el vector de pilas
    int total = 0;
    for(int i : tamanios)
        total += i;
    pilas.resize(total,0);

    // Creamos los vectores iteradores
    base.push_back(pilas.begin());
    for(int i : tamanios){
        tope.push_back(base.back() - 1);
        base.push_back(base.back() + i);
    }
}

VectorPilas::VectorPilas(const VectorPilas &other) {

    // Copiamos la información de other a pilas
    copiar(other);
}

VectorPilas &VectorPilas::operator=(const VectorPilas &other) {
    if(&other != this)
        copiar(other);
    return *this;
}

bool VectorPilas::push(int i, int n) {

    assert(i >= 0 && i < size());

    if(tope[i] >= base[i+1] - 1)
        return false;

    *++tope[i] = n;

    return true;
}

void VectorPilas::pop(int i) {

    assert(i >= 0 && i < size());

    if(tope[i] >= base[i])
        --tope[i];
}