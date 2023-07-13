class Solution {
public:
    int rowSize, colSize;
    
    int getsum(int i, int j ,vector<vector<int>> & pre){
        if(i < 0 || j < 0) 
            return 0;
       if(i > rowSize ) i = rowSize;
       if(j > colSize ) j = colSize;
        
        return pre[i][j];
        
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        rowSize = mat.size();
        colSize = mat[0].size();
        
        vector<vector<int>> pre(rowSize + 1, vector<int>(colSize + 1, 0)); // 1 based index prefix matrix    
        // constructing the prefix sum matrix
           
        for(int i=1; i<= rowSize;i++){
            for(int j = 1;j<= colSize;j++){
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        
        vector<vector<int>> result(rowSize , vector<int> (colSize));
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                int x1, y1, x2, y2;
                x1 = i+1 - k, y1 = j+1 - k; // +1 as prefix sum array is 1 index based 
                x2 = i+1 + k, y2 = j+1 + k;
                result[i][j] = getsum(x2,y2,pre) - getsum(x1-1,y2,pre) - getsum(x2, y1-1,pre) + getsum(x1-1, y1-1,pre);
            }
        }

        
        return result;
    }
};
