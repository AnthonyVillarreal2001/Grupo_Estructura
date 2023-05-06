#include "Division.h"

Division::Division(int num1, int num2) {
    this->num1 = num1;
    this->num2 = num2;
    this->resultado = static_cast<double>(num1) / static_cast<double>(num2);
}

double Division::obtenerResultado() {
    return resultado;
}