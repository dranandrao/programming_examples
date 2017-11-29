#include<stdio.h>
void quick_sort(int array[],int low,int high);
int partition(int array[],int low,int high);
void swap(int *a,int *b);
void main()
{
	int a[30],n;
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Enter the elements of the array");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("Sorted array is:");
	for (int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
void quick_sort(int array[],int low,int high)
{
	if(low<high){
		int pi = partition(array,low,high);
		quick_sort(array,low,pi-1);
		quick_sort(array,pi+1,high);
	}
}
int partition(int array[],int low,int high)
{
	int pivot = array[high];
	int i = low-1;
	for (int j=low;j<=high-1;j++)
	{
		if(array[j] <= pivot)
		{
			i++;
			swap(&array[i],&array[j]);
		}
	
	}
	swap(&array[i+1],&array[high]);
	return (i+1);
	
}
void swap(int *element1,int *element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}


