#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modpow(ll a, ll n, ll p){
    ll res=1;
    while(n){
        if(n&1)
            res=(res %p * a %p)%p;
        a=(a %p * a% p)%p;
        n>>=1;
    }
    return res;
}
void solve()
{
    ll a,n,p;
    cin>>a>>n>>p;
    ll res= a;
    for(ll i=1;i<=n;i++){
        res=modpow(res,i,p); 
    } 
    cout<<res<<endl;
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
// a^n! % p
