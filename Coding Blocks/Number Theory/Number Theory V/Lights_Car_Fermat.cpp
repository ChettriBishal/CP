#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
ll epow(ll a,ll b)
{
    ll res=1ll;
    while(b){
        if(b&1)
            res=(res%P* a%P)%P;
        a=(a%P * a%P)%P;
        b>>=1;
    }
    return res%P;
}

void solve()
{
    string a,b;
    cin>>a>>b;
    ll base=0;
    for(int i=0;i<(int)a.length();i++){
        base=base*10+(a[i]-'0');
        base%=P;
    }
    ll exp=0;
    for(int i=0;i<(int)b.length();i++){
        exp=exp*10+(b[i]-'0');
        exp%=(P-1);
    }
    cout<<epow(base,exp)<<endl;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
