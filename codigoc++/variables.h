#include <iostream>
#include <string.h>

using namespace std;

#define MAX_REGISTERS 50
#define MAX_APPOINTMENTS 50

#define APPOINTMENTS_FILE "appointment.txt"
#define REGISTERS_FILE "register.txt"

//para convertir precios 
#define EXCHANGE_RATE 36.5 // Tasa de cambio ejemplo de dólar a córdobas


#include <iostream>
using namespace std;


#define MAX_APPOINTMENT 50

struct SCHEDULE{
    char hour[3];
    char minute[3]; 
};

struct DATE{
    char day[3];
    char year[5];
    char month[3];
};

struct APPOINTMENT{
    int id;
    char namePatient[21];
    char treatment[51];
    SCHEDULE time;
    DATE dates;
};

struct REGISTER{
    int id;
    char name[21];
    char lastName[21];
    char address[31];
    char number[10];
    char gender[10];
    char age[3];
    char consultationReason[30];
    char medicalHistory[50];
}; 


// =========================================
// Declaracion de Arreglos Globales
APPOINTMENT appointments[MAX_APPOINTMENTS];
int posAppointment = 0;

REGISTER registers[MAX_REGISTERS];
int posRegister = 0;