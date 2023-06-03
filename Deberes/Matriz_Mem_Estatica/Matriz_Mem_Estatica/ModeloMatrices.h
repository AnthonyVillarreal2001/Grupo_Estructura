#pragma once
#define TAM 100
class ModeloMatrices
{
public:
   virtual void sumaMatriz(int vect1[][TAM],int vect[][TAM],int filas, int columnas)=0;
   virtual void multMatriz(int vect1[][TAM],int vect[][TAM],int filas, int columnas)=0;
   virtual void imprimir(int [][TAM],int,int)=0;
   virtual void crearMatriz(int [TAM][TAM],int,int)=0;
   virtual void ingresarDatosMatriz()=0;
   virtual int ingresarEnteros(void)=0;

protected:
private:

};