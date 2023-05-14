#pragma once

template<typename T>
class Fraccion
{
public:
	T getNumerador(void);
	void setNumerador(T newNumerador);
	T getDenominador(void);
	void setDenominador(T newDenominador);
	Fraccion(T num, T den);
	~Fraccion();

protected:
private:
	T numerador;
	T denominador;

};

//template<typename T>
//T Fraccion<T>::getNumerador(void)
//{
//	return numerador;
//}
//
//template<typename T>
//void Fraccion<T>::setNumerador(T newNumerador)
//{
//	this->numerador = newNumerador;
//}
//
//template<typename T>
//T Fraccion<T>::getDenominador(void)
//{
//	return denominador;
//}
//
//template<typename T>
//void Fraccion<T>::setDenominador(T newDenominador)
//{
//	this->denominador = newDenominador;
//}
//
//template<typename T>
//Fraccion<T>::Fraccion(T num, T den)
//{
//	// TODO : implement
//	this->numerador = num;
//	this->denominador = den;
//}
//
//template<typename T>
//Fraccion<T>::~Fraccion()
//{
//	// TODO : implement
//	numerador = 0;
//	denominador = 1;
//}