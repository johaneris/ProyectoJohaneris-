#include <iostream>
#include <string.h>
#include "funciones.cpp" 
#include <locale.h>
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "spanish");
    mainMenu();
    return 0;
}
