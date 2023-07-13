// Prints out any of the LCS 
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

int LCSLength(vector<int>&a, vector<int>&b, vector<vector<int>> &dp){ // iterative version
    int n = (int) a.size();
    int m = (int) b.size();

    for(int i=1;i <= n;i++){
        for(int j=1;j <= m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m]; // the length of the LCS

}

vector<int> LCS(vector<int>& a, vector<int>&b, int n, int m, vector<vector<int>>&dp){
    vector<int> res;

    while(n > 0 && m > 0){
        if(a[n-1] == b[m-1]){ // if current characters are same they are part of lcs
            res.push_back(a[n-1]);
            n--, m--;
        }
        // if not we find the larger of the two 
        // and go in the direction of larger value
        else if(dp[n-1][m] > dp[n][m-1])
            n--;
        else
            m--;

    }

    reverse(res.begin(),res.end()); // cause we have pushed back the values 

    return res;

}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(auto&x: a) cin >> x;
    for(auto&x: b) cin >> x;

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    int len = LCSLength(a,b,dp);


    vector<int> res = LCS(a,b,n,m,dp);

    for(auto &x: res)
        cout << x <<" ";
	
}

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;

    while(t--)
        solve();

    return 0;
}

