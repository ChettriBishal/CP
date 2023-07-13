#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll query(ll p,int len,vector<int>& pre)
{
    ll m = p/len; // integral portion
    int rem = p %len; // remaining
    return pre[len-1]*1LL*m + pre[rem];
}

void build(vector<int> & pre,int a,int b )
{
    int len = a*b;
    pre[0] = 0;
    for(int i=1;i<=len;i++){
        pre[i] = pre[i-1];
        if((i%a)%b != (i%b)%a) // if element satisfies the given condition
            pre[i]++;
    }
}

void solve()
{
    int a,b,q;
    cin>>a>>b>>q;
    int len = a*b; 
    vector<int> pre(len+1);
    build(pre,a,b); // building the prefix array 
    
    // now taking the queries
    // query(l,r) --> query(0,r) - query(0,l-1)
   
    ll left, right;
    while(q--){
       cin>>left>>right;
       ll res = query(right,len,pre) - query(left-1,len,pre);
       cout<<res<<" ";
    }
    cout<<endl;

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
