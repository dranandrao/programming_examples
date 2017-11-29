#include<stdio.h>
void merge_sort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

int main(){
	int a[30],n;
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Enter the elements of the array");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,0,n-1);
	printf("Sorted array is:");
	for (int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
return 0;
}

void merge_sort(int a[],int i,int j)
{
	int mid;
	if(i<j){
		mid = (i+j)/2;
		merge_sort(a,i,mid);
		merge_sort(a,mid+1,j);
		merge(a,i,mid,mid+1,j);	
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];
	int i,j;
	i=i1;
	j=j2;
	int k=0;
	
	while(i<=j1 && j<=j2)
	{
		if(a[i] < a[j])
		{
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++]; 		
		}		
	}
	
	while(i<=j1)
	{
		temp[k++] = a[i++];
	}
	while(j<=j2)
	{
		temp[k++] = a[j++];
	}
	for(i=i1,j=0;i<j2;i++,j++)
	{
		a[i] = temp[j];
	}
}
