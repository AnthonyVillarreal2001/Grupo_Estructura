#pragma once

class Suma {
public:
    Suma(int num1, int num2); // Constructor
    int obtenerResultado(); // M�todo para obtener la suma de los n�meros
private:
    int num1;
    int num2;
    int resultado;
};