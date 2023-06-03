#pragma once
class Division
{
public:
    Division(int num1, int num2); // Constructor
    double obtenerResultado(); // Método para obtener la división de los números
private:
    int num1;
    int num2;
    double resultado;
};

