class Solution {
public:
    // also see diagram for this 
    void reorderList(ListNode* head) {
        if(!head or !head->next)
            return;
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<ListNode*> st;
        ListNode* temp = slow->next;
        // we fill the elements of the second half of the linked list 
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        temp = head;
        ListNode* nnext;
        while(temp != slow && !st.empty()){
            nnext = temp ->next;
            temp->next = st.top();
            st.top()->next = nnext;
            temp = nnext;
            st.pop();
        }
        if(!st.empty())
            st.top()->next = NULL;
        else 
            nnext ->next = NULL;
        
    }
};
