#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=40050; // 200 * 200 +

int pre[N];

int len; // length 0.....a*b

void build(int a,int b) // to construct the prefix sum array meeting the conditions 
{
    len=a*b;
    memset(pre,0,sizeof(pre));

    for(int i=1;i<=len;i++)
    {
        int addon=0;
        if((i%a)%b != (i%b)%a) // required condition 
            addon=1;
        pre[i]=pre[i-1]+addon;
    }
}
ll query(ll start)
{
    ll full=start/len; // no of full parts (0..a*b) from the required segment
    int rem=start%len; // remaining segment

    return (ll) pre[len]*full + pre[rem];
}

void solve()
{
    int a,b,q;
    cin>>a>>b>>q;
    build(a,b); // create the prefix sum array from 0 to a*b
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<" ";
    }
    cout<<endl;
}   

int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;

}
