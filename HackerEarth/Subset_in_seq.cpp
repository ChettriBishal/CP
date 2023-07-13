#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
ll expow(ll a, ll b) // binary exp
{
    ll res=1;
    while(b>0)
    {
        if(b&1) 
            res=res*a;
        a=a*a;
        b>>=1; 
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll>res;
    ll i=0;
    while(n){
        if(n&1){ // if the bit at position 'i' is set then consider the power of that 
            res.pb(expow(3,i));
        }
        n>>=1; // traversing all the bits 
        i++;
    }   
    cout<<res.size()<<endl;
    for(ll x:res)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
