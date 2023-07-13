class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        for(int i=0;i<(1<<n);i++){ // 2 ^n subsets
            vector<int> temp;
            for(int j =0; j< n;j++){
                if(i & (1 << j))
                    temp.push_back(nums[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
