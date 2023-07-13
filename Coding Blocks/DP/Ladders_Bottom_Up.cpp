/* No of ways to reach the top of the ladder of N steps Bottom UP*/
#include<iostream>
using namespace std;

int ways(int n,int k)
{
    int dp[n+1]={0};
    dp[0] = 1; //start case
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++)
            if(i - j >= 0)
                dp[i] += dp[i-j];
    }

    cout<<"DP Table\n";
    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return dp[n];
}


int main()
{
    int n,k;
    cin>>n>>k;
    int no = ways(n,k); // no of ways
    cout<<"Ways = "<<no<<endl;

    return 0;
}
