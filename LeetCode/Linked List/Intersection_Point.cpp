class Solution {
public:
    int length(ListNode* root){
        int n =0;
        while(root){
            root = root->next;
            n++;
        }
        return n;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lA = length(headA);
        int lB = length(headB);
        while(lA > lB){
            headA = headA ->next;
            lA--;
        }
        while(lB > lA){
            headB = headB ->next;
            lB --;
        }
        while(headA && headB){
            if(headA == headB)
                return headA;
            headA = headA ->next;
            headB = headB ->next;
        }
        return NULL;
    }
};
