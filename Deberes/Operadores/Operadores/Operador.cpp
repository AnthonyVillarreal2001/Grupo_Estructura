#include "Operador.h"

template<typename T>
Operador<T>::Operador() {
    valor = 0;
}

template<typename T>
Operador<T>::Operador(T valor) {
    this->valor = valor;
}

//template<typename T>
//Operador<T>::~Operador() {
//    // No se requiere ninguna limpieza especial en este caso
//}

template<typename T>
T Operador<T>::getValor() const {
    return valor;
}

//template<typename T>
//void Operador<T>::setValor(T valor) {
//    this->valor = valor;
//}

template<typename T>
Operador<T> Operador<T>::operator%(const Operador<T>& num) const {
    int result = valor % num.valor;
    return Operador(result);
}

template<typename T>
Operador<T> Operador<T>::operator^(const Operador<T>& num) const {
    int result = 1;
    for (int i = 0; i < num.valor; i++) {
        result *= valor;
    }
    return Operador(result);
}
