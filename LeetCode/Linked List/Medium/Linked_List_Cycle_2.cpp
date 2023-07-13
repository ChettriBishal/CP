class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL|| head->next == NULL)
            return NULL;
        ListNode* slow, *fast;
        slow = fast = head;

        while(fast->next && fast->next->next){
            slow = slow ->next;
            fast = fast ->next ->next;
            
             if(slow == fast){ // cycle found 
                ListNode* entry = head;
                 while(entry != slow){
                     entry = entry ->next;
                     slow = slow->next;
                 }
                 return entry;
             }
        }
        return NULL;
    }
};
/*
Step 1: Determine whether there is a cycle

1.1) Using a slow pointer that move forward 1 step each time

1.2) Using a fast pointer that move forward 2 steps each time

1.3) If the slow pointer and fast pointer both point to the same location after several moving steps, there is a cycle;

1.4) Otherwise, if (fast->next == NULL || fast->next->next == NULL), there has no cycle.

Step 2: If there is a cycle, return the entry location of the cycle

2.1) L1 is defined as the distance between the head point and entry point

2.2) L2 is defined as the distance between the entry point and the meeting point


Distance traveled by slow when they meet: L1+L2
Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

2(L1+L2) = L1+L2+x+L2
2L1 + 2L2 = L1+2L2+x
=> x = L1

so we need to move L1 steps from the current meeting point to reach the entry point of the cycle.
*/
