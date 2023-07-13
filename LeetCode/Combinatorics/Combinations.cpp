class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> nums;
        generate(nums,1,n,k);
        
        return result;
    }
    
    void generate(vector<int>& nums, int itr,int n, int k){
        if(nums.size() == k){
            result.push_back(nums);
            return;
        }
        for(int i = itr;i <= n;i++){
            nums.push_back(i);
            generate(nums,i +1, n, k);
            nums.pop_back();
        }
    }
};
