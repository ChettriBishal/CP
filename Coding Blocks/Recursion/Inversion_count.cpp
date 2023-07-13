#include<iostream>
using namespace std;

int merge(int* a, int s , int e)
{
    int mid=(s+e)/2;
    int i = s, j= mid+1, k = s;
    int temp[10000];

    int cnt=0; // cross inversions 

    while(i<=mid && j<=e)
    {
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }
        // important from the second sub array
        else{
            temp[k++] = a[j++];
           
            // cnt of elements in left sub-array greater than the current one
            cnt+=mid-i+1;
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }
    
    while(j<=e){
        temp[k++] = a[j++];
    }

    for(int x=s;x<=e;x++)
        a[x] = temp[x];

    return cnt;

}

int inversion_count(int* a, int s, int e)
{
    if(s>=e)
        return 0;
    
    int mid=(s+e)/2;
    int x = inversion_count(a,s,mid);
    int y = inversion_count(a,mid+1,e);
    int z = merge(a,s,e);  // cross inversions

    return (x+y+z);
}



int main()
{
    int a[]={1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(int);

    cout<<inversion_count(a,0,n-1); // like the merge sort function

}
