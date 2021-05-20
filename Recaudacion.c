#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"

int iniciarRecaudacion(eRecaudacion recaudacion[], int tamRecaudacion)
{
    int error=-1;
    if(recaudacion!=NULL && tamRecaudacion>0)
    {
        error=1;
        for(int i=0; i<tamRecaudacion; i++)
        {
            recaudacion[i].isEmpty=1;
        }
    }
    return error;
}
int buscarRecaudacionvacia(eRecaudacion recaudacion[], int tamRecaudacion, int* error)
{
    *error=-1;
    int posicion=-1;
    if(recaudacion!=NULL && tamRecaudacion>0)
    {
        for(int i=0; i<tamRecaudacion; i++)
        {
            if(recaudacion[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}


int subMenuTipoRecaudacion()
{
    system("cls");
    int opcion;
    printf("|--TIPO RECAUDACION--|\n");
    printf("|  1) ARBA           |\n");
    printf("|  2) IIBB           |\n");
    printf("|  3) GANANCIAS      |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>3)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}
