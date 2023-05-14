#pragma once
#include "Proceso.h"
#include "Fraccion.h"

template<typename T>
class Calculos : Proceso<T> {
public:
    Fraccion<T> calculo(Fraccion<T> obj1, Fraccion<T> obj2);
    T calculo(T obj1, T obj2);
};
//
//template<typename T>
//Fraccion<T> Calculos<T>::calculo(Fraccion<T> obj1, Fraccion<T> obj2) {
//    float num1 = obj1.getNumerador();
//    float den1 = obj1.getDenominador();
//    float num2 = obj2.getNumerador();
//    float den2 = obj2.getDenominador();
//    float numResultado = (num1 * den2) + (den1 * num2);
//    float denResultado = den1 * den2;
//    Fraccion<T> resultado(numResultado, denResultado);
//    return resultado;
//}
//
//template<typename T>
//T Calculos<T>::calculo(T obj1, T obj2) {
//    return obj1 + obj2;
//}