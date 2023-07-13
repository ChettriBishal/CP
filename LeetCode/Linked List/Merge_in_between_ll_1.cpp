class Solution {
public:
    ListNode* lastnode(ListNode* node){ // to get the last node
        while(node ->next){
            node = node->next;
        }
        return node;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* head = list1;
        vector<ListNode*> bis;
        int pp = 0;
        ListNode * temp = head;
        while(pp < a-1){ // to reach (a-1)th node
            temp = temp->next;
            pp++;
        }
        bis.push_back(temp); 
        while(pp < b+1 ){ // to reach (b+1)th node
            temp = temp->next;
            pp++;
        }
        bis.push_back(temp);
        bis[0]->next = list2; // (a-1)th node ---> head of list2
        lastnode(list2) ->next = bis[1];  // tail of list2 ----> (b+1)th node of list 1
        return head;

        
    }
};
