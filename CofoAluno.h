#ifndef CofoAluno_H_INCLUDED
#define CofoAluno_H_INCLUDED

//CRIA ESTRUTURA NÓ
typedef struct _tnode_{
    struct _tnode_ *l;
    struct _tnode_ *r;
    void *data;
}tnode;

//HEADERS DA LISTA SIMPLESMENTE ENCADEADA
tnode *abpCreate();
int dllDestroy(tnode *l);
tnode *abpInsert(tnode *t,void *data, int(*cmp)(void*,void*));
tnode *abpRemove(tnode *t,void *key,int(*cmp)(void*,void*),void **data);
void *abpQuery(tnode *t, void *key, int (*cmp)( void *, void *));
void abpPreOrder(tnode *t,int(*visit)(void*));
void abpPosOrder(tnode *t,int(*visit)(void*));
void abpSimetrica(tnode *t,int(*visit)(void*));
void *abpMaior(tnode* t,int(*cmp)(void*,void*));
void *abpMaiorDeTres(void* a,void *b,void* c);
int visit(void *data);


//HEADERS DO ALUNO
int CmpData(void *a, void *b);


#endif


