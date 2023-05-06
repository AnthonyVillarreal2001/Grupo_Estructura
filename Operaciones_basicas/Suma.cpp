#include "Suma.h"

Suma::Suma(int num1, int num2) {
    this->num1 = num1;
    this->num2 = num2;
    this->resultado = num1 + num2;
}

int Suma::obtenerResultado() {
    return resultado;
}