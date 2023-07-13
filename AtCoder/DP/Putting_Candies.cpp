// https://atcoder.jp/contests/abc241/tasks/abc241_e
#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    int dp[40][200010];
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;

    for(int j=0;j < n;j++)
        dp[0][j] = arr[j];

    for(int i=0;i < 39;i++){
        for(int j=0;j < n;j++){
            dp[i+1][j] = dp[i][j] + dp[i][(j + dp[i][j])%n];
        }
    }

    for(int i=0;i < 40;i++){
        for(int j=0;j < n;j++){
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }

    int ans = 0;

    for(int i=0;i < 40;i++){
        if(k &1){
            ans += dp[i][ans%n];
        }
        k >>= 1;
    }

    cout << ans <<"\n";


}

