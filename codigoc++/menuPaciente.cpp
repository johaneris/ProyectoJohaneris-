#include <iostream>

#include "funcionesRegister.cpp"



// =========================================
// Funcion de Apoyo

bool validarOpcion(int variable, int primera_opcion, int ultima_opcion) {
    bool resultado = !(variable < primera_opcion || variable > ultima_opcion);
    return resultado; // Va a retornar falso si la opcion no es valida
}
// =========================================
// Menu Paciente

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
        void editAppointmentData();
        void deleteData();
        void showAppointments();

        void showPacienteAppointmentByID();
        void editPacienteAppointmentData();
        void deletePacienteData();
        void showPacienteAppointments();

        bool existeIDPaciente(string ID);

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
        cout << "2. Ver precios en cordobas\n";
        cout << "3. Ver horarios de atencion\n";
        cout << "4. Programar una cita\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
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
    cout << "Sabados: 9:00 AM - 1:00 PM\n";
    cout << "Domingos: Cerrado\n";
}

// =========================================
void menuProgramarCita()
{
    bool validado = false;

    do {
        string ID_INPUT;
        cout << "---- Autenticaci�n ----\n";
        cout << "Inserte su ID de Paciente: ";
        cin >> ID_INPUT;
        if(existeIDPaciente(ID_INPUT)) {
            IDPaciente = ID_INPUT;
            cout << "Acceso ganado!\n";
            validado = true;
            system("pause");
        } else {
            cout << "El ID no existe, desea crearlo? (S/N): ";
            char SN;
            cin >> SN;

            if(SN == 'N' || SN == 'n') return;
            else {
                IDPaciente = ID_INPUT;
                IDPacientes[posPacientes] = ID_INPUT;
                posPacientes++;
                savePacientes();
                validado = true;
                cout << "ID creado con exito!\n";
                system("pause");
            }
        }
    } while(!validado);

    while(true) {
        system("cls");
        int option;

        cout << "\033[1;34mAgendar citas - Menu\033[0m\n";
        cout << "1. Agendar cita\n";
        cout << "2. Mostrar cita por ID\n";
        cout << "3. Editar cita\n";
        cout << "4. Eliminar cita\n";
        cout << "5. Mostrar todas mis citas\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;

        cin.ignore(INT_MAX, '\n'); // pal buffer

        switch (option)
        {
        case 1:
            askDataAppointments();
            break;
        case 2:
            showPacienteAppointmentByID();
            break;
        case 3:
            editPacienteAppointmentData();
            break;
        case 4:
            deletePacienteData();
            break;
        case 5:
            showPacienteAppointments();
            break;
        case 6:
            cout << "Saliendo\n";
            return;
        default:
            cout << "Opcion invalida\n";
            break;
        }
        if (option != 6)
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
    cout << "\033[1;36mIngrese su nombre: \033[0m"; /*secuencias de
    escape ANSI para cambiar el color del texto en la consola*/
    scanf(" %[^\n]", a.namePatient); /*El formato %[^\n] indica que debe leer 
    hasta encontrar un salto de línea, permitiendo 
    sí capturar nombres con espacios.*/
    cout << "\033[1;36mIngrese el tratamiento: \033[0m"; // En el código, se utilizan secuencias de escape ANSI para cambiar el color del texto en la consola.
    scanf(" %[^\n]", a.treatment);
    do{
    cout << "\033[1;36mIngrese el dia de la cita (dd): \033[0m";
    scanf(" %[^\n]", a.dates.day);
    cout << "\033[1;36mIngrese el mes de la cita (mm): \033[0m";
    scanf(" %[^\n]", a.dates.month);
    cout << "\033[1;36mIngrese el anio de la cita (yyyy): \033[0m";
    scanf(" %[^\n]", a.dates.year);
    if (!isValidDate(a.dates.day, a.dates.month, a.dates.year)){
        cout << "Fecha invalida. Por favor ingrese una fecha valida.\n";
    }
 }while (!isValidDate(a.dates.day, a.dates.month, a.dates.year));
    do{
    cout << "\033[1;36mIngrese la hora de la cita (hh): \033[0m";
    scanf(" %[^\n]", a.time.hour);
    cout << "\033[1;36mIngrese los minutos de la cita (mm): \033[0m";
    scanf(" %[^\n]", a.time.minute);
     if (!isValidTime(a.time.hour, a.time.minute)) {
        cout << "Hora invalida. Por favor ingrese una hora valida.\n";
    }
}while (!isValidTime(a.time.hour, a.time.minute));
    
    a.idPaciente = IDPaciente;
    addAppointment(&a); /*Llama a una funcion addAppointment pasandole la direccion de la variable a.*/
    saveAppointment(a);

}

// =========================================
void showAppointmentByID()
{
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);
    if (a.id != -1)
    {
        showData(a);
    }
    else
    {
        cout << "Cita no encontrada.\n";
    }
}

// =========================================
void showPacienteAppointmentByID() {
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);
    if(a.idPaciente == IDPaciente && a.id != -1) {
        showData(a);
    } else {
        cout << "La cita no se encontro o no se puede accesar.\n";
    }
}

// =========================================
void editAppointmentData()
{
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);
    if (a.id != -1)
    {
        cout << "Ingrese el nuevo nombre del paciente: ";
        cin.ignore();
        scanf(" %[^\n]", a.namePatient);
        cout << "Ingrese el nuevo tratamiento: ";
        scanf(" %[^\n]", a.treatment);

        // Editar fecha
        cout << "Ingrese el nuevo dia de la cita (dd): ";
        scanf(" %[^\n]", a.dates.day);
        cout << "Ingrese el nuevo mes de la cita (mm): ";
        scanf(" %[^\n]", a.dates.month);
        cout << "Ingrese el nuevo año de la cita (yyyy): ";
        scanf(" %[^\n]", a.dates.year);

        // Editar hora
        cout << "Ingrese la nueva hora de la cita (hh): ";
        scanf(" %[^\n]", a.time.hour);
        cout << "Ingrese los nuevos minutos de la cita (mm): ";
        scanf(" %[^\n]", a.time.minute);

        rewriteAppointment(&a, id);
        saveEntireAppoint();
        cout << "Se actualizo su cita...\n";
    }
    else
    {
        cout << "Cita no encontrada.\n";
    }
}

// =========================================
void editPacienteAppointmentData() {

    int id = getValidID();
    APPOINTMENT a = identify_ID(id);

    if (a.idPaciente == IDPaciente && a.id != -1)
    {
        cout << "Ingrese el nuevo nombre del paciente: ";
        cin.ignore();
        scanf(" %[^\n]", a.namePatient);
        cout << "Ingrese el nuevo tratamiento: ";
        scanf(" %[^\n]", a.treatment);

        // Editar fecha
        cout << "Ingrese el nuevo dia de la cita (dd): ";
        scanf(" %[^\n]", a.dates.day);
        cout << "Ingrese el nuevo mes de la cita (mm): ";
        scanf(" %[^\n]", a.dates.month);
        cout << "Ingrese el nuevo año de la cita (yyyy): ";
        scanf(" %[^\n]", a.dates.year);

        // Editar hora
        cout << "Ingrese la nueva hora de la cita (hh): ";
        scanf(" %[^\n]", a.time.hour);
        cout << "Ingrese los nuevos minutos de la cita (mm): ";
        scanf(" %[^\n]", a.time.minute);

        rewriteAppointment(&a, id);
        saveEntireAppoint();
        cout << "Se actualizo su cita...\n";
    }
    else
    {
        cout << "La cita no se encontro o no se puede accesar.\n";
    }
}

// =========================================
void deleteData()
{
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);

    if(a.id != -1) {
        deleteAppointment(id);
        saveEntireAppoint();
        cout << "Cita eliminada.\n";
    } else {
        cout << "Cita no encontrada.\n";
    }
}

// =========================================
void deletePacienteData() {
    int id = getValidID();
    APPOINTMENT a = identify_ID(id);

    if(a.idPaciente == IDPaciente && a.id != -1) {
        deleteAppointment(id);
        saveEntireAppoint();
        cout << "Cita eliminada.\n";
    } else {
        cout << "La cita no se encontro o no se puede accesar.\n";
    }
}

// =========================================
void showAppointments()
{
    system("cls");
    for (int i = 0; i < posAppointment; i++)
    {
        showData(appointments[i]);
    }
}

// =========================================
void showPacienteAppointments()
{
    system("cls");
    for(int i = 0; i < posAppointment; i++) {
        if(appointments[i].idPaciente == IDPaciente) showData(appointments[i]);
    }
}

// =========================================
bool existeIDPaciente(string ID) {
    for(int i = 0; i < posPacientes; i++) {
        if(IDPacientes[i] == ID) return true;
    }
    return false;
}