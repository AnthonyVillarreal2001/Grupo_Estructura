#include "ListaDobleCircular.cpp"
//#include <iostream>
//using namespace std;
//
//int main() {
//    ListaDobleCircular<int> lista;
//    int opcion, valor;
//
//    while (true) {
//        system("cls");
//        cout << "---- Menú ----" << endl;
//        cout << "1. Insertar elemento" << endl;
//        cout << "2. Eliminar elemento" << endl;
//        cout << "3. Buscar elemento" << endl;
//        cout << "4. Mostrar elementos" << endl;
//        cout << "5. Ordenar lista de menor a mayor" << endl;
//        cout << "6. Ordenar lista de mayor a menor" << endl;
//        cout << "7. Salir" << endl;
//        cout << "Ingrese una opción: ";
//        cin >> opcion;
//
//        switch (opcion) {
//        case 1:
//            cout << "Ingrese el valor a insertar: ";
//            cin >> valor;
//            lista.insertar(valor);
//            break;
//        case 2:
//            cout << "Ingrese el valor a eliminar: ";
//            cin >> valor;
//            lista.eliminar(valor);
//            break;
//        case 3:
//            cout << "Ingrese el valor a buscar: ";
//            cin >> valor;
//            lista.buscar(valor);
//            break;
//        case 4:
//            lista.mostrar();
//            break;
//        case 5:
//            lista.ordenar(true);  // Ordenar de menor a mayor
//            break;
//        case 6:
//            lista.ordenar(false);  // Ordenar de mayor a menor
//            break;
//        case 7:
//            exit(0);
//        default:
//            cout << "Opción inválida. Intente nuevamente." << endl;
//        }
//
//        system("pause");
//    }
//
//    return 0;
//}
#include <iostream>
#include <conio.h>  // Biblioteca para la detección de teclas especiales
using namespace std;

int main() {
    ListaDobleCircular<int> lista;
    int opcion = 1;  // Opción seleccionada
    int tecla;

    while (true) {
        system("cls");
        cout << "---- Menú ----" << endl;
        cout << (opcion == 1 ? "> " : "  ") << "1. Insertar elemento" << endl;
        cout << (opcion == 2 ? "> " : "  ") << "2. Eliminar elemento" << endl;
        cout << (opcion == 3 ? "> " : "  ") << "3. Buscar elemento" << endl;
        cout << (opcion == 4 ? "> " : "  ") << "4. Mostrar elementos" << endl;
        cout << (opcion == 5 ? "> " : "  ") << "5. Ordenar lista de menor a mayor" << endl;
        cout << (opcion == 6 ? "> " : "  ") << "6. Ordenar lista de mayor a menor" << endl;
        cout << (opcion == 7 ? "> " : "  ") << "7. Salir" << endl;

        // Esperar hasta que se presione una tecla especial
        do {
            tecla = _getch();
        } while (tecla != 224 && tecla != 13);  // 224: teclas especiales, 13: Enter

        if (tecla == 224) {
            // Se presionó una tecla especial (flechas)
            tecla = _getch();  // Leer el código de la tecla especial

            switch (tecla) {
            case 72:  // Flecha arriba
                opcion = (opcion > 1) ? opcion - 1 : 7;
                break;
            case 80:  // Flecha abajo
                opcion = (opcion < 7) ? opcion + 1 : 1;
                break;
            }
        }
        else if (tecla == 13) {
            // Se presionó Enter
            switch (opcion) {
            case 1:
                int valor;
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                lista.insertar(valor);
                system("pause");
                break;
            case 2:
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                system("pause");
                break;
            case 3:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                lista.buscar(valor);
                system("pause");
                break;
            case 4:
                lista.mostrar();
                system("pause");
                break;
            case 5:
                lista.ordenar(true);  // Ordenar de menor a mayor
                system("pause");
                break;
            case 6:
                lista.ordenar(false);  // Ordenar de mayor a menor
                system("pause");
                break;
            case 7:
                exit(0);
            }
        }
    }

    return 0;
}
