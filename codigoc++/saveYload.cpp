#include <iostream>
#include <fstream>
#include <string>

#include "variables.h"

// =========================================
// Funciones de Save & Load
void saveAppointment(APPOINTMENT arg);
void saveEntireAppoint();

void saveRegister(REGISTER r);
void saveEntireRegister();

void loadAppointments();
void loadRegisters();

// ==================================================================================
// Funcion de Soporte
// ==================================================================================

string readUntilSemicolon(string arg) {

    string resultado = "";

    for(char ch : arg) {
        if(ch != ';') resultado += ch;
        else return resultado;
    }

    return resultado; // Aqui llega si no hay punto y coma del todo
}

// ==================================================================================
// Funciones de Save & Load
// ==================================================================================

// =========================================
void saveAppointment(APPOINTMENT arg){

    fstream appointment;
    appointment.open(APPOINTMENTS_FILE, ios::app);

    if(!appointment.is_open()){
        cout << "No se puede abrir el archivo para lectura" << endl;
        return;
    } else {
        appointment << arg.id <<"; ID" << endl;
        appointment << arg.namePatient <<"; NOMBRE DEL PACIENTE" << endl;
        appointment << arg.treatment << "; TRATAMIENTO" << endl;
        appointment << arg.dates.day << "; DIA" << endl;
        appointment << arg.dates.month << "; MES" << endl;
        appointment << arg.dates.year << "; AÑO" << endl;
        appointment << arg.time.hour << "; HORA" << endl;
        appointment << arg.time.minute << "; MINUTO" << endl;
    }

}

// =========================================
void saveEntireAppoint() {
    fstream appointmentf(APPOINTMENTS_FILE, ios::out);
    appointmentf << "";
    appointmentf.close();
    
    for(int i = 0; i < posAppointment; i++) {
        saveAppointment(appointments[i]);
    }
}

// =========================================
void saveRegister(REGISTER r){
    fstream Saveregister(REGISTERS_FILE, ios::app);

    if(Saveregister.is_open()){
        Saveregister << r.id <<"; ID" <<  "\n";
        Saveregister << r.name << "; nombre del paciente" << "\n";
        Saveregister << r.lastName << "; apellido del paciente" << "\n";
        Saveregister << r.address <<"; direccion"<<  "\n";
        Saveregister <<r.number << "; numero de telefono" <<  "\n";
        Saveregister << r.age << "; edad del paciente" << "\n";
        Saveregister << r.gender << "; genero del paciente" << "\n";
        Saveregister <<r.medicalHistory << "; historial medico" <<  "\n";
        Saveregister << r.consultationReason <<"; razon de la consulta" <<  "\n";
    } else {
        cout << "No se puede abrir el archivo para lectura" << endl;
        return;
    }

}

// =========================================
void saveEntireRegister() {
    fstream Saveregister(REGISTERS_FILE, ios::out);
    Saveregister << "";
    Saveregister.close();
    
    for(int i = 0; i < posRegister; i++) {
        saveRegister(registers[i]);
    }
}

// =========================================
void loadAppointments() {
    fstream appointmentf;
    appointmentf.open(APPOINTMENTS_FILE, ios::in);

    if(appointmentf.is_open()) {
        string linea;
        int app_n = 0;

        while(getline(appointmentf,linea)) {
            appointments[app_n].id = stoi(readUntilSemicolon(linea));

            getline(appointmentf,linea);
            appointments[app_n].namePatient = readUntilSemicolon(linea);

            getline(appointmentf,linea);
            appointments[app_n].treatment = readUntilSemicolon(linea);
            
            getline(appointmentf,linea);
            appointments[app_n].dates.day = readUntilSemicolon(linea);

            getline(appointmentf,linea);
            appointments[app_n].dates.month = readUntilSemicolon(linea);

            getline(appointmentf,linea);
            appointments[app_n].dates.year = readUntilSemicolon(linea);

            getline(appointmentf,linea);
            appointments[app_n].time.hour = readUntilSemicolon(linea);

            getline(appointmentf,linea);
            appointments[app_n].time.minute = readUntilSemicolon(linea);

            app_n++;
            posAppointment++;
        }
    }
}

// =========================================
void loadRegisters() {
    fstream registerf;
    registerf.open(REGISTERS_FILE, ios::in);

    if(registerf.is_open()) {
        string linea;
        int app_n = 0;

        while(getline(registerf,linea)) {
            registers[app_n].id = stoi(readUntilSemicolon(linea));

            getline(registerf,linea);
            registers[app_n].name = readUntilSemicolon(linea);

            getline(registerf,linea);
            registers[app_n].lastName = readUntilSemicolon(linea);
            
            getline(registerf,linea);
            registers[app_n].address = readUntilSemicolon(linea);

            getline(registerf,linea);
            registers[app_n].number = readUntilSemicolon(linea);

            getline(registerf,linea);
            registers[app_n].age = readUntilSemicolon(linea);

            getline(registerf,linea);
            registers[app_n].gender = readUntilSemicolon(linea);

            getline(registerf,linea);
            registers[app_n].medicalHistory = readUntilSemicolon(linea);

            getline(registerf,linea);
            registers[app_n].consultationReason = readUntilSemicolon(linea);

            app_n++;
            cout << "Registro cargado" << endl;
            posRegister++;
        }
    }
}