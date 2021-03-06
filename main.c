#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"
#include "Contribuyente.h"
#include "ContribuyentexRecaudacion.h"
//TAMA?O DE MIS ARRAYS
#define TAM_CONTRIBUYENTE 50
#define TAM_RECAUDACION 50
int submenuInformes();
int subMenuPreguntar();
int main()
{
    eContribuyente contribuyentes[TAM_CONTRIBUYENTE];
    eRecaudacion recaudaciones[TAM_RECAUDACION];
    int seguirPrincipal=0;
    //VARIABLES CONTRIBUYENTES
    int posicionContribuyente;
    int errorContribuyenteAlta;
    int idContribuyente=1000;
    int contadorInicialContribuyente=0;
    //VARIABLES CONTRIBUYENTES
    int posicionRecaudacion;
    int errorAltaRecaudacion;
    int idRecaudacion=100;
    int contadorInicialRecaudacion=0;
    //INICIALIZO
    iniciarContribuyente(contribuyentes, TAM_CONTRIBUYENTE);
    iniciarRecaudacion(recaudaciones, TAM_RECAUDACION);

    do
    {
        switch(MenuPrincipal())
        {
        case 1:
            posicionContribuyente = buscarContribuyenteVacio(contribuyentes, TAM_CONTRIBUYENTE, &errorContribuyenteAlta);
            if(errorContribuyenteAlta!=-1)
            {
                altaContribuyente(contribuyentes, TAM_CONTRIBUYENTE, posicionContribuyente, idContribuyente);
                idContribuyente++;
                contadorInicialContribuyente=1;
            }
            else
            {
                printf("No se encuentra lugar vacio\n");
            }
            break;
        case 2:
            if(contadorInicialContribuyente==1)
            {
                modificarContribuyente(contribuyentes, TAM_CONTRIBUYENTE, recaudaciones, TAM_RECAUDACION);
            }
            else
            {
                printf("Hay que cargar contribuyentes antes de modificar\n");
            }
            break;
        case 3:
            if(contadorInicialContribuyente==1)
            {
                mostrarContribuyentes(contribuyentes, TAM_CONTRIBUYENTE, recaudaciones, TAM_RECAUDACION);
                bajaContribuyente(contribuyentes, TAM_CONTRIBUYENTE, recaudaciones, TAM_RECAUDACION);
            }
            else
            {
                printf("Debes cargar antes de dar de baja\n");
            }
            break;
        case 4:
            if(contadorInicialContribuyente==1)
            {
                posicionRecaudacion = buscarRecaudacionvacia(recaudaciones, TAM_RECAUDACION, &errorAltaRecaudacion);
                if(errorAltaRecaudacion!=-1)
                {
                    if(altaRecaudacion(recaudaciones, TAM_RECAUDACION, contribuyentes, TAM_CONTRIBUYENTE, posicionRecaudacion, idRecaudacion)==1)
                    {
                        idRecaudacion++;
                        contadorInicialRecaudacion=1;
                    }
                }
                else
                {
                    printf("No se encuentra lugar vacio\n");
                }
            }
            else
            {
                printf("Debes cargar un contribuidor antes de una recaudacion\n");
            }
            break;
        case 5:
            if(contadorInicialRecaudacion==1 && contadorInicialContribuyente==1)
            {
                RefinanciarRecaudacion(contribuyentes, TAM_CONTRIBUYENTE, recaudaciones, TAM_RECAUDACION);
            }
            else
            {
                printf("Se debe cargar un contribuidor y una recaudacion para refinanciar\n");
            }
            break;
        case 6:
            if(contadorInicialRecaudacion==1 && contadorInicialContribuyente==1)
            {
                SaldarRecaudacion(contribuyentes, TAM_CONTRIBUYENTE, recaudaciones, TAM_RECAUDACION);
            }
            else
            {
                printf("Se debe cargar un contribuidor y una recaudacion para saldar\n");
            }
            break;
        case 7:
            if(mostrarContribuyentes(contribuyentes, TAM_CONTRIBUYENTE, recaudaciones, TAM_RECAUDACION)==-1)
            {
                printf("    No se cargo ningun contribueyente\n");
            }
            break;
        case 8:
            if(mostrarRecaudacionesSaldadas(recaudaciones, TAM_RECAUDACION, contribuyentes, TAM_CONTRIBUYENTE)==-1)
            {
                printf("    No se cargo ninguna recaudacion Saldada\n");
            }
            break;
        case 9:
            switch(submenuInformes())
            {
            case 1:
                if(mostrarRecaudacionesFinanciar(recaudaciones, TAM_RECAUDACION, contribuyentes, TAM_CONTRIBUYENTE)==-1)
                {
                    printf("Se debe cargar recaudaciones en estado financiar antes de mostrar\n");
                }
                break;
            case 2:
                if(mostrarRecaudacionesSaldadasMayorMil(recaudaciones, TAM_RECAUDACION, contribuyentes, TAM_CONTRIBUYENTE)==-1)
                {
                    printf("Se debe cargar recaudaciones en estado saldado antes de mostrar\n");
                }
                break;
            case 3:
                if(mostrarDatosContribuyentes(recaudaciones, TAM_RECAUDACION, contribuyentes, TAM_CONTRIBUYENTE)==-1)
                {
                    printf("Se debe cargar recaudaciones antes de mostrar\n");
                }
                break;
            case 4:
                if(mostrarContribuyentesFebrero(recaudaciones, TAM_RECAUDACION, contribuyentes, TAM_CONTRIBUYENTE)==-1)
                {
                    printf("Se debe cargar recaudaciones mes de Febrero antes de mostrar\n");
                }
                break;
            }
            break;
        }
        system("pause");

    }
    while(seguirPrincipal==0);
    return 0;
}

int submenuInformes()
{
    system("cls");
    int opcion;
    printf("|------INFORMES------|\n");
    printf("|  1) CONTR REFIN    |\n");
    printf("|  2) RECAUD SALD    |\n");
    printf("|  3) RECAUD USUAR   |\n");
    printf("|  4) RECAUD FEBRER  |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>4)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

