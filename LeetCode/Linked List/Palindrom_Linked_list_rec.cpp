class Solution {
public:
    ListNode* a, *b;
    bool pal = true;
    void fromback(ListNode* b){
        if(b == NULL)
            return;
        fromback(b ->next);
        if(b->val == a->val){ // if equal move "a" forward
            a = a ->next;
        }
        else pal = false;
    }
    bool isPalindrome(ListNode* head) {
        a = b = head;
        fromback(b);
        return pal;
    }
};
