class MyCircularDeque {
public:
    struct Node{
        int val;
        Node* prev, *next;
        Node(){
            prev = NULL;
            next = NULL;
        }
    };
    int MAXN;
    Node* front, *rear;
    int len ; // current length of the deque 
    MyCircularDeque(int k) {
        front = rear = NULL;
        MAXN = k;
        len = 0;
    }
    
    bool insertFront(int value) {
        if(len == MAXN)
            return false;
        Node* temp = new Node();
        temp -> val =value;
        if(len == 0){ // first entry 
            front = rear = temp;
            len++;
            return true; 
        }
        temp ->next = front;
        front ->prev = temp;
        front = temp;
        len++;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(len == MAXN)
            return false;
        Node* temp = new Node();
        temp -> val =value;
        if(len == 0){ // first entry 
            front = rear = temp;
            len++;
            return true;
        }
        temp->prev = rear;
        rear ->next = temp;
        rear = temp;
        len++;
        return true;
    
    }
    
    bool deleteFront() {
        if(front == NULL || len == 0)
            return false;
        Node* temp = front;
        front = front ->next;
        if(front)
            front ->prev = NULL;
        delete temp;
        len--;
        if(len == 0){ // no elements left 
            front = rear = NULL;
        }
        return true;
    }
    
    bool deleteLast() {
        if(rear == NULL || len == 0)
            return false;
        Node* temp = rear;
        rear = rear ->prev;
        if(rear)
            rear ->next = NULL;
        delete temp;
        len--;
        if(len == 0){ // no elements left
            front = rear = NULL;
        }
        return true;
    }
    
    int getFront() {
        if(front == NULL)
            return -1;
        return front->val;
    }
    
    int getRear() {
        if(rear == NULL)
            return -1;
        return rear ->val;
    }
    
    bool isEmpty() {
       if(len == 0)
           return true;
        return false;
    }
    
    bool isFull() {
        if(len == MAXN)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
