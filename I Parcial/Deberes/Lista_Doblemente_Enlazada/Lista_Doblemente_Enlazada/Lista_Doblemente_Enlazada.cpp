/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Lista doblemente enlazada
Autores: Carlos Campoverde, Anthony Villarreal, Ariel Pozo
Fecha de creacion: 24/05/2023
Fecha de modificacion: 24/05/2023
9671 ESTRUCTURA DE DATOS
*/
#include <iostream>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

    Nodo(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoblementeEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr) {}

    ~ListaDoblementeEnlazada() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertarPorCabeza(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = cola = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    void insertarPorCola(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cola == nullptr) {
            cabeza = cola = nuevoNodo;
        }
        else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    void insertarEntreNodos(T valor, int posicion) {
        if (posicion <= 0 || cabeza == nullptr) {
            insertarPorCabeza(valor);
        }
        else {
            Nodo<T>* actual = cabeza;
            int contador = 1;
            while (actual && contador < posicion) {
                actual = actual->siguiente;
                contador++;
            }
            if (actual) {
                Nodo<T>* nuevoNodo = new Nodo<T>(valor);
                nuevoNodo->siguiente = actual->siguiente;
                nuevoNodo->anterior = actual;
                if (actual->siguiente) {
                    actual->siguiente->anterior = nuevoNodo;
                }
                actual->siguiente = nuevoNodo;
            }
            else {
                insertarPorCola(valor);
            }
        }
    }

    void imprimir() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

int main() {
    ListaDoblementeEnlazada<int> lista;

    lista.insertarPorCabeza(3);
    lista.insertarPorCabeza(2);
    lista.insertarPorCabeza(1);

    lista.insertarPorCola(4);
    lista.insertarPorCola(5);

    lista.insertarEntreNodos(10, 2);
    lista.insertarEntreNodos(8, 5);

    lista.imprimir();

    return 0;
}
