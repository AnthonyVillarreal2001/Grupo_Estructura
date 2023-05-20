#pragma once
#include <iostream>
using namespace std;

class Cmenu{
    public:
        void menuPrincipal();
        char *ingresarDatosEnteros(char *msj);
        char *ingresarDatosFlotantes(char *);
        /*char *ingresarChar(char *msj);*/
    private:
        int opcion=0;
	    char dato[10],dato1[10],dato2[10],dato3[10],dato4[10],dato5[10],dato6[10];
};