#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "inputs.h"
int getIntIntentos(int* input,char* msj,char* eMsj,int minimo,int maximo,int reintentos)
{
    int i;
    int error;
    int num;
    error=0;
    num=*input;
    printf("%s",msj);
    scanf("%d",&num);
    if(num<minimo||num>maximo)
    {
        if(reintentos)
        {
            for(i=0; i<reintentos; i++)
            {
                printf("%s",eMsj);
                scanf("%d",&num);
                if(num>=minimo&&num<=maximo)
                {
                    *input=num;
                    error=0;
                    break;
                }
                else
                {

                    error=1;
                }
            }

        }
        else
        {
            while(num<minimo||num>maximo)
            {
                printf("%s",eMsj);
                scanf("%d",&num);
            }
            *input=num;
        }
    }
    else
    {
        *input=num;
    }
    return error;
}

/*int getInt(int*input,char*msj,char*eMsj,int minimo,int maximo)
{
    int error = 0;
    printf("%s",msj);
    scanf("%d",input);
    if(minimo!=maximo)
    {
        if(*input>maximo || *input<minimo)
        {
            printf("%s",eMsj);
            scanf("%d",input);
        }
        if(*input>maximo || *input<minimo)
        {
            error = 1;
        }
    }

    return error;
}*/

int getInt(int* input,char*msj,char*eMsj,int minimo)
{
    int num;
    int error = 0;
    printf("%s",msj);
    scanf("%d",&num);

    if(num < minimo)
    {
        printf("%s",eMsj);
        system("pause");
        error = 1;
    }
    *input = num;

    return error;
}



int getRandom(int primerNumero, int ultimoNumero,int primeraVez)
{
    if(primeraVez)
    {
        srand(time(NULL));
    }
    int random;
    random=primerNumero+(rand()%((ultimoNumero+1)-primerNumero));
    return random;
}
int getChar(char*msj,char letraCorrecta)
{
    int confirmacion;
    char letraEntrada;
    confirmacion=0;
    printf("%s",msj);
    scanf("%c",&letraEntrada);

    if(letraEntrada==letraCorrecta)
    {
        confirmacion=1;
    }
    return confirmacion;
}
void getFloatPlus(float*input,char*msj,char*eMsj,float minimo,float maximo)
{
    printf("%s",msj);
    scanf("%f",input);
    while(*input>maximo || *input<minimo)
    {
        printf("%s",eMsj);
        scanf("%f",input);
    }
}
int getString(char* str,char*msj,char*eMsj,int limite)
{
    int error = 0;

    printf(msj);
    fflush(stdin);
    gets(str);
    if(strlen(str)>limite)
    {
        printf(eMsj);
        error=1;
    }


    return error;
}

