#include<iostream>
#include<utility>
#include<vector>
typedef long long ll;
using namespace std;

ll maxvalue(vector<pair<ll,ll>> & wp,ll W,ll pos,vector<vector<ll>> &dp)
{
    if(W == 0 || pos < 0){ // if the knapsack capacity is exhausted or end of array has reached
        return 0;
    }
    if(dp[pos][W] != -1)
        return dp[pos][W];

    // we include 
    ll whenincluded = 0;
    if(wp[pos].first <= W)
        whenincluded = wp[pos].second + maxvalue(wp,W-wp[pos].first, pos-1,dp);

    // we exclude
    ll whenexcluded = 0;
    whenexcluded = maxvalue(wp,W,pos-1,dp);
    
    return dp[pos][W] = max(whenincluded, whenexcluded);
}

signed main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    ll N, W;
    cin>>N>>W; // N items and capacity of knapsack W 
    vector<pair<ll,ll>> wp;
    ll a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        wp.push_back({a,b}); // weight value pairs
    }

    vector<vector<ll> > dp(N, vector<ll> (W+1,-1));

    cout<<maxvalue(wp,W,N-1,dp)<<endl;

    return 0;
}
