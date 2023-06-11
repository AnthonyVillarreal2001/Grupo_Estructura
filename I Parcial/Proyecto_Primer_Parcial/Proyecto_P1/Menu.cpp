/***********************************************************************
Universidad de las Fuerzas Armadas ESPE
AUTORES: Carlos Campoverde, Ariel Pozo, Anthony Villarreal
FECHA DE CREACIÓN: 30/05/2023
FECHA DE MODIFICACIÓN: 06/06/2023
Proyecto 1er Parcial- Registro y control de personal
 ***********************************************************************/
#include "Menu.h"
#include "Registro.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <regex>
#include <chrono>
#pragma warning(disable : 4996)

using namespace std;

template<typename T>
Menu<T>::Menu() {
    const string nombreArchivo = "registros.txt";
    cargarRegistrosDesdeArchivo(nombreArchivo);
}

template<typename T>
void Menu<T>::ejecutar() {
    
    int opcion = 0;
    while (opcion != 5) {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrarNuevoUsuario();
           
            system("pause");
            system("cls");
            break;
        case 2:
            ingresarConCedula();
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarRegistros();
            system("pause");
            system("cls");
            break;
        case 4:
            eliminarRegistroPorCedula();
            system("pause");
            system("cls");
            break;
        case 5:
            buscarPorCedula();
            system("pause");
            system("cls");
            break;

        case 6:
            cout << "Saliendo del programa..." << endl;
            system("pause");
            system("cls");
            break;

        default:
            cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    const string nombreArchivo = "registros.txt";
    guardarRegistrosEnArchivo(nombreArchivo);
    
}
template<typename T>
void Menu<T>::buscarPorCedula()
{
    std::string cedula;
    std::cout << "Ingrese el número de cédula: ";
    std::cin >> cedula;

    std::ifstream archivo("registros.txt"); // Abrir el archivo
    std::string linea;

    while (std::getline(archivo, linea)) { // Leer cada línea del archivo
        // Verificar si la línea contiene la cédula buscada
        if (linea.find(cedula) != std::string::npos) {
            std::cout << linea << std::endl; // Mostrar la línea encontrada
            // Si hay más campos asociados a la cédula, puedes leerlos aquí
        }
    }

    archivo.close(); // Cerrar el archivo
}

template<typename T>
bool esMayorDe18(const T& fechaNacimiento) {
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);
    int currentYear = timeinfo.tm_year + 1900;
    int currentMonth = timeinfo.tm_mon + 1;
    int currentDay = timeinfo.tm_mday;

    int userYear = stoi(fechaNacimiento.substr(0, 4));
    int userMonth = stoi(fechaNacimiento.substr(5, 2));
    int userDay = stoi(fechaNacimiento.substr(8, 2));

    int age = currentYear - userYear;

    if (currentMonth < userMonth || (currentMonth == userMonth && currentDay < userDay)) {
        age--;
    }
    return age >= 18;
}

template<typename T>
int calcularEdad(const T& fechaNacimiento) {
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);
    int currentYear = timeinfo.tm_year + 1900;
    int currentMonth = timeinfo.tm_mon + 1;
    int currentDay = timeinfo.tm_mday;

    int userYear = stoi(fechaNacimiento.substr(0, 4));
    int userMonth = stoi(fechaNacimiento.substr(5, 2));
    int userDay = stoi(fechaNacimiento.substr(8, 2));

    int age = currentYear - userYear;

    if (currentMonth < userMonth || (currentMonth == userMonth && currentDay < userDay)) {
        age--;
    }

    return age;
}

template<typename T>
bool Menu<T>::validarCedula(const T& cedula) {
    // La cédula debe tener 10 dígitos
    if (cedula.length() != 10) {
        return false;
    }

    // Los dos primeros dígitos representan el código de la provincia
    int codigoProvincia = stoi(cedula.substr(0, 2));
    if (codigoProvincia < 1 || codigoProvincia > 24) {
        return false;
    }

    // Verificar el tercer dígito
    int tercerDigito = stoi(cedula.substr(2, 1));
    if (tercerDigito < 0 || tercerDigito > 5) {
        return false;
    }

    // Algoritmo de verificación
    int sumaPares = 0;
    for (int i = 0; i < 9; i += 2) {
        int digito = stoi(cedula.substr(i, 1)) * 2;
        sumaPares += (digito > 9) ? digito - 9 : digito;
    }

    int sumaImpares = 0;
    for (int i = 1; i < 8; i += 2) {
        sumaImpares += stoi(cedula.substr(i, 1));
    }

    int sumaTotal = sumaPares + sumaImpares;
    int digitoVerificador = (10 - (sumaTotal % 10)) % 10;

    // Verificar el último dígito (dígito verificador)
    int ultimoDigito = stoi(cedula.substr(9, 1));
    if (ultimoDigito != digitoVerificador) {
        return false;
    }

    return true;
}

template<typename T>
string Menu<T>::obtenerHoraActual() {
    time_t now = time(0);
    tm timeinfo;
    localtime_s(&timeinfo, &now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return buffer;
}

template<typename T>
void Menu<T>::cargarRegistrosDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos1 = linea.find("/");
        size_t pos2 = linea.find("/", pos1 + 1);
        size_t pos3 = linea.find("/", pos2 + 1);
        size_t pos4 = linea.find("/", pos3 + 1);
        size_t pos5 = linea.find("/", pos4 + 1);
        size_t pos6 = linea.find("/", pos5 + 1);

        string cedula = linea.substr(0, pos1);
        string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        string fechaNacimiento = linea.substr(pos2 + 1, pos3 - pos2 - 1);
        string edad = linea.substr(pos3 + 1, pos4 - pos3 - 1);
        string horaEntrada = linea.substr(pos4 + 1, pos5 - pos4 - 1);
        string horaAlmuerzo = linea.substr(pos5 + 1, pos6 - pos5 - 1);
        string horaSalida = linea.substr(pos6 + 1);
        listaPersonal.agregarRegistro(cedula, nombre, fechaNacimiento, edad, horaEntrada, horaAlmuerzo, horaSalida);
    }
    archivo.close();
}

template<typename T>
void Menu<T>::guardarRegistrosEnArchivo(const std::string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    Registro<T>* actual = listaPersonal.obtenerPrimerRegistro();
    while (actual) {
        archivo << actual->cedula << "/"
            << actual->nombre << "/"
            << actual->fechaNacimiento<< "/"
            << actual->edad<<"/"
            << actual->horaEntrada << "/"
            << actual->horaAlmuerzo << "/"
            << actual->horaSalida << endl;
        actual = actual->siguiente;
    }

    archivo.close();
}

template<typename T>
void Menu<T>::mostrarMenuPrincipal() {
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Registrar nuevo usuario" << endl;
    cout << "2. Ingresar con cedula" << endl;
    cout << "3. Mostrar registros" << endl;
    cout << "4. Eliminar por cedula" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

template<typename T>
void Menu<T>::mostrarMenuRegistroUsuario() {
    cout << "MENU REGISTRO USUARIO" << endl;
    cout << "1. Registrar hora de entrada" << endl;
    cout << "2. Registrar hora de almuerzo" << endl;
    cout << "3. Registrar hora de salida" << endl;
    cout << "4. Volver al menu principal" << endl;
    cout << "Ingrese su opcion: ";
}

template<typename T>
void Menu<T>::registrarNuevoUsuario() {
    T cedula;
    bool cedulaValida = false;
    
    while (!cedulaValida) {
        cout << "Ingrese la cedula: ";
        cin.ignore();
        getline(cin, cedula);

        if (!validarCedula(cedula)) {
            cout << "Cedula invalida. Ingrese una cedula valida." << endl;
        }
        else {
            cedulaValida = true;
        }
    }

    if (listaPersonal.existeUsuario(cedula)) {
        cout << "Ya existe un usuario registrado con la cedula " << cedula << "." << endl;
        return;
    }
    string fechaNacimiento;


    bool fechaValida = false;
    while (!fechaValida) {
        cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
        getline(cin, fechaNacimiento);

        // Validar el formato "YYYY-MM-DD"
        regex fechaRegex(R"(\d{4}-\d{2}-\d{2})");
        if (!regex_match(fechaNacimiento, fechaRegex)) {
            cout << "Formato de fecha incorrecto. Ingrese la fecha en el formato YYYY-MM-DD." << endl;
        }
        else {
            // Obtener la fecha actual
            auto ahora = chrono::system_clock::now();
            time_t ahoraTime = chrono::system_clock::to_time_t(ahora);
            tm* fechaActual = localtime(&ahoraTime);

            // Extraer el año, mes y día de la fecha de nacimiento ingresada
            int anioNacimiento = stoi(fechaNacimiento.substr(0, 4));
            int mesNacimiento = stoi(fechaNacimiento.substr(5, 2));
            int diaNacimiento = stoi(fechaNacimiento.substr(8, 2));

            // Crear una estructura tm para la fecha de nacimiento
            tm fechaNac;
            fechaNac.tm_year = anioNacimiento - 1900;  // Año - 1900
            fechaNac.tm_mon = mesNacimiento - 1;       // Mes (0 - 11)
            fechaNac.tm_mday = diaNacimiento;          // Día

            // Convertir la fecha de nacimiento a un objeto time_t
            time_t fechaNacTime = mktime(&fechaNac);

            // Verificar si la fecha es válida
            if (fechaNac.tm_year != anioNacimiento - 1900 ||
                fechaNac.tm_mon != mesNacimiento - 1 ||
                fechaNac.tm_mday != diaNacimiento) {
                cout << "Fecha de nacimiento no válida." << endl;
            }
            else if (fechaNacTime > ahoraTime) {
                cout << "La fecha de nacimiento no puede ser en el futuro." << endl;
            }
            else {
                // Verificar si el año es bisiesto
                bool esBisiesto = ((anioNacimiento % 4 == 0 && anioNacimiento % 100 != 0) || (anioNacimiento % 400 == 0));

                // Verificar los días en el mes
                if ((mesNacimiento == 4 || mesNacimiento == 6 || mesNacimiento == 9 || mesNacimiento == 11) && diaNacimiento > 30) {
                    cout << "El mes " << mesNacimiento << " solo tiene 30 días." << endl;
                }
                else if (mesNacimiento == 2) {
                    if (esBisiesto && diaNacimiento > 29) {
                        cout << "El mes de febrero en el año bisiesto solo tiene 29 días." << endl;
                    }
                    else if (!esBisiesto && diaNacimiento > 28) {
                        cout << "El mes de febrero en el año no bisiesto solo tiene 28 días." << endl;
                    }
                    else {
                        // Calcular la edad en años
                        int edad = fechaActual->tm_year + 1900 - anioNacimiento;

                        // Verificar si la edad está en el rango permitido (18-65 años)
                        if (edad >= 18 && edad <= 65) {
                            fechaValida = true;
                        }
                        else {
                            cout << "El usuario debe tener entre 18 y 65 años para ser registrado." << endl;
                        }
                    }
                }
                else {
                    // Calcular la edad en años
                    int edad = fechaActual->tm_year + 1900 - anioNacimiento;

                    // Verificar si la edad está en el rango permitido (18-65 años)
                    if (edad >= 18 && edad <= 65) {
                        fechaValida = true;
                    }
                    else {
                        cout << "El usuario debe tener entre 18 y 65 años para ser registrado." << endl;
                    }
                }
            }
        }
    }

    /*bool fechaValida = false;
    while (!fechaValida) {
        cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
        getline(cin, fechaNacimiento);

        // Validar el formato "YYYY-MM-DD"
        regex fechaRegex(R"(\d{4}-\d{2}-\d{2})");
        if (!regex_match(fechaNacimiento, fechaRegex)) {
            cout << "Formato de fecha incorrecto. Ingrese la fecha en el formato YYYY-MM-DD." << endl;
        }
        else {
            // Obtener la fecha actual
            auto ahora = chrono::system_clock::now();
            time_t ahoraTime = chrono::system_clock::to_time_t(ahora);
            tm* fechaActual = localtime(&ahoraTime);

            // Extraer el año, mes y día de la fecha de nacimiento ingresada
            int anioNacimiento = stoi(fechaNacimiento.substr(0, 4));
            int mesNacimiento = stoi(fechaNacimiento.substr(5, 2));
            int diaNacimiento = stoi(fechaNacimiento.substr(8, 2));

            // Crear una estructura tm para la fecha de nacimiento
            tm fechaNac;
            fechaNac.tm_year = anioNacimiento - 1900;  // Año - 1900
            fechaNac.tm_mon = mesNacimiento - 1;       // Mes (0 - 11)
            fechaNac.tm_mday = diaNacimiento;          // Día

            // Convertir la fecha de nacimiento a un objeto time_t
            time_t fechaNacTime = mktime(&fechaNac);

            // Comparar la edad mínima requerida (18 años) con la fecha de nacimiento
            const int edadMinima = 18;
            tm fechaMinima = *fechaActual;
            fechaMinima.tm_year -= edadMinima;  // Restar la edad mínima al año actual

            if (fechaNacTime > mktime(&fechaMinima)) {
                cout << "El usuario debe ser mayor de " << edadMinima << " años para ser registrado." << endl;
            }
            else {
                fechaValida = true;
            }
        }
    }*/
    /*bool fechaValida = false;
    while (!fechaValida) {
        cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
        getline(cin, fechaNacimiento);
        // Validar el formato "YYYY-MM-DD"
        regex fechaRegex(R"(\d{4}-\d{2}-\d{2})");
        if (!regex_match(fechaNacimiento, fechaRegex)) {
            cout << "Formato de fecha incorrecto. Ingrese la fecha en el formato YYYY-MM-DD." << endl;
        }
        else {
            if (!esMayorDe18(fechaNacimiento)) {
                cout << "El usuario debe ser mayor de 18 años para ser registrado." << endl;
            }
            else {
                fechaValida = true;
            }
        }
    }*/

    int edadStr = calcularEdad(fechaNacimiento);
    string edad = to_string(edadStr);
    cout << "Tu edad es: " << edad << " años." << endl;

    string nombre;
    regex nombreRegex("[A-Za-z ]+"); //expresión para validar cadenas
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nombre);

    while (!regex_match(nombre, nombreRegex)) {
        cout << "El nombre ingresado es invalido. \n\tIngrese un nombre valido: ";
        getline(cin, nombre);
    }

    listaPersonal.agregarRegistro(cedula, nombre, fechaNacimiento, edad, "", "", "");
    cout << "Se registro al usuario con cedula " << cedula << endl;
}

template<typename T>
void Menu<T>::ingresarConCedula() {
    T cedula;
    bool cedulaValida = false;

    while (!cedulaValida) {
        cout << "Ingrese la cedula: ";
        cin.ignore();
        getline(cin, cedula);

        if (!validarCedula(cedula)) {
            cout << "Cedula invalida. Ingrese una cedula valida." << endl;
        }
        else {
            cedulaValida = true;
        }
    }
    if (!listaPersonal.existeUsuario(cedula)) {
        cout << "El usuario no existe. Registre al usuario antes de registrar la hora de entrada, salida o almuerzo." << endl;
        return;
    }

    int opcionRegistroUsuario = 0;
    while (opcionRegistroUsuario != 4) {
        mostrarMenuRegistroUsuario();
        cin >> opcionRegistroUsuario;

        switch (opcionRegistroUsuario) {
        case 1: {
            string horaEntrada = obtenerHoraActual();
            listaPersonal.registrarHoraEntrada(cedula, horaEntrada);
            cout << "Se registro la hora de entrada: " << horaEntrada << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string horaAlmuerzo = obtenerHoraActual();
            listaPersonal.registrarHoraAlmuerzo(cedula, horaAlmuerzo);
            cout << "Se registro la hora de almuerzo: " << horaAlmuerzo << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            string horaSalida = obtenerHoraActual();
            listaPersonal.registrarHoraSalida(cedula, horaSalida);
            cout << "Se registro la hora de salida: " << horaSalida << endl;
            system("pause");
            system("cls");
            break;
        }
        case 4:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

template<typename T>
void Menu<T>::mostrarRegistros() {
    listaPersonal.mostrarRegistros();
}


template<typename T>
void Menu<T>::eliminarRegistroPorCedula() {
    cout << "Ingrese la cedula del usuario que desea eliminar: ";
    T cedula;
    cin >> cedula;

    Registro<T>* registroActual = listaPersonal.obtenerPrimerRegistro();
    Registro<T>* registroAnterior = nullptr;
    bool encontrado = false;

    while (registroActual != nullptr) {
        if (registroActual->cedula == cedula) {
            encontrado = true;
            break;
        }
        registroAnterior = registroActual;
        registroActual = registroActual->siguiente;
    }

    if (encontrado) {
        listaPersonal.eliminarRegistro(cedula);

        ofstream archivo("registros.txt");
        if (archivo.is_open()) {
            Registro<T>* registro = listaPersonal.obtenerPrimerRegistro();
            while (registro != nullptr) {
                archivo << registro->cedula << "," << registro->nombre << "," << registro->edad << endl;
                registro = registro->siguiente;
            }
            archivo.close();
            cout << "Registro eliminado exitosamente." << endl;
        }
        else {
            cout << "No se pudo abrir el archivo de registros." << endl;
        }
    }
    else {
        cout << "No se encontró un registro con la cedula especificada." << endl;
    }
}


/*template<typename T>
void Menu<T>::eliminarRegistroPorCedula() {
    T cedula;
    cout << "Ingrese la cedula del usuario a eliminar: ";
    cin.ignore();
    getline(cin, cedula);

    if (!validarCedula(cedula)) {
        cout << "Cedula invalida. Ingrese una cedula valida." << endl;
        return;
    }

    if (!listaPersonal.existeUsuario(cedula)) {
        cout << "El usuario no existe." << endl;
        return;
    }

    listaPersonal.eliminarRegistro(cedula);
    cout << "Se ha eliminado el registro del usuario con cedula " << cedula << endl;
}*/