/* No of ways to reach the top of the ladder with N steps, taking at max k steps at a time*/
#include<iostream>
#include<map>
using namespace std;

/*
Optimised Method O(n +k ) --> O(n) ; as k < n   
dp[n] = dp[n-1] + dp[n-k-1] + dp[n-1]
dp[n] = 2*dp[n-1] + dp[n-k-1]
*/

int ways(int n,int k)
{
    int dp[n+1]= {0};
    dp[0] = dp[1] =1; // base conditions 

    
    for(int i=2;i<=k;i++) // upto n-k-1 < 0 so...we consider dp[n-k-1] = 0; 
        dp[i] = 2*dp[i-1];


    for(int i = k+1;i<=n;i++)
    {
        dp[i] = 2*dp[i-1] - dp[i-k-1]; 
    }

    //dp array
    cout<<"DP Array\n";
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
