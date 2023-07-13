#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    ll cnt=0,x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x&1) cnt++;// count of odd numbers
    }
    cout<<cnt*(n-cnt)<<endl; //aka observation
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
