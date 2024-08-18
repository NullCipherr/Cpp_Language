#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

using namespace std;

void insertionSort(int vetor[], int size)
{
	int i , j , numeroSelecionado ; // VARIAVEIS
	
	for(int i = 1; i < size; i++)
	{
		int numeroSelecionado = vetor[i]; // Elemento selecionado do Vetor assume o valor do elemento 1
		int j = i - 1 ; // J = 0
		
		//cout << "J Inicio: " << j << "\n";
		
		while((j >= 0) && (vetor[j] > numeroSelecionado)) // Enquanto J >= 0 e se o Elemento 0 for maior que o numero selecionado
		{
			vetor[j+1] = vetor[j]; // VETOR [1] = VETOR [0]
			j--; // J = 0
		}
		vetor[j+1] = numeroSelecionado; // VETOR [1] = Numero Selecionado (Vetor[0])
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
	
	insertionSort(v, sizeVetor);
	
	cout << "------------VETOR ORDENADO------------ \n";
	for(int i=0; i < sizeVetor ; i++)
	{
		cout << v[i] << "   ";
	}
	
	cout << "\n\n";
	
	return 0;

}
