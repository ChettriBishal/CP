class Solution {
    public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
        int ok = 0; // to store the xor
        for(const auto& k: nums)
            ok ^= k;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int curr = 0;
            for(int bit = 0;bit < maximumBit; bit++){
                int ith = (ok & (1 << bit));
                if(! ith){ // if the current bit is not set then the ith bit of curr should be set
                    curr |= (1 << bit);
                }
            }
            res.push_back(curr);
            ok ^= nums.back();
            nums.pop_back(); // as per the question

        }
        return res;
    }
};
