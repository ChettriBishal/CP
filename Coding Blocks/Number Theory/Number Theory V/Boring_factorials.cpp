/* Using Wilson's theorem 
 * and Fermat's little Theorem to find the modulo multiplicative inverse
 * https://www.spoj.com/problems/DCEPC11B/
 * Important lesson from this problem : modulo slows the execution time 
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modpow(ll a,ll b, ll mod)
{
    ll res=1ll;
    while(b){
        if(b&1)
            res=(res * a)% mod;
        a=(a * a)%mod;
        b>>=1;
    }
    return res % mod;
}

void solve()
{
    ll n,p;
    cin>>n>>p;
    if(n>=p){
        cout<<0<<endl;
        return;
    }
    ll res=-1ll;
    for(ll i=n+1;i<p;i++){
        res=(res * modpow(i,p-2,p));
        res=res % p;   
    }
    cout<<res+p<<endl;  // as the value is negative at first 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
