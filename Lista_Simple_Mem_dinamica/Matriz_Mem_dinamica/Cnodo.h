#pragma once
#include <iostream>
using namespace std;

class Cnodo{
    private:
        int entrada;
        Cnodo *siguiente;
    public:
        Cnodo(int, Cnodo *siguiente);
        Cnodo() {};
        ~Cnodo();
        int getEntrada();
        Cnodo *getSiguiente();
        void setEntrada(int);
        void setSiguiente(Cnodo *siguiente);
};