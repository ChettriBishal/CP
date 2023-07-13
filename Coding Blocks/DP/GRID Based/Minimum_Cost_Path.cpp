#include<iostream>
using namespace std;

int min_cost(int R,int C,int cost[][3],int dp[][3]) // minimum cost to reach cell (R-1, C-1)
{
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            //base case
            if(i == 0 && j == 0)
                dp[i][j] = cost[0][0];
            else if(i == 0)
                dp[i][j] = dp[0][j-1] + cost[0][j];
            else if(j == 0)
                dp[i][j] = dp[i-1][0] + cost[i][0];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
        }
    } 
    return dp[R-1][C-1];
}

int main()
{
    int cost[][3] = {{1,5,2},{7,1,1},{8,1,3}};
    int dp[3][3];

    cout<<"MIN COST "<<min_cost(3,3,cost,dp)<<endl;

    // to print the dp matrix
    cout<<"DP Matrix\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
