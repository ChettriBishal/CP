#include<iostream>

using namespace std;

int first_occurrence(int* a,int n, int key)
{
    int s=0;
    int e=n-1;

    int res = -1;

    // Update in a direction that res value gets lower  
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            res=mid;
            e=mid-1;
        }
        else if(a[mid]<key)
            s=mid+1;
        else
            e=mid-1;
    }    
    return res;
}

int last_occurrence(int* a,int n, int key)
{
    int s=0;
    int e=n-1;
    
    int res=-1;
    
    // Update in a direction that res value gets higher 

    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            res=mid;
            s=mid+1;
        }
        else if(a[mid]<key)
            s=mid+1;
        else 
            e=mid-1;
    }
    return res;
}
int main()
{
    int a[]={1,2,3,4,8,8,8,8,8,8,9,12};
    
    for(auto x:a)
        cout<<x<<" ";
    cout<<endl;


    int n=sizeof(a)/sizeof(int);

    int key;
    cin>>key;

    cout<<"First occurrence "<<first_occurrence(a,n,key)<<endl;

    cout<<"Last occurrence "<<last_occurrence(a,n,key)<<endl;

    return 0;
}
