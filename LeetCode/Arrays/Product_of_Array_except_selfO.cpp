class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int runp = 1; // running product
        for(int i=0;i<n;i++){  // ---->
            runp *= nums[i];
            res[i] = runp;
        } 
        runp = 1;
        for(int i= n-1;i>0;i--){  // <----
            res[i] = res[i-1] * runp;
            runp *= nums[i];
        }
        res[0] = runp;
        
        return res;
    }
};
/*
nums[]    1   2   3   4
After the first iteration
res[]     1   2   6   24

then we iterate from the right

* ---> curr
^ ---> curr - 1
so take the n-1th element into consideration
1. res[]     1   2   6   24
                     ^   *
                     
res[curr] = runp * res[curr- 1] --> 1 * 6 

runp = runp * nums[curr] --> 1 * 4

curr = curr - 1

2. res[]     1   2   6   6 
                 ^   *
                 
 res[curr] =  runp * res[cur-1] --> 4 * 2  
 
 runp = runp * nums[curr] --> 4 * 3

this continues till i > 0

finally runp will contain the product of the all the numbers except the 0th element
so we do 
res[0] = runp

*/
