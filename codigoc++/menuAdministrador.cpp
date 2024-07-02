#include <iostream>

#include "menuPaciente.cpp"





// =========================================
// Menu de Administrador

void menuAdministrador(); // Funcion Principal

    // =========================================
    // Opciones del Menu

    void askRegisterData();
    void showRegisters();
    void showRegisterByID();
    void showRegisterData(REGISTER &r);
    void editRegisterData();
    void removeRegisterData();

// ==================================================================================
// Menu de Administrador
// ==================================================================================

// =========================================
void menuAdministrador()
{
    int option;
    do
    {
        system("cls"); 
        cout << "\033[1;94m-----------Menu de registro(Administrador)--------\033[0m\n";
        cout << "1. Agregar registro\n";
        cout << "2. Mostrar todos los registros\n";
        cout << "3. Mostrar registro segun ID\n";
        cout << "4. Editar registro\n";
        cout << "5. Eliminar registro\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;
        cin.ignore();

        switch (option){
        case 1:
            askRegisterData();
            break;
        case 2:
            showRegisters();
            break;
        case 3:
            showRegisterByID();
            break;
        case 4:
            editRegisterData();
            break;
        case 5:
            removeRegisterData();
            break;
        case 6:
            cout << "Saliendo\n";
            break;
        }
        if (option != 6)
        {
            system("pause");
        }
    } while (option != 6);
}

// ==================================================================================
// Opciones de Menu de Administrador
// ==================================================================================

// =========================================
void askRegisterData()
{
    REGISTER r;
    r.id = getValidID();
    cout << "\033[1;36mIngrese el nombre del paciente: \033[0m";
    getline(cin,r.name);
    cout << "\033[1;36mIngrese el apellido del paciente: \033[0m";
    getline(cin, r.lastName);
    cout << "\033[1;36mIngrese la direccion de domicilio del paciente: \033[0m";
    getline(cin, r.address);
    cout << "\033[1;36mIngrese el telefono del paciente (+505): \033[0m";
    getline(cin, r.number);
    cout << "\033[1;36mIngrese la edad del paciente: \033[0m";
    getline(cin, r.age);
    cout << "\033[1;36mIngrese el genero del paciente (masculino o femenino): \033[0m"; // mejorar esto para que solo se puedan elegir dos opciones
    getline(cin, r.gender);
    cout << "\033[1;36mIngrese el historial medico del paciente: \033[0m";
    getline(cin, r.medicalHistory);
    cout << "\033[1;36mIngrese los la razon del la cita:  \033[0m";
    getline(cin, r.consultationReason);

    addRegister(&r);
    saveRegister(r);
    cout << "Paciente agregado con exito\n";
}

// =========================================
void showRegisters()
{
    system("cls");
    for (int i = 0; i < posRegister; i++)
    {
        showRegisterData(registers[i]);
    }

    system("pause");
}

// =========================================
// enfasis aqui
void showRegisterByID()
{
    int id = getValidID();
    REGISTER r = identifyRegisterByID(id);
    if (r.id != 0)
    {
        showRegisterData(r);
    }
    else
    {
        cout << "no se encuentra el registro\n";
    }
    cin.ignore();
    cin.get();
}

// =========================================
void showRegisterData(REGISTER &r)
{
    cout << "------------------------------------------------------" << endl;
    cout << "|" << "Numero del registro: " << r.id << endl;
    cout << "|" << "Nombre y apellido: " << r.name << " " << r.lastName << endl;
    cout << "|" << "Direccion: " << r.address << endl;
    cout << "|" << "su numero de telefono: " << r.number << endl;
    cout << "|" << "Edad: " << r.age << endl;
    cout << "|" << "genero: " << r.gender << endl;
    cout << "|" << "Historial medico: " << r.medicalHistory << endl;
    cout << "|" << "Razon de la cita: " << r.consultationReason << endl;
    cout << "-----------------------------------------------------" << endl;
}

// =========================================
void editRegisterData()
{
    int id = getValidID();
    REGISTER r = identifyRegisterByID(id);
    if (r.id != 0)
    {
        cout << "ingrese el nuevo nombre del paciente: \n";
        getline(cin, r.name);
        cout << "ingrese el nuevo apellido del paciente: \n ";
        getline(cin, r.lastName);
        cout << "ingrese la nueva direccion del paciente: \n";
        getline(cin, r.address);
        cout << "ingrese el nuevo numero de telefono del paciente: \n";
        getline(cin, r.number);
        cout << "ingrese la nueva edad del paciente: \n";
        getline(cin, r.age);

        editRegister(&r, id);
        cout << "registro editado\n";
    }
    else
    {
        cout << "no se encuentra el registro\n";
    }

    saveEntireRegister();
    system("pause");
}

// =========================================
void removeRegisterData()
{
    int id = getValidID();
    deleteRegister(id);
    saveEntireRegister();
    cout << "registro eliminado\n";
    system("pause");
}