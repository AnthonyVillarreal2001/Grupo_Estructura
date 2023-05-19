#include <iostream>
#include "Operador.cpp"
using namespace std;

int main() {
	int valor1, valor2;

	cout << "Ingrese el valor 1: ";
	cin >> valor1;

	cout << "Ingrese el valor 2: ";
	cin >> valor2;

	Operador<int> num1(valor1);
	Operador<int> num2(valor2);

	Operador<int> modResult = num1 % num2;
	Operador<int> powResult = num1 ^ num2;

	cout << "Resultado de la operacion: "<< num1.getValor()<<" % "<<num2.getValor() << " es: " << modResult.getValor() << endl;
	cout << "Resultado de la operacion: "<< num1.getValor()<<" ^ "<<num2.getValor() <<" es: "<< powResult.getValor() << endl;

	return 0;
}