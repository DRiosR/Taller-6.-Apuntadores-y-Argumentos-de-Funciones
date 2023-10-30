#include <stdio.h>
#include "RRD.h"
#include <time.h>
#include <stdlib.h>

int multiplicarPorDos(int *entero);
void llenar_arreglo(int arreglo[], int tamano);
void sumarAElementos(int arreglo[], int tamano, int entero);
int main()
{
    srand(time(NULL));

    // 1
    int x, *ptr;
    // 2
    int x2, *ptr2;
    // 3
    int arreglo[7], *ptr3;
    //
    int areglo2[] = {2, 3, 1, 7, 4, 9}, con, numerp_a_sumar;
    int menu, opc, i;
    do
    {
        menu = 0;
        opc = validarnumeros("MENU\n1.Apuntadores Básicos\n2.Pasar Apuntadores a una Funcion\n3.-Arreglos\n4.Modificar Elementos de un Arreglo\n0.-SALIR\n", 0, 4);
        switch (opc)
        {
        case 0:
            system("cls");
            printf("FIN DEL PROGRAMA");
            break;
        case 1:
            printf("[========ACTIVIDAD1========]\n");
            x = 2;
            ptr = &x;
            
            printf("x = %d\nptr = %p\n", x, ptr);

            printf("[==========================]\n");
            menu = repetir();
            break;
        case 2:
            printf("[========ACTIVIDAD2========]\n");
            x2 = 10;
            printf("x2 = %d\n", x2);
            ptr2 = &x2;
            *ptr2 = multiplicarPorDos(ptr2);
            printf("x2 * 2 ==%d\n", *ptr2);
            printf("[==========================]\n");
            menu = repetir();
            break;
        case 3:
            printf("[========ACTIVIDAD3========]\n");
            llenar_arreglo(arreglo, 7);
            for (i = 0; i < 7; i++)
            {
                ptr3 = &arreglo[i];
                printf("valor %d en posicion %d\n", *ptr3, i + 1);
            }
            printf("[==========================]\n");

            menu = repetir();
            break;
        case 4:
            numerp_a_sumar = 10;

            printf("[========ACTIVIDAD4========]\n");

            printf("valor antes de la suma:\n");
            con = sizeof(areglo2) / sizeof(areglo2[0]);
            for (int i = 0; i < con; i++)
            {
                printf("%d=%d\n", i + 1, areglo2[i]);
            }
            printf("numero que se sumara :%d\n", numerp_a_sumar);

            sumarAElementos(areglo2, con, numerp_a_sumar);
            for (int i = 0; i < con; i++)
            {
                printf("%d=%d\n", i + 1, areglo2[i]);
            }

            printf("[==========================]\n");

            menu = repetir();
            break;
        }
    } while (menu == 1);
}

int multiplicarPorDos(int *entero)
{
    int multi;
    multi = *entero * 2;
    return multi;
}

void llenar_arreglo(int arreglo[], int tamano)
{
    int i, j, repetido;

    for (i = 0; i < tamano; i++)
    {
        do
        {
            repetido = 0;
            arreglo[i] = rand() % 50 + 1;
            for (j = 1; j < i; j++)
            {
                if (arreglo[i] == arreglo[j])
                {
                    repetido = 1;
                }
            }
        } while (repetido == 1);
    }
}

void sumarAElementos(int arreglo[], int tamano, int entero)
{
    int *x = arreglo;

    for (int i = 0; i < tamano; i++)
    {
    
            *x = *x + entero;
            x++;
        
    }
}
