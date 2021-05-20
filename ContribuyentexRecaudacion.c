#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ContribuyentexRecaudacion.h"

int modificarContribuyente(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudacion[], int tamRecaudacion)
{
    int posicion;
    char nuevoNombre[25];
    char nuevoApellido[25];
    int nuevoCuil;
    int error=-1;
    if(contribuyentes!=NULL && tamContribuyente>0 && recaudacion!=NULL && tamRecaudacion>0)
    {
        mostrarContribuyentes(contribuyentes, tamContribuyente,recaudacion, tamRecaudacion);
        printf("Ingrese id a modificar: ");
        scanf("%d", &posicion);
        for(int i=0; i<tamContribuyente; i++)
        {
            if(contribuyentes[i].idContribuyente==posicion)
            {
                switch(submenuModificarContribuyente())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nuevoNombre);
                    strcpy(contribuyentes[i].nombre, nuevoNombre);
                    printf("Cambio de nombre exitoso\n");
                    error=1;
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(nuevoApellido);
                    strcpy(contribuyentes[i].apellido, nuevoApellido);
                    printf("Cambio de apellido exitoso\n");
                    error=1;
                    break;
                case 3:
                    printf("Ingrese nuevo cuil(sin guion): ");
                    scanf("%d", &nuevoCuil);
                    contribuyentes[i].cuil = nuevoCuil;
                    printf("Cambio de cuil exitoso\n");
                    error=1;
                    break;
                }
            }
        }
    }
    return error;
}

void mostrarContribuyente(eContribuyente contribuyente, eRecaudacion recaudacion)
{
    char descripcionTipoRecaudacion[25];
    int mes;
    float importe;
    int idRecaudacion;
    if(recaudacion.tipo==1)
    {
        strcpy(descripcionTipoRecaudacion, "ARBA");
    }
    else if(recaudacion.tipo==2)
    {
        strcpy(descripcionTipoRecaudacion, "IIBB");
    }
    else if(recaudacion.tipo==3)
    {
        strcpy(descripcionTipoRecaudacion, "GANANCIAS");
    }
    else
    {
        strcpy(descripcionTipoRecaudacion, "NINGUNO");
    }
    if(contribuyente.idContribuyente==recaudacion.idContribuyente)
    {

        mes=recaudacion.mes;
        importe=recaudacion.importe;
        idRecaudacion=recaudacion.idRecaudacion;
    }
    else
    {
        mes=0;
        importe=0;
        idRecaudacion=0;
    }
    printf(" %d       %s       %s     %d         %d           %d           %.2f          %s        %s\n",contribuyente.idContribuyente,
    contribuyente.nombre,contribuyente.apellido,contribuyente.cuil,idRecaudacion,
    mes, importe,descripcionTipoRecaudacion,contribuyente.idEstado);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

int mostrarContribuyentes(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudaciones[], int tamRecaudacion)
{
    int error=-1;
    if(contribuyentes!=NULL && tamContribuyente>0 && recaudaciones!=NULL && tamRecaudacion>0)
    {
        printf("ID-CONTRIB  NOMBRE    APELLIDO    CUIL       ID-RECAU        MES        IMPORTE         TIPO        ESTADO\n");
        for(int i=0; i<tamContribuyente; i++)
        {
            if(contribuyentes[i].isEmpty==0)
            {
                mostrarContribuyente(contribuyentes[i], recaudaciones[i]);
                error=0;
            }
        }
    }
    return error;
}

int bajaContribuyente(eContribuyente contribuyente[], int tamContribuyente, eRecaudacion recaudaciones[], int tamRecaudaciones)
{
    int posicion;
    char confirmacion;
    int error=-1;
    if(contribuyente!=NULL && tamContribuyente>0 && recaudaciones!=NULL && tamRecaudaciones>0)
    {
        printf("Ingrese id de musico a dar de baja: ");
        scanf("%d", &posicion);
        for(int i=0; i<tamContribuyente; i++)
        {
            if(contribuyente[i].idContribuyente==posicion)
            {
                mostrarContribuyente(contribuyente[i],recaudaciones[i]);
                printf("Deseas continuar con la baja(Y/N): ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = toupper(confirmacion);
                while(confirmacion!='Y' && confirmacion!='N')
                {
                    printf("Error. Deseas continuar con la baja(Y/N): ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = toupper (confirmacion);
                }
                if(confirmacion=='Y')
                {
                    error=1;
                    contribuyente[i].isEmpty=1;
                    contribuyente[i].idContribuyente=' ';
                    recaudaciones[i].idRecaudacion=' ';
                    recaudaciones[i].idContribuyente=' ';
                    recaudaciones[i].isEmpty=1;
                    printf("Baja exitosa\n");
                    break;
                }
                else
                {
                    printf("Baja cancelada\n");
                    break;
                }
            }
        }
    }
    return error;
}

int altaRecaudacion(eRecaudacion recaudacion[],int tamRecaudacion,eContribuyente contribuyente[], int tamContribuyente, int posicion,int idRecaudacion)
{
    int error=-1;
    int mostrar;
    int tipoRecaudacion;
    int idIngresado;
    if(recaudacion!=NULL && tamRecaudacion>0 && posicion!=-1 && contribuyente!=NULL && tamContribuyente>0)
    {

        mostrar = mostrarContribuyentes(contribuyente, tamContribuyente,recaudacion, tamRecaudacion);
        if(mostrar==-1)
        {
            printf("Se debe cargar contribuyente antes de agregar una recaudacion\n");
        }
        else
        {
            printf("Ingrese id de contribuyente del listado: ");
            scanf("%d", &idIngresado);

            for(int i=0; i<tamRecaudacion; i++)
            {
                /*
                if(idIngresado != contribuyente[i].idContribuyente)
                {
                    printf("Id de contribuyente inexistente\n");
                }
                */
                if(idIngresado== contribuyente[i].idContribuyente)
                {
                    printf("Ingrese mes(1-12): ");
                    scanf("%d", &recaudacion[i].mes);

                    tipoRecaudacion = subMenuTipoRecaudacion();
                    recaudacion[i].tipo = tipoRecaudacion;

                    printf("Ingrese importe: ");
                    scanf("%f", &recaudacion[i].importe);

                    recaudacion[i].isEmpty=0;

                    recaudacion[i].idRecaudacion = idRecaudacion;

                    recaudacion[i].idContribuyente = idIngresado;

                    strcpy(recaudacion[i].estado,"Activo");

                    strcpy(contribuyente[i].idEstado, "Activo");

                    error=1;

                    printf("Alta recaudacion exitoso\n");

                    break;
                }
            }
        }
    }
    return error;
}

int RefinanciarRecaudacion(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudacion[], int tamRecaudacion)
{
    int error=-1;
    char confirmacion;
    int mostrar;
    int idContribuyente;
    if(contribuyentes!=NULL && tamContribuyente>0 && recaudacion!=NULL && tamRecaudacion>0)
    {
        mostrar = mostrarContribuyentes(contribuyentes, tamContribuyente,recaudacion, tamRecaudacion);
        if(mostrar==-1)
        {
            printf("Se debe cargar contribuyente antes de refinanciar una recaudacion\n");
        }
        else
        {
            printf("Ingrese id de contribuyente del listado: ");
            scanf("%d", &idContribuyente);
            for(int i=0; i<tamContribuyente; i++)
            {
                if(recaudacion[i].idContribuyente == idContribuyente && strcmp(recaudacion[i].estado, "Activo")==0)
                {
                    printf("Desear confirmar refinanciacion(Y/N): \n");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = toupper(confirmacion);
                    while(confirmacion!='Y' && confirmacion!='N')
                    {
                        printf("Error. Desear confirmar refinanciacion(Y/N): \n");
                        fflush(stdin);
                        scanf("%c", &confirmacion);
                        confirmacion = toupper(confirmacion);
                    }
                    if(confirmacion=='Y')
                    {
                        strcpy(recaudacion[i].estado,"Refinanciar");
                        strcpy(contribuyentes[i].idEstado, "Refinanciar");
                        error=1;
                        printf("Refinanciado exitoso\n");
                        break;
                    }
                    else
                    {
                        printf("Refinanciamiento cancelado\n");
                        break;
                    }
                }
            }
        }
    }
    return error;
}

int SaldarRecaudacion(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudacion[], int tamRecaudacion)
{
    int error=-1;
    char confirmacion;
    int mostrar;
    int idContribuyente;
    if(contribuyentes!=NULL && tamContribuyente>0 && recaudacion!=NULL && tamRecaudacion>0)
    {
        mostrar = mostrarContribuyentes(contribuyentes, tamContribuyente,recaudacion, tamRecaudacion);
        if(mostrar==-1)
        {
            printf("Se debe cargar contribuyente antes de saldar una recaudacion\n");
        }
        else
        {
            printf("Ingrese id de contribuyente del listado: ");
            scanf("%d", &idContribuyente);
            for(int i=0; i<tamContribuyente; i++)
            {
                if(recaudacion[i].idContribuyente == idContribuyente && (strcmp(recaudacion[i].estado, "Activo")==0 || strcmp(recaudacion[i].estado, "Refinanciar")==0))
                {
                    printf("Desear confirmar saldar(Y/N): \n");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = toupper(confirmacion);
                    while(confirmacion!='Y' && confirmacion!='N')
                    {
                        printf("Error. Desear confirmar saldar(Y/N): \n");
                        fflush(stdin);
                        scanf("%c", &confirmacion);
                        confirmacion = toupper(confirmacion);
                    }
                    if(confirmacion=='Y')
                    {
                        strcpy(recaudacion[i].estado,"Saldado");
                        strcpy(contribuyentes[i].idEstado, "Saldado");
                        error=1;
                        printf("Saldado exitoso\n");
                        break;
                    }
                    else
                    {
                        printf("Saldado cancelado\n");
                        break;
                    }
                }
            }
        }
    }
    return error;
}

void mostrarRecaudacion(eRecaudacion recaudacion, eContribuyente contribuyente)
{
    char descripcionTipo[20];
    if(recaudacion.tipo==1)
    {
        strcpy(descripcionTipo, "ARBA");
    }
    else if(recaudacion.tipo==2)
    {
        strcpy(descripcionTipo, "IIBB");
    }
    else if(recaudacion.tipo==3)
    {
        strcpy(descripcionTipo, "GANANCIAS");
    }
    printf("%d      %d        %d        %s      %.2f      %s     %s     %s     %d\n",recaudacion.idRecaudacion,recaudacion.idContribuyente,recaudacion.mes,
    descripcionTipo,recaudacion.importe,recaudacion.estado,contribuyente.nombre,contribuyente.apellido,contribuyente.cuil);
    printf("-------------------------------------------------------------------------------------------------\n");
}


int mostrarRecaudacionesSaldadas(eRecaudacion recaudacion[], int tamRecaudacion, eContribuyente contribuyente[], int tamContribuyente)
{
    int error=-1;
    printf("ID-REC   ID-CONTR    MES      TIPO        IMPORT    ESTADO    NOMBRE    APELLIDO    CUIL\n");
    if(recaudacion!=NULL && tamRecaudacion>0)
    {
        for(int i=0; i<tamRecaudacion; i++)
        {
            if(recaudacion[i].isEmpty==0 && strcmp(recaudacion[i].estado, "Saldado")==0)
            {
                mostrarRecaudacion(recaudacion[i],contribuyente[i]);
                error=1;
            }
        }
    }
    return error;
}
