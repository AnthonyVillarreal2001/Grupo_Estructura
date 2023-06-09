#pragma once
#include "Registro.h"
#include <iostream>
#include <string>

/**
* @file ListaPersonal.h
* @version 1.0
* @date 06/06/2023
* @authors Campoverde Carlos, Pozo Ariel, Villarreal Anthony
* @title Proyecto_P1 REgistro e personal
* @code 
*/

template<typename T>
class ListaPersonal {
private:
    Registro<T>* primero;
    Registro<T>* ultimo;

public:
    /**

    @brief Constructor de la clase ListaPersonal.
    Crea un objeto ListaPersonal vacío, sin registros.
    El primer y último nodo de la lista se inicializan como nullptr.
    */
    ListaPersonal() : primero(nullptr), ultimo(nullptr) {}
    /**

    @brief Obtener el primer registro de la lista.
    @return Un puntero al primer registro de la lista o nullptr si la lista está vacía.
    **/
    Registro<T>* obtenerPrimerRegistro() const;
    /**

    @brief Agregar un nuevo registro a la lista.
    @param cedula La cédula del nuevo registro a agregar.
    @param nombre El nombre del nuevo registro a agregar.
    @param horaEntrada La hora de entrada del nuevo registro a agregar.
    @param horaAlmuerzo La hora de almuerzo del nuevo registro a agregar.
    @param horaSalida La hora de salida del nuevo registro a agregar.
    */
    void agregarRegistro(const T& cedula, const T& nombre, const T& fechaNacimiento, const T& edad, const T& horaEntrada, const T& horaAlmuerzo, const T& horaSalida);
    /**

     @brief Eliminar un usuario en la lista.
     @param cedula La cédula del usuario a buscar en la lista.
     */
    void eliminarRegistro(const T& cedula);
    /**

     @brief Verificar si existe un usuario en la lista.
     @param cedula La cédula del usuario a buscar en la lista.
     @return True si el usuario existe en la lista, False en caso contrario.
     */
    bool existeUsuario(const T& cedula);
    /**

    @brief Registrar la hora de entrada para un usuario en la lista.
    @param cedula La cédula del usuario al que se le registrará la hora de entrada.
    @param horaEntrada La hora de entrada a registrar.
    */
    void registrarHoraEntrada(const T& cedula, const T& horaEntrada);
    /**

    @brief Registrar la hora de almuerzo para un usuario en la lista.
    @param cedula La cédula del usuario al que se le registrará la hora de almuerzo.
    @param horaAlmuerzo La hora de almuerzo a registrar.
    */
    void registrarHoraAlmuerzo(const T& cedula, const T& horaAlmuerzo);
    /**

    @brief Registrar la hora de salida para un usuario en la lista.
    @param cedula La cédula del usuario al que se le registrará la hora de salida.
    @param horaSalida La hora de salida a registrar.
    */
    void registrarHoraSalida(const T& cedula, const T& horaSalida);
    /**

    @brief Mostrar los registros de la lista.
    Imprime en pantalla los registros de todos los usuarios presentes en la lista.
    */
    void mostrarRegistros();
};