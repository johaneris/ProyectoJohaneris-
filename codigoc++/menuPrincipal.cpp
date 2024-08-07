#include <iostream>
#include <string.h>
#include <locale.h>

#include "menuAdministrador.cpp"



void mainMenu() {

    int user;

    while(true)
    {
        system("cls");
        cout << "\033[1;34mBienvenido al sistema de clinica dental los olivos\033[0m\n";
        cout << "1. Paciente\n";
        cout << "2. Doctor\n";
        cout << "3. Cerrar Sesion\n";
        cout << "Ingrese una opcion: ";

        while ((cin >> user) && !validarOpcion(user, 1, 3))
        {
            cout << "Ingrese una opcion valida: ";
            cin.clear();
            cin.ignore();
        }

        cin.ignore();
        switch (user)
        {
            case 1:
                menuPaciente();
                break;
            case 2:
                menuAdministradorGeneral();
                break;
            case 3:
                return; // Salir del programa por algo la funcion se llama exit
                break;
            default:
                cout << "Opcion invalida. Por favor intente de nuevo.\n";
                break;
        }

        if (user != 3)
        {
            system("pause");
        }
    }
}