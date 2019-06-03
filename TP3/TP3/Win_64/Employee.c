#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* emp = (Employee*) malloc (sizeof(Employee));
    if(emp != NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre,"") ;
        emp->sueldo = 0;
        emp->horasTrabajadas = 0;
    }

    return emp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* sueldoStr,char* horasTrabajadasStr)
{
    int error = 1;
    Employee* emp = (Employee*) malloc (sizeof(Employee));
    if(emp != NULL)
    {
        if(employee_setId(emp,atoi(idStr))==0)
        {
            if(employee_setNombre(emp,nombreStr)==0)
            {
                if(employee_setHorasTrabajadas(emp,nombreStr)==0)
                {
                    if(employee_setSueldo(emp,sueldoStr)==0)
                    {
                        error = 0;

                    }
                }
            }
        }
        if (error = 1)
        {
            free(emp);
            emp = NULL;
        }
    }
    return emp;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;

    if(this != NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if (this != NULL || sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;

}

int employee_setId(Employee* this,int id)
{
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}
int employee_getId(Employee* this,int* sueldo)
{
    int error = 1;
    if (this != NULL || id!=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;

}
