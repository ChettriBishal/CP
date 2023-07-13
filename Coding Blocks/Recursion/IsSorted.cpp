/* To check if an array is sorted */
#include<iostream>
using namespace std;
bool sorted(int *p, int n)
{
    // base case
    if(n==1) // only one element
        return true;
    if(p[0]<p[1] && sorted(p+1,n-1))
        return true;
    return false;
}
int main()
{
    cout<<"Enter 5 elements in the array\n";
    int a[5];
    for(int &x:a)
        cin>>x;
    if(sorted(a,5))
        cout<<"SORTED\n";
    else
        cout<<"NOT SORTED\n";

    return 0;

}
