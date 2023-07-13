class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int valrequired = 0; // maximum xor 
        int result = 0;
        
        for(auto &x: nums)
            valrequired |= x;
        
        int n = nums.size();
        
        for(int i=1;i<(1 << n);i++){
            int check = 0;
            for(int j= 0;j< n;j++){
                if(i & ( 1 <<j))
                    check |= nums[j];
            }
            if(check == valrequired)
                result++;
        }
        
        return result;
    }
};
