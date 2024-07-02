#include <iostream>

#include "funcionesRegister.cpp"



// =========================================
// Funcion de Apoyo

bool validarOpcion(int variable, int primera_opcion, int ultima_opcion) {
    bool resultado = !(variable < primera_opcion || variable > ultima_opcion);
    return resultado; // Va a retornar falso si la opcion no es valida
}
// =========================================
// Men� Paciente

void menuPaciente(); // Funcion Principal

    // =========================================
    // Opciones del Menu

    void ShowDentalTreatments();
    void showPricesInDolares();
    void showClinicHours();
    void menuProgramarCita(); // Menu anidado para programar citas

        // =========================================
        // Funciones de Programacion de Cita

        void askDataAppointments();
        void showAppointmentByID();
        void appointmentxID();
        void editAppointmentData();
        void deleteData();
        void showAppointments();

// ==================================================================================
// Menu Pacientes
// ==================================================================================
void menuPaciente()
{
    int option;
    do
    {
        system("cls"); 
        cout << "\033[1;34m-------------Menu de Paciente-------------------\033[0m\n";
        cout << "1. Ver tratamientos dentales\n";
        cout << "2. Ver precios en c�rdobas\n";
        cout << "3. Ver horarios de atenci�n\n";
        cout << "4. Programar una cita\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opci�n: ";
        cin >> option;
        cin.ignore();

        switch (option){
        case 1:
            ShowDentalTreatments();
            break;
        case 2:
            showPricesInDolares();
            break;
        case 3:
            showClinicHours();
            break;
        case 4:
            menuProgramarCita(); // Funcion de gestion de citas
            break;
        case 5:
            cout << "Saliendo\n";
            return;
        }
        if (option != 5)
        {
            system("pause");
        }
    } while (option != 5);
}

// ==================================================================================
// Opciones de menuPaciente
// ==================================================================================

// =========================================
void ShowDentalTreatments()
{
    cout << "----------tratamientos dentales disponibles (precios en cordobas)---------\n";
    cout << "1. Limpieza dental -- 650 C$\n";
    cout << "2. Restauracion de resina -- 750 C$\n";
    cout << "3. Protesis total -- 6,500 C$\n";
    cout << "4. Protesis removible -- 3,500 C$\n";
    cout << "5. Cirugia de tercer molar -- 3,000 C$\n";
    cout << "6. Extraccion convencional -- 500 C$\n";
}

// =========================================
void showPricesInDolares()
{
    cout << "----------tratamientos dentales disponibles (precios en dolares)---------\n";
    cout << "1. Limpieza Dental - " << 650 / EXCHANGE_RATE << " $ \n";
    cout << "2. Restauracion de resina - " << 750 / EXCHANGE_RATE << " $ \n";
    cout << "3. Protesis total - " << 6500 / EXCHANGE_RATE << " $ \n";
    cout << "4. Protesis removible - " << 3500 / EXCHANGE_RATE << " $ \n";
    cout << "5. Cirugia de tercer molar - " << 3000 / EXCHANGE_RATE << " $ \n";
    cout << "5. Extraccion convencional- " << 500 / EXCHANGE_RATE << " $ \n";
}

// =========================================
void showClinicHours()
{
    cout << "------------Horarios de atenci�n disponibles------------\n";
    cout << "Lunes a Viernes: 8:00 AM - 12 PM / 1 PM - 5:00 PM\n";
    cout << "S�bados: 9:00 AM - 1:00 PM\n";
    cout << "Domingos: Cerrado\n";
}

// =========================================
void menuProgramarCita()
{
    while(true) {
        system("cls");
        int option;

        cout << "\033[1;34mAgendar citas - Menu\033[0m\n";
        cout << "1. Agendar cita\n";
        cout << "2. Mostrar cita por ID\n";
        cout << "3. Buscar cita por ID\n";
        cout << "4. Editar cita\n";
        cout << "5. Eliminar cita\n";
        cout << "6. Mostrar todas las citas\n";
        cout << "7. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;

        cin.ignore(INT_MAX, '\n'); // pal buffer

        switch (option)
        {
        case 1:
            askDataAppointments();
            break;
        case 2:
            showAppointmentByID();
            break;
        case 3:
            appointmentxID();
            break;
        case 4:
            editAppointmentData();
            break;
        case 5:
            deleteData();
            break;
        case 6:
            showAppointments();
            break;
        case 7:
            cout << "Saliendo\n";
            return;
        default:
            cout << "Opcion invalida\n";
            break;
        }
        if (option != 7)
        {
            system("pause");
        }
    };
}

// ==================================================================================
// Opciones de menuProgramarCita
// ==================================================================================

// =========================================
void askDataAppointments(){

    APPOINTMENT a;
    a.id = getValidID();
    cout << "\033[1;36mIngrese su nombre: \033[0m";      /*secuencias de
         escape ANSI para cambiar el color del texto en la consola*/
    getline(cin, a.namePatient);
    cout << "\033[1;36mIngrese el tratamiento: \033[0m"; // En el codigo, se utilizan secuencias de escape ANSI para cambiar el color del texto en la consola.
    getline(cin, a.treatment);
    cout << "\033[1;36mIngrese el dia de la cita (dd): \033[0m";
    cin >> a.dates.day;
    cout << "\033[1;36mIngrese el mes de la cita (mm): \033[0m";
    cin >> a.dates.month;
    cout << "\033[1;36mIngrese el año de la cita (yyyy): \033[0m";
    cin >> a.dates.year;
    cout << "\033[1;36mIngrese la hora de la cita (hh): \033[0m";
    cin >> a.time.hour;
    cout << "\033[1;36mIngrese los minutos de la cita (mm): \033[0m";
    cin >> a.time.minute;

    addAppointment(&a); /*Llama a una funcion addAppointment pasandole la direccion de la variable a.*/
    saveAppointment(a);

}

// =========================================
void showAppointmentByID()
{
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);
    if (a.id != 0)
    {
        showData(a);
    }
    else
    {
        cout << "Cita no encontrada.\n";
    }
    
    system("pause");
}

// =========================================
void appointmentxID()
{
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);
    if (a.id != 0)
    {
        showData(a);
    }
    else
    {
        cout << "Cita no encontrada.\n";
    }
    system("pause");
}

// =========================================
void editAppointmentData()
{
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);
    if (a.id != 0)
    {
        cout << "Ingrese el nuevo nombre del paciente: ";
        cin.ignore();
        getline(cin, a.namePatient);

        cout << "Ingrese el nuevo tratamiento: ";
        getline(cin, a.treatment);

        // Editar fecha
        cout << "Ingrese el nuevo dia de la cita (dd): ";
        cin >> a.dates.day;
        cout << "Ingrese el nuevo mes de la cita (mm): ";
        cin >> a.dates.month;
        cout << "Ingrese el nuevo año de la cita (yyyy): ";
        cin >> a.dates.year;

        // Editar hora
        cout << "Ingrese la nueva hora de la cita (hh): ";
        cin >> a.time.hour;
        cout << "Ingrese los nuevos minutos de la cita (mm): ";
        cin >> a.time.minute;

        rewriteAppointment(&a, id);
        saveEntireAppoint();
        cout << "Se actualizo su cita...\n";
    }
    else
    {
        cout << "Cita no encontrada.\n";
    }
    system("pause");
}

// =========================================
void deleteData()
{
    int id = getValidID();
    deleteAppointment(id);
    saveEntireAppoint();
    cout << "Cita eliminada.\n";
    system("pause");
}

// =========================================

void showAppointments()
{
    system("cls");
    for (int i = 0; i < posAppointment; i++)
    {
        showData(appointments[i]);
    }
    system("pause");
}