#pragma once
#include <iostream>
using namespace std;

template<typename T>
class OperacionesMatriz {
public:
    void ingresarValores(T** matriz, T f, T c);
    void encerar(T** matriz, T filas, T c);
    T** segmentar(T f, T c);
    void imprimir(T** matriz, T f, T c);
    void sumaRecursivaMatrices(T** mat1, T** mat2, T** matR, T f, T c);
    /*void multiplicacionRecursivaMatrices(T** mat1, T** mat2, T** matR, T f, T c, T k);*/
private:
    T** mat;
};