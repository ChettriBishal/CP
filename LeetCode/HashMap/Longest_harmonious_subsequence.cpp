class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        for(int &x: nums){
            cnt[x]++;
        }
        int res = 0;
        for(auto &p: cnt){
            int tar = p.first + 1;
            if(cnt.find(tar) != cnt.end()){
                int temp = cnt[p.first] + cnt[tar];
                res = max(res,temp);
            }
        }
        return res;
    }
};
