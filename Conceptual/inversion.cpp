#include<iostream>
using namespace std;

int merge(int arr[],int temp[],int left,int mid, int right)
{
	int i,j,k,cnt=0;
	i=left; //i is the index for left subarray 
	j=mid; // j is the index for right subarray
	k=left; // k is the index for resultant merged subarray
	while((i<=mid-1) && (j<=right))
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else 
		{
			temp[k++]=arr[j++];
			cnt+=mid-i;
		}
	}
	while(i<=mid-1)// all remaining elements from left subarray
		temp[k++]=arr[i++];
	while(j<=right) // all remaining elements from right subarray
		temp[k++]=arr[j++];
	for(i=left;i<=right;i++)
		arr[i]=temp[i];
	return cnt;
}
int mergesort(int arr[],int temp[],int left, int right)
{
	int mid, cnt=0;
	if(right>left)
	{
		mid=(right+left)/2;
		cnt+=mergesort(arr,temp,left,mid); // left half 
		cnt+=mergesort(arr,temp,mid+1,right); //right half
		cnt+=merge(arr,temp,left,mid+1,right);
	}
	return cnt;
}

int main()
{
	int arr[]={5,3,2,4,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int temp[n];
	int res=mergesort(arr,temp,0,n-1);
	cout<<"Number of inversions: "<<res<<endl;
	return 0;
}
