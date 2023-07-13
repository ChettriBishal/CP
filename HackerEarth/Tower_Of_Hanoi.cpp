#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
using namespace std;
// template<typename T>
//using ordered_set= tree<T, null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define setbits  __builtin_popcountll
#define ll long long 
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> vec;
    ll r,h;
    for(int i=0;i < n;i++){
        cin >> r >> h;
        vec.push_back({r,h});
    }

    sort(vec.rbegin(),vec.rend()); // sorting (descending order) on the basis of radius
    debug(vec); 


    vector<ll> dp(n,0);
    dp[0] = vec[0].second;
    for(int i=1;i < n;i++){
        ll temp;
        dp[i] = LLONG_MIN;
        for(int j=0;j <i;j++){
            if(vec[i].second < vec[j].second  && vec[i].first < vec[j].first){ // if the current disk can be placed on top of previous disk
                temp = vec[i].second + dp[j];
            }
            else
                temp = vec[i].second;

            dp[i] = max(dp[i], temp);
        }
    }

    cout << *max_element(dp.begin(),dp.end()) <<"\n";
	
}

/*
 after sorting: radii of elements at the front will be greater than those that come afterwards
 then check if both radius and height of the disk at front are greater than current disk
 if yes then we consider that in the dp for the ith disk...ie (+ dp[j])
 */

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

