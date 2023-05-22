#include "Operaciones_Matriz.h"
#include <conio.h>

//char* ingresarDatosEnteros(char* msj) { //Puntero sinónimo de arreglo
//    char* dato = new char[30], c; //New instancia (fusionar o enlazar una clase con otra)
//    int i = 0;
//    printf("%s ", msj);
//    while ((c = _getch()) != 13) {
//        if (c >= '0' && c <= '9') {
//            printf("%c", c);
//            dato[i++] = c;
//        }
//        else if (c == 8 || c == 127) {
//            printf("\b \b");
//            dato[i--] = 0;
//        }
//    }
//    dato[i] = '\0';
//    return dato;
//}

template<typename T>
void OperacionesMatriz<T>::ingresarValores(T** matriz, T filas, T columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> *(*(matriz + i) + j);
        }
    }
}

template<typename T>
void OperacionesMatriz<T>::encerar(T** matriz, T filas, T columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = 0;
        }
    }
}

template<typename T>
T** OperacionesMatriz<T>::segmentar(T filas, T columnas) {
    int** matriz = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        *(matriz + i)= (int*)malloc(columnas * sizeof(int));
    }
    return matriz;
}

template<typename T>
void OperacionesMatriz<T>::imprimir(T** matriz, T filas, T columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

template<typename T>
void OperacionesMatriz<T>::sumaRecursivaMatrices(T** mat1, T** mat2, T** matR, T f, T c) {
    if ((f >= 0) && (c >= 0)) {
        *(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
        sumaRecursivaMatrices(mat1, mat2, matR, f - 1, c);
        sumaRecursivaMatrices(mat1, mat2, matR, f, c - 1);
    }
}

//template<typename T>
//void OperacionesMatriz<T>::multiplicacionRecursivaMatrices(T** mat1, T** mat2, T** matR, T f, T c, T k) {
//    if ((f >= 0) && (c >= 0) && (k >= 0)) {
//        *(*(matR + f) + c) += *(*(mat1 + f) + k) * *(*(mat2 + k) + c);
//        multiplicacionRecursivaMatrices(mat1, mat2, matR, f, c, k - 1);
//        multiplicacionRecursivaMatrices(mat1, mat2, matR, f, c - 1, k);
//        multiplicacionRecursivaMatrices(mat1, mat2, matR, f - 1, c, k);
//    }
//}
