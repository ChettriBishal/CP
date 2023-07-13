class Solution {
public:
    vector<vector<int>> dp;
    bool present(vector<int>& vec,int curr,int sum, int n )
    {
        if(sum == 0)
            return true;
        if(curr >= n || sum < 0)
            return false;
        if(dp[curr][sum] != -1) // if already calculated
            return dp[curr][sum];
        
        return dp[curr][sum] = present(vec,curr+1,sum,n) || present(vec,curr +1,sum - vec[curr],n);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto &x: nums){
            sum += x;
        }
        if(sum % 2 != 0){
            return false;
        }
        int half = sum /2;
        dp.resize(n+1,vector<int>(half+1,-1));
        
        return present(nums,0,half,n);
        
    }
};
