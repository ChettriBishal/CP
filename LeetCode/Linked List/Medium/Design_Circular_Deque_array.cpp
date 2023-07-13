class MyCircularDeque {
    vector<int> deq;
    int MAXN, front, rear, len;
public:
    MyCircularDeque(int k) {
        deq.resize(k,0);
        MAXN = k;
        front = k-1;
        rear = 0;
        len = 0;
    }
    // <---- front - rear ---->
    bool insertFront(int value) {
        if(isFull())
            return false;
        
        front = (front -1 + MAXN) % MAXN; // <--- front
        deq[front] = value;
        len++;
        if(len == 1) // after the first entry 
            rear = front;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        
        rear = (rear + 1) % MAXN; // rear --->
        deq[rear] = value;
        len++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        front = (front + 1)% MAXN; // front --->
        len--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        rear = (rear -1 + MAXN) % MAXN; // rear <--- 
        len--;
        return true;
    }
    
    int getFront() {
        if(!isEmpty())
            return deq[front];
        return -1;
    }
    
    int getRear() {
        if(!isEmpty())
            return deq[rear];
        return -1;
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == MAXN;
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
