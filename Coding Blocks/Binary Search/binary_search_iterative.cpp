#include<iostream>
using namespace std;

// to search in sorted arrays
int binary_search(int* a,int n, int key)
{
    int s=0; // start
    int e=n-1; // end

    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            e=mid-1;
        else
            s=mid+1;
    }
    return -1;
}

int main()
{
    int a[]={2,3,6,8,9,10,11,12,45,67,99};
    int n=sizeof(a)/sizeof(int);

    cout<<"Enter the element you want to search for:\n";
    int key;
    cin>>key;
    int ind=binary_search(a,n,key);

    if(ind>=0){
        cout<<"Element found at index "<<ind<<endl;
    }
    else
        cout<<"Not found\n";

    return 0;
}
