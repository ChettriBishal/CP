class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp; // to store running sum -> node mapping
        
        ListNode* dummy = new ListNode(0);
        dummy ->next = head;
        
        mp[0] = dummy;
        
        int run = 0; // running sum 
        while(head){
            
            run += head->val;
            
            if(mp.find(run) != mp.end()){
                ListNode* toremove = mp[run]->next;
                int psum = run;
                
                while(toremove != head){ // removing the deleted segment from the map
                    psum += toremove->val;
                    mp.erase(psum);
                    toremove = toremove->next;
                }
                // redraw the link 
                mp[run]->next = head->next;
            }
            else{
                mp[run] = head;
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};
