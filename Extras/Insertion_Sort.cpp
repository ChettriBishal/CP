#include<iostream>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)

void insertion_sort(int* a,int n)
{
    cout<<"INSERTION SORT WORKING\n\n";
    for(int i=1;i<n;i++)
    {
        int prev=i-1; 
        int key=a[i];
        while(prev>-1 && a[prev]>key)
        {
            a[prev+1]=a[prev];
            --prev;
        }
        a[prev+1]=key;
        
        fr(i,n)
            cout<<a[i]<<" ";
        cout<<endl<<endl;
    }
}

int main()
{
    int a[]={12,13,9,10,5,2,1};
    int n=sizeof(a)/sizeof(int);

    insertion_sort(a,n);

    cout<<"Sorted Array\n";

    for(auto s:a)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
