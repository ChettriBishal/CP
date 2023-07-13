/* Bishal
20-Apr-21 6:09:52 PM
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
    int n,r;
    cin>>n>>r;
    vector<ll>a(n);
    for(auto &x:a)
        cin>>x;
    vector<pair<ll,int>>bis;
    int d;
    for(int i=0;i<n;i++){   
        cin>>d;
        bis.push_back({a[i],d});
    }
    ll res=bis[0].s, prev=res;
    for(int i=1;i<n;i++)
    {
        prev-=r*(bis[i].f-bis[i-1].f); // first check the decrement for tension
        if(prev<0LL) prev=0LL; // "maximized with zero" if the decrement turns tension negative
        prev+=bis[i].s; 
        res=max(res,prev);
    }
    cout<<res<<"\n";
}
int main()
{
    io;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
