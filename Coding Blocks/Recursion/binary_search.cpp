/* to perform binary search in a sorted array */
#include<iostream>
using namespace std;
int binsearch(int *p,int l,int r,int key)
{
    // base case left pointer is greater than the right one
    if(l>r){
        return -1;
    }
    int mid=(l+r)/2;
    if(p[mid]==key)
        return mid;
    else if(p[mid]<key)
        return binsearch(p,mid+1,r,key);
    else
        return binsearch(p,l,mid-1,key);
}
int main()
{
    int a[]={1,6,18,23,67,89,90,101,304,456,789,800};
    int n=sizeof(a)/sizeof(int);
    int key;
    cout<<"Enter a number to search for: "; 
    cin>>key;
    int fo=binsearch(a,0,n-1,key);
    if(fo!=-1)
        cout<<"Found at index: "<<fo<<endl;
    else
        cout<<"Not found\n";
    return 0;

}
