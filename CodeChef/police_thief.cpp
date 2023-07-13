#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
    int n,m;
    cin>>n>>m;
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    int thief=n-x+m-y;  // no of moves for thief to reach the bottom right corner
    int police=max(n-a,m-b); // no of moves for police to reach the bottom right corner
    if(thief<=police) // if thief reaches earlier
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
signed main()
{
	io;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
