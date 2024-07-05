#include <locale.h>
#include "menuPrincipal.cpp"

int main()
{

    setlocale(LC_ALL, "spanish");
    loadAppointments();
    loadRegisters();
    loadPacientes();
    mainMenu();
    return 0;
}
