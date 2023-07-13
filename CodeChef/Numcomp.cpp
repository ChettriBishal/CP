/* Bishal
 * 18-Jun-21 12:12:22 AM
*/
#include<bits/stdc++.h>
//#include"bistimulus.h"
using namespace std;
typedef long long ll;
const ll N=1e7+3;
bitset<N+3>primes;
vector<ll> pre(N+3,0);
void sieve()
{
    primes.set();
    primes[1]=primes[0]=0; // not prime
    for(ll i=4;i<=N;i+=2)
        primes[i]=0;
    for(ll i=3;i*i<=N;i+=2)
    {
        if(primes[i]){
            for(ll j=i*i;j<=N;j+=i)
                primes[j]=0;
        }
    }        
    // now create the prefix array to store the sum 
    for(ll i=2;i<=N;i++){
        pre[i]=pre[i-1]+(int)primes[i];
    } 
}
void solve()
{
    ll n;
    cin>>n;
    if(n==2){
        cout<<1<<"\n";
    }
    else if(n==3){
        cout<<2<<"\n";
    }
    else{
        cout<<pre[n]-pre[n/2]+1<<endl;       
    }
}

int main()
{
    sieve();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
