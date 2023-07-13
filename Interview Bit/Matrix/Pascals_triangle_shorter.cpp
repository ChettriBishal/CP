vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans(A);
    for(int i=0;i < A;i++){
        ans[i] = vector<int> (i+1,1);
        for(int j =1;j < i;j++){
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];        
        }
    }
    return ans;
}
