#include<bits/stdc++.h>
using namespace std;


// top down 
int max_profit_topdown(int* prices,int *dp, int n)
{
    if( n <= 0 ){
        return 0;
    }
    if(dp[n]){
        return dp[n];
    }
    int res = INT_MIN;
    for(int i=1;i<n;i++){
        int cut = i+1; // place where the cut is located
        int current_ans = prices[i] + max_profit_topdown(prices,dp,n - cut);
        
        res = max(res,current_ans);
    }

    return dp[n] = res;
}

// bottom up
int max_profit_bottomup(int* prices,int n)
{
    int dp[n+1];
    dp[0] = 0; 

    for(int len = 1;len <= n;len++)
    {
        int ans = INT_MIN; // to store ans for every state of dp
        for(int i=0;i<len;i++){
            int cut = i+1;
            int current_ans = prices[i] + dp[len- cut];
            ans = max(current_ans, ans);
        }
        dp[len] = ans;
    }

    cout<<"DP Table\n";

    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[n];
}



int main()
{
    int prices[] = {1,5,8,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);
    int dp[n+1] = {0};

    cout<<max_profit_topdown(prices,dp,n)<<endl;

    cout<<max_profit_bottomup(prices,n)<<endl;

    return 0;

}
