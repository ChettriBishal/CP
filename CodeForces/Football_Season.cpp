#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){
        x=1; 
        y=0;
        return a;
    }
    ll x1,y1;
    ll hcf=extgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;

    return hcf;
}

ll modinv(ll a,ll m) // to find mod inverse of 'a' wrt m
{
    ll x,y;
    ll hcf=extgcd(a,m,x,y);
    assert(hcf==1);
    ll b= (x%m+m)%m;
    
    return b;
}
void solve()
{
    // x*w + y*d =p
    // x + y + z =n
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll x,y,z;
    ll g= __gcd(w,d);
    if((p%g)!=0){
        cout<<-1<<endl;
        return;
    }
    // if team wins all the matches but also loses the match
    // y=0 (no draws) then x=n ..no of wins is same as no of matches 
    if(n*w<p){
        cout<<-1<<endl;
        return;
    }
    
    p/=g;
    w/=g;
    d/=g;

    // draws 
    // (p/d)% w
    y= ((p%w) *modinv(d,w))%w;
    x=(p-y*d)/w;
    if(x+y>n){
        cout<<-1<<endl;
        return;
    }
    if(x<0){
        cout<<-1<<endl;
        return;
    }
    z=n-(x+y);
    cout<<x<<" "<<y<<" "<<z<<" "<<endl;
}
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
