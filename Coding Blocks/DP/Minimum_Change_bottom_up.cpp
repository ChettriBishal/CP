/* Minimum coin change problem BOTTOM Up ---> Iterative */
#include<iostream>
#include<climits>
using namespace std;

// cn is the number of coins possible as per the currency
int mincoins(int N,int* coins,int cn)
{
   int dp[100]= {0};

   // Iterate over all states 1 ...N
   for(int n=1;n<=N;n++){
       dp[n] = INT_MAX;

       for(int i=0;i<cn;i++){
           if(n-coins[i] >= 0){
               int subprob = dp[n-coins[i]];
               dp[n] = min(dp[n],subprob + 1);
           }
       }
   }

   return dp[N];
}


int main()
{
    cout<<"Enter the amount whose change you want\n";
    int n;
    cin>>n;
    int coins[] = {1,7,10};
    cout<<mincoins(n,coins,3)<<endl;

    return 0;
}

