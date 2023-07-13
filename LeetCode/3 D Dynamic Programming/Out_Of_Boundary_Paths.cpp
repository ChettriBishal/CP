class Solution {
public:
    int m ,n;
    int MOD;
    int dp[51][51][51];
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        MOD = 1e9 + 7;
        
        memset(dp,-1,sizeof(dp));
        
        int res = reach(maxMove,startRow, startColumn);
        
        return res;
    }
    
    int reach(int moves, int x, int y){
        if(moves < 0)
            return 0;
        
        if(x < 0 || y < 0 || x >= m || y >= n){
            return 1;
        }
        
        if(dp[x][y][moves] != -1)
            return dp[x][y][moves];
        
        int dx[] = {0,-1,0,1};
        int dy[] = {1,0,-1,0};
        
        int cnt = 0;
        for(int i=0;i < 4;i++){
            cnt += reach(moves-1,x + dx[i], y + dy[i]);
            cnt %= MOD;
        }
        
        return dp[x][y][moves] = cnt;
    }
};
