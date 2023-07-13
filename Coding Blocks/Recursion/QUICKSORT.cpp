#include<iostream>
using namespace std;

int partition(int* a,int s, int e)
{
   int pivot = a[e];

   int p = s; // pivot index

   for(int i=s;i<=e-1;i++)
   {
       if(a[i]<=pivot){
           swap(a[i],a[p]);
           p++;
       }
   }
    swap(a[e],a[p]);

    return p;

}

void quicksort(int * a,int s, int e)
{
    // base case
    if(s>=e)
        return;
    
    // partition index --> recursive case
    int p = partition(a,s,e);
    
    // left
    quicksort(a,s,p-1);
    // right
    quicksort(a,p+1,e);
}

int main()
{
    int a[]={2,7,8,6,1,5,4};
    int n = sizeof(a) / sizeof(int);

    quicksort(a,0,n-1); 

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
