#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>

int main()
{
    float num1;
    float num2;
    int opcion;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorial;
    int resultadoFactorial2;
    int flag;
    flag=0;
    num1=0;
    num2=0;

    while(opcion!=5)
    {
        printf("\nTRABAJO PRACTICO Nª1\n");
        printf("1) Ingresar 1er operando(A=%f)\n",num1);
        printf("2) Ingresar 2do operando(B=%f)\n",num2);
        printf("3) Calcular todas las operaciones\n");
        printf("4) Informar resultados \n");
        printf("5) Salir.\n");
        scanf("%d",&opcion);

        while(opcion>5 || opcion<1)
        {
            printf("La opcion ingresada es incorrecta.\n");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
            printf("Ingrese el numero: ");
            scanf("%f",&num1);
            break;
            case 2:
            printf("Ingrese el numero: ");
            scanf("%f",&num2);
            break;
            case 3:
            resultadoSuma=fsumar(num1,num2);
            resultadoResta=frestar(num1,num2);
            resultadoDivision=fdivision(num1,num2);
            resultadoMultiplicacion=fmultiplicacion(num1,num2);
            resultadoFactorial=ffactorial((int)num1);
            resultadoFactorial2=ffactorial((int)num2);
            flag=1;
            break;
            case 4:
            if(flag==1)
            {
                printf("El resultado de %.2f+%.2f es: %.4f\n",num1,num2,resultadoSuma);//suma
                printf("El resultado de %.2f-%.2f es: %.4f\n",num1,num2,resultadoResta);//resta
                if(num1==0||num2==0)//division
                {
                    printf("El resultado de %.0f/%.0f es: ERROR (No se puede dividir por 0)\n",num1,num2);
                }
                else
                {
                    printf("El resultado de %.2f/%.2f es: %.4f\n",num1,num2,resultadoDivision);
                }

                printf("El resultado de %.2f*%.2f es: %.4f\n",num1,num2,resultadoMultiplicacion);//multiplicacion
                if(resultadoFactorial==-1)//FACTORIAL
                {
                    printf("El factorial de %d es: ERROR (No puede realizarse el factorial de numeros negativos) ",(int)num1);

                }
                else
                {
                    printf("El factorial de %d es: %d ",(int)num1,resultadoFactorial);

                }
                if(resultadoFactorial2==-1)
                {
                    printf("y El factorial de %d es ERROR (No puede realizarse el factorial de numeros negativos)\n",(int)num2);
                }
                else
                {
                    printf("y El factorial de %d es %d\n",(int)num2,resultadoFactorial2);
                }


                system(("pause"));
                flag=0;
                num1=0;
                num2=0;
            }
            else
            {
                printf("Primero debe realizar todas las operaciones\n ");
            }

            break;
        }


    }


    return 0;
}
