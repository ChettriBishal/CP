class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++)
            pre[i] = pre[i-1] + nums[i-1];
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int sum = pre[j] - pre[i];
                if( sum >= target){
                    res = min(res,j-i);
                    break;
                }
            }
        }
        if(res != INT_MAX) return res;
        return 0;
    }
};
