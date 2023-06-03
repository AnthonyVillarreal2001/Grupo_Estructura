#pragma once

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion();
    Fraccion(int numerador, int denominador);
    int getNumerador() const;
    void setNumerador(int numerador);
    int getDenominador() const;
    void setDenominador(int denominador);
    void simplificar();
    Fraccion operator+(const Fraccion& f2) const;
    Fraccion operator-(const Fraccion& f2) const;
    Fraccion operator*(const Fraccion& f2) const;
    Fraccion operator/(const Fraccion& f2) const;
    void imprimir() const;
};