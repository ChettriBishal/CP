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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0); // all val < x
        ListNode* second = new ListNode(0); // all val >= x
        ListNode* temp = head, *rfHead = first,*rsHead = second; // resultant first head .... resultant second head; rf and rs
        while(head){
            if(head->val < x){
                first ->next = head;
                first = head;
            }
            else{
                second->next = head;
                second = head;
            }
            head = head->next;
        }
        second->next = NULL; // terminating the second part's end point  
        first ->next = rsHead->next;

        return rfHead->next;
    }
};
