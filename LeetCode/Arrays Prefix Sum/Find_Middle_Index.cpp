class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        vector<int> pre(n + 2);
        pre[0] = 0; // middleIndex == 0, the left side sum is considered to be 0
        for(int i=1;i<=n;i++)
            pre[i] = pre[i-1] + nums[i-1];
        pre[n+1] = 0; // if middleIndex == nums.length - 1, the right side sum is considered to be 0.
        for(int i=0;i<=n+1;i++){
            if(i+1 <=n && pre[i] == pre[n]- pre[i+1]) 
                return i;
        }
        return -1;
    }
};
