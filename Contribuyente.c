#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyente.h"

int MenuPrincipal()
{
    system("cls");
    int opcion;
    printf("|--------AMB---------|\n");
    printf("|  1) ALTA CONTRIB   |\n");
    printf("|  2) MODIF CONTRIB  |\n");
    printf("|  3) BAJA CONTRIB   |\n");
    printf("|  4) ALTA RECAUD    |\n");
    printf("|  5) REFIN RECAUD   |\n");
    printf("|  6) SALDAR RECAUD  |\n");
    printf("|  7) IMP CONTRIB    |\n");
    printf("|  8) IMP RECAUD     |\n");
    printf("|  9) INFORMES       |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>9)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int iniciarContribuyente(eContribuyente contribuyentes[], int tamContribuyente)
{
    int error=-1;
    if(contribuyentes!=NULL && tamContribuyente>0)
    {
        error=1;
        for(int i=0; i<tamContribuyente; i++)
        {
            contribuyentes[i].isEmpty=1;
        }
    }
    return error;
}

int buscarContribuyenteVacio(eContribuyente contribuyentes[], int tamContribuyente, int* error)
{
    *error=-1;
    int posicion=-1;
    if(contribuyentes!=NULL && tamContribuyente>0)
    {
        for(int i=0; i<tamContribuyente; i++)
        {
            if(contribuyentes[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaContribuyente(eContribuyente contribuyentes[],int tamContribuyente,int posicion,int idContribuyente)
{
    int error=-1;
    if((contribuyentes!=NULL && tamContribuyente>0) && posicion!=-1)
    {
        contribuyentes[posicion].isEmpty=0;

        contribuyentes[posicion].idContribuyente = idContribuyente;

        strcpy(contribuyentes[posicion].idEstado, "Ninguno");

        printf("Ingrese nombre de contribuyente: ");
        fflush(stdin);
        scanf("%s", contribuyentes[posicion].nombre);

        printf("Ingrese apellido de contribuyente: ");
        fflush(stdin);
        scanf("%s", contribuyentes[posicion].apellido);

        printf("Ingrese cuil de contribuyente(Sin guion): ");
        //VALIDAR 11 DIGITOS
        scanf("%d", &contribuyentes[posicion].cuil);

        error=1;

        printf("Alta exitosa\n");
    }
    return error;
}

int submenuModificarContribuyente()
{
    system("cls");
    int opcion;
    printf("|---MENU MODIFICAR---|\n");
    printf("|  1) NOMBRE         |\n");
    printf("|  2) APELLIDO       |\n");
    printf("|  3) CUIL           |\n");
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
