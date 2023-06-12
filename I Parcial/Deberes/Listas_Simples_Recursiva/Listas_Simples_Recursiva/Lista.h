#pragma once 
#include <iostream>
#include <stdio.h>
#include "Nodo.h"

using namespace std;

class Lista {
    public:
        Lista();
        void insertar(int);
        void insertarporcabeza(int);
        void insertarporcola(int);
        void imprimir();
        void imprimirporcabeza();
        void modificar(int);
        void buscar(int);
        void ordenar();
        void eliminarUltimo();
        void eliminarporCabeza();
        bool recursividadPrimo(int,int);
        void recursivaPrimo();
    private:
        Nodo* primero;
        Nodo* ultimo;
};