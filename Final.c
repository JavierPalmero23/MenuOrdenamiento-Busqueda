/*

Integrantes de Equipo:
    ~ Jose Luis Alfaro Martinez
	~ Antonio Isai Lopez Leal
	~ Javier Martin Palmero Torres

*/

/*
    Sobre una lista enlazada.
        Contar cuantas iteraciones realizo cada Metodo
        Medir timepo de cada metodo
    -Metodos de Ordenamiento
        -Burbuja
        -Seleccion
        -Insercion
        -QuickSort
        ->Merge
    -Metodo de Busqueda
        -Busqueda Binaria
*/

#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

typedef struct pLista{
    struct pLista *Ant;
    int val;
    struct pLista *Sig;
}LISTA;

LISTA *pLista, *pInicio, *pNuevo;
int longitud=0;

//  Funcion Pauas Ejecucion para visualizar Resultados
void vista(){
    printf("\nPulse la tecla ENTER para Continuar...");
    getchar();getchar();
}

//  Impresion de Lista en Pantalla
void Ver(){
    system("cls");
    LISTA *pAux=(LISTA*)malloc(sizeof(LISTA));
    pAux=pInicio;
    printf("\n");
    while(pAux){
        printf("[%d]",pAux->val);
        if(!pAux->Sig||pAux->Sig==pInicio)break;
        pAux=pAux->Sig;
    }
}

//  Ordenamiento por Metodo de Burbuja
void Burbuja(){
    int contador=0;                             //  contador de vueltas realizadas
    LISTA *pAux, *pAuxAnt, *pAuxSig;
    int i,j;
    for(i=0;i<longitud;i++){
        pAux=pInicio;
        pAuxAnt=pInicio;
        for(j=0;j<longitud-1;j++){
            pAuxSig=pAux->Sig;
            if(pAux->val>pAuxSig->val){
                if(pAux==pInicio){
                    pAux->Sig=pAuxSig->Sig;
                    pAuxSig->Sig=pAux;
                    pInicio=pAuxSig;
                }else{
                    pAux->Sig=pAuxSig->Sig;
                    pAuxSig->Sig=pAux;
                    pAuxAnt->Sig=pAuxSig;
                }
            }
            pAuxAnt=pAux;
            pAux=pAuxSig;
        }
        contador+=1;                             //  Se completa una vuelta y aumenta el contador  
    }
    Ver();
    printf("\n\nVueltas realizadas: %d",contador);
    
}

//  Ordenamiiento por Metodo de Seleccion
void Seleccion(){
    LISTA *pActual = pInicio;
    LISTA *pMenor = NULL;
    LISTA *pRecorre = NULL;
    int temp,contador=0;

    while(pActual != NULL){
        pMenor = pActual;
        pRecorre = pActual->Sig;
        while(pRecorre != NULL){
            if(pRecorre->val < pMenor->val){
                pMenor = pRecorre;
            }
            pRecorre = pRecorre->Sig;
        }
        if(pMenor != pActual){
            temp = pActual->val;
            pActual->val = pMenor->val;
            pMenor->val = temp;
        }
        pActual = pActual->Sig;
        contador+=1;
    }
    Ver();
    printf("\n\nVueltas realizadas: %d",contador);
}

//  Ordenamiento por Metodo de Insercion
void Insercion(){
    LISTA *pActual, *pRecorre, *pAnterior;
    int temp,contador=0;

    pActual = pInicio->Sig; // Comienza desde el segundo elemento
    pInicio->Sig = NULL; // Separa el primer elemento de la lista

    while (pActual != NULL) {
        temp = pActual->val;
        pRecorre = pInicio;
        pAnterior = NULL;

        // Busca la posicion adecuada para insertar el elemento actual
        while (pRecorre != NULL && pRecorre->val < temp) {
            pAnterior = pRecorre;
            pRecorre = pRecorre->Sig;
        }

        // Inserta el elemento actual en la posicion adecuada
        if (pAnterior == NULL) {
            pInicio = pActual;
        } else {
            pAnterior->Sig = pActual;
        }
        pActual = pActual->Sig;
        pAnterior->Sig = pInicio->Ant = pNuevo = (LISTA*)malloc(sizeof(LISTA));
        pNuevo->val = temp;
        pNuevo->Sig = NULL;
        pNuevo->Ant = pAnterior;
        contador+=1;
    }
    Ver();
    printf("\n\nVueltas ralizadas: %d",contador);
    
}


void intercambio(LISTA *nodo1, LISTA *nodo2) {                  //  Intercambia los valores de los elementos para el metodo QuickSort
    int temp=nodo1->val;
    int temp2=nodo2->val;
    nodo1->val=temp2;
    nodo2->val=temp;
}

LISTA *particion(LISTA * pComienzo, LISTA* pFinal) {            //  Genera las particiones 'Pivote' a partir de donde se trabajara para el metodo QuickSort
    int pivot = pFinal->val;
    LISTA* i = pComienzo->Ant;
    LISTA *j;
    for (j = pComienzo; j != pFinal; j = j->Sig) {
        if (j->val < pivot) {
            i = (i == NULL) ? pComienzo : i->Sig;
            intercambio(i, j);
        }
    }
    i = (i == NULL)?pComienzo : i->Sig;
    intercambio(i, pFinal);
    return i;
}

//  Ordenamiento por Metodo Quicksort   //
void QuickSort(LISTA *pInicio, LISTA *pFinal) {
    if (pFinal != NULL && pInicio != pFinal && pInicio != pFinal->Sig) {
        LISTA *pMedio = particion(pInicio, pFinal);
        QuickSort(pInicio, pMedio->Ant);
        QuickSort(pMedio->Sig, pFinal);
    }
    Ver();
}

// Ordenamiento por Metodo Merge            //LOS PUNTEROS GENERAN PROBLEMAS

/*
void Division(LISTA *pOrigen,LISTA *pPrincipal, LISTA *pPosterior){
    LISTA *pRap, *pLen;
    pLen=pOrigen;
    pRap=pOrigen->Sig;
    while(pRap!=NULL){
        pRap=pRap->Sig;
        if(pRap!=NULL){
            pLen=pLen->Sig;
            pRap=pRap->Sig;
        }
    }
    pPrincipal=pOrigen;
    pPosterior=pLen->Sig;
    pLen->Sig=NULL;
}
LISTA *Mergeordenado(LISTA *a, LISTA *b);
LISTA *Mergeordenado(LISTA *a, LISTA *b){
    LISTA *resultaso=NULL;
    if(a==NULL){
        return b;
    }else{
        if(b==NULL){
            return a;
        }
    }
    if(a->val<=b->val){
        resultaso=a;
        resultaso->Sig=MergeOrdenado(a->Sig,b);
    }else{
        resultaso=b;
        resultaso->Sig=MergeOrdenado(a,b->Sig);
    }
    return resultaso;
}

LISTA MergeOrdena(LISTA  *pReferencia){
        int contador=0;
        LISTA *pInicio=pReferencia;
        LISTA *a, *b;
        if(pInicio==NULL||pInicio->Sig==NULL){
            return;
        }
        Division(pInicio,&a,&b);
        MergeOrdena(&a);
        MergeOrdena(&b);
        pReferencia=MergeOrdenado(a,b);

        Ver();
        printf("\n\nVueltas ralizadas: %d",contador);
    }
*/

//  Busqueda Binaria
void Binary(){
    LISTA *pAux=pInicio;
    int val,contador=0;
    int pos=longitud/2, ant=0;
    printf("\nSeleccione el Valor a Buscar: ");
    scanf(" %d",&val);
    int i;
    for(i=0;i<pos;i++){                                                                     //  Posiciona la lista en el elemento medio
        pAux=pAux->Sig;
    }
    while(pos>0||pos<longitud){
        if((val<pAux->val&&&(pAux->Ant)->val==ant) || (val>pAux->val&&&(pAux->Sig)->val==ant)){//   Si el valor es mayor/menor y regresa a un valor visto
            printf("\nNo se Ha encontrado el Valor!");
            break;
        }
        if(val<pAux->val){                                                                      //  Si el valor es menor
            if(pAux->Ant==NULL||pos==0){                                                        //  Si ya no hay nada antes
                printf("\nValor no Encontrado! !");
                break;
            }
            ant=&pAux->val;
            pAux=pAux->Ant;
            pos--;
        }
        if(val>pAux->val){                                                                       //  Si el valor es mayor
            if(pAux->Sig==NULL||pos==longitud){                                                  //  Si ya no hay nada despues
                printf("\nValor no Encontrado!! !");
                break;
            }
            ant=&pAux->val;
            pAux=pAux->Sig;
            pos++;
        }
        if(val==pAux->val){
            printf("\nValor encontrado en la posicion: %d",pos);
            break;
        }
        contador+=1;
    }
    printf("\n\nVueltas ralizadas: %d",contador);
    }


int main(){

    struct timeval start, end;
    long seconds,micros;
    int op=0;
    //  Se llena una lista dinamica con elementos dados por el usuario
    do{
        system("cls");
        pNuevo=(LISTA*)malloc(sizeof(LISTA));
        printf("\nIngrese el valor a agregar o 0 para SALIR: \n");
        scanf(" %d",&pNuevo->val);
        pNuevo->Sig=NULL;
        if(pNuevo->val==0){break;}
        if(pLista==NULL){
            pInicio=pNuevo;
            pInicio->Ant=pLista;
            pLista=pNuevo;
        }else{
            pLista->Sig=pNuevo;
            pNuevo->Ant=pLista;
            pLista=pNuevo;
        }
        
        longitud++;
    }while(pInicio);

    //  Inicio del menu de funciones de metodos de ordenamiento y busqueda
    do{
        system("cls");
        printf("\nSeleccione un Metodo de:\nOrdenamiento\n [1] - Burbuja\n [2] - Seleccion\n [3] - Insercion\n [4] - Quicksort\n [5] - Merge\nBusqueda:\n [6] - Binaria (SOLO EFECTIVO EN LISTAS ORDENADAS!)\n\n [0] - Salir\n\nOperacion:");
        scanf(" %d", &op);
        switch (op){
        case 0:
            printf("\nFinalizando ...");
            break;
        case 1:
            gettimeofday(&start, NULL);
            Burbuja();
            gettimeofday(&end, NULL);
             seconds = (end.tv_sec - start.tv_sec);
             micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("\nTiempo de Ejecucion: %ld.%ld seg\n", seconds, micros);
            vista();
            break;
        case 2:
            gettimeofday(&start, NULL);
            Seleccion();gettimeofday(&end, NULL);
             seconds = (end.tv_sec - start.tv_sec);
             micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("\nTiempo de Ejecucion: %ld.%ld seg\n", seconds, micros);
            vista();
            break;
        case 3:
            gettimeofday(&start, NULL);
            Insercion();gettimeofday(&end, NULL);
             seconds = (end.tv_sec - start.tv_sec);
             micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("\nTiempo de Ejecucion: %ld.%ld seg\n", seconds, micros);
            vista();
            break;
        case 4:
            gettimeofday(&start, NULL);
            LISTA *pUltimo=pInicio;
            while(pUltimo){
                if(!pUltimo->Sig)break;
                pUltimo=pUltimo->Sig;
            }
            QuickSort(pInicio,pUltimo);gettimeofday(&end, NULL);
             seconds = (end.tv_sec - start.tv_sec);
             micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("\n\nTiempo de Ejecucion: %ld.%ld seg\n", seconds, micros);
            vista();
            break;
        case 5:
            gettimeofday(&start, NULL);
            //MergeOrdena(pLista);
            printf("\n Esta Funcion se encuentra FUERA DE SERVICIO!");
            gettimeofday(&end, NULL);
             seconds = (end.tv_sec - start.tv_sec);
             micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("\nTiempo de Ejecucion: %ld.%ld seg\n", seconds, micros);
            vista();
            break;
        case 6:
            gettimeofday(&start, NULL);
            Binary();gettimeofday(&end, NULL);
             seconds = (end.tv_sec - start.tv_sec);
             micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("\nTiempo de Ejecucion: %ld.%ld seg\n", seconds, micros);
            vista();
            break;
        default:
            printf("\nOperacion no Valida!");vista();
            break;
        }
    }while(op!=0);
    return 0;
}
