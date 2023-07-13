#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *a,int start,int end)
{
	int pivot=a[end]; // cause we usually take the last index's element as pivot
	int pivot_index=start; // initially this it will be at the beginning
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[i],a[pivot_index]);
			pivot_index++; // shifting it to the right
		}
	}
	swap(a[end],a[pivot_index]);
	return pivot_index;
}
void quick_sort(int *a,int start, int end)
{
	if(start<end)
	{
		int pivot_index=partition(a, start, end);
		quick_sort(a,start,pivot_index-1);
		quick_sort(a,pivot_index+1,end);
	}
}
int main()
{
	int arr[]={7,2,1,6,8,5,3,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,n);
	printf("Sorted array\n");
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
