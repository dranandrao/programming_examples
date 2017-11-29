#include<stdio.h>
void insertion_sort(int arr[],int n);
void main(){
	int n,array[10];
	printf("Enter the size of the array");
	scanf("%d",&n);
	printf("Enter the elements");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	insertion_sort(array,n);
	printf("Sorted array is :");
	for(int i=0;i<n;i++)
	{
		printf("%d",array[i]);
	}
}
void insertion_sort(int array[],int n)
{
	int i,j,key;
	for (int i=1;i<n;i++)
	{
		key = array[i];
		j = i-1;
		while(j>=0 && array[j] > key)
		{
			array[j+1] = array[j];
			j = j-1;
		}
		array[j+1] = key;
	}	
}
