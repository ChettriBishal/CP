class Solution {
public:
    // we pick the maximum value from every column
    // https://leetcode.com/problems/find-a-peak-element-ii/discuss/1276556/JavaPythonC%2B%2B-Clear-Explanation-with-Images-or-M*Log(N)-or-Very-Short-code
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0, endCol = mat[0].size()-1;
        
        while(startCol <= endCol){
            int maxRow = 0;
            int midCol = (startCol + endCol)/2;
            
            for(int row = 0;row < mat.size();row++){
                if(mat[row][midCol] > mat[maxRow][midCol]){
                    maxRow = row;
                }
            }
            
            bool leftbig = midCol -1 >= startCol && mat[maxRow][midCol -1] > mat[maxRow][midCol];
            bool rightbig = midCol + 1 <= endCol && mat[maxRow][midCol +1] > mat[maxRow][midCol];
            
            if(!leftbig && !rightbig){
                return {maxRow, midCol};
            }
            
            else if(leftbig){
                endCol = midCol -1;
            }
            else{
                startCol = midCol + 1;
            }
        }
        
        return {-1,-1};
    }
};
