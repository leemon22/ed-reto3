#include <vector>
#include <assert.h>

using namespace std;

#ifndef RETO3_VECTORPILAS_H
#define RETO3_VECTORPILAS_H

/**
 * TDA VectorPilas
 *
 * Representa un vector con un número fijo de pilas.
 * Cada pila del vector tiene un tamaño fijo.
 *
 * @author Pedro Javier Pérez Jiménez
 * @author Pablo Reyes Sousa
 */
class VectorPilas{
private:

    typedef vector<int>::iterator iterador;

    /**
     * @brief Aquí guardamos los elementos de la pilas. Todo está contiguo en memoria.
     */
    vector<int> pilas;
    /**
     * @brief Vector que guarda las posiciones iniciales y finales de las pilas.
     */
    vector<iterador> base;
    /**
     * Vector que guarda las posiciones del tope de la pila.
     */
    vector<iterador> tope;

    /**
     * @brief Función auxiliar para copiar el vector pilas de otro VectorPilas en este VectorPilas y actualizar
     * los punteros con la nueva información.
     * @param other VectorPilas del que queremos copiar su contenido.
     * @pre El vector de pilas debe estar vacío.
     */
    void copiar(const VectorPilas &other);

    /**
     * @brief Elimina los datos de los vectores pilas, base y tope.
     */
    void eliminar();

public:

    /**
     * @brief Constructor donde se pasa por parámetros un vector con el tamaño de cada pila.
     * @param tamanios Vector donde tamanios[i] representa el tamaño de la pila en la posición i.
     * @pre tamanios[i] > 0, 0 <= i < tamanios.size()
     */
    VectorPilas(const vector<int> &tamanios);

    /**
     * @brief Constructor de copia.
     * @param other VectorPilas del que se copia su contenido.
     */
    VectorPilas(const VectorPilas &other);

    /**
     * @brief Sobrecarga del operador asignación.
     * @param other VectorPilas del que se copia su contenido.
     * @return *this para encadenar asignaciones.
     */
    VectorPilas &operator=(const VectorPilas &other);

    /**
     * @brief Tamaño del vector.
     * @return El número de pilas que hay en el vector.
     */
    int size() const{
        return tope.size();
    }

    /**
     * Tamaño de la pila i.
     * @param i Índice de la pila.
     * @return Tamaño de la pila de índice i.
     * @pre i >= 0 && i < size()
     */
    int stack_size(int i) const{
        assert(i >= 0 && i < size());
        return 1 + tope[i] - base[i];
    }

    /**
     * Tamaño máximo de la pila i.
     * @param i Índice de la pila.
     * @return Tamaño máximo de la pila de índice i.
     * @pre i >= 0 && i < size()
     */
    int max_stack_size(int i) const{
        assert(i >= 0 && i < size());
        return base[i + 1] - base[i];
    }

    /**
     * @brief Comprueba que la pila i está vacía.
     * @param i Índice de la pila que queremos comprobar.
     * @return True si la pila i está vacía.
     */
    bool empty(int i) const{
        assert(i >= 0 && i < size());
        return tope[i] < base[i];
    }

    /**
     * @brief Devuelve el tope de la pila i.
     * @param i Índice de la pila que queremos tomar su tope.
     * @return Tope de la pila i.
     */
    int &top(int i){
        assert(i >= 0 && i < size());
        assert(!empty(i));
        return *tope[i];
    }

    /**
     * @brief Devuelve el tope de la pila i.
     * @param i Índice de la pila que queremos tomar su tope.
     * @return Tope de la pila i.
     */
    const int &top(int i) const{
        assert(i >= 0 && i < size());
        assert(!empty(i));
        return *tope[i];
    }

    /**
     * @brief Intenta añadir un elemento en el tope de la pila i.
     * @param i Índice de la pila que queremos añadir un elemento en el tope.
     * @param n Elemento que queremos añadir al tope de la pila.
     * @return True si se ha conseguido añadir el elemento.
     * @post El elemento se añadirá al tope de la pila si esa pila no está llena.
     */
    bool push(int i, int n);

    /**
     * @brief Saca el elemento del tope de la pila i.
     * @param i Índice de la pila que queremos sacar el elemento del tope.
     * @pre La pila no está vacía.
     */
    void pop(int i);


};

#endif //RETO3_VECTORPILAS_H
