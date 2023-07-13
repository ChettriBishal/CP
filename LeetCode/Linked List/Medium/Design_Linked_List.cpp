struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val=val;
        next=NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int len = 0; // length of the linked list
    MyLinkedList() {
        head= new Node(0);
    }
    
    int get(int index) {
        if(index >= len)
            return -1;
        Node* temp = head -> next;
        for(int i=0;i<index;i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node * temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        len++;
    }
    void addAtTail(int val) {
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new Node(val);
        len++; 
    }
    
    void addAtIndex(int index, int val) {
        if(index > len)
            return;
        Node* temp = head;
        for(int i=0;i<index;i++)
            temp = temp->next;
        Node* temp2 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp2;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= len)
            return;
        Node *temp = head;
        for(int i=0;i<index;i++)
            temp = temp->next;
        Node* temp2 = temp->next;
        temp->next = temp->next->next;
        temp2->next = NULL;
        delete temp2;
        len--;
    }
};
