#include "TorreHanoi.h"

template<typename T>
void HanoiTower<T>::setNumDiscos(T num) {
    numDiscos = num;
}

template<typename T>
T HanoiTower<T>::getNumDiscos() const {
    return numDiscos;
}

template<typename T>
void HanoiTower<T>::resolver() {
    if (torreInicio == torreFinal) {
        cout << "Error: Torre Inicial y Torre final son iguales. Porfavor deben ser diferentes." << endl;
        return;
    }

    function<void(T, T, T, T)> moverDiscos = [&](T n, T inicio, T aux, T finalT) {
        if (n > 0) {
            moverDiscos(n - 1, inicio, finalT, aux);
            cout << "Mover disco " << n << " desde la torre " << inicio << " hasta la torre " << finalT << endl;
            totalMoves++;
            moverDiscos(n - 1, aux, inicio, finalT);
        }
    };

    moverDiscos(numDiscos, torreInicio, 6 - torreInicio - torreFinal, torreFinal);
}

template<typename T>
T HanoiTower<T>::getMovTotales() const {
    return totalMoves;
}

template<typename T>
HanoiTower<T>::~HanoiTower() {}