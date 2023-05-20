#include <iostream>
#include "Validacion.h"
#include "Calculos.cpp"
#include "Fraccion.cpp"
using namespace std;

int main() {
    Validacion validar;
    cout << "Ingrese el numerador de la primera fraccion: ";
    float num1 = validar.ingresarDatosfloat();
    cout << "Ingrese el denominador de la primera fraccion: ";
    float den1 = validar.ingresarDatosfloat();
    cout << "Ingrese el numerador de la segunda fraccion: ";
    float num2 = validar.ingresarDatosfloat();
    cout << "Ingrese la denominador de la segunda fraccion: ";
    float den2 = validar.ingresarDatosfloat();
    Fraccion<float> fraccion1(num1, den1);
    Fraccion<float> fraccion2(num2, den2);
    Calculos<float> operacion;
    Fraccion<float> resultado = operacion.calculo(fraccion1, fraccion2);
    float numResultado = resultado.getNumerador();
    float denResultado = resultado.getDenominador();
    cout << "El resultado es: " << numResultado << "/" << denResultado << endl;
    return 0;
}