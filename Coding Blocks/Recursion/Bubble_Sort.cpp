#include<iostream>
using namespace std;

// converting the iterative version to recursive
void bubble_sort(int *a, int n)
{
    // base case
    if(n==1)
        return;

    // recursive case
    // moving the current largest element to the end
    for(int i=0;i<n-1;i++)  // the iterative part here
    {
        if(a[i]>a[i+1])
            swap(a[i],a[i+1]);
    }
    // sort n-1 elements
    bubble_sort(a,n-1);
}

// completely recursive function
void bubble_recursive(int* a,int j,int n)
{
    if(n==1)
        return;
    if(j==n-1){
        // single traversal of the current array has been done
        return bubble_recursive(a,0,n-1); // resetting with size less
    }
    if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    
    bubble_recursive(a,j+1,n); 
    return;
}
int main()
{
    int a[]={2,3,1,8,23,11};
    int n=sizeof(a)/sizeof(int);
    bubble_sort(a,n);
    for(auto x:a)
        cout<<x<<" ";
    
    cout<<endl;

    int b[]={44,55,12,90,3,89,99};
    n=sizeof(b)/sizeof(int);
    bubble_recursive(b,0,n);
    for(auto x:b)
        cout<<x<<" ";
    return 0;
}
