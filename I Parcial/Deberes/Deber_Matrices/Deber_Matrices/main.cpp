/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Deber Multiplicacion de Matrices
Autores: Carlos Campoverde, Anthony Villarreal, Ariel Pozo
Fecha de creacion: 19/05/2023
Fecha de modificacion: 19/05/2023
9671 ESTRUCTURA DE DATOS
*/

#include "Operacion.h"
#include "Operacion.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int filasA, filasB, columnasA, columnasB;

	cout << "Ingrese el numero de filas para la matriz A: ";
	cin >> filasA;
	cout << "Ingrese el numero de columnas para la matriz A: ";
	cin >> columnasA;
	cout << "Ingrese el numero de filas para la matriz B: ";
	cin >> filasB;
	cout << "Ingrese el numero de columnas para la matriz B: ";
	cin >> columnasB;

	int** matriz1;
	int** matriz2;
	int** matrizResultante;
	Operacion<int> op;

	// Asignar memoria a matriz1 y matriz2
	matriz1 = op.segmentar(filasA, columnasA);
	matriz2 = op.segmentar(filasB, columnasB);

	// Inicializar las matrices con ceros
	op.encerar(matriz1, filasA, columnasA);
	op.encerar(matriz2, filasB, columnasB);
	cout << "***************Ingrese la MATRIZ A***************" << endl;
	op.ingresar(matriz1, filasA, columnasA);
	cout << "				Matriz A:				" << endl;
	op.imprimir(matriz1, filasA, columnasA);


	cout << "***************Ingrese la MATRIZ B***************" << endl;
	op.ingresar(matriz2, filasB, columnasB);
	cout << "				Matriz B:				" << endl;
	op.imprimir(matriz2, filasB, columnasB);
	matrizResultante = op.segmentar(filasA, columnasB);

	cout << "				Resultado				" << endl;
	op.multiplicacion(matriz1, matriz2, matrizResultante, filasA, columnasA, columnasB, filasB);

	return 0;
}
