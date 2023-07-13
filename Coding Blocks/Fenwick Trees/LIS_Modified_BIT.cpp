/*
 *You are given a sequence of N integers A denoted by A[1] , A[2]…..A[N].
 *Each integer in the sequence has a value associated with it W[1],W[2]…. W[N].
 *You have to select a subsequence of given array A such that all the elements in A are in strictly increasing order and sum of values of elements in this selected subsequence is maximum. You have to print this maximum value.
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
ll BIT[N], a[N], b[N],c[N];

void update(ll i,int n,ll val)
{
    while(i <= n){
        BIT[i] = max(val,BIT[i]);
        i += (i & (-i));
    }
}

ll query(ll i)
{
    ll res = 0;
    while(i>0){
        res = max(res,BIT[i]);
        i -= (i & (-i));
    }
    return res;
}

void solve(){
    
    memset(BIT,0,sizeof(BIT));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int n;
    cin>>n;
    for(int i= 0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
   
    // coordinate compression
    for(int i = 0;i<n;i++){
        a[i] = lower_bound(b,b+n,a[i]) -b +1;
    }
    
    // weights
    for(int i = 0;i<n;i++){
        cin>>c[i];
    }

    ll res = 0;
    for(int i= 0;i<n;i++){
        ll val = c[i];
        val += query(a[i]-1);
        update(a[i],n,val);
        res = max(res,val);
    }

    cout<<res<<endl;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
