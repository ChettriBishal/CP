// IMPORTANT: use unsigned long long for the array 
// https://www.spoj.com/problems/UPDATEIT/
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long  // required to store large numbers 

ull a[10003];  // it will store the sum of integers so
int n;
void update(int i,int val)
{
    while(i<=n){
        a[i] += val;
        i += (i & (-i));
    } 
}

ull query(int i)
{
    ull res = 0;
    while(i>0){
       res += a[i];
       i -= (i & (-i));
    }
    return res;
}
// to updates elements within the range [l,r]
void update_range(int l,int r,int val)
{
    update(l,val);
    update(r+1,-val);
}

void solve()
{
    int u;
    cin>>n>>u;
    memset(a,0,sizeof(a));
    while(u--){
        int l,r,val;
        cin>>l>>r>>val;
        l++;r++;
        update_range(l,r,val);
    }
    int q;
    cin>>q;
    while(q--){
        int i;
        cin>>i;
        ++i;
        cout<<query(i)<<endl;
    }
}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
