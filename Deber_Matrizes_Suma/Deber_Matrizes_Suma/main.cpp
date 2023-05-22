#include "Operaciones_Matriz.cpp"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    int filas, columnas;
    cout << "**********SUMA DE MATRICES**********" << endl;
    cout << "Ingrese la dimension de las matrices (filas columnas): " << endl;
    cin >> filas >> columnas;

    OperacionesMatriz<int> sm;
    // Segmentar matrices
    int** mat1 = sm.segmentar(filas, columnas);
    int** mat2 = sm.segmentar(filas, columnas);
    int** matR = sm.segmentar(filas, columnas);

    // Inicializar matrices
    sm.encerar(mat1, filas, columnas);
    sm.encerar(mat2, filas, columnas);
    sm.encerar(matR, filas, columnas);

    if (filas == columnas) {
        // Asignar valores a las matrices
        cout << "Ingrese los valores de la Matriz 1:" << endl;
        sm.ingresarValores(mat1, filas, columnas);
        cout << "Ingrese los valores de la Matriz 2:" << endl;
        sm.ingresarValores(mat2, filas, columnas);
        // Imprimir matrices resultantes
        cout << ("Matriz 1:") << endl;
        sm.imprimir(mat1, filas, columnas);
        cout << ("Matriz 2:") << endl;
        sm.imprimir(mat2, filas, columnas);
        // Sumar matrices recursivamente
        sm.sumaRecursivaMatrices(mat1, mat2, matR, filas - 1, columnas - 1);
        cout << ("Matriz Resultante Suma:") << endl;
        sm.imprimir(matR, filas, columnas);
    }
    else {
        cout << "Las matrices no tienen las mismas dimensiones. No se puede realizar la suma." << endl;
    }

    // Liberar memoria asignada dinámicamente previamente con la función malloc(), calloc(), o realloc(). 
    for (int i = 0; i < filas; i++) {
        free(*(mat1 + i));
        free(*(mat2 + i));
        free(*(matR + i));
    }
    free(mat1);
    free(mat2);
    free(matR);

    return 0;
}