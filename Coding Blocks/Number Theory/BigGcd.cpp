#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll epow(ll a, ll b, ll n) // taking mod wrt n
{
    ll res=1ll;
    while(b)
    {
        if(b&1)
            res=(res*a)%n;
        a=(a*a)%n;
        b>>=1;
    }
    return res%n;
}
void solve()
{
    ll n;
    string m;
    cin>>n>>m;
    if(n==0){
        cout<<m<<endl;
        return;
    }
    ll sec=0;
    int len=(int)m.length();
    for(int i=0;i<len;i++)
    {
        ll val=((m[i]-'0') % n *epow(10,len-i-1,n) % n) %n;
        sec=(sec%n + val % n)%n;
    }
    cout<<__gcd(n,sec)<<endl;
}
int main()
{
    solve();
    return 0;
}
