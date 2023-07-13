class MyHashSet {
public:
    struct node{
        int data;
        node* next;
    };

    node* head;
    MyHashSet() {
        head = NULL;
    }
    
    void add(int key) {
        node* temp = new node;
        temp ->data= key;
        temp ->next = NULL;
        if(head == NULL){ // first entry
            head = temp;
            return;
        }
        if(contains(key)) // if it exists already 
            return;
        temp ->next = head;
        head = temp;
        return;
    }
    
    void remove(int key) {
        if(!contains(key))
            return ;
        node* trav = head;
        node* prev= NULL;
        if(head -> data == key){
            //cout<<key<<" "<<"Here\n";
            //dis();
            head = head->next;
            delete trav;
            return;
        }
        while(trav){
            if(trav ->data == key)
                break;
            prev = trav;
            trav = trav ->next;
        }
        
        prev ->next = trav->next;
        delete trav;      
    }
    void dis()
    {
        cout<<"List so far\n";
        node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool contains(int key) {
        node* temp = head;
        while(temp != NULL){
            if(temp ->data == key)
                return true;
            temp = temp ->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
