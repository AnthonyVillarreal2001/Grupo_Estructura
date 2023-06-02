#include "Fraccion.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Fraccion::Fraccion() {
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int numerador, int denominador) {
    if (denominador == 0) {
        throw invalid_argument("El denominador no puede ser cero.");
    }
    this->numerador = numerador;
    this->denominador = denominador;
    simplificar();
}

int Fraccion::getNumerador() const {
    return numerador;
}

void Fraccion::setNumerador(int numerador) {
    this->numerador = numerador;
    simplificar();
}

int Fraccion::getDenominador() const {
    return denominador;
}

void Fraccion::setDenominador(int denominador) {
    if (denominador == 0) {
        throw invalid_argument("El denominador no puede ser cero.");
    }
    this->denominador = denominador;
    simplificar();
}

void Fraccion::simplificar() {
    int divisorComun = gcd(numerador, denominador);
    numerador /= divisorComun;
    denominador /= divisorComun;
    if (denominador < 0) {
        numerador *= -1;
        denominador *= -1;
    }
}

Fraccion Fraccion::operator+(const Fraccion& f2) const {
    int nuevoDenominador = denominador * f2.denominador;
    int nuevoNumerador = numerador * f2.denominador + f2.numerador * denominador;
    return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::operator-(const Fraccion& f2) const {
    int nuevoDenominador = denominador * f2.denominador;
    int nuevoNumerador = numerador * f2.denominador - f2.numerador * denominador;
    return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::operator*(const Fraccion& f2) const {
    int nuevoNumerador = numerador * f2.numerador;
    int nuevoDenominador = denominador * f2.denominador;
    return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::operator/(const Fraccion& f2) const {
    int nuevoNumerador = numerador * f2.denominador;
    int nuevoDenominador = denominador * f2.numerador;
    if (nuevoDenominador == 0) {
        throw overflow_error("El resultado de la división es una fracción con denominador cero.");
    }
    return Fraccion(nuevoNumerador, nuevoDenominador);
}

void Fraccion::imprimir() const {
    cout << numerador << "/" << denominador;
}