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
    ListNode* reverse(ListNode* head){ // reversing the portion after head
        ListNode* prev = NULL;
        while(head){
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // reverse the second half of the list
        ListNode* dum = head;
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast->next && fast->next->next){ // first middle
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        while(slow){
            if(slow ->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
