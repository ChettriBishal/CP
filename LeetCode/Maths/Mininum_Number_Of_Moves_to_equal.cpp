class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        for(int i=0;i < n;i++){
            sum += nums[i];
        }
        
        return (sum - n * nums[0]);
    }
  
    /*
        # sum = sum of all items in nums
        # m   = number of moves
        # x   = value of all items in nums after m moves
        # n   = number of items in nums
        # x*n = sum of all items after m moves
        # each move add (n-1) to sum
        # so m moves add m*(n-1) to sum
        # so x*n = sum + m*(n - 1) ............. (1)
        
        # smallest is smallest number in nums before moves, after m moves, m got added to it and it became x
        # smallest + m = x  ............... (2)
        
        # smallest * n + m*n = sum + m*n - m.................using (1) and (2)
        # smallest * n       = sum - m ............ m*n cancel on both side
        # m  = sum - smallest * n .......... m (final desired result)
    */
};
