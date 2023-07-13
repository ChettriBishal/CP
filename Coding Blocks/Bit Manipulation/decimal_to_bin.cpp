#include<bits/stdc++.h>
using namespace std;
int tobin(int n) // to convert into binary
{
    int base=1; // base for multiplication
    int res=0;
    while(n){
        res=(n&1)*base+res;
        base*=10;
        n=n>>1;
    }
    return res;
}
int main()
{
    cout<<"Enter a number to convert to binary: \n";
    int n;
    cin>>n;
    cout<<tobin(n)<<"\n";
    return 0;
    
}
