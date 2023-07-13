#include <bits/stdc++.h>

using namespace std;

int main()
{
    int amount , n;
    cin >> amount  >>n;
    int coins[n];
    for(auto &x: coins)
        cin >>x;
    long dp[n+1][amount+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i <=n ;i++) // to make zero amount is always possible 
        dp[i][0] = 1;
    
    for(int i=1; i <=n;i++){
        for(int am = 1; am <= amount; am++){
            dp[i][am] = dp[i-1][am]; // when excluded
            if(am- coins[i-1] >= 0) // when included
                dp[i][am] += dp[i][am-coins[i-1]];
        }
    }
    
    cout <<dp[n][amount] <<endl;
    
    return 0;
}

/*
 dp[r][c] = dp[r-1][c] + dp[r][c-coins[r-1]]
 */
