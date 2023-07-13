class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       
        unordered_map<int,vector<int>> mp;
        unordered_set<int> ok;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i); 
            ok.insert(nums[i]);
        }
        int cnt =0;
        for(auto k: ok){
            int n= mp[k].size();
            if(n >1)
                cnt += ((n-1)*n)/2;
        } 
       
        return cnt;
        
        
    }
};
