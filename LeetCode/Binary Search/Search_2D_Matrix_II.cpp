class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        
        while(col >= 0 && row < matrix.size()){
            if(matrix[row][col] == target)
                return true;
            else if(target > matrix[row][col])
                row++;
            else if(target < matrix[row][col])
                col--;
        }
        
        return false;
    }
};
