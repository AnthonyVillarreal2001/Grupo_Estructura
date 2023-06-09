/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Carlos Campoverde, Ariel Pozo, Anthony Villarreal
FECHA DE CREACI�N: 30/05/2023
FECHA DE MODIFICACI�N: 06/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
#include "ListaPersonal.h"

template<typename T>
Registro<T>* ListaPersonal<T>::obtenerPrimerRegistro() const {
    return primero;
}

template<typename T>
void ListaPersonal<T>::agregarRegistro(const T& cedula, const T& nombre, const T& fechaNacimiento, const T& edad, const T& horaEntrada, const T& horaAlmuerzo, const T& horaSalida) {
    Registro<T>* nuevo = new Registro<T>(cedula, nombre, fechaNacimiento, edad, horaEntrada, horaAlmuerzo, horaSalida);

    if (!primero) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }
}

template<typename T>
void ListaPersonal<T>::eliminarRegistro(const T& cedula) {
    Registro<T>* actual = primero;

    while (actual) {
        if (actual->cedula == cedula) {
            if (actual == primero) {
                primero = actual->siguiente;
                if (primero) {
                    primero->anterior = nullptr;
                }
                else {
                    ultimo = nullptr;
                }
            }
            else if (actual == ultimo) {
                ultimo = actual->anterior;
                if (ultimo) {
                    ultimo->siguiente = nullptr;
                }
                else {
                    primero = nullptr;
                }
            }
            else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            break;
        }
        actual = actual->siguiente;
    }
}

template<typename T>
bool ListaPersonal<T>::existeUsuario(const T& cedula) {
    Registro<T>* actual = primero;
    while (actual) {
        if (actual->cedula == cedula) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

template<typename T>
void ListaPersonal<T>::registrarHoraEntrada(const T& cedula, const T& horaEntrada) {
    Registro<T>* actual = primero;
    while (actual) {
        if (actual->cedula == cedula) {
            actual->horaEntrada = horaEntrada;
            break;
        }
        actual = actual->siguiente;
    }
}

template<typename T>
void ListaPersonal<T>::registrarHoraAlmuerzo(const T& cedula, const T& horaAlmuerzo) {
    Registro<T>* actual = primero;
    while (actual) {
        if (actual->cedula == cedula) {
            actual->horaAlmuerzo = horaAlmuerzo;
            break;
        }
        actual = actual->siguiente;
    }
}

template<typename T>
void ListaPersonal<T>::registrarHoraSalida(const T& cedula, const T& horaSalida) {
    Registro<T>* actual = primero;
    while (actual) {
        if (actual->cedula == cedula) {
            actual->horaSalida = horaSalida;
            break;
        }
        actual = actual->siguiente;
    }
}

template<typename T>
void ListaPersonal<T>::mostrarRegistros() {
    Registro<T>* actual = primero;
    while (actual) {
        std::cout << "Cedula: " << actual->cedula << std::endl;
        std::cout << "Nombre: " << actual->nombre << std::endl;
        std::cout << "Fecha de Nacimiento: " << actual->fechaNacimiento << std::endl;
        std::cout << "Edad: " << actual->edad << std::endl;
        std::cout << "Hora de entrada: " << actual->horaEntrada << std::endl;
        std::cout << "Hora de almuerzo: " << actual->horaAlmuerzo << std::endl;
        std::cout << "Hora de salida: " << actual->horaSalida << std::endl;
        std::cout << std::endl;

        actual = actual->siguiente;
    }
}

// Declaraci�n de las instanciaciones m�s comunes de la clase ListaPersonal
template class ListaPersonal<std::string>;
template class ListaPersonal<int>;