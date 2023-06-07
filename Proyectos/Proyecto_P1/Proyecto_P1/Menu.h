#pragma once
#include "ListaPersonal.h"

/**
* @file Menu.h
* @version 1.0
* @date 06/06/2023
* @authors Campoverde Carlos, Pozo Ariel, Villarreal Anthony
* @title Proyecto_P1 REgistro e personal
*�@code�
*/

template<typename T>
class Menu {
public:
    Menu();
    void ejecutar();
private:
    /**
    @brief Validar la c�dula proporcionada.
    @param cedula La c�dula a validar.
    @return True si la c�dula es v�lida, False en caso contrario.
    */
    bool validarCedula(const T& cedula);
    /**
    @brief Obtener la hora actual del sistema.
    @return Una cadena de caracteres que representa la hora actual en el formato especificado.
    */
    std::string obtenerHoraActual();
    /**
    @brief Cargar los registros desde un archivo.
        @param nombreArchivo El nombre del archivo desde el cual cargar los registros.
        */
    void cargarRegistrosDesdeArchivo(const std::string& nombreArchivo);
    /**

    @brief Guardar los registros en un archivo.
    @param nombreArchivo El nombre del archivo en el cual guardar los registros.
    */
    void guardarRegistrosEnArchivo(const std::string& nombreArchivo);
    /**

    @brief Mostrar el men� principal.
    Imprime en pantalla las opciones del men� principal.
    */
    void mostrarMenuPrincipal();
    /**

    @brief Mostrar el men� de registro de usuario.
    Imprime en pantalla las opciones del men� de registro de usuario.
    */
    void mostrarMenuRegistroUsuario();
    /**

    @brief Registrar un nuevo usuario.
    Solicita al usuario los datos necesarios y registra un nuevo usuario en la lista de personal.
    */
    void registrarNuevoUsuario();
    /**

    @brief Ingresar con la c�dula de un usuario.
    Solicita al usuario ingresar su c�dula y realiza las operaciones correspondientes seg�n la opci�n seleccionada.
    */
    void ingresarConCedula();
    /**

    @brief Mostrar los registros almacenados.
    Imprime en pantalla los registros de todos los usuarios almacenados en la lista de personal.
    */
    void mostrarRegistros();
    /**
    @brief Eliminar con la c�dula de un usuario.
        Solicita al usuario ingresar su c�dula y realiza la eliminacion correspondiente dependiendo el nodo seleccionado.
        */
    void eliminarRegistroPorCedula();

    //** Objeto de la clase ListaPersonal utilizado para almacenar los registros de personal.
    ListaPersonal<T> listaPersonal;
};