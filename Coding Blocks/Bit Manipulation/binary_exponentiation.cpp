#include<iostream>
using namespace std;
typedef long long ll;
ll epow(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) 
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    cout<<"Enter a and b to find a^b:\n";
    ll a,b;
    cin>>a>>b;
    cout<<epow(a,b)<<"\n";
    return 0;
}
/*
The exponent B will contain log(B) with base 2
So the time taken by this method is log B
*/
