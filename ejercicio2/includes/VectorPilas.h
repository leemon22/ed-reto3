#include <vector>
#include <assert.h>

using namespace std;

#ifndef RETO3_VECTORPILAS_H
#define RETO3_VECTORPILAS_H

class VectorPilas{
private:

    typedef vector<int>::iterator iterador;

    vector<int> pilas;
    vector<iterador> base;
    vector<iterador> tope;

    void copiar(const VectorPilas &other);
    void eliminar();

public:

    VectorPilas(const vector<int> &tamanios);
    VectorPilas(const VectorPilas &other);
    VectorPilas &operator=(const VectorPilas &other);

    int size() const{
        return tope.size();
    }

    int stack_size(int i) const{
        assert(i >= 0 && i < size());
        return 1 + tope[i] - base[i];
    }

    bool empty(int i) const{
        assert(i >= 0 && i < size());
        return tope[i] == base[i];
    }
    int &top(int i){
        assert(i >= 0 && i < size());
        return *tope[i];
    }
    const int &top(int i) const{
        assert(i >= 0 && i < size());
        return *tope[i];
    }

    bool push(int i, int n);
    void pop(int i);


};

#endif //RETO3_VECTORPILAS_H
