class Solution {
public:
    // builds upon subarray sum equals k 
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i=0;i < n;i++){ // prefix sum for every row
            for(int j=1;j < m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int res = 0;
        
        for(int c1 = 0; c1 < m; c1++){
            for(int c2 = c1; c2 < m; c2++){ //   [ ]
                unordered_map<int,int> cnt;
                cnt[0]++;
                
                int sum = 0;
                
                for(int row= 0;row < n;row++){
                    sum += matrix[row][c2];    
                    if(c1 > 0)
                        sum -= matrix[row][c1-1];
                    
                    if(cnt.find(sum - target) != cnt.end()){
                        res += cnt[sum - target];
                    }
                    
                    cnt[sum]++;
                }
            }
        }
        
        return res;
    }
};

/*
Steps
find the prefix sum for every row

for each pair of column find the subarrays sum equal to target
*/
