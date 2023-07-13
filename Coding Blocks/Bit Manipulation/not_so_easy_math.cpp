#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<int>primes{2,3,5,7,11,13,17,19}; // primes below 20;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll res=0;
        for(ll i=1;i<(1<<primes.size());i++)
        {
            vector<ll>temp;
            ll k=i;
            ll j=0;
            while(k>0){
                if(k & 1)
                    temp.push_back(primes[j]);
                j++;
                k=k>>1;
            }
            ll prod=1;
            for(auto val:temp)
                prod*=val;
            if(temp.size() &1) res+=n/prod;
            else res-=n/prod;
        }
        cout<<res<<"\n";
    }
    return 0;
    
}
