#include "Resta.h"

Resta::Resta(int num1, int num2) {
    this->num1 = num1;
    this->num2 = num2;
    this->resultado = num1 - num2;
}

int Resta::obtenerResultado() {
    return resultado;
}