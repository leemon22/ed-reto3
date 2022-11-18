#include <iostream>
#include <list>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;

/**
 * @author Pedro Javier Pérez Jiménez
 * @author Pablo Reyes Sousa
 */

/**
 * @brief Functor que nos servirá para ordenar las pilas dependiendo de que su elemento en la posición superior
 * sea menor o mayor.
 */
class LessStack {
public:

    /**
     * @brief Sobrecarga del operador () para el functor.
     * @param s1 Primera pila
     * @param s2 Segunda pila
     * @return True si el elemento al tope de la primera pila es menor que el de la segunda. False en caso contrario
     * @pre Ninguna pila está vacía.
     */
    bool operator()(const stack<int>s1, const stack<int>s2) {

        // Ordenamos las pilas por el primer elemento.
        return s1.top() < s2.top();
    }
};

/**
 * @brief Función que elimina el entero que se pase como parámetro del tope de las pilas de la lista que se le pase y las reordena de menor a mayor.
 * @param L La lista de pilas
 * @param elemento Entero a borrar del tope de las pilas.
 */
void Borrar(list<stack<int>> &L, int elemento) {

    // Usamos un bucle para borrar los elementos coincidentes del tope de las pilas.
    // Además, borramos las listas vacías.
    list<stack<int>>::iterator it = L.begin();

    while (it != L.end())
        if(it->empty())
            it = L.erase(it);
        else if (it->top() == elemento)
            if(it->size() == 1)
                it = L.erase(it);
            else{
                it->pop();
                ++it;
            }
        else
            ++it;

    // Por último, utilizamos el functor descrito anteriormente como método de ordenación de la lista de pilas.
    L.sort(LessStack());
}

int main() {
    // Datos del ejemplo que viene en el pdf.
    list<stack<int>> lista;
    stack<int> pilas[4];
    pilas[0].push(1);
    pilas[0].push(9);
    pilas[0].push(2);
    pilas[1].push(0);
    pilas[1].push(1);
    pilas[1].push(2);
    pilas[2].push(2);
    pilas[3].push(7);
    pilas[3].push(10);
    pilas[3].push(9);
    pilas[3].push(3);

    // Se añade las pilas a la lista
    for (int i = 0; i < 4; ++i) {
        lista.push_back(pilas[i]);
    }

    // Función implementada
    Borrar(lista, 2);

    // Mostramos los elementos en el tope de las pilas ya ordenadas.
    for (list<stack<int>>::iterator i = lista.begin(); i != lista.end(); ++i) {
        if(!i->empty()) cout << i->top() << endl;
    }

    return 0;
}
