// ॐ मणि पद्मे हूँ
#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
// template<typename T>
//using ordered_set= tree<T, null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
#define setbits  __builtin_popcountll
#define ll long long 
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ALL_THE(Cake,Lie) for(auto Lie = Cake.begin(); Lie!= Cake.end(); Lie++)
#define all(x) begin(x), end(x)
#define here cout <<"HERE\n"

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for(ll &x: arr) cin >> x;

    vector<ll> pre(n,0), suff(n,0);

    pre[0] = 1;
    vector<ll> lis;
    lis.pb(arr[0]);

    for(int i= 1;i < n;i++){
        if(arr[i] > lis.back()){
            pre[i] = pre[i-1] + 1;
            lis.pb(arr[i]);
        }
        else{
            auto it = lower_bound(all(lis), arr[i]);
            if(it != lis.end()){
                *it = arr[i];
            }
            pre[i] = pre[i-1];
        }
    }

    lis.clear();
    lis.pb(-arr[n-1]);
    suff[n-1] = 1;
    for(int i=n-2;i >=0;i--){
        if(-arr[i] > lis.back()){
            suff[i] = suff[i+1] + 1;
            lis.pb(-arr[i]);
        }
        else{
            auto it = lower_bound(all(lis), -arr[i]);
            if(it != lis.end()){
                *it = -arr[i];
            }
            suff[i] = suff[i+1];
        }
    }

    ll res = 0;
    for(int i=0;i < n-1;i ++){
        res = max(res, pre[i] + suff[i+1]);
    }
    
    cout << res << endl;
	
}

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;
    cin>>t;

    while(t--)
        solve();

    return 0;
}

