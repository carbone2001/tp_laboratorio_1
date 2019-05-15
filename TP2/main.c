#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define TAM 1000

int main()
{
    Employee emp[TAM];
    initEmployees(emp,TAM);
    int contId;
    int opcion;
    opcion=1;
    contId=7;
    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(emp,TAM,&contId);
            break;
        case 2:
            modificarEmpleado(emp,TAM,&contId);
            break;
        case 3:
            bajarEmpleado(emp,TAM,&contId);
            break;
        case 4:
            informarEmpleados(emp,TAM,&contId);
            break;
        default:
            printf("La opcion ingresada es invalida");
            opcion=0;
            break;
        }
    }while(opcion);
    return 0;
}
