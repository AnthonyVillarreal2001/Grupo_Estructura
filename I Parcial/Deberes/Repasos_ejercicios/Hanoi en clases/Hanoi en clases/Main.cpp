#include "TorresHanoi.h"
#include <iostream>
using namespace std;

int main() {
    int numDiscos;
    cout << "Ingrese el número de discos: ";
    cin >> numDiscos;

    TorresHanoi hanoi;
    hanoi.resolver(numDiscos, 'A', 'B', 'C');

    cout << "Se resolvieron las Torres de Hanoi en " << hanoi.obtenerNumMovimientos() << " movimientos." << endl;

    return 0;
}