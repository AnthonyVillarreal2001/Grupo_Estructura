#include "Resto_division.h"

Resto_division::Resto_division(int num1, int num2) {
    this->num1 = num1;
    this->num2 = num2;
    this->resultado = num1 % num2;
}

int Resto_division::obtenerResultado() {
    return resultado;
}