#include <stdio.h>
#include<stdlib.h>

// Definição da estrutura do nó
typedef struct no{
    int chave;
    struct no *dir;
    struct no *esq;
}NO;

// Função para inserir um nó na árvore
void inserir(NO *raiz,NO *p)
{
    // Verifica se a chave do nó é maior que a chave da raiz
    if(p->chave > raiz->chave)
	{ 
        // Verifica se o nó à direita da raiz está vazio
        if(raiz->dir == NULL)
        {
			raiz->dir = p ;
		}
        else 
		{
			inserir(raiz->dir,p) ;	
		}
    }
    // Verifica se a chave do nó é menor que a chave da raiz
    if(p->chave < raiz->chave)
	{
        // Verifica se o nó à esquerda da raiz está vazio
        if(raiz->esq == NULL) 
			raiz->esq = p ;
        else 
			inserir(raiz->esq,p) ;
    }
}

// Função para imprimir a árvore em pré-ordem
void imprimePreOrdem(NO *raiz)
{ 
    printf("%d ",raiz->chave);
    
    // Verifica se o nó à esquerda da raiz não está vazio
	if(raiz->esq != NULL)
	{
		imprime(raiz->esq);	
	} 
    // Verifica se o nó à direita da raiz não está vazio
    if(raiz->dir != NULL)
	{
		imprime(raiz->dir);
	} 
}

// Função para imprimir a árvore em ordem
void imprimeOrdem(NO *raiz)
{ 
    // Verifica se o nó à esquerda da raiz não está vazio
    if(raiz->esq != NULL)
	{
		imprime(raiz->esq) ;
	} 
    
	printf("%d ",raiz->chave);
    
    // Verifica se o nó à direita da raiz não está vazio
	if(raiz->dir != NULL)
	{
		imprime(raiz->dir);
	}
}

// Função para imprimir a árvore em pós-ordem
void imprimePosOrdem(NO *raiz)
{ 
    // Verifica se o nó à esquerda da raiz não está vazio
    if(raiz->esq != NULL) 
	{
		imprime(raiz->esq);	
	}
    // Verifica se o nó à direita da raiz não está vazio
    if(raiz->dir != NULL) 
	{
		imprime(raiz->dir);
	}
    
	printf("%d ",raiz->chave);
}

// Função para buscar um nó na árvore
void buscar(NO *raiz, int chave)
{
    // Verifica se a chave da raiz é igual à chave buscada
    if(raiz->chave == chave) 
	{
		printf("Achou");
	}
    // Verifica se a chave buscada é maior que a chave da raiz e se o nó à direita da raiz não está vazio
    if(chave > raiz->chave && raiz->dir != NULL) 
	{
		buscar(raiz->dir,chave);	
	}
    // Verifica se a chave buscada é menor que a chave da raiz e se o nó à esquerda da raiz não está vazio
    if(chave < raiz->chave && raiz->esq != NULL) 
	{
		buscar(raiz->esq,chave);	
	}
}

// Função para inicializar a raiz da árvore
void init(NO* raiz)
{ 
    raiz = NULL;
}

// Função para verificar se a raiz da árvore está vazia
int nula(NO* raiz)
{ 
    if(raiz == NULL)
	{
		return 1 ; 	
	} 
    else 
    {
    	return 0 ;	
	}
}