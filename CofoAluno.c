#ifndef CofoAluno_C_INCLUDED
#define CofoAluno_C_INCLUDED
#include "CofoAluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

//CRIA ARVORE BINARIA{
tnode *abpCreate(){
    tnode *t;
    t = (tnode*)malloc(sizeof(tnode));
    if(t!= NULL){
        t->l = NULL;
        t->r = NULL;
        t->data = NULL;
        return t;
    }
    return NULL;
}

//DESTROI A LISTA SE A LISTA ESTIVER VAZIA



void abpPreOrder(tnode *t,int(*visit)(void*)){
    if(t != NULL){
        visit(t->data);
        abpPreOrder(t->l,visit);
        abpPreOrder(t->r,visit);
    }
}

void abpPosOrder(tnode *t,int(*visit)(void*)){
    if(t != NULL){

        abpPosOrder(t->l,visit);
        abpPosOrder(t->r,visit);
        visit(t->data);
    }
}

void abpSimetrica(tnode *t,int(*visit)(void*)){
    if(t != NULL){

        abpSimetrica(t->l,visit);
        visit(t->data);
        abpSimetrica(t->r,visit);
    }
}

int visit(void *data){
    if(data != NULL){
        printf(" %i,",(int)data);
    }
}


//PROCURA ELEMENTO ESPECIFICADO POR UMA CHAVE
void *abpQuery(tnode *t, void *key, int (*cmp)( void *, void *)){
    int stat;
    if (t != NULL){
        stat = cmp(key,t->data);
        if(stat == 0){
            return t->data;
        }else if(stat < 0){
            return abpQuery(t->l,key,cmp);
        }else{
            return abpQuery(t->r,key,cmp);
        }

    }
    return NULL;
}
//INSERE NA LISTA
tnode *abpInsert(tnode *t,void *data,int(*cmp)(void*,void*)){
    tnode *newnode;
    int stat;

    if(t!= NULL) {
        stat = cmp(data, t->data);
        if (stat <= 0) {
            t->l = abpInsert(t->l, data, cmp);
        } else {
            t->r = abpInsert(t->r, data, cmp);
        }
        return t;
    }else{
        newnode = (tnode*)malloc(sizeof(tnode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->l = NULL;
            newnode->r = NULL;
            return newnode;
        }
    }
    return NULL;
}



// REMOVE ESPECIFICADO
tnode *abpRemove(tnode *t,void *key,int(*cmp)(void*,void*),void **data){
    tnode *aux;
    void *data2;
    int stat;
    if(t != NULL) {
        stat = cmp(key,t->data);
        if(stat == -1){
            t->r = abpRemove(t,key,cmp,*data);
            return t;
        }else if(stat ==1){
            t->l = abpRemove(t,key,cmp,*data);
            return t;
        }else{
            *data = t->data;
            if(t->l == NULL && t->r == NULL){
                free(t);
                return NULL;
            }else if(t->l != NULL && t->r == NULL){
                aux = t->l;
                free(t);
                return aux;
            }else if(t->l == NULL && t->r != NULL){
                aux = t->r;
                free(t);
                return aux;
            }else{
                t->data = abpMaior(t->l,cmp);
                abpRemove(t->l,t->data,cmp,&data2);
                return t;
            }
        }
    }
    return NULL;
}

void *abpMaiorDeTres(void* a,void *b,void* c){
    if(a != NULL){
        if(b != NULL){
            if(c != NULL){
                if(a >= b && b >= c){
                    return a;
                }else if(b >= a && a >= c){
                    return b;
                }else if(c >= b && b >= a){
                    return c;
                }
            }
        }
    }
    return NULL;
}

void *abpMaior(tnode* t,int(*cmp)(void*,void*)){
    void* MaiorL = NULL, *MaiorR = NULL;
    if(t != NULL){
        if(t->l == NULL && t->r == NULL){
            return t->data;
        }else{
            if(t-> l != NULL){
                MaiorL = abpMaior(t->l,cmp);
            }
            if(t->r != NULL){
                MaiorR = abpMaior(t->r,cmp);
            }

            return abpMaiorDeTres(t->data,MaiorL,MaiorR);
        }
    }
}





//COMPARA O ELEMENTO COM A CHAVE ENVIADA
int CmpData(void *a, void *b) {
    int *pa;
    int *pb;
    pa = (int *) a;
    pb = (int *) b;
    if (pb == pa) {
        return 0;
    }else if (pb > pa) {
        return -1;
    }else if (pb < pa) {
        return 1;
    }else{
        return 2;
    }
}


#endif


