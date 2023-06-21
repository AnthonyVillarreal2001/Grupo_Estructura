#pragma once
template<typename T>
struct Nodo {
    T dato;
    Nodo<T>* previo;
    Nodo<T>* siguiente;
};

template<typename T>
class ListaDobleCircular {
private:
    Nodo<T>* cabeza;

public:
    ListaDobleCircular();
    void insertar(T valor);
    void eliminar(T valor);
    void buscar(T valor);
    void mostrar();
    void ordenar(bool ascendente);

private:
    int particion(T arreglo[], int inicio, int fin);
    void quicksort(T arreglo[], int inicio, int fin);
};