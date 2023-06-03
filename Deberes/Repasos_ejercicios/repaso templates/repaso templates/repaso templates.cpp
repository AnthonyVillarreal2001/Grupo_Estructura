

#include <iostream>
#include <conio.h>
using namespace std;

template <typename t> 


void Intercambiar(t a, t b) {

    t c = a;
    a = b;
    b = c;

    cout << a << "  " << b << endl;
    cout << b << "  " << a << endl;


    return;
}




int main()
{
    Intercambiar(10, 15);
    Intercambiar(10.4, 10.36);
    Intercambiar("aqui", "alla");
    Intercambiar(true, false);

    return (0);
}
