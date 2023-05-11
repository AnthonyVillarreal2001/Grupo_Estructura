#include "Fraccion.h"

float Fraccion::getNumerador(void)
{
   return numerador;
}

void Fraccion::setNumerador(float newNumerador)
{
   this->numerador = newNumerador;
}

float Fraccion::getDenominador(void)
{
   return denominador;
}

void Fraccion::setDenominador(float newDenominador)
{
   this->denominador = newDenominador;
}

Fraccion::Fraccion(float num, float den)
{
   // TODO : implement
   this->numerador=num;
   this->denominador=den;
}

Fraccion::~Fraccion()
{
   // TODO : implement
	numerador = 0;
	denominador = 1;
}
