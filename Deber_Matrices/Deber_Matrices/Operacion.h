#pragma once

template<typename T>
class Operacion {
public:

	
	T** segmentar(T, T);
	
	void multiplicacion(T**, T**, T**, T, T, T, T);
	
	void imprimir(T**, T, T);
	
	bool validacion(T, T);
	
	void ingresar(T**, T, T);

	
	void encerar(T**, T, T);
}; 
