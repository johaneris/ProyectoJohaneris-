#include <iostream>
#include <climits>
#include <cctype>

#include "saveYload.cpp"


bool isDigit(string arg) {

    char digits[] = {'0','1','2','3','4','5','6','7','8','9'};

    for(char ch : arg) {
        bool is_any_digit = false;
        for(char digit : digits) {
            if(ch == digit) { is_any_digit = true; break; }
        }
        if(!is_any_digit) return false;
    }
    return true;
} 

// =========================================
// Funciones de Appointments

APPOINTMENT identify_ID(int id);
int findAppointmentPos(int id);
int getValidID();
void showData(APPOINTMENT &a);
void addAppointment(APPOINTMENT *a);
void rewriteAppointment(APPOINTMENT *a, int id);
void deleteAppointment(int id);
bool isValidDate(const char* day, const char* month, const char* year);
bool isValidTime(const char* hour, const char* minute);


// ==================================================================================
// Funciones de Appointments
// ==================================================================================

// =========================================
/*La funcion busca una cita en el arreglo appointments con un id especifico.
basicamente si no se encuentra una cita con el id especificado, la devuelve.
Si no encuentra una cita con ese id, devuelve una cita con valores predeterminados.*/
APPOINTMENT identify_ID(int id)
{
    for (int i = 0; i < posAppointment; i++)
    {
        if (appointments[i].id == id)
        {
            return appointments[i];
        }
    }
    APPOINTMENT a = {-1, "", "", "", {"", ""}, {"", "", ""}}; /*Esto es como decir "Si no encontramos la cita, devolvamos una
    cita vacia para indicar que no se encontr�", entones se inicializa
    con valores por defecto.*/
    return a;
}

// =========================================
/*esta funcion busca la posicion de una cita en una lista de citas segun un identificador (id) especifico.*/
// Busca la posicion de una cita en el array de citas segun el ID proporcionado.
int findAppointmentPos(int id)
{
    for (int i = 0; i < posAppointment; i++)
    {
        if (appointments[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

// =========================================
int getValidID()
{
    int id;
    while (true) /*Este es un bucle infinito que se ejecutara hasta que
     encontremos una razon para salir de el. En este caso, queremos que el usuario
     siga intentando ingresar un ID valido hasta que lo consiga.*/
    {
        cout << "Ingrese el numero de su cita (solo numeros): ";
        cin >> id;
        if (cin.fail() || id < 0) /* cin.fail() devuelve true si la entrada no es
         un numero entero. Si esto ocurre, se ejecutan los siguientes paso*/
        {
            cin.clear() /*Esta funcion limpia el estado de error de cin.
              Es como reiniciar el estado de entrada para que pueda aceptar nuevas entradas.*/
                ;
            cin.ignore(10000, '\n') /* Esta funcion ignora los caracteres en el bufer de entrada
              hasta encontrar un salto de linea (\n) o hasta haber ignorado 10,000 caracteres, lo que
               ocurra primero. Esto limpia cualquier entrada residual que el usuario haya dejado.*/
                ;
            cout << "Entrada invalida. Por favor ingrese un numero valido.\n";
        }
        else
        {
            cin.ignore(10000, '\n');
            return id;
        }
    }
}
//====================================================================================
bool isValidDate(const char* day, const char* month, const char* year) {
    int d = atoi(day);
    int m = atoi(month);
    int y = atoi(year);

    if(y < 1000 || y > 9999) return false;
    if(m < 1 || m > 12) return false;
    if(d < 1 || d > 31) return false;

    if(m == 2) {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if(isLeap && d > 29) return false;
        if(!isLeap && d > 28) return false;
    }

    if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;

    return true;
}

bool isValidTime(const char* hour, const char* minute) {
    int h = atoi(hour);
    int m = atoi(minute);

    if(h < 0 || h > 12) return false;
    if(m < 0 || m > 59) return false;

    return true;
}

//========================================================================================================================

// =========================================
void showData(APPOINTMENT &a)
{
    cout << "---------------------------------------------------" << endl;
    cout << "Numero de cita: " << a.id << endl;
    cout << "Nombre: " << a.namePatient << endl;
    cout << "Tratamiento: " << a.treatment << endl;
    cout << "Fecha: " << a.dates.day << "/" << a.dates.month << "/" << a.dates.year << endl;
    cout << "Hora: " << a.time.hour << ":" << a.time.minute << endl;
    cout << "-----------------------------------------------------" << endl;
}

// =========================================
void addAppointment(APPOINTMENT *a)
{
    if (posAppointment < MAX_APPOINTMENTS)
    {
        appointments[posAppointment] = *a;
        posAppointment++;
    }
    else
    {
        cout << "\033[1;31mNo se pueden agregar mas citas.\033[0m\n";
    }
}

// =========================================
/*strcpy copia la cadena namePatient de a a
 appointments[posi], sobrescribiendo cualquier valor anterior en appointments[posi].namePatient.*/
void rewriteAppointment(APPOINTMENT *a, int id)
{
    int posi = findAppointmentPos(id);
    if (posi != -1)
    {
        strcpy(appointments[posi].namePatient, a->namePatient);
        strcpy(appointments[posi].treatment, a->treatment);
        strcpy(appointments[posi].dates.day, a->dates.day);
        strcpy(appointments[posi].dates.month, a->dates.month);
        strcpy(appointments[posi].dates.year, a->dates.year);
        strcpy(appointments[posi].time.hour, a->time.hour);
        strcpy(appointments[posi].time.minute, a->time.minute);

    }
}

// =========================================
void deleteAppointment(int id)
{
    int posi = id;
    if (posi != -1)
    {
        for (int i = posi; i < posAppointment - 1; i++)
        {
            appointments[i] = appointments[i + 1];
        }
        posAppointment--;
    }
}