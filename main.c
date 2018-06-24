#include <stdio.h>
#include <stdlib.h>
#include "CofoAluno.h"

int main() {
    //DECLARAÇÃO DAS VARIÁVEIS
    tnode *t;
    int b;
    int resp,modo = 100;

    if(t != NULL){
        t = abpCreate();
    }

    //INICIO DO MENU
    while(modo != 0){
        //IMPRIME TODAS AS OPÇÕES NA TELA
        if (modo >= 12){
            modo = 101;
            printf("\n");
            printf("1 - Inserir na Arvore\n");
            printf("2 - Remover da Arvore\n");
            printf("3 - Procurar na Arvore\n");
            printf("4 - Imprimir\n");
            printf("0 - Sair\n");
            printf("Escolha uma Opção: ");
            scanf("%i",&modo);
            printf("\n");
        }
        //ESCOLHE A OPÇÃO DE CRIAR A LISTA
        /*if(modo == 1){

        modo = 100;
        }*/
        //ESCOLHE A OPÇÃO DE INSERIR UM ELEMENTO NO COMEÇO DA LISTA
        if(modo == 1){
            int x;
            printf("Informe o numero que quer inserir: \n");
            scanf("%i",&x);
            t = abpInsert(t,(void*)x,CmpData);
            if(t != NULL){
                printf("Elemento Inserido com Sucesso!\n");
            }else{
                printf("Falha ao Inserir Elemento\n");
            }
            modo = 100;
        }
        //REMOVE DA ARVORE
        if(modo == 2){
            tnode *data;
            int numProcurado;
            printf("Qual o numero pelo qual quer remover? ");
            scanf("%i",&numProcurado);
            data = abpRemove(t,(void*)numProcurado, CmpData,&t->data);

            if(data != NULL){
                printf("Numero %d removido!\n", (int)data->data);
            }else{
                printf("Nao Encontrado\n");

            }

            modo = 100;
        }
        //PROCURAR NA ARVORE
        if(modo == 3){
            int data;
            int numProcurado;
            printf("Qual o numero pelo qual quer procurar? ");
            scanf("%i",&numProcurado);
            data = (int)abpQuery(t,(void*)numProcurado, CmpData);

            if(data != NULL){
                printf("Numero %d Encontrado!\n", data);
            }else{
                printf("Nao Encontrado\n");

            }

            modo = 100;
        }
        //IMPRIME A ARVORE
        if(modo == 4){

            printf("Simetrica: ");
            abpSimetrica(t,visit);
            printf("\n");

            printf("PreOrder: ");
            abpPreOrder(t,visit);
            printf("\n");

            printf("PosOrder: ");
            abpPosOrder(t,visit);
            printf("\n");

            modo = 100;
        }


    }
}