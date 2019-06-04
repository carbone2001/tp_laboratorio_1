#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("Memoria insuficiente");
        system("pause");
        exit(1);
    }



    do{
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nError al cargar desde texto");
                    system("pause");
                }
                break;
                case 2:
                if(controller_loadFromBinary("data.csv",listaEmpleados))
                {
                    printf("\nError al cargar desde binario");
                    system("pause");
                }
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
                case 6:
                break;
                case 7:
                break;
                case 8:
                break;
                case 9:
                break;
                default:
                    printf("\nOpcion invalida");
                    system("cls");
                    break;

        }

        printf("\nMenu");
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        printf("\n10. Salir\n");
        scanf("%d",&option);


    }while(option != 10);
    return 0;
}
