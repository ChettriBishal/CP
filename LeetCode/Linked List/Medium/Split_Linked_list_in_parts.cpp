class Solution {
public:
    int getlen(ListNode* head){
        int n = 0;
        while(head){
            head = head->next;n++;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getlen(head);
        int grps = n / k; // no of groups
        int rem = n % k; // extras 
        vector<ListNode*> res;
        while(head){
            res.push_back(head);
            int cnt = 1;
            while(cnt < grps){
                head = head ->next;
                cnt++;
            }
            if(rem > 0 && n > k){
                head = head->next;
                rem--;
            }
            ListNode* temp = head ->next;
            head ->next = NULL;
            head = temp;
        }
        while(n < k){
            res.push_back(NULL);
            n++;
        }
        return res;
        
    }
};
