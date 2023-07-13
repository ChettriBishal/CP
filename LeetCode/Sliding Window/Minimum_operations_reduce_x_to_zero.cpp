class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int reqsum = sum -x; // required sum from -->
        if(reqsum == 0)
            return n;
        int runn = 0; // running sum 
        int low = 0;
        int res = INT_MIN; // maximum len from left = minimum len from right
        for(int i=0;i<n;i++){
            runn += nums[i];
            while(low<=i && runn > reqsum ){
                runn -= nums[low++];
            }
            if(runn == reqsum ) res = max(res,i-low+1); 
        }
        if(res == INT_MIN) return  -1;
        return n-res;
    }
};
