#include<iostream> 
using namespace std;

void insertionSort(int numbers[], int array_size) 
{   
	int i, j, index; 
 	for (i=1; i < array_size; i++)  
	{     
	  	index = numbers[i]; 
		j = i;    
		while ((j > 0) && (numbers[j-1] > index))     
		{       
			numbers[j] = numbers[j-1];
			j = j - 1;
		}     
		numbers[j] = index;  
	} 
} 

int main()
{
	int size=4;
	int num[]={8,2,5,4};
	insertionSort(num,size);
	for(int i = 0;i<size;i++)
	{
		cout<< num[i]<<endl;
	}
}
