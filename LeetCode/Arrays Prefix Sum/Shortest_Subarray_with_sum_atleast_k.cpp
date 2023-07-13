class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long> pre(n, 0);
        pre[0] = nums[0];
        
        for(int i=1;i < n;i++)
            pre[i] = (long) pre[i-1] + nums[i];
        
        deque<int> d;
        
        int res = n+1;
        
        for(int i=0;i<n;i++){
            
            if(pre[i] >= k)
                res = min(res, i+1);
            
            while(d.size() > 0 && pre[i] - pre[d.front()] >= k){
                res = min(res, i - d.front());
                d.pop_front();
            }
            
            while(d.size() > 0 && pre[i] <= pre[d.back()])
                d.pop_back();
            
            d.push_back(i);
        }
        
        return res <= n ? res: -1;
    }
};
