#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Matriz.h"
#define TAM 100
using namespace std;

int main(){
	int M1[TAM][TAM];
	int M2[TAM][TAM];
	int opcion;
	Matriz matriz;
	matriz.ingresarDatosMatriz();
	cout<<"Matriz A: "<<endl;
	matriz.crearMatriz(M1,matriz.getFilas(),matriz.getColumnas());
	matriz.imprimir(M1,matriz.getFilas(),matriz.getColumnas());
	cout<<"Matriz B: "<<endl;
	matriz.crearMatriz(M2,matriz.getFilas(),matriz.getColumnas());
	matriz.imprimir(M2,matriz.getFilas(),matriz.getColumnas());
	if(matriz.getOpcion()==1){
		cout<<"---------------------------------"<<endl;
		cout<<"\nLA SUMA DE LA MATRIZ A Y B ES: "<<endl;
		matriz.sumaMatriz(M1,M2,matriz.getFilas(),matriz.getColumnas());
		system("PAUSE");
		system("CLS");
		return main(); 
	}else if(matriz.getOpcion()==2){
		cout<<"-------------------------------------------"<<endl;
		cout<<"\nLA MULTIPLICACION DE LA MATRIZ A Y B ES: "<<endl;
		matriz.multMatriz(M1,M2,matriz.getFilas(),matriz.getColumnas());
		system("PAUSE");
		system("CLS");
		return main(); 
	}
	
	return 0;
}