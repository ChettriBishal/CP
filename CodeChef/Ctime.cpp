#include<bits/stdc++.h>
#ifdef M3sh
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
#define f first
#define s second
using namespace std;
typedef long long ll;
void solve()
{
    ll n,k,f;
    cin>>n>>k>>f;
    vector<pair<int,int>>d;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        d.push_back({a,b});
    }
    sort(d.begin(),d.end());
    ll high=0, tot=0;
    for(int i=0;i<n;i++){ 
        if(d[i].f>high){
            tot+=(d[i].f-high); // only chance for him
        }
        if(d[i].s>high){
            high=d[i].s; // increase the upper bound 
        }
    }
    tot+=(f-high);
    if(tot>=k){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
int main()
{
#ifdef M3sh
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
