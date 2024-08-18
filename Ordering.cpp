#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define tamanhoVetor 3000

typedef int tipoVetor[tamanhoVetor] ;

/*
void mostraVetor(tipoVetor v, int tam)
{
	int i = 0 ;

	for(i=0; i < tam; i++)
	{
		printf(" %d ", v[i]) ;
	}

	printf("\n\n") ;
}
*/

void geraVetorCrescente(tipoVetor v, int tam)
{
	int i = 0 ;
	
	for(i=0; i < tam; i++)
	{
		v[i] = rand() % 100 ;
	}

    int troca=1;
    int aux;

    while (troca == 1)
    {
        troca = 0;
        for (i = 0; i <= tam; i++)
        {
            if (v[i] > v[i + 1])
            {
                troca = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
    }
}

void geraVetorDecrescente(tipoVetor v, int tam)
{
	int i = 0,troca=1,aux;
	
	for(i=0; i < tam; i++)
	{
		v[i] = rand() % 100 ;
    }

    while (troca == 1)
    {
        troca = 0;
        for (i = 0; i <= tam; i++)
        {
            if (v[i] < v[i + 1])
            {
                troca = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
	}
}

void geraVetorAleatorio(tipoVetor v, int tam)
{
	int i = 0 ;

	for(i=0; i < tam; i++)
	{
		v[i] = rand() % 100 ;
	}
}

void insertionSort (tipoVetor V, int tam)
{
	int ultord, aux, ant;

	for (ultord=0; ultord < tam-1; ultord++)
    {
        aux=V[ultord+1] ; 
        ant=ultord ;

        while ((ant > -1) && (V[ant] > aux))
        {
            V[ant+1] = V[ant] ; 
            ant-- ;
        }
        	V[ant+1] = aux;
    }
}


void bubbleSort (tipoVetor V, int tam)
{
	int posord, prox, aux, ulttroca, nComparations = 0 ;
    posord = tam-1 ;

	while (posord > 0)
    {
        ulttroca = 0 ;

        for (prox=0; prox<posord; prox++)
        {
            if (V[prox] > V[prox+1])
            {
                aux = V[prox] ;
                V[prox] = V[prox+1] ;
                V[prox+1] = aux ;
                ulttroca = prox ;
            }
        }
    	posord = ulttroca;
    }
}

void selectionSort (tipoVetor V, int tam)
{
	int posord, i, menor, posmenor, aux ;

	for (posord=0; posord<tam-1 ; posord++)
	{
        menor = V[posord] ; 
        posmenor = posord ; 

		for (i=posord+1; i < tam ; i++) //I = 1; I < TAM; I++
        {
            if (V[i]<menor) 
            {
                menor = V[i] ; 
                posmenor = i ; 
            }
        }
        aux = V[posord] ;
        V[posord] = menor ;
        V[posmenor] = aux ;
	}
}

void shellSort (tipoVetor V, int tam)
{
	int ultord, aux, ant, desl ;
	
	desl=tam/2 ;
  	
	while (desl > 0)
  	{
    	for (ultord=0; ultord < tam-desl; ultord++)
    	{
        	aux=V[ultord+desl] ;
        	ant=ultord ;

        	while ((ant>-1) && (V[ant]>aux))
        	{
            	V[ant+desl] = V[ant] ;
            	ant = ant-desl ;
        	}
        	V[ant+desl] = aux ;
    	}
    	desl = desl/2 ;
  	}
}





int particiona (tipoVetor V, int ini, int fim)
{
	int posdivisor, i, aux, meio, divisor ;

	meio = (ini+fim)/2 ;
    aux = V[fim] ;
    V[fim] = V[meio] ;
    V[meio] = aux ;
    divisor = V[fim] ;
    posdivisor = ini ;

	for (i=ini; i<fim; i++)
    {
        if (V[i]<divisor)
        {
        	aux = V[i];
            V[i] = V[posdivisor] ;
            V[posdivisor] = aux ;
            posdivisor++ ;
        }
    }
    V[fim] = V[posdivisor] ;
    V[posdivisor]= divisor ;

    return (posdivisor) ;
}

void qSort (tipoVetor V, int ini, int fim)
{
	int posDivisor ;
    	
	if (fim > ini)
    {
        posDivisor = particiona(V, ini, fim) ;
        qSort(V, ini, posDivisor-1) ;
        qSort(V, posDivisor+1, fim) ;
    }
}


void quickSort (tipoVetor V, int tam)
{
	qSort(V, 0, tam-1) ;
}





int indFilhoEsquerda (int ind)
{
    return (2*ind+1) ;
}

int indFilhoDireita (int ind)
{
    return (2*ind+2) ;
}

void reorgMaxHeap(tipoVetor V, int tam, int ind)
{
	int maior, posmaior, aux ;
    maior = V[ind] ;
    posmaior = ind ;

    if (indFilhoEsquerda(ind) < tam)
    {
		if (V[indFilhoEsquerda(ind)] > maior)
        {
			maior = V[indFilhoEsquerda(ind)] ;
           	posmaior = indFilhoEsquerda(ind) ;
        }
        if (indFilhoDireita(ind) < tam)
        {
			if (V[indFilhoDireita(ind)] > maior)
           	{
					maior = V[indFilhoDireita(ind)];
                	posmaior = indFilhoDireita(ind);
            }
        }
    }
	if (posmaior != ind)
    {
        aux = V[ind] ;
        V[ind] = maior ;
        V[posmaior] = aux ;
        reorgMaxHeap(V, tam, posmaior) ;
	}
}

void criaMaxHeap (tipoVetor V, int tam)
{
	int i ;
	
	for (i=(tam-2)/2; i>-1; i--)
    {
        reorgMaxHeap(V, tam, i) ;
    }
}

void heapSort (tipoVetor V, int tam)
{
	int i, aux ;

	criaMaxHeap(V, tam) ;
	
	for (i=tam-1; i > 0; i--)
    {
        aux = V[i] ;
        V[i] = V[0] ;
        V[0] = aux ;
        reorgMaxHeap(V,i,0) ;
    }
}




void merge (tipoVetor V, int ini, int meio, int fim)
{
	int tam1=0, tam2=0, i, j, k, maiordetodos ;
	tipoVetor A1, A2;

    for (i=ini; i<meio+1; i++)
    {
        A1[tam1] = V[i] ;
        tam1++ ;
   	}

    for (i=meio+1; i<fim+1; i++)
    {
        A2[tam2] = V[i] ;
        tam2++ ;
    }

    maiordetodos = abs(A1[tam1-1])+abs(A2[tam2-1])+1 ;

    A1[tam1] = maiordetodos ;
    A2[tam2] = maiordetodos ;

	i=0;
    j=0;

	for (k=ini; k < fim+1; k++)
    {
        if (A1[i] < A2[j])
        {
            V[k]=A1[i];
            i++;
        }
        else
        {
            V[k]=A2[j];
            j++;
        }
    }
}

void mergeSort (tipoVetor V, int ini, int fim)
{
	int meio;

	if ((fim-ini) > 0)
    {
        meio = (ini+fim)/2 ;
        mergeSort(V, ini, meio) ;
        mergeSort(V, meio+1, fim) ;
        merge(V, ini, meio, fim) ;
    }
}


void radixSort(tipoVetor V, int tam)
{
	int i ;
    int *b ;
    int maior = V[0] ;
    int exp = 1 ;
	b = (int *)calloc(tam, sizeof(int));
	
	for (i = 0; i < tam; i++)
	{
        if (V[i] > maior)
        {
    	    maior = V[i] ;
		}
   	}
    while (maior/exp > 0)
	{
        int bucket[10] = { 0 } ;
		
		for (i = 0; i < tam; i++)
		{
    	    bucket[(V[i] / exp) % 10]++ ;
		}
    	for (i = 1; i < 10; i++)
    	{
    	    bucket[i] += bucket[i - 1] ;
		}
    	for (i = tam-1; i >= 0; i--)
    	{
    		b[--bucket[(V[i] / exp) % 10]] = V[i] ;
		}
    	for (i = 0; i < tam; i++)
    	{
    	    V[i] = b[i] ;
		}
		exp *= 10;
	}
    free(b) ;
}




int main()
{
	int y ;
	
	tipoVetor v ;
	
	setlocale(LC_ALL, "Portuguese");

    system("cls || clear") ; //LIMPA A TELA

    printf("1)Gerar Vetor Crescente\n2)Gerar Vetor Decrescente\n3)Gerar Vetor Rand�mico\n\n");
    printf("Option: ");
    scanf("%d", &y);
    
    system("cls || clear") ; //LIMPA A TELA
	
	if(y == 1)
	{
		geraVetorCrescente(v,tamanhoVetor) ;
	}
	if(y == 2)
	{
		geraVetorDecrescente(v,tamanhoVetor) ;	
	}
	if(y == 3)
	{
		geraVetorAleatorio(v,tamanhoVetor) ;	
	}
    
    // CHAME A SUA ORDENA��O AQUI !!
    selectionSort(v,tamanhoVetor) ;
    //bubbleSort(v,tamanhoVetor) ;
    //insertionSort(v,tamanhoVetor) ;
    //shellSort(v,tamanhoVetor) ;
    //quickSort(v,tamanhoVetor) ;
    //heapSort(v,tamanhoVetor) ;
    //mergeSort(v,0,tamanhoVetor) ;
    //radixSort(v,tamanhoVetor) ;
    
    
	
	return 0 ;
    
    
}
