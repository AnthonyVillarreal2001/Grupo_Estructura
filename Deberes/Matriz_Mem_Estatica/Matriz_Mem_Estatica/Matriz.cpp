#include "Matriz.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define TAM 100
using namespace std;


int Matriz::getFilas(void)
{
   return filas;
}


void Matriz::setFilas(int newFilas)
{
   filas = newFilas;
}

int Matriz::getColumnas(void)
{
   return columnas;
}

int Matriz::getOpcion(void)
{
   return opcion;
}


void Matriz::setOpcion(int newOpcion)
{
   opcion = newOpcion;
}

void Matriz::setColumnas(int newColumnas)
{
   columnas = newColumnas;
}

Matriz::Matriz()
{
}


Matriz::~Matriz()
{
   // TODO : implement
}



void Matriz::sumaMatriz(int vect1[][TAM],int vect[][TAM],int filas, int columnas){
	int vect3[TAM][TAM];
     
    for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			vect3[i][j]=vect1[i][j]+vect[i][j];
		}
	}
	imprimir(vect3,getFilas(),getColumnas());
}


void Matriz::multMatriz(int vect1[][TAM],int vect[][TAM],int filas, int columnas){
	int vect3[TAM][TAM];
    
    for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			vect3[i][j]=0;
			for(int k=0;k<columnas;k++){
				vect3[i][j]+=vect1[i][k]*vect[k][j];
			}
		}
			
	}
	imprimir(vect3,getFilas(),getColumnas());
}

void Matriz::imprimir(int vect[][TAM] ,int filas,int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<vect[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void Matriz::crearMatriz( int matriz[TAM][TAM],int filas, int columnas){
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero: ["<< i+1<<","<< j+1<<"]"<<endl;
			matriz[i][j] = ingresarEnteros();
			cout<<"\n";
		}
	}
	cout<<"\n";
}


void Matriz::ingresarDatosMatriz(){
	
	int numeros[50][50];
	int filas, columnas,opcion;
	do{
		cout<<"------------------SUMA Y MULTIPLICACION DE MATRICES---------------"<<endl;
		cout<<"1. Suma Matrices"<<endl;
		cout<<"2. Multiplicacion de matrices "<<endl;
		opcion=ingresarEnteros();
		if(opcion<1 || opcion>2){
			cout<<"\nIngrese una opcion correcta"<<endl;
		
			system("PAUSE");
			system("CLS");
		}
	}while(opcion<1 || opcion>2 );
		setOpcion(opcion);
		
	do{
		cout<<"\t\tMatrices cuadradas"<<endl;
		cout<<"TAMANIO DE MATRIZ A Y B"<<endl;
		cout<<"Numero de filas: ";
		filas=ingresarEnteros();
		cout<<"\nNumero de columnas: ";
		columnas=ingresarEnteros();
		cout<<"\n";
		if(filas<0 ||columnas<0 ){
			system("CLS");
		}
		if( columnas!=filas){
			cout<<"LAS FILAS Y COLUMNAS DE LAS MATRICES NO CORRESPONDEN A UNA CUADRATICA"<<endl;
			cout<<"ingrese nuevamente"<<endl;
			system("PAUSE");
			system("CLS");
		}
	}while(columnas<0 || filas<0 || columnas!=filas );
		setFilas(filas);
		setColumnas(columnas);
		
}


int Matriz::ingresarEnteros() {
	char *dato=new char[10];
	int i=0;
	int numero;
	char c;
	while((c=_getch())!=13){
		
		if(c>='0' && c<='9' || c==45){
			
			dato[i++]=c;
			printf("%c",c);
			numero = atoi(dato);
				
		}else if(c==8){
		
			dato[i]=0;
			i--;
				
			putchar(8);
			putchar(32);
			putchar(8);			
		}
	}
	dato[i]='\0';
	return numero;
}









   
   
   
   