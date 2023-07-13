#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<vector<int>> dp(1001,vector<int>(1001,0));


long noofways(int r,int c)
{
    
    if(dp[0][0] == -1){ // if the first cell is blocked
        return 0;
    }


    // first set the values for the first rowc
    for(int i=0;i<c;i++){
        if(dp[0][i] == -1) 
            break;
        dp[0][i] = 1;
    }
    // then for the first column
    for(int i=0;i<r;i++){
        if(dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }

    // now we'll do prefix sum array sort of thing
    // BOTTOM UP APPROACH
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(dp[i][j] == -1) // if the cell is blocked
                continue;

            dp[i][j] = 0; // intially

            if(dp[i-1][j] != -1)
                dp[i][j] = ( dp[i-1][j] )% MOD;

            if(dp[i][j-1] != -1)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) %MOD;
        }
    }

    if(dp[r-1][c-1] == -1){
        return 0;
    }

    return dp[r-1][c-1];

}


int main()
{

	#ifdef Bis
        freopen("input.txt","r",stdin);
	#endif
    int m,n,p;
    cin>>m>>n>>p;
    while(p--){
        int l,r;
        cin>>l>>r; // cells which are blocked
        dp[l-1][r-1] = -1;
    }

    cout<<noofways(m,n)<<endl;

    return 0;
}
