void dfs(int i,int j,vector<vector<int>> &A, vector<vector<bool>>& visited){
    int n = A.size();
    int m = A[0].size();

    if(i >= n || j >= m || i < 0 || j < 0)
        return;

    visited[i][j] = true; 
    
    // check down
    if(i+1 < n && A[i+1][j] >= A[i][j] && visited[i+1][j] == false)
        dfs(i+1,j,A,visited);
    // check right
    if(j+ 1 < m && A[i][j+1] >= A[i][j] && visited[i][j+1] == false)
        dfs(i,j+1,A,visited);
    // check up
    if(i -1 >= 0 && A[i-1][j] >= A[i][j] && visited[i-1][j] == false)
        dfs(i-1,j,A,visited);
    // check left
    if(j -1 >=0 && A[i][j-1] >= A[i][j] && visited[i][j-1] == false)
        dfs(i,j-1,A,visited);
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> blue(n, vector<bool>(m,false));
    vector<vector<bool>> red(n,vector<bool>(m,false));

    // blue side
    for(int i=0;i < n;i++)
        dfs(i,0,A,blue);
    for(int j=0;j < m;j++)
        dfs(0,j,A,blue);
    
    // red side
    for(int i=0;i < n;i++)
        dfs(i,m-1,A,red);
    for(int j =0;j < m;j++)
        dfs(n-1,j,A,red);

    int cnt = 0;
    for(int i=0;i < n;i++)
        for(int j=0;j < m;j++)
            if(red[i][j] && blue[i][j])
                cnt++;
    
    return cnt;
}
