#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(auto &x:a) cin>>x;
    ll first_hill=a[n/2]-k/2; // position of the first hill
    ll last_hill=first_hill+k-1; // position of the last hill
    ll ans=0;
    for(auto x:a){  
        ll dist=max(abs(first_hill-x),abs(last_hill-x));
        ans+=dist;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
The median of the hills must be same as the median of position of the houses given
So the first hill starts at a[mid]-k/2; 
For every house we either travel to the first hill or the last hill anyone which is the farthest
And then we sum them up into our ans
*/
