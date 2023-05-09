#include "Fraccion.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(int num, int den) {
    numerador = num;
    denominador = den;
}

Fraccion Fraccion::suma(Fraccion otra) {
    int nuevo_numerador = numerador * otra.denominador + denominador * otra.numerador;
    int nuevo_denominador = denominador * otra.denominador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

Fraccion Fraccion::resta(Fraccion otra) {
    int nuevo_numerador = numerador * otra.denominador - denominador * otra.numerador;
    int nuevo_denominador = denominador * otra.denominador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

Fraccion Fraccion::multiplicacion(Fraccion otra) {
    int nuevo_numerador = numerador * otra.numerador;
    int nuevo_denominador = denominador * otra.denominador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

Fraccion Fraccion::division(Fraccion otra) {
    int nuevo_numerador = numerador * otra.denominador;
    int nuevo_denominador = denominador * otra.numerador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

void Fraccion::simplificar() {
    int mcd = calcular_mcd(numerador, denominador);
    numerador /= mcd;
    denominador /= mcd;
}

void Fraccion::imprimir() {
    cout << numerador << "/" << denominador << endl;
}

int Fraccion::calcular_mcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return calcular_mcd(b, a % b);
    }
}
