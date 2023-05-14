#if !defined(__Class_Diagram_1_Proceso_h)
#define __Class_Diagram_1_Proceso_h
#include "Fraccion.h"

template <typename T>
class Proceso
{
public:
	virtual Fraccion<T> calculo(Fraccion<T> obj1, Fraccion<T> ojb2) = 0;
	virtual T calculo(T obj1, T obj2) = 0;

protected:
private:

};

#endif
