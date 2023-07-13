#include<bits/stdc++.h>
using namespace std;

int main()
{

#ifdef Bis
    freopen("input.txt","r",stdin);
#endif

    int n;
    cin >> n;

    vector<int> values(n);

    for(int &x: values) cin >> x;

    vector<int> weights(n);

    for(int &x: weights) cin >> x;

    int cap;

    cin >> cap;

    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));


    for(int i= 0;i <= n;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i <= n;i++){
        for(int wt = 0;wt <= cap;wt++){
            if(wt >= weights[i-1]){
                dp[i][wt] = max(dp[i-1][wt] , dp[i-1][wt - weights[i-1]] + values[i-1]);
            }
            else{
                dp[i][wt] = dp[i-1][wt];
            }
        }
    }

    cout << dp[n][cap] << endl;

    return 0;
    
}



