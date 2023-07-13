class Solution {
public:
    int getlen(ListNode* node){
        int n= 0;
        while(node){
            n++;
            node = node->next;
        }
        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int m = getlen(head);
        vector<ListNode*> bis(2);
        ListNode* temp = head;
        for(int i=0;i<m;i++){
            if(i == k-1){
                bis[0] = temp;
            }
            if(i == m- k){
                bis[1] = temp;
            }
            temp = temp ->next;
        }
        swap(bis[0]->val, bis[1]->val);
        return head;
    }
};
