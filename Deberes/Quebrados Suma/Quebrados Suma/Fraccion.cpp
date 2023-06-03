#include "Fraccion.h"

template<typename T>
T Fraccion<T>::getNumerador(void)
{
	return numerador;
}

template<typename T>
void Fraccion<T>::setNumerador(T newNumerador)
{
	this->numerador = newNumerador;
}

template<typename T>
T Fraccion<T>::getDenominador(void)
{
	return denominador;
}

template<typename T>
void Fraccion<T>::setDenominador(T newDenominador)
{
	this->denominador = newDenominador;
}

template<typename T>
Fraccion<T>::Fraccion(T num, T den)
{
	// TODO : implement
	this->numerador = num;
	this->denominador = den;
}

template<typename T>
Fraccion<T>::~Fraccion()
{
	// TODO : implement
	numerador = 0;
	denominador = 1;
}