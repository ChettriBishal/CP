class Solution {
public:
     vector<int> dx{-1,0,1,0};
     vector<int> dy{0,1,0,-1};
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0; // no of islands
        
        for(int i=0;i < grid.size(); i++){
            for(int j= 0;j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return cnt;
    }
    
    void dfs(vector<vector<char>> & grid, int x,int y)
    {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        
        for(int k = 0; k < 4; k++)
            dfs(grid,x + dx[k] , y + dy[k]);
         
    }
};
