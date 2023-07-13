class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode * slow, *fast;
        slow = fast = head;
        while(slow && fast && fast ->next){
            slow  = slow -> next;
            fast  = fast -> next ->next;
        }
        return slow;
    }
};
