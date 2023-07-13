/*

tiling problem 
Given a floor of size nXm.
Find the number of to tile the floor with tile of size 1Xm. 
A tile can either be place horizontally or vertically

Using iterative dp here
*/

#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int noofways(int n, int m)
{
    int dp[n+1];
    dp[0]=dp[1]=1;

    for(int i=2;i<=n;i++){
        if(i>=m)
            dp[i]=( dp[i-1]+ dp[i-m] ) % MOD;
        else
            dp[i]=dp[i-1];
    }
    return dp[n];
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<noofways(n,m)<<endl;
    }

    return 0;
}
