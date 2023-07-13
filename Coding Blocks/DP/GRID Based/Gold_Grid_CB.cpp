#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> dp(1001,vector<int>(1001,0));

int getgoldcoins(int n)
{
    // first row
    for(int i=1;i<n;i++){
        dp[0][i] = dp[0][i-1] + dp[0][i];
    }
    // first col 
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + dp[i][0];
    }
    // for the matrix 2 d prefix sum 
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    int res = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int part1 = dp[i][j];
            int part2 = dp[i][n-1] - part1;
            int part3 = dp[n-1][j] - part1;
            int part4 = dp[n-1][n-1] - (part1 + part2 + part3 );

            res = max(res, min(min(part1,part2),min(part3,part4)));
        }
    }
    
    return res;

}

void display(int n)
{

    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" " ;
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        dp[l-1][r-1] = 1; // gold coin present at that cell
   }

   // dp before
   //display(n);
   cout<<getgoldcoins(n)<<endl;
    
   // dp after
   //display(n);

   return 0;
}
