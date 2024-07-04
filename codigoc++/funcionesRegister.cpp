#include <iostream>
#include <climits>
#include <cctype>

#include "funcionesAppointment.cpp"

// =========================================
// Funciones de Registers

void addRegister(REGISTER *r);
void deleteRegister(int id);
void editRegister(REGISTER *r, int id);
REGISTER identifyRegisterByID(int id);
bool isValidPhoneNumber(const char* number);
bool isValidGender(const char* gender);

// ==================================================================================
// Funciones de Register
// ==================================================================================
void addRegister(REGISTER *r)
{
    if (posRegister < MAX_REGISTERS)
    {
        registers[posRegister] = *r;
        posRegister++;
    }
    else
    {
        cout << "\033[1;31mNo se pueden agregar mas registros\033[0m\n";
    }
}
//==========================================
bool isValidGender(const char* gender){
    return strcmp(gender, "masculino") == 0 || strcmp(gender, "femenino") == 0;
}

bool isValidPhoneNumber(const char* number) {
    if(strlen(number) != 8) return false;
    for(int i = 0; i < 8; i++) {
        if(!isdigit(number[i])) return false;
    }
    return true;
}

// =========================================
void deleteRegister(int id)
{
    int posi = findAppointmentPos(id);
    if (posi != -1)
    {
        for (int i = posi; i < posRegister; i++)
        {
            registers[i] = registers[i + 1];
        }
        posRegister--;
    }
}

// =========================================
void editRegister(REGISTER *r, int id)
{
    int posi = findAppointmentPos(id);
    if (posi != -1)
    {
        strcpy(registers[posi].name, r->name);
        strcpy(registers[posi].lastName, r->lastName);
        strcpy(registers[posi].address, r->address);
        strcpy(registers[posi].number, r->number);
        strcpy(registers[posi].age, r->age);
        strcpy(registers[posi].gender, r->gender);
        strcpy(registers[posi].medicalHistory, r->medicalHistory);
        strcpy(registers[posi].consultationReason, r->consultationReason);
    }
}

// =========================================
REGISTER identifyRegisterByID(int id)
{
    for (int i = 0; i < posRegister; i++)
    {
        if (registers[i].id == id)
        {
            return registers[i];
        }
    }
    REGISTER r = {0, "", "", "", "", "", "", "", "", }; /*Esto es como decir "Si no encontramos la cita, devolvamos una
cita vacia para indicar que no se encontro", entones se inicializa
con valores por defecto.*/
    return r;
}