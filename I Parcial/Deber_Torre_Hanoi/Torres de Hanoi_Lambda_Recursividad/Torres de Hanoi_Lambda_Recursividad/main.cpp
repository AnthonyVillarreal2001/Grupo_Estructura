/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Uso de memoria estatica en matrices
Autores: Carlos Campoverde, Anthony Villarreal, Ariel Pozo
Fecha de creacion: 19/05/2023
Fecha de modificacion: 19/05/2023
9671 ESTRUCTURA DE DATOS
*/

#include <iostream>
#include "TorreHanoi.cpp"

int main() {
    int numDiscos;
    int torreInicio;
    int torreFinal;

    cout << "Ingresa el numero total de discos: ";
    cin >> numDiscos;

    cout << "Ingresa la Torre en la cual quieres que se inicie (1, 2, o 3): ";
    cin >> torreInicio;

    cout << "Ingresa la Torre en la cual quieres que se termine (1, 2, or 3): ";
    cin >> torreFinal;

    HanoiTower<int> hanoi(numDiscos, torreInicio, torreFinal);
    hanoi.resolver();

    cout << "Total moves: " << hanoi.getMovTotales() << endl;

    return 0;
}
