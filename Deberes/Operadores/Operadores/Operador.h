#pragma once

template<typename T>
class Operador {
private:
	T valor;

public:
	Operador();                  // Constructor predeterminado
	Operador(T valor);         // Constructor con parámetro
	//~Operador();                 // Destructor

	T getValor() const;       // Getter
	//void setValor(int valor);   // Setter

	Operador<T> operator%(const Operador<T>& num) const;   // Operador sobrecargado %
	Operador<T> operator^(const Operador<T>& num) const;   // Operador sobrecargado ^
};