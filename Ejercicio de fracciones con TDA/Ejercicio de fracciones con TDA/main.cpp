/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Fracciones en TDA
Autores: Carlos Campoverde, Anthony Villarreal, Ariel Pozo
Fecha de creacion: 19/05/2023
Fecha de modificacion: 19/05/2023
9671 ESTRUCTURA DE DATOS
*/

#include <iostream>
#include "Fraccion.h"

using namespace std;

int main() {
    int numerador1, denominador1, numerador2, denominador2;

    cout << "Ingrese la primera fraccion: ";
    cin >> numerador1 >> denominador1;
    Fraccion f1(numerador1, denominador1);

    cout << "Ingrese la segunda fraccion: ";
    cin >> numerador2 >> denominador2;
    Fraccion f2(numerador2, denominador2);

    Fraccion suma = f1 + f2;
    Fraccion resta = f1 - f2;
    Fraccion producto = f1 * f2;
    Fraccion division;
    try {
        division = f1 / f2;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    cout << "Suma: ";
    suma.imprimir();
    cout << endl;

    cout << "Resta: ";
    resta.imprimir();
    cout << endl;

    cout << "Producto: ";
    producto.imprimir();
    cout << endl;

    cout << "Division: ";
    division.imprimir();
    cout << endl;

    return 0;
}
