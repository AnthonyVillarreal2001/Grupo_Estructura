#pragma once
#include <string>
/**
* @file Registro.h
* @version 1.0
* @date 06/06/2023
* @authors Campoverde Carlos, Pozo Ariel, Villarreal Anthony
* @title Proyecto_P1 REgistro e personal
* @code 
*/
template<typename T>
struct Registro {
    T cedula;
    T nombre;
    T fechaNacimiento;
    T edad;
    T horaEntrada;
    T horaAlmuerzo;
    T horaSalida;
    Registro* siguiente;
    Registro* anterior;

    /**
    @brief Inicializa un objeto Registro con los datos proporcionados.
    @param cedula El número de cédula asociado al registro.
    @param nombre El nombre asociado al registro.
    @param horaEntrada La hora de entrada asociada al registro.
    @param horaAlmuerzo La hora de almuerzo asociada al registro.
    @param horaSalida La hora de salida asociada al registro.
    */

    Registro(const T& cedula, const T& nombre, const T& fechaNacimiento, const T& edad, const T& horaEntrada, const T& horaAlmuerzo, const T& horaSalida)
        : cedula(cedula), nombre(nombre), fechaNacimiento(fechaNacimiento), edad(edad), horaEntrada(horaEntrada), horaAlmuerzo(horaAlmuerzo), horaSalida(horaSalida),
        siguiente(nullptr), anterior(nullptr) {}
};