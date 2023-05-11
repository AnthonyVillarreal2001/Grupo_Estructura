#include <iostream>
#include "Fraccion.h"
#include "Proceso.h"
using namespace std;

class SumaFracciones : public Proceso {
public:
    Fraccion calculo(Fraccion obj1, Fraccion obj2) {
        float num1 = obj1.getNumerador();
        float den1 = obj1.getDenominador();
        float num2 = obj2.getNumerador();
        float den2 = obj2.getDenominador();
        float numResultado = (num1 * den2) + (den1 * num2);
        float denResultado = den1 * den2;
        Fraccion resultado(numResultado, denResultado);
        return resultado;
    }
    float calculo(float obj1, float obj2) {
        return obj1 + obj2;
    }
};

int main() {
    float num1, den1, num2, den2;
    cout << "Ingrese la primera fraccion: ";
    cin >> num1 >> den1;
    cout << "Ingrese la segunda fraccion: ";
    cin >> num2 >> den2;
    Fraccion fraccion1(num1, den1);
    Fraccion fraccion2(num2, den2);
    SumaFracciones operacion;
    Fraccion resultado = operacion.calculo(fraccion1, fraccion2);
    float numResultado = resultado.getNumerador();
    float denResultado = resultado.getDenominador();
    cout << "El resultado es: " << numResultado << "/" << denResultado << endl;
    return 0;
}