class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        vector<int> freq(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<i))
                   freq[i]++; 
            }
        }
        int res =0;
        for(int i=0;i<32;i++){
            if(freq[i]% 3 == 1){  
                 res += (1<<i);          
            }
        }
        return res;
    }
};
/*
Let X be the required number which occurs only once 
Let freq[] be the frequency array
* freq[i] = number of elements with ith bit set
* If ith bit is set in X, then freq[i] would be of the form 3n+ 1
* Thus when we take modulo with 3 we get 1
https://www.youtube.com/watch?v=dc7HF3PA250&list=PL2q4fbVm1Ik7ip1VkWwe5U_CEb93vw6Iu&index=14
*/
