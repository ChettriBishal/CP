#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    unordered_map<int,int> dp;
    for(int &x: a) cin>>x;

    dp[0] = 0; // to reach the first stone
    dp[1] = abs(a[1] - a[0]); // only one way to reach second stone from first one

    for(int i=2;i<n;i++){
        int cost = INT_MAX;
        for(int km = 1;km <=k;km++){ // all k valid choices of indices
            if(i - km < 0 ) break;
            cost = min(cost, dp[i-km] + abs(a[i] - a[i-km]));
        }
        dp[i] = cost;
    }

    cout<<dp[n-1]<<endl;
}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
   int t = 1;
   //cin>>t;
   while(t--){
       solve();
   }
   return 0;
}
