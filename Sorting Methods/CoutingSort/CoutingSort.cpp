// Counting sort which takes negative numbers as well
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
void countingSort(int arr[], int tam)
{
    int max, min ;
    int i ;
    
    max = arr[0] ;
    min = arr[0] ;
    
    for(i=0; i < tam ; i++)
    {
    	if(arr[i] > max)
    	{
    		max = arr[i] ;
		}
		if(arr[i] < min)
		{
			min = arr[i] ;
		}
	}
	
	int range = max - min + 1;
 
    int count[range] ;
	int output[tam] ;
    
	for (int i = 0; i < tam; i++)
	{
        count[arr[i] - min] ++ ;
	}
 
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1] ;
	}
 
    for (int i = tam - 1; i >= 0; i--) 
	{
        output[count[arr[i] - min] - 1] = arr[i] ;
        count[arr[i] - min]-- ;
    }
 
    for (int i = 0; i < tam; i++)
    {
    	arr[i] = output[i] ;
	}
}
 
void printArray(int arr[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << arr[i] << " " ;
	}
    
	cout << "\n";
}

int main()
{
    int tam = 10 ;
	int arr[tam];
    
	countingSort(arr, 8) ;
    printArray(arr, 8) ;
    
	return 0 ;
}
