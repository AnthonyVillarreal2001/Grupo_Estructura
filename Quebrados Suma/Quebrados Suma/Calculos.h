#pragma once
#include "Proceso.h"
#include "Fraccion.h"

template<typename T>
class Calculos : Proceso<T> {
public:
    Fraccion<T> calculo(Fraccion<T> obj1, Fraccion<T> obj2);
    T calculo(T obj1, T obj2);
};