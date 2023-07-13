class Solution {
    public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> ind;

        for(int i=0;i<nums.size();i++){
            ind[nums[i]] = i;
        }

        set<pair<int,int>> gone;
        for(int i=0;i<nums.size();i++){
            int tar = nums[i] - k;
            if(ind.find(tar) != ind.end() && ind[tar] != i ) {
                gone.insert({nums[i], tar});
            }

        }
        return gone.size();
    }
};
