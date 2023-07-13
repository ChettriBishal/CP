class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        Node* temp = head;
        while(temp){
            Node* nnext = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nnext;
            temp = nnext;
        }
        Node* res = head->next;
        temp = head;
        while(temp && temp->next){
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        // make the given linked list as it is now 
        // separte the copy from the original 
        temp = head;
        while(temp){
            Node* nnext = temp->next->next;
            Node* copy = temp->next;
            temp->next = nnext;
            if(nnext)
                copy->next = nnext->next;
            temp = nnext;
        }
        return res;
    }
};
