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