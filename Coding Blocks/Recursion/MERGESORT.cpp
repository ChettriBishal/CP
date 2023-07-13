#include<iostream>
#include<tuple>
using namespace std;

void merge(int a[],int start,int end)
{
    int mid=(start+end)/2;
    int i,j,k;
    // i is pointer for the left sub array 
    // j is pointer for right sub array
    // k is the pointer for resultant merged array
    tie(i,j,k)=make_tuple(start,mid+1,start);

    int temp[100003]; // to store the merged resultant

    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    // remaining elements if present
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=end){
        temp[k++]=a[j++];
    }
    // finally copy all the elements in the original array
    for(int x = start; x <= end; x++)
        a[x] = temp[x];

}

void mergesort(int a[],int start,int end)
{
    // base case only one or no elements  
    if(start >= end)
       return;
    // follow 3 steps
    // 1. Divide the array
    int mid=(start+end)/2;

    // 2. Recursively sort the divided arrays: start-> mid & mid ->end
    
    mergesort(a,start,mid);
    mergesort(a,mid+1,end);

    // 3. Merge the two parts

    merge(a,start,end);

}
int main()
{
    cout<<"Enter size of the array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements\n";
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Sorted Array\n";

    mergesort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
