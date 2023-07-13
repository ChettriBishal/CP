// Reverse Nodes in K Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        for(int i=0;i < k -1 && node;i++){
            node = node ->next;
        }
        if(!node)
            return head;
        
        ListNode* newbegin = node->next;
        
        auto newhead = reverse(head, node);
        head->next = reverseKGroup(newbegin,k);
        
        return newhead;
        
    }
    ListNode* reverse(ListNode* first, ListNode* last){
        ListNode* prev = NULL, *end = last->next;
      
        while(first != end){
            ListNode* nex = first->next;
            first->next = prev;
            prev = first;
            first = nex;
        }
        
        return prev; 
    }
};
