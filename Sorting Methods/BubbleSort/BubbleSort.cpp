#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

using namespace std;

void swap(int *x, int *y)
{
	int	temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int vetor[], int size)
{
	int k , j ; // VARIAVEIS
	bool continuaOrd = false ;
	
	for(k = 1; k < size; k++) 
	{
		for(j=0; j < size - k; j++) 
		{	
			if(vetor[j] > vetor[j+1])
			{
				swap(vetor[j], vetor[j+1]) ;
			}
			
			continuaOrd = false ;
			
			for (int l = j; l < size - k ; l++)
			{
				if (vetor[l] > vetor[l+1])
				{
					continuaOrd = true;
					break;
				}
			}
			if(continuaOrd == false)
			{
				break;
			}
			
		}
	}
}


int main()
{
	int sizeVetor = 0;
	int *v;
	
	cout << "TAMANHO DO VETOR: ";
	cin >> sizeVetor;
	
	system("cls");
	
	v = (int *) malloc(sizeVetor * sizeof(int)) ;
		
	cout << "------------DIGITE O VETOR------------ \n";
	for(int i=0; i < sizeVetor; i++)
	{
		cout << "V[" << i+1 << "]: " ;
		cin >> v[i];
	}
	
	system("cls");
	
	cout << "------------VETOR BASE------------ \n";
	for(int i=0; i < sizeVetor; i++)
	{
		cout << v[i] << "   ";
	}
	
	cout << "\n\n\n";		
	
	bubbleSort(v, sizeVetor);
	
	cout << "------------VETOR ORDENADO------------ \n";
	for(int i=0; i < sizeVetor ; i++)
	{
		cout << v[i] << "   ";
	}
	
	cout << "\n\n";
	
	return 0;

}
