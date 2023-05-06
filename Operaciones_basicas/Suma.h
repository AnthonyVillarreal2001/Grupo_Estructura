#pragma once

class Suma {
public:
    Suma(int num1, int num2); // Constructor
    int obtenerResultado(); // Método para obtener la suma de los números
private:
    int num1;
    int num2;
    int resultado;
};