#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull power(ull a,ull n)
{
    // base case
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}
int main()
{
    cout<<"Enter a,n to find a^n: \n";
    ull a,n;
    cin>>a>>n;
    cout<<power(a,n)<<endl;

    return 0;
}
