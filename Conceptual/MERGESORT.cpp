#include<iostream>
#include<algorithm>
using namespace std;
void merge(int* a,int l,int m,int r)
{
	int n1=m-l+1; // size of left sub-array
	int n2=r-m;   // size of right sub-array
	int left[n1],right[n2]; // sub-arrays
	for(int i=0;i<n1;i++)
		left[i]=a[l+i]; // the left sub-array will include the middle most element as well
	for(int i=0;i<n2;i++)
		right[i]=a[m+1+i];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=left[i];
		k++,i++;
	}
	while(j<n2)
	{
		a[k]=right[j];
		k++,j++;
	}
}
void merge_sort(int* a, int l, int r)
{
	if(l>=r)
		return;
	int m=(l+r)/2;
	merge_sort(a,l,m);
	merge_sort(a,m+1,r);
	merge(a,l,m,r);
}
int main()
{
	int a[]={7,2,1,6,8,5,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	merge_sort(a,0,n-1);
	for(int x:a)
		cout<<x<<" ";
	return 0;
}
