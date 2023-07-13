class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = fast = nums[0];
        
        do{
            slow = nums[slow]; // moving by one 
            fast = nums[nums[fast]]; // moving by two 
        }while(slow != fast);
        
        // slow now points to the meeting point
        
        fast = nums[0]; // from the start 
        while(slow != fast){ // moving both by one now
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
/*
Step 2: If there is a cycle, return the entry location of the cycle

2.1) L1 is defined as the distance between the head point and entry point

2.2) L2 is defined as the distance between the entry point and the meeting point


Distance traveled by slow when they meet: L1+L2
Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

2(L1+L2) = L1+L2+x+L2
2L1 + 2L2 = L1+2L2+x
=> x = L1

so we need to move L1 steps from the current meeting point to reach the entry point of the cycle.
*/
