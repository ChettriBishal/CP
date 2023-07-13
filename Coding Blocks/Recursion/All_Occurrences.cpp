#include<iostream>
using namespace std;

void allocc(int* a,int i, int n, int key)
{
    if(i==n)
        return;
    if(a[i]==key)
        cout<<i<<" ";
    allocc(a,i+1,n,key);
}
// returns the size of the output array 
int storeocc(int* a, int i, int n, int key,int* out,int j)
{
   if(i==n)
       return j;
   
   if(a[i]==key)
   {
       out[j]=i;
       return storeocc(a,i+1,n,key,out,j+1);
   }
   return storeocc(a,i+1,n,key,out,j); // observe that only i is getting incremented not j 
}
int main()
{
    int a[]={1,2,3,3,4,5,5,3,9,3,10};
    int n=sizeof(a)/sizeof(int);
    int key=3;
    int output[10];
    int cnt=storeocc(a,0,n,key,output,0);
    for(int i=0;i<cnt;i++)
        cout<<output[i]<<" ";
    cout<<endl;
    allocc(a,0,n,key);

}
