/* Wines Problem Top Down Recursive */
#include<iostream>
#include<algorithm>
using namespace std;

// i -> starting index 
// j -> ending index
// y -> current year

int maxprice(int* prices,int dp[][100],int i,int j,int y)
{
    // base case; no bottle left
    if(i> j){
        return 0;
    }

    if(dp[i][j]){
        return dp[i][j];
    }

    // f(i+1,j)
    int first = prices[i]*y + maxprice(prices,dp,i+1,j,y+1); 
    
    // f(i,j-1)
    int second = prices[j]* y + maxprice(prices,dp,i,j-1,y+1);

    return dp[i][j] = max(first,second);

}

int main()
{
    int prices[] = {2,3,5,1,4};
    int n = sizeof(prices)/sizeof(int);
    int dp[100][100];
    cout<<maxprice(prices,dp,0,n-1,1)<<endl; 

    return 0;
}

