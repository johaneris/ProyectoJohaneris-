#include <iostream>
#include <string.h>
#include <locale.h>

#include "menuAdministrador.cpp"

void mainMenu() {
    setlocale(LC_ALL, "spanish");

    int user;
    loadAppointments();
    loadRegisters();

    while(true)
    {
        system("cls");
        cout << "\033[1;34mBienvenido al sistema de clinica dental los olivos\033[0m\n";
        cout << "Elija su usuario: \n";
        cout << "1. Paciente\n";
        cout << "2. Administrador\n";
        cout << "3. Salir\n";
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
                menuAdministrador();
                break;
            case 3:
                exit(0); // Salir del programa por algo la funcion se llama exit
                break;
            default:
                cout << "Opci�n inv�lida. Por favor intente de nuevo.\n";
                break;
        }

        if (user != 3)
        {
            system("pause");
        }
    }
}