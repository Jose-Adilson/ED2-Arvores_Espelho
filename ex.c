#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Noh
{
    int valor;
    struct Noh *esq, *dir;
};

typedef struct Noh Elem;

Elem * cria_elemento(int valor)
{
    Elem* noh = (Elem*)malloc(sizeof(Elem));
    noh->valor  = valor;
    noh->esq  =  noh->dir  = NULL;
    return(noh);
}

int eh_espelho(Elem* a, Elem* b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return  a->valor == b->valor &&
            eh_espelho(a->esq, b->dir) &&
            eh_espelho(a->dir, b->esq);
}

Elem * cria_espelho(Elem* a)
{
	if (a == NULL) {
        Elem *espelho = NULL;
        return espelho;
    }

    Elem *espelho = cria_elemento(a->valor);

    if(a->esq != NULL){
    	espelho->dir = cria_espelho(a->esq);
	}
	if(a->dir != NULL){
    	espelho->esq = cria_espelho(a->dir);
	}
	return espelho;
}

void imprime_arvore(Elem* a){
	if(a == NULL) {
		return;
	}
	imprime_arvore(a->esq);
	printf(" %d", a->valor);
	imprime_arvore(a->dir);
}



int main()
{
    int entrada = 0;

    printf("Digite os elementos da arvore 1:(Obs: 5 nohs, de cima pra baixo, da esquerda para direita.\n");
    scanf("%d", &entrada);
    Elem *arvore1 = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore1->esq = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore1->dir = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore1->dir->esq  = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore1->dir->dir = cria_elemento(entrada);

    printf("Digite os elementos da arvore 2:(Obs: 5 nohs, de cima pra baixo, da esquerda para direita.\n");
    scanf("%d", &entrada);
    Elem *arvore2 = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore2->esq = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore2->dir = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore2->esq->esq = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore2->esq->dir = cria_elemento(entrada);

 	int retorno = eh_espelho(arvore1, arvore2);

 	if(retorno){
        printf("As arvore 2 eh espelho da 1.\n\n");
 	} else {
        printf("As arvore 2 nao eh espelho da 1.\n\n");
 	}


 	Elem *espelho = cria_espelho(arvore1);
 	printf("A arvore espelho da arvore 1 eh : (esq/mei/dir)\n");
 	imprime_arvore(espelho);

    return 0;
}

