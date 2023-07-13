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

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

bool func(ll t,ll n,ll k, vector<pair<ll,ll>>& vec){

    ll m = vec.size();
    vector<ll> temp(m,0);

    for(ll i=0;i < m;i++){
        if(t >= vec[i].f)
            temp[i] = 1ll + (t - vec[i].f) / vec[i].s;
    }

    sort(all(temp),greater<ll>());

    ll nuts = 0ll;

    for(ll i=0;i < min(n,m);i++){
        nuts += temp[i];
    }

    return (nuts >= k);
}

void solve()
{
    ll n,m,k;
    cin >> m >> n >> k;

    vector<pair<ll,ll>> vec(m);

    for(int i=0;i < m;i++)
        cin >> vec[i].f;

    for(int i=0;i < m;i++)
        cin >> vec[i].s;

    ll lo = 0, hi = 1e9;

    while(hi - lo > 1){
        ll mid = lo + (hi - lo)/2ll;
        if(func(mid,n,k, vec)){
            hi = mid;
        }
        else
            lo = mid;
    }

	
    cout << hi << endl;
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

