#include<iostream>
using namespace std;
typedef long long ll;
ll modexpo(ll a, ll b, ll mod)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main()
{

    cout<<modexpo(5,3,100)<<endl;

    return 0;

}
