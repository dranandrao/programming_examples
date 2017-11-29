#include<stdio.h>
void bubble_sort(int arr[],int n);
void main(){
	int array[10],n;
	printf("Enter the size of array");
	scanf("%d",&n);
	printf("Enter the elements");
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&array[i]);
	}

	bubble_sort(array,n);
	printf("Sorted array is :");
	for(int i=0;i<n;i++)
	{
		printf("%d",array[i]);
	}
}

void bubble_sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

} 
