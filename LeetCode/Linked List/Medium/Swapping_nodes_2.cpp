class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kth= NULL, *ptr1, *ptr2;
        ptr1 = ptr2 = head;
        while(--k){
            ptr1 = ptr1 ->next;
        }
        kth = ptr1;
        ptr1 = ptr1 ->next;
        while(ptr1){
            ptr1 = ptr1 ->next;
            ptr2 = ptr2 ->next;
        }
        swap(kth->val, ptr2->val);
        
        return head;
    }
};
/*
We traverse the list until we reach the kth node.
Then we set "kth" to that node to remember it, set ptr2 to head and continue traversing the list,while we move both ptr1 and ptr2.
When ptr1 reaches the end - ptr2 is on the (n-k)th node.
Now we swap "kth" and "ptr2" and we're done!
*/
