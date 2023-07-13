class Solution {
public:
    int dp[71][70 * 70 + 1] = {[0 ... 70][0 ... 70*70] = INT_MAX};
    
    int dfs(vector<set<int>> &rows,int i, int sum, int target){
        if(i >= rows.size())
            return abs(sum - target);
        
        if(dp[i][sum] != INT_MAX)
            return dp[i][sum];
        
        for(auto it = begin(rows[i]); it!= end(rows[i]); it++){
            
            dp[i][sum] = min(dp[i][sum], dfs(rows, i+1, sum + *it, target));
            
            if(dp[i][sum] == 0 || dp[i][sum] + *it > target)
                break;
        }
        
        return dp[i][sum];
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<set<int>> rows;
        
        for(int i=0; i < mat.size();i++){
            rows.push_back(set<int>(mat[i].begin(), mat[i].end()));
        }
        
        return dfs(rows, 0,0, target);
    }
};
/*
Approach 1: DP + Pruning
The sum of the entire matrix cannot be larger than 70 * 70. We can use this fact for memoisation.

Now, to achieve good runtime (the code below is ~80 ms), we need to sort each row and remove duplicates.

This way, we can stop after the running sum exceeds the target.
*/
