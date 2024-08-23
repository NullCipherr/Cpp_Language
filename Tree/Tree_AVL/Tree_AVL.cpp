#include <iostream>
#include <stdlib.h>
#include "Tree_AVL.h"

using namespace std;

typedef struct no * Tponteiro;

// Definição da estrutura do nó
typedef struct no {
    int info;
    int h, fb;
    Tponteiro esq, dir;
} Tno;

// Função para criar um nó
void criar(Tponteiro *T)
{
    *T = NULL;
}

// Função para verificar se o nó está vazio
int vazia(Tponteiro *T)
{
  if(*T == NULL)
  	return 1;
  else 
  	return 0;
}

// Função para calcular a altura e o fator de balanceamento de um nó
void alt_fb(Tponteiro *p)
{
    int he, hd;
    
    if((*p)->esq == NULL)
        he = 0;
    else 
    	he = (*p)->esq->h + 1;
    
    if((*p)->dir == NULL)
        hd = 0;
    else 
    	hd = (*p)->dir->h + 1;
    
    if(he > hd)
        (*p)->h = he;
    else 
    	(*p)->h = hd;
    

    (*p)->fb = hd - he;
}

// Função para recalcular a altura e o fator de balanceamento de todos os nós de uma subárvore com raiz em p
void recalcula_h(Tponteiro *p)
{
    if(*p != NULL)
    {
        recalcula_h(&((*p)->esq));
        recalcula_h(&((*p)->dir));
        alt_fb(&(*p));
    }
}

// Função para realizar a rotação à esquerda de um nó
void rotacao_esq(Tponteiro *p)
{ 
    Tponteiro  q, temp;
    
    cout << endl << "rotacao esq de "<< (*p)->info;
    
    q = (*p)->dir;
    temp = q->esq;
    q->esq =  (*p);
    (*p)->dir = temp;
    (*p) = q;
}

// Função para realizar a rotação à direita de um nó
void rotacao_dir(Tponteiro *p)
{ 
    Tponteiro q, temp;
    
    cout << endl << "rotacao dir de "<< (*p)->info;
    
    q = (*p)->esq;
    temp = q->dir;
    q->dir =  (*p);
    (*p)->esq = temp;
    (*p) = q;
}

// Função para realizar o rebalanceamento de um nó
void rebalanceamento(Tponteiro *p)
{
    if ((*p)->fb < 0)
    {
       if ((*p)->esq->fb > 0)
           rotacao_esq(&((*p)->esq));
       
       rotacao_dir(&(*p));
    }
    else 
    {
       if ((*p)->dir->fb < 0)
           rotacao_dir(&((*p)->dir));
       
       rotacao_esq(&(*p));
    }
    
    recalcula_h(&(*p));
}

// Função para inserir um elemento na árvore
void inserir(int x, Tponteiro *p)
{
    if ((*p) != NULL)
    {
        cout <<endl<< "comparando x com  "<<(*p)->info;
        
        if ((*p)->info < x)
            inserir (x, &((*p)->dir));
        else inserir (x, &((*p)->esq));
        
        alt_fb(&(*p));
        
        if (abs((*p)->fb)>1)
        {
            cout << endl << (*p)->info << " desbalanceado!";
            rebalanceamento(&(*p));
        }
    }
    else 
    {
        (*p) = (Tponteiro) malloc(sizeof(Tno));
        (*p)->info = x;
        (*p)->dir = NULL;
        (*p)->esq = NULL;
        (*p)->h = 0;
        (*p)->fb = 0;
    }
}

// Função para mostrar a árvore
void mostrar(Tponteiro p)
{
    if(p != NULL)
    {
        mostrar(p->esq);
        cout << p->info << " alt: " << p->h<< " fb: " << p->fb << endl;
        mostrar(p->dir);
    }
}

// Função para remover um nó folha
void remove_folha(Tponteiro *p)
{    
    Tponteiro q;
    
    q = *p;
    *p = NULL;
    free(q);
}

// Função para remover um nó com filho à esquerda
void remove_no_com_filho_esq(Tponteiro *p)
{
    Tponteiro paux;
    
    paux = *p;
    *p = (*p)->esq;
    free(paux);
}

// Função para remover um nó com filho à direita
void remove_no_com_filho_dir(Tponteiro *p)
{
    Tponteiro paux;
    
    paux = *p;
    *p = (*p)->dir;
    free(paux);
}

// Função para encontrar o sucessor de um nó
Tponteiro encontra_sucessor(Tponteiro *p)
{
    Tponteiro paux;
    
    paux = (*p)->dir;
    
    while(paux->esq != NULL)
        paux = paux->esq;
    
    return paux;
}

// Função para remover um nó com dois filhos
void remove_no_com_2filhos(Tponteiro *p)
{
    Tponteiro suc = encontra_sucessor(&(*p));
    
    (*p)->info = suc->info;
    remover(suc->info,&((*p)->dir));
}

// Função para remover um elemento da árvore
int remover(int x, Tponteiro *p)
{
    int res;
    
    // Verifica se o nó está vazio
    if (*p == NULL)
        res = 0; // elemento não está na árvore
    else 
    {
        // Verifica se o valor do nó é diferente do valor a ser removido
        if ((*p)->info != x)
        {
            cout <<endl<< "comparando x com  "<<(*p)->info;
            // Verifica se o valor do nó é maior que o valor a ser removido
            if ((*p)->info > x)
                res = remover(x,&((*p)->esq)); // Remove o valor no nó à esquerda
            else 
            	res = remover(x,&((*p)->dir)); // Remove o valor no nó à direita
        }
        else 
        {
            cout <<endl<< "encontrou x em p:  "<<(*p)->info;
            // Verifica se o nó à direita está vazio
            if ((*p)->dir == NULL)
                // Verifica se o nó à esquerda está vazio
                if((*p)->esq == NULL)
                    remove_folha(&(*p)); // Remove o nó folha
                else 
                	remove_no_com_filho_esq(&(*p)); // Remove o nó com filho à esquerda
            else if((*p)->esq == NULL)
                remove_no_com_filho_dir(&(*p)); // Remove o nó com filho à direita
            else 
            	remove_no_com_2filhos(&(*p)); // Remove o nó com dois filhos
        }
        res = 1;
    }
    // Verifica se o resultado é 1 e o nó não está vazio
    if ((res = 1 && (*p)!= NULL))
    {
        alt_fb(&(*p)); // Recalcula a altura e o fator de balanceamento do nó
        // Verifica se o valor absoluto do fator de balanceamento do nó é maior que 1
        if (abs((*p)->fb)>1)
        {
            cout << endl << (*p)->info << " desbalanceado!";
            rebalanceamento(&(*p)); // Realiza o rebalanceamento do nó
        }
    }
    return res; // Retorna o resultado
}