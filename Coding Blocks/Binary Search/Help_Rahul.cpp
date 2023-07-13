// Rotated array
#include<iostream>
using namespace std;


int find_key(int* a, int n, int key)
{
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key)
            return mid;

        // case 1: midpoint lies in first part of the array
        else if(a[s]<=a[mid]){
            if(key>=a[s] && key<=a[mid]){
                e=mid-1;
            }
            else
                s=mid+1;
        }
        else // case 2: midpoint lies in second part of the array (a[mid]<=a[end])
        {
            if(key>=a[mid] && key<=a[e]){
                s=mid+1;
            }
            else
                e=mid-1;
        }
    }

    return -1;

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];

    int key;
    cin>>key;
    
    cout<<find_key(a,n,key)<<endl;

    return 0;
}
