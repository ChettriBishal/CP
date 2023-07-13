class Solution {
public: // BFS
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 2)
            return 0;
        
        int currMax = 0;
        
        int i =0;
        int level = 0;
        while(i <= currMax){
            int furthest = currMax;
            
            for(;i <= currMax;i++){
                furthest = max(furthest, i + nums[i]);
                if(furthest >= n-1) return level +1;
            }
            
            level++;
            currMax = furthest;
        }
        
        return 0;
    }
};
