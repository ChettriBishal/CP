#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve()
{
    int n,x;
    cin>>n>>x;
    set<ll>bis;
    ll val;
    for(int i=0;i<n;i++){   
        cin>>val;
        bis.insert(val);
    }
    cout<<min((int)bis.size(),n-x)<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
