#include <iostream>
#include "Calculos.h"
using namespace std;

int main() {
    float num1, den1, num2, den2;
    cout << "Ingrese la primera fraccion: ";
    cin >> num1 >> den1;
    cout << "Ingrese la segunda fraccion: ";
    cin >> num2 >> den2;
    Fraccion<float> fraccion1(num1, den1);
    Fraccion<float> fraccion2(num2, den2);
    Calculos<float> operacion;
    Fraccion<float> resultado = operacion.calculo(fraccion1, fraccion2);
    float numResultado = resultado.getNumerador();
    float denResultado = resultado.getDenominador();
    cout << "El resultado es: " << numResultado << "/" << denResultado << endl;
    return 0;
}