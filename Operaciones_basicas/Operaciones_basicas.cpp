#include <iostream>
#include "Suma.h"
#include "Resta.h"
#include "Multiplicacion.h"
#include "Division.h"  
#include "Resto_division.h"
using namespace std;

int main()
{
    int num1, num2;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;

    Suma suma(num1, num2); // Crea un objeto de la clase Suma con los números ingresados
    cout << "La suma de " << num1 << " y " << num2 << " es: " << suma.obtenerResultado() << std::endl;
    Resta resta(num1, num2); // Crea un objeto de la clase Resta con los números ingresados
    cout << "La resta de " << num1 << " y " << num2 << " es: " << resta.obtenerResultado() << std::endl;
    Multiplicacion multiplicacion(num1, num2); // Crea un objeto de la clase Multiplicacion con los números ingresados
    cout << "La multiplicación de " << num1 << " y " << num2 << " es: " << multiplicacion.obtenerResultado() << std::endl;
    Division division(num1, num2); // Crea un objeto de la clase Division con los números ingresados
    cout << "La división de " << num1 << " y " << num2 << " es: " << division.obtenerResultado() << std::endl;
    Resto_division resto_division(num1, num2); // Crea un objeto de la clase Resto con los números ingresados
    cout << "El resto de la división de " << num1 << " y " << num2 << " es: " << resto_division.obtenerResultado() << std::endl;

    return 0;
}
