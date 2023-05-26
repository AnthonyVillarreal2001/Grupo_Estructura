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
