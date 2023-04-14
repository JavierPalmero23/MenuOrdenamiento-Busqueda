/*
Sobre una lista enlazada.
    Contar cuantas iteraciones realizo cada Metodo
    Medir timepo de cada metodo
-Metodos de Ordenamiento
    -Burbuja v
    -Selección
    -Inserción
    -QuickSort
    ->Merge
-Metodo de Busqueda
    -Busqueda Binaria
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct pLista{
    struct pLista *Ant;
    int val;
    struct pLista *Sig;
}LISTA;

LISTA *pLista, *pInicio, *pNuevo;
int longitud=0;

void vista(){
    printf("\nPulse la tecla ENTER para Continuar...");
    getchar();getchar();
}
void Ver(){
    LISTA *pAux=(LISTA*)malloc(sizeof(LISTA));
    pAux=pInicio;
    printf("\n");
    while(pAux){
        printf("[%d]",pAux->val);
        if(!pAux->Sig)break;
        pAux=pAux->Sig;
    }
}
void Burbuja(){
    clock_t start=clock();
    LISTA *pAux, *pAuxAnt, *pAuxSig;
    for(int i=0;i<longitud;i++){
        pAux=pInicio;
        pAuxAnt=pInicio;
        for(int j=0;j<longitud-1;j++){
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
    }
    printf("Tiempo transcurrido: %f",((clock() - start)/CLOCKS_PER_SEC));
    Ver();
}
void Seleccion(){
        clock_t start=clock();
        
        printf("Tiempo transcurrido: %f",(clock() - start)/CLOCKS_PER_SEC);
        }
void Insercion(){
        clock_t start=clock();
        printf("Tiempo transcurrido: %f",(clock() - start)/CLOCKS_PER_SEC);
        }
void QuickSort(){
        clock_t start=clock();
        printf("Tiempo transcurrido: %f",(clock() - start)/CLOCKS_PER_SEC);
        }
void Merge(){
        clock_t start=clock();
        printf("Tiempo transcurrido: %f",(clock() - start)/CLOCKS_PER_SEC);
        }
void Binary(){
        clock_t start=clock();
        printf("Tiempo transcurrido: %f",(clock() - start)/CLOCKS_PER_SEC);
        }


int main(){
    int op=0;
    do{
        system("cls");
        pNuevo=(LISTA*)malloc(sizeof(LISTA));
        printf("\nIngrese el valor a agregar ó 0 para SALIR: \n");
        scanf(" %d",&pNuevo->val);
        pNuevo->Sig=NULL;
        if(pNuevo->val==0){break;}
        if(pLista==NULL){
            pInicio=pNuevo;
            pLista=pNuevo;
        }else{
            pLista->Sig=pNuevo;
            pLista=pNuevo;
        }
        longitud++;
    }while(pInicio);
    do{
        system("cls");
        printf("\nSeleccione un Metodo de:\nOrdenamiento\n [1] - Burbuja\n [2] - Seleccion\n [3] - Insercion\n [4] - Quicksort\n [5] - Merge\nBusqueda:\n [6] - Binaria\n\nOperacion:");
        scanf(" %d", &op);
        switch (op){
        case 0:
            printf("\nFinalizando ...");
            break;
        case 1:
            Burbuja();vista();
            break;
        case 2:
            Seleccion();vista();
            break;
        case 3:
            Insercion();vista();
            break;
        case 4:
            QuickSort();vista();
            break;
        case 5:
            Merge();vista();
            break;     
        case 6:
            Binary();vista();
            break;
        default:
            printf("\nOperacion no Valida!");vista();
            break;
        }
    }while(op!=0);    
    return 0;
}