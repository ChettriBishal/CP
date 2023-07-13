class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // cols
        
        int lo = 0, hi = n * m -1;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(matrix[mid / m][mid % m] == target) 
                return true;
            else if(matrix[mid/m][mid % m] < target)
                lo = mid + 1;
            else
                hi = mid -1;
        }
        return false;
    }
};
/*
Converting 2D index into 1D index and checking 
*/
