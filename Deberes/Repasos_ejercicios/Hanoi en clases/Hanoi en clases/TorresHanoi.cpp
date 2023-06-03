#include "TorresHanoi.h"
#include <iostream>
using namespace std;

TorresHanoi::TorresHanoi() {
    numMovimientos = 0;
    resolverHanoi = [this](int n, char inicio, char aux, char final) {
        if (n == 1) {
            cout << "Mover disco 1 de " << inicio << " a " << final << endl;
            numMovimientos++;
        }
        else {
            resolverHanoi(n - 1, inicio, final, aux);
            cout << "Mover disco " << n << " de " << inicio << " a " << final << endl;
            numMovimientos++;
            resolverHanoi(n - 1, aux, inicio, final);
        }
    };
}

void TorresHanoi::resolver(int n, char inicio, char aux, char final) {
    resolverHanoi(n, inicio, aux, final);
}

int TorresHanoi::obtenerNumMovimientos() {
    return numMovimientos;
}