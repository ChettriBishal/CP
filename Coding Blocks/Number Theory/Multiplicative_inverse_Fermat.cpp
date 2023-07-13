#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll mpow(ll a,ll b)
{
    ll res=1ll;
    while(b){
        if(b&1)
            res=((res % mod)*(a % mod)) % mod;
        a=((a % mod) * (a %mod)) % mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ll n;
    cin>>n;
    cout<<mpow(n,mod-2)<<endl;
    return 0;
}
/* Using fermat's little theorem
 * a^M is congruent to a over mod (M)
 * a^(M-1) is congruent to 1 over mod (M)
 * a^(M-2) is congruent to a^-1 over mod (M)
 * thus a^(m-2) is congruent to a inverse over mod (M)
 */
