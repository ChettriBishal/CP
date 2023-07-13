class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int rows[n],cols[n];
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rows[i] = max(rows[i],grid[i][j]); // max along row i
                cols[i] = max(cols[i],grid[j][i]); // max along col i
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp = min(rows[i],cols[j]); // min of ith row and jth col
                res += (temp - grid[i][j]);
            }
        }
        return res;
    }
};
