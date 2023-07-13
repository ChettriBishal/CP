#include<bits/stdc++.h> // from the explanation
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    int primes[]={2,3,5,7,11,13,17,19};
    ll m=sizeof(primes)/sizeof(int);
    ll subsets=(1<<m);
    ll res=0ll;
    for(ll i=1;i<subsets;i++) // say i--> rows and j-->bits
    {
        ll prod=1ll; // product in denominator
        ll sizei=__builtin_popcount(i); // no of set bits gives the size of the subset 
        
        for(ll j=0;j<m;j++) // iterate through all positions and consider the ones which have set bit
        {
            if(i & (1<<j)) // checking if the jth bit in 'i' is set then consider the jth element in the subset
                prod*=primes[j];
        }
        if(sizei & 1){ // if size of subset is odd
            res+=n/prod;
        }
        else // if size of subset is even
            res-=n/prod;
    }
    cout<<res<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
