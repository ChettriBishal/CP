#include<iostream>
using namespace std;
int lsearch(int * a, int key, int n)
{
    // if the search reaches the end
    if(n==0){
        return -1;
    }
    if(a[0]==key){
        return 0;
    }
    int i=lsearch(a+1,key,n-1);
    if(i==-1)
        return -1;
    return i+1; // cause we're counting from the back
}
// another way writing the same function
int linearsearch(int* a,int n,int i, int key)
{
    // if the cases are exhausted
   
    if(i==n) // base case
        return -1;
    if(a[i]==key)
        return i;
    return linearsearch(a,n,i+1,key);
}

int main()
{
    int a[]={89,45,23,22,12,80,78};
    int n=sizeof(a)/sizeof(int);
    int key=22 ; // to find the occurence of this
    int there=lsearch(a,key,n);
 
    cout<<"First method "<<there<<endl;
    cout<<"From another method ";
    
    there=linearsearch(a,n,0,key);
    cout<<there<<endl;


    return 0;
}
