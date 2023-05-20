#pragma once
#include "Cnodo.h"
#include <iostream>

class Clista{
    private:
        Cnodo *referencial;
        Cnodo *origen;
        bool ListaVacia(){
            return (this->origen==NULL);
        }
    public:
        Clista();
        virtual void insertarCab(int);
        virtual void insertarCol(int);
        virtual void imprimir();
        virtual void eliminarCab(int);
        virtual void eliminarCol(int);
        virtual void buscar(int);
        virtual int tamanioLista();
};