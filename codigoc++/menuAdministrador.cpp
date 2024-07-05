#include <iostream>
#include <conio.h>
#include <string>

#include "menuPaciente.cpp"



// =========================================
// Password

void passwordGet(string &inp) {
    char BACKSPACE = '\b';
    char ENTER = '\r';
    char TAB = '\t';
    char VOID = '\0';

    char ch = getch();
    string return_string = "";

    while(ch != ENTER || return_string.length() <= 0) {
        if(ch == BACKSPACE) {
            if(return_string.length() > 0) {
                return_string.resize(return_string.length() - 1);
                cout << "\b \b";
            }
        }  else if(ch == ENTER || ch == TAB || ch == VOID) {
            ch = getch(); continue;
        } else {
            return_string += ch;
            cout << '*';
        }

        ch = getch();
    }
    inp = return_string;
}

// =========================================
// Menu de Administrador

void menuAdministradorGeneral(); // Funcion Principal
void menuAdministradorCitas();
void menuAdministradorRegistros();

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
void menuAdministradorGeneral() {
    int option;

    bool validado = false;

    do {
        system("cls");
        string usuario, password;
        cout << "\033[1;31m---- Autenticacion ----\033[0m\n";
        cout << "Inserte el usuario de administrador: ";
        cin >> usuario;

        cout << "Inserte la contrasena proporcionada: ";
        passwordGet(password);

        if(usuario == adUSUARIO && password == adPASS) {
            validado = true;
            cout << "Acceso Garantizado!\n";
        } else {
            cout << "Los datos son incorrectos, desea intentar de nuevo? (S/N): ";
            char SN;
            cin >> SN;

            if(SN == 'n' || SN == 'N') return;
        }
    } while(!validado);

    do {
        system("cls");
        system("cls"); 
        cout << "\033[1;94m-----------Menu General (Administrador)--------\033[0m\n";
        cout << "1. Menu de Citas\n";
        cout << "2. Menu de Registros\n";
        cout << "3. Cerrar Sesion\n";
        cout << "Ingrese una opcion: ";

        cin >> option;

        switch(option) {
            case 1:
            menuAdministradorCitas();
            break;

            case 2:
            menuAdministradorRegistros();
            break;

            case 3:
            cout << "Saliendo...\n";
            break;

            if(option != 3) {
                system("pause");
            }
        }
    } while(option != 3);
}

// =========================================
void menuAdministradorCitas()
{
    int option;
    do
    {
        system("cls"); 
        cout << "\033[1;94m-----------Menu de Citas (Administrador)--------\033[0m\n";
        cout << "1. Mostrar todas las citas\n";
        cout << "2. Mostrar cita segun ID\n";
        cout << "3. Editar cita\n";
        cout << "4. Eliminar cita\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;
        cin.ignore();

        switch (option){
        case 1:
            showAppointments();
            break;
        case 2:
            showAppointmentByID();
            break;
        case 3:
            editAppointmentData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            cout << "Saliendo\n";
            break;
        }
        if (option != 5)
        {
            system("pause");
        }
    } while (option != 5);
}

// =========================================
void menuAdministradorRegistros()
{
    int option;
    do
    {
        system("cls"); 
        cout << "\033[1;94m-----------Menu de Registros (Administrador)--------\033[0m\n";
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
    scanf(" %[^\n]", r.name);
    cout << "\033[1;36mIngrese el apellido del paciente: \033[0m";
    scanf(" %[^\n]", r.lastName);
    cout << "\033[1;36mIngrese la direccion de domicilio del paciente: \033[0m";
    scanf(" %[^\n]", r.address);
    do{
    cout << "\033[1;36mIngrese el telefono del paciente (+505): \033[0m";
    scanf(" %[^\n]", r.number);
    if (!isValidPhoneNumber(r.number)) {
         cout << "Numero de telefono invalido. Por favor ingrese un numero valido.\n";
        }
    }while(!isValidPhoneNumber(r.number));
    
    do{
    cout << "\033[1;36mIngrese el genero del paciente (masculino / femenino): \033[0m"; // mejorar esto para que solo se puedan elegir dos opciones
    scanf(" %[^\n]", r.gender);
    if(!isValidGender(r.gender)){ 
        cout << "Genero invalido. Por favor ingrese un genero valido.\n";
     }
    }while(!isValidGender(r.gender));
    cout << "\033[1;36mIngrese la edad del paciente: \033[0m";
    scanf(" %[^\n]", r.age);
    cout << "\033[1;36mIngrese el historial medico del paciente: \033[0m";
    scanf(" %[^\n]", r.medicalHistory);
    cout << "\033[1;36mIngrese los la razon del la cita:  \033[0m";
    scanf(" %[^\n]", r.consultationReason);
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
        cin.ignore();
        scanf(" %[\n]", r.name);
        cout << "ingrese el nuevo apellido del paciente: \n ";
        scanf(" %[\n]", r.lastName);
        cout << "ingrese la nueva direccion del paciente: \n";
        scanf(" %[\n]", r.address);
        cout << "ingrese el nuevo numero de telefono del paciente: \n";
        scanf(" %[\n]", r.number);
        cout << "ingrese la nueva edad del paciente: \n";
        scanf(" %[\n]", r.age);
        editRegister(&r, id);
        cout << "registro editado\n";
    }
    else
    {
        cout << "no se encuentra el registro\n";
    }

    saveEntireRegister();
}

// =========================================
void removeRegisterData()
{
    int id = getValidID();
    deleteRegister(id);
    saveEntireRegister();
    cout << "registro eliminado\n";
}