/* Minimum coin change problem TOP Down --> Recursive */
#include<iostream>
#include<climits>
using namespace std;


int mincoins(int n,int* coins,int cn,int* dp)
{
    if(n == 0){
        return 0;
    }

    if(dp[n]){
        return dp[n];
    }

    int x = INT_MAX;
    for(int i=0;i<cn;i++){
        if(n- coins[i] >=0){
            int subprob = mincoins(n-coins[i],coins,cn,dp); 
            x= min(x,subprob + 1);
        }
    }
    dp[n] = x;
    return dp[n];
}


int main()
{
    cout<<"Enter the amount whose change you want\n";
    int n;
    cin>>n;
    int coins[] = {1,7,10};
    int dp[100] = {0};
    cout<<mincoins(n,coins,3,dp)<<endl;

    return 0;
}
