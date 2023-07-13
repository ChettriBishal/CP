class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* h = head;h; h = h->next){
            if(h ->child){
                Node* next = h ->next; // as node->next will now point to child 
                h ->next = h ->child;
                h ->child = NULL; // remove the child; it isn't child anymore
                h -> next ->prev = h; // reset the back link 
                Node* p = h->next;
                while(p ->next) // traverse to the last node from the child
                    p = p->next;
                p->next = next; // set the link 
                if(next)
                    next->prev = p; // back link 
            }
        }
        return head;
    }
};
