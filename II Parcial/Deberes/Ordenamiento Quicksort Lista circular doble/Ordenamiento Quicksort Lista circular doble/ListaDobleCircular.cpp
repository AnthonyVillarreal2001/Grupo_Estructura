#include "ListaDobleCircular.h"

#include <iostream>
using namespace std;

template<typename T>
ListaDobleCircular<T>::ListaDobleCircular() {
    cabeza = nullptr;
}

template<typename T>
void ListaDobleCircular<T>::insertar(T valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>();
    nuevoNodo->dato = valor;

    if (cabeza == nullptr) {
        nuevoNodo->previo = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        cabeza = nuevoNodo;
    }
    else {
        Nodo<T>* ultimo = cabeza->previo;

        nuevoNodo->previo = ultimo;
        nuevoNodo->siguiente = cabeza;

        ultimo->siguiente = nuevoNodo;
        cabeza->previo = nuevoNodo;
    }

    cout << "Elemento insertado: " << valor << endl;
}

template<typename T>
void ListaDobleCircular<T>::eliminar(T valor) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;
    bool encontrado = false;

    do {
        if (actual->dato == valor) {
            encontrado = true;
            break;
        }

        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);

    if (encontrado) {
        if (actual == cabeza && actual->siguiente == cabeza) {
            // Solo hay un nodo en la lista
            cabeza = nullptr;
        }
        else if (actual == cabeza) {
            // El nodo a eliminar es la cabeza de la lista
            cabeza = actual->siguiente;
            cabeza->previo = actual->previo;
            actual->previo->siguiente = cabeza;
        }
        else {
            // El nodo a eliminar está en el medio o al final de la lista
            anterior->siguiente = actual->siguiente;
            actual->siguiente->previo = anterior;
        }

        delete actual;
        cout << "Elemento eliminado: " << valor << endl;
    }
    else {
        cout << "Elemento no encontrado." << endl;
    }
}

template<typename T>
void ListaDobleCircular<T>::buscar(T valor) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo<T>* actual = cabeza;
    bool encontrado = false;
    int posicion = 0;

    do {
        if (actual->dato == valor) {
            encontrado = true;
            break;
        }

        actual = actual->siguiente;
        posicion++;
    } while (actual != cabeza);

    if (encontrado) {
        cout << "Elemento encontrado en la posición " << posicion << "." << endl;
    }
    else {
        cout << "Elemento no encontrado." << endl;
    }
}

template<typename T>
void ListaDobleCircular<T>::mostrar() {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo<T>* actual = cabeza;

    do {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    } while (actual != cabeza);

    cout << endl;
}

template<typename T>
void ListaDobleCircular<T>::ordenar(bool ascendente) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    int tamaño = 0;
    Nodo<T>* actual = cabeza;

    do {
        tamaño++;
        actual = actual->siguiente;
    } while (actual != cabeza);

    T* arreglo = new T[tamaño];
    actual = cabeza;

    for (int i = 0; i < tamaño; i++) {
        arreglo[i] = actual->dato;
        actual = actual->siguiente;
    }

    quicksort(arreglo, 0, tamaño - 1);

    actual = cabeza;
    if (ascendente) {
        for (int i = 0; i < tamaño; i++) {
            actual->dato = arreglo[i];
            actual = actual->siguiente;
        }
    }
    else {
        for (int i = tamaño - 1; i >= 0; i--) {
            actual->dato = arreglo[i];
            actual = actual->siguiente;
        }
    }

    delete[] arreglo;
    cout << "Lista ordenada." << endl;
}

template<typename T>
int ListaDobleCircular<T>::particion(T arreglo[], int inicio, int fin) {
    T pivote = arreglo[fin];
    int pIndice = inicio;

    for (int i = inicio; i < fin; i++) {
        if (arreglo[i] <= pivote) {
            swap(arreglo[i], arreglo[pIndice]);
            pIndice++;
        }
    }

    swap(arreglo[pIndice], arreglo[fin]);

    return pIndice;
}

template<typename T>
void ListaDobleCircular<T>::quicksort(T arreglo[], int inicio, int fin) {
    if (inicio >= fin) {
        return;
    }

    int pivote = particion(arreglo, inicio, fin);

    quicksort(arreglo, inicio, pivote - 1);
    quicksort(arreglo, pivote + 1, fin);
}
