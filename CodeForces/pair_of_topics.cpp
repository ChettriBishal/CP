#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
int main()
{
    int n;
    cin>>n;
    vector<ll>a(n),b(n),c(n);
    for(ll &x: a) cin>>x;
    for(ll &x: b) cin>>x;
    for(int i=0;i<n;i++)
        c[i]=a[i]-b[i];
    ordered_set st;
    ll res=0;
    for(int i=0;i<n;i++){
        res+=st.size()-st.order_of_key({-1ll * c[i],i});
        st.insert({c[i],i});
    }
    cout<<res<<"\n";
    return 0;

}
/*
https://codeforces.com/problemset/problem/1324/D
*/
