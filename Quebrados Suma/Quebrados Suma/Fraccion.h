#if !defined(__Class_Diagram_1_Fraccion_h)
#define __Class_Diagram_1_Fraccion_h

class Fraccion
{
public:
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   Fraccion(float num, float den);
   ~Fraccion();

protected:
private:
   float numerador;
   float denominador;

};

#endif