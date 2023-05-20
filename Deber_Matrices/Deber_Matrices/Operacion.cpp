#include "Operacion.h"
#include <iostream>
#include <stdio.h>

using namespace std;

template<typename T>
bool Operacion<T>::validacion(T columnasA, T filasB) {
	if (columnasA == filasB)
		return true;
	else
		return false;
}

template<typename T>
T** Operacion<T>::segmentar(T filas, T columnas) {
	T** mat, j;
	mat = (int**)malloc(filas * sizeof(*mat));
	for (j = 0; j < filas; j++) {
		*(mat + j) = (int*)malloc(columnas * sizeof(int));
	}
	return mat;
}

template<typename T>
void Operacion<T>::encerar(T** mat, T filas, T columnas) {
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			*(*(mat + i) + j) = 0;
}

template<typename T>
void Operacion<T>::multiplicacion(T** matriz1, T** matriz2, T** matrizResultante, T filasA, T columnasA, T colmnasB, T filasB) {
	encerar(matrizResultante, filasA, colmnasB);
	if (validacion(columnasA, filasB)) {
		for (int i = 0; i < filasA; i++) {
			for (int j = 0; j < colmnasB; j++) {
				for (int h = 0; h < columnasA; h++) {
					*(*(matrizResultante + i) + j) = *(*(matrizResultante + i) + j) + *(*(matriz1 + i) + h) * (*(*(matriz2 + h) + j));
				}
			}
		}
		cout << "\n";
		imprimir(matrizResultante, filasA, colmnasB);
	}
	else {
		cout << "Las matrices no son compatibles para multiplicacion.\n";
	}

}

template<typename T>
void Operacion<T>::ingresar(T** mat, T filas, T columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			scanf_s("%d", &(*(*(mat + i) + j)));
		}
	}
}

template<typename T>
void Operacion<T>::imprimir(T** matriz, T filas, T columnas)
{
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			printf("%d", *(*(matriz + i) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}