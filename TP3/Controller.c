#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    LinkedList* nuevoEmpleado;
    LinkedList* aux;
    char buffer[4][128];
    int cant;
    int contador;
    contador = 0;
    FILE * file;

    file = fopen(path,"r");

    if(file != NULL)
    {
        //Leida fantasma
        cant = fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(cant==4)
        {
            while(!feof(file))
            {
                cant = fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                if(cant!=4)
                {
                    if(feof(file))
                    {
                        error = 0;
                        break;
                    }

                    break;
                }
                nuevoEmpleado = (LinkedList*)employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(aux == NULL)
                {
                    break;
                }
                *(pArrayListEmployee+contador) = *nuevoEmpleado;
                contador++;

                aux = (LinkedList*) realloc ( pArrayListEmployee,sizeof(Employee)*(contador+1));
                if(aux==NULL)
                {
                    break;
                }
                pArrayListEmployee = aux;
            }
        }
        fclose(file);
    }
    free(nuevoEmpleado);
    free(aux);

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    int cant;
    FILE *file;

    file = fopen(path,"rb");
    if(file != NULL)
    {
        //Evita leer los nombres de cada columna
        fseek(file,sizeof(Employee),SEEK_SET);

        while(!feof(file))
        {
            cant = fread(pArrayListEmployee,sizeof(Employee),1,file);
            if(cant != 4)
            {
                if(feof(file))
                {
                    error = 0;
                    break;
                }
                break;
            }

        }
    }
    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

