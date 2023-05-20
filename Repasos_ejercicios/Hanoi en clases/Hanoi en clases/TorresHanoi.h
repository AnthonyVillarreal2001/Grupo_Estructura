#pragma once
#ifndef TORRESHANOI_H
#define TORRESHANOI_H

#include <functional>

class TorresHanoi {
private:
    int numMovimientos;
    std::function<void(int, char, char, char)> resolverHanoi;

public:
    TorresHanoi();

    void resolver(int n, char inicio, char aux, char final);
    int obtenerNumMovimientos();
};

#endif