#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    ll res=0;
    // these cases handle singular as well as extra cubes at the top
    if(n%4==1) // one dice
        res=20;
    if(n%4==2) // two 
        res=36;
    if(n%4==3) // three
        res=51;
    ll lev=n/4LL; // the levels 
    res+=lev*44LL; // only two faces visible
    if(lev>=1) // flat squares at the top having 4 pips
        res+=(4LL * ll(4-n%4));
    cout<<res<<"\n";
}
int main()
{   
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
