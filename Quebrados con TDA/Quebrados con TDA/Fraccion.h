#pragma once

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int num, int den);
    Fraccion suma(Fraccion otra);
    Fraccion resta(Fraccion otra);
    Fraccion multiplicacion(Fraccion otra);
    Fraccion division(Fraccion otra);
    void simplificar();
    void imprimir();

private:
    int calcular_mcd(int a, int b);
};