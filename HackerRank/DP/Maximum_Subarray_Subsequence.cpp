#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &x: arr) cin >> x;

    // firstly let's find the maximum subarray sum
    
    int res = INT_MIN;
    int run = 0;

    for(int i=0;i < n;i++){
        run = max(run, 0);
        run += arr[i];
        res = max(res, run);
    }

    cout << res <<" ";

    // now find maximum subsequence sum 
    
    vector<int> dp(n+1,0);

    dp[0] = arr[0];
    for(int i= 1;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-1]+ arr[i]);
        dp[i] = max(dp[i], arr[i]);
    }

    cout << dp[n-1] <<endl;
}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin >> t;
    while(t--)
        solve();


    return 0;

}
