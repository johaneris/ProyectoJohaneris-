#include <iostream>
#include <string.h>

using namespace std;

#define MAX_REGISTERS 50
#define MAX_APPOINTMENTS 50

#define APPOINTMENTS_FILE "appointment.txt"
#define REGISTERS_FILE "register.txt"

//para convertir precios 
#define EXCHANGE_RATE 36.5 // Tasa de cambio ejemplo de dólar a córdobas


struct SCHEDULE{
    string hour;
    string minute; 
};

struct DATE{
    string day;
    string year;
    string month;
};

struct APPOINTMENT{
    int id;
    string namePatient;
    string treatment;
    SCHEDULE time;
    DATE dates;
};

struct REGISTER{
    int id;
    string name;
    string lastName;
    string address;
    string number;
    string gender;
    string age;
    string consultationReason;
    string medicalHistory;
};

// =========================================
// Declaracion de Arreglos Globales
APPOINTMENT appointments[MAX_APPOINTMENTS];
int posAppointment = 0;

REGISTER registers[MAX_REGISTERS];
int posRegister = 0;