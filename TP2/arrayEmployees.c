#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

int menu()
{
    int opcion;
    printf("\n***  ABM EMPLEADOS  ***");
    printf("\n1. Alta empleado.");
    printf("\n2. Modificar empleado");
    printf("\n3. Bajar empleado");
    printf("\n4. Informar");
    printf("\n Ingrese opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
void altaEmpleado(Employee* list,int len,int* contId)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(name);
    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(lastName);
    printf("Ingrese salario: ");
    scanf("%f",&salary);
    printf("Ingrese sector: ");
    scanf("%d",&sector);
    *contId=*contId+1;
    id=*contId;

    if(addEmployee(list,len,id,name,lastName,salary,sector))
    {
        printf("\nNo hay espacio libre");
    }
    else
    {
        printf("\nEl empleado ha sido de alta con exito!");
    }
}
void modificarEmpleado(Employee* list,int len,int* contId)
{
    int id;
    int opcion;
    int found;
    if(*contId>0)
    {
        printf("\nIngrese el ID del empleado a modificar: ");
        scanf("%d",&id);
        found=findEmployeeById(list,len,id);
        if(found==-1)
        {
            printf("\nEl empleado no ha sido encontrado");
        }
        else
        {
            printf("\nQue desea modificar?");
            printf("\n1) Nombre");
            printf("\n2) Apellido");
            printf("\n3) Sueldo");
            printf("\n4) Sector");
            printf("\n5) Salir");
            printf("\nSeleccione opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("\nIngrese nuevo nombre");
                fflush(stdin);
                gets(list[found].name);
                printf("\nSe ha modificado el nombre exitosamente");
                break;
            case 2:
                printf("\nIngrese nuevo apellido");
                fflush(stdin);
                gets(list[found].lastName);
                printf("\nSe ha modificado el apellido exitosamente");
                break;
            case 3:
                printf("\nIngrese nuevo sueldo");
                scanf("%f",&list[found].salary);
                printf("\nSe ha modificado el salario exitosamente");
                break;
            case 4:
                printf("\nIngrese nuevo sector");
                scanf("%d",&list[found].sector);
                printf("\nSe ha modificado el sector exitosamente");
                break;
            case 5:
                system("cls");
                break;
            default:
                printf("\n\nOpcion invalida\n\n");
                break;
            }

        }

    }
    else
    {
        printf("Error. Debe haberse dado de alta al menos un empleado");
    }
}
void bajarEmpleado(Employee* list,int len,int* contId)
{
    int id;
    int error;
    if(*contId>0)
    {
        printf("\nIngrese ID del empleado a bajar: ");
        scanf("%d",&id);
        error=removeEmployee(list,len,id);
        if(error==-1)
        {
            printf("El empleado seleccionado no existe!");
        }
        else
        {
            printf("El empleado se ha bajado con exito!");
        }

    }
    else
    {
        printf("Error. Debe haberse dado de alta al menos un empleado");
    }
}

int initEmployees(Employee* list, int len)
{
    int i;
    int error;
    if(list==NULL)
    {
        error=-1;
    }
    else
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
    }

    return error;
}

int addEmployee(Employee* list, int len, int id, char* name, char* lastName,float salary,int sector)
{
    int i;
    int freeSpace=-1;
    if(list==NULL)
    {
        freeSpace=-1;
    }
    else
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                freeSpace=0;
                strcpy(list[i].name,name);
                strcpy(list[i].lastName,lastName);
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].id=id;
                list[i].isEmpty=0;
                break;
            }

        }
    }

    return freeSpace;
}
int findEmployeeById(Employee* list,int len,int id)
{
    int i;
    int placeFound;
    placeFound=-1;
    if(list==NULL)
    {
        placeFound=-1;
    }
    else
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                placeFound=i;
                break;
            }
        }
    }

    return placeFound;
}
int removeEmployee(Employee *list,int len, int id)
{
    int i;
    int found;
    found=-1;
    if(list==NULL)
    {
        found=-1;
    }
    else
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                list[i].isEmpty=1;
                found=1;
                break;
            }
        }
    }

    return found;
}
int sortEmployees(Employee* list,int len,int order)
{
    int i;
    int j;
    Employee aux;

    int error;
    if(list==NULL)
    {
        error=-1;
    }
    else
    {
        if(order==1)
        {

            for(i=0; i<len-1; i++)
            {
                for(j=0; j<len; j++)
                {
                    strlwr(list[i].lastName);
                    strlwr(list[j].lastName);

                    if(strcmp(list[i].lastName,list[j].lastName)>0 && list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }

            for(i=0; i<len-1; i++)
            {

                for(j=0; j<len; j++)
                {

                    if(list[i].sector>list[j].sector && (strcmp(list[i].lastName,list[j].lastName)==0) && list[i].isEmpty==0 && list[j].isEmpty==0)
                    {

                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
            printf("\nSe ha ordenado con exito de forma acendente");
        }
        else
        {
            for(i=0; i<len-1; i++)
            {
                for(j=0; i<len; j++)
                {
                    strlwr(list[i].lastName);
                    strlwr(list[j].lastName);
                    if(strcmp(list[i].lastName,list[j].lastName)<0  && list[i].isEmpty==0 && list[j].isEmpty==0)
                    {

                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
            for(i=0; i<len-1; i++)
            {
                for(j=0; i<len; j++)
                {
                    if(list[i].sector<list[j].sector && (strcmp(list[i].lastName,list[j].lastName)==0)  && list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }

                printf("\nSe ha ordenado con exito de forma descendente");
            }

        }

    }
    return error;

}
int printfEmployees(Employee* list,int len)
{
    int i;
    printf("\nID    Nombre    Apellido     Sueldo   Sector");
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n%d    %s     %s      %.2f      %d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}
void informarEmpleados(Employee* list,int len,int* contId)
{
    int opcion;
    int i;
    int contadorSalarios;
    float acumuladorSalarios;
    float promedioSalarios;
    int mayorAlSalarioPromedio;
    contadorSalarios=0;
    acumuladorSalarios=0;
    mayorAlSalarioPromedio=0;
    if(*contId>0)
    {
        printf("\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.");
        printf("\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.");
        printf("\nIngerse opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            sortEmployees(list,len,1);
            printfEmployees(list,len);
            break;
        case 2:
            for(i=0; i<len; i++)
            {
                if(list[i].isEmpty==0)
                {
                    contadorSalarios++;
                    acumuladorSalarios=acumuladorSalarios+list[i].salary;

                }
            }
            promedioSalarios=acumuladorSalarios/(float)contadorSalarios;
            for(i=0; i<len; i++)
            {
                if(list[i].salary>promedioSalarios && list[i].isEmpty==0)
                {
                    mayorAlSalarioPromedio++;
                }
            }
            printf("\nSalarios Totales: %.2f",acumuladorSalarios);
            printf("\nPromedio de salarios: %.2f",promedioSalarios);
            printf("\nEmpleados que superan al sueldo promedio: %d\n\n",mayorAlSalarioPromedio);
            break;
        default:
            printf("\nOpcion invalida!");
            break;
        }
    }
    else
    {
        printf("Error. Debe haberse dado de alta al menos un empleado");
    }
}

