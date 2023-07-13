class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head ->next == NULL) // no node or only one node
            return false;
        ListNode* slow, *fast;
        slow = head;
        fast = head ->next->next;
        while(slow && fast && fast ->next){
            if(slow == fast)
                return true;
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        return false;
    }
};
