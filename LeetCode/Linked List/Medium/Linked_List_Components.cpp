class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int cnt = nums.size(); // initially 
        unordered_set<int> there(nums.begin(),nums.end());
        while(head->next){
            int a, b;
            a = head ->val;
            b = head ->next ->val;
            auto e = there.end();
            if(there.find(a) != e && there.find(b) != e)
                cnt--;
            head = head ->next;
            
        }
        return cnt;
    }
};
/*

If you use the concepts from Union-Find, it becomes easy to understand.
nums is the initail state of a Union-Find problem, each number in nums is a node, every nodes is disjointed from other nodes.
Whenever we Union two nodes, components decrease by 1.
How do we know which two nodes to Union? Description says "two values are connected if they appear consecutively in the linked list."
So we traverse the linked list, for each edge, if both vals are in nums, we decrease components by 1.

*/
