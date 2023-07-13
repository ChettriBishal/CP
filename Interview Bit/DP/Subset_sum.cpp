int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(B == 0)
        return true;
    if(n == 0)
        return false;
    vector<vector<int>> dp(n+1, vector<int>(B+1, 0));
    for(int i=0;i <= n;i++)
        dp[i][0] = 1; // possible to create an zero sum ie empty set
    
    for(int i=1; i<= n;i++){
        for(int j=1; j<= B; j++){
            if(A[i-1] <= j && j - A[i-1] >= 0){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]]; // excluding + including
            }
            else{
                dp[i][j] = dp[i-1][j]; // excluding 
            }
        }
    }

    return dp[n][B] != 0;
    

}
