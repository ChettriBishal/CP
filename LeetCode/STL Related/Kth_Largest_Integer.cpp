class Solution {
public:
    class comp{
        public:
        bool operator() (string & a, string & b){
            if(a.size() != b.size())
                return a.size() > b.size();
            
            return a > b;
        }
    };
  
    string kthLargestNumber(vector<string>& nums, int k) {
        
        nth_element(nums.begin(), nums.begin() + k -1, nums.end(), comp());
        
        return nums[k-1];
    }
};
