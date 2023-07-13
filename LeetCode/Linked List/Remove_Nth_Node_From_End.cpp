class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* nnext = temp;
        ListNode* prev =NULL;
        while(temp!= NULL){
            for(int i=0;i<n&& nnext!= NULL;i++){
                nnext = nnext ->next;
            }
            if(nnext == NULL){
               // cout<<prev->val<<endl;
                if(temp != head){
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
                else{
                    head = head->next;
                    delete temp;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
            nnext = temp;
        }
        return head;
    }
};
