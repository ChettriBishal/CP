class Solution {
public:
     vector<int> dx{-1,0,1,0};
     vector<int> dy{0,1,0,-1};
    
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0; // no of islands 
        
        for(int i=0;i < grid.size(); i++){
            for(int j=0;j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    grid[i][j] = '0';
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        pair<int,int> curr = q.front();
                        q.pop();
                        for(int k = 0; k < 4;k++){
                            int r = curr.first + dx[k], c = curr.second + dy[k];
                            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
                                continue;
                            grid[r][c] = '0';
                            q.push({r,c});
                            
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};
